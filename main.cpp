/*
SISTEM DE GESTIUNE A UNEI SALI DE SPORT. ACEST SISTEM INCLUDE ADAUGAREA, REACTIVAREA , CAUTAREA ABONAMENTELOR CLIENTIILOR,
IAR PENTRU CONCRETIZAREA VALIDITATII ACESTUI PROIECT AM INCLUS SI O FUNCTIE DE ACCELERARE A TIMPULUI PENTRU A VEDEA CUM
ABONAMENTELE POT EXPIRA. EXISTA 2 TABELE, 1 PENTRU CLIENTII A CAROR ABONAMENTE SUNT ACTIVE SI 1 PENTRU TOATE ABONAMENTELE
 CE AU EXISTAT VREODATA. DATELE SUNT ADAUGATE DE LA TASTATURA, PROGRAMUL AVAND O INTERFATA DEZVOLTATATA SPECIAL PENTRU
 EFICIENTIZAREA BAZEI DE DATE A UNEI SALI ;].
 */
#include <iostream>
#include <fstream>
class Data {
    int zi;
    int luna;
public:
    Data() {
        zi = 1;
        luna = 1;
    }
    Data(int z, int l){
        zi = z;
        luna = l;
    }
    void setData(int zi1, int luna1) {
        zi = zi1;
        luna = luna1;
    }
    int getZi() const {
        return zi;
    }
    int getLuna() const {
        return luna;
    }
    friend std::ostream& operator<<(std::ostream& os, const Data& d) {
        if (d.zi < 10) os << "0";
        os << d.zi << "/";
        if (d.luna < 10) os << "0";
        os << d.luna;
        return os;
    }
};
class Abonament {
    char denumire[30];
    int durataInitiala;
public:
    Abonament() {
        durataInitiala = 30;
        const char* def = "Standard";
        int j = 0;
        while(def[j] != '\0') { denumire[j] = def[j]; j++; }
        denumire[j] = '\0';
    }
    void setTip(const char* nume) {
        int j = 0;
        while(nume[j] != '\0' && j < 29) {
            denumire[j] = nume[j];
            j++;
        }
        denumire[j] = '\0';
    }
    int calculeazaZileRamase(int dif) const {
        int ramase = durataInitiala - dif;
        if (ramase < 0) return 0;
        return ramase;
    }
    friend std::ostream& operator<<(std::ostream& os, const Abonament& a) {
        os << "Tip: " << a.denumire;
        return os;
    }
};
class Client {
    char nume[50];
    int id;
    Data dataInceput;
    Abonament tipAb;
public:
    Client() {
        id = 0;
        nume[0] = '\0';
    }
    Client(const Client& altul) {
        id = altul.id;
        dataInceput = altul.dataInceput;
        tipAb = altul.tipAb;
        int j = 0;
        while (altul.nume[j] != '\0' && j < 49) {
            nume[j] = altul.nume[j]; j++;
        }
        nume[j] = '\0';
    }
    Client& operator=(const Client& altul) {
        if (this != &altul) {
            id = altul.id;
            dataInceput = altul.dataInceput;
            tipAb = altul.tipAb;
            int j = 0;
            while (altul.nume[j] != '\0' && j < 49) {
                nume[j] = altul.nume[j]; j++;
            }
            nume[j] = '\0';
        }
        return *this;
    }
    ~Client() {}
    void reactivare(int z, int l) {
        dataInceput.setData(z, l);
    }
    void citesteClient(const char* n, int i, int z, int l, const char* numeAb) {
        id = i;
        dataInceput.setData(z, l);
        tipAb.setTip(numeAb);
        int j = 0;
        while (n[j] != '\0' && j < 49) {
            nume[j] = n[j];
            j++;
        }
        nume[j] = '\0';
    }
    int getZileRamase(int ziAcum, int lunaAcum) const {
        int totalZileStart = dataInceput.getLuna() * 30 + dataInceput.getZi();
        int totalZileAcum = lunaAcum * 30 + ziAcum;
        int diferenta = totalZileAcum - totalZileStart;
        return tipAb.calculeazaZileRamase(diferenta);
    }
    friend std::ostream& operator<<(std::ostream& os, const Client& c) {
        os << "ID: " << c.id << " | Nume: " << c.nume << " | " << c.tipAb
           << " | Data activare: " << c.dataInceput;
        return os;
    }
};
class SalaSport {
    Client* bazaDate;
    int nr;
    int ziSistem, lunaSistem;
public:
    SalaSport() {
        nr = 0;
        ziSistem = 1;
        lunaSistem = 1;
        bazaDate = new Client[100];
    }
    ~SalaSport() {
        delete[] bazaDate;
    }

    void afiseazaRegulament() const {
        std::ifstream f("Regulament.txt");
        char linie[200];
            while (f.getline(linie, 200)) {
                std::cout << linie << "\n";
            }
            f.close();
    }
    void afiseazaBeneficii() const {
        std::ifstream f("Beneficii.txt");
        char linie[200];
            while (f.getline(linie, 200)) {
                std::cout << linie << "\n";
            }
            f.close();
    }

    void activareID() {
        int idCautat;
        std::cout << "ID client pentru reactivare: ";
        std::cin >> idCautat;
        if (idCautat > 0 && idCautat <= nr) {
            bazaDate[idCautat - 1].reactivare(ziSistem, lunaSistem);
            std::cout << "Abonament reactivat!";
            std::cout << std::endl;
        } else {
            std::cout << "Eroare: Id-ul pus nu exista.";
            std::cout << std::endl;
            exit(0);
        }
    }
    void adauga() {
        if (nr >= 100) return;
        char n[50];
        int optAb;
        std::cout << "Cum te numesti?";
        std::cin.get();
        std::cin.getline(n,50);
        afiseazaBeneficii();
        std::cout << "Alegeti tip(1.Platinum, 2.Spartan,3.Luptator): ";
        std::cin >> optAb;
        const char* t;
        if (optAb == 1) t = "SpartanPlatinum";
        else if (optAb == 2) t = "Spartan";
        else t = "Luptator";
        bazaDate[nr].citesteClient(n, nr + 1, ziSistem, lunaSistem, t);
        nr++;
        std::cout << "Abonamentul " << t << " a fost  activat!";
        std::cout << std::endl;
    }
    void afisareStatus(const Client& c) const {
        int ramase = c.getZileRamase(ziSistem, lunaSistem);
        std::cout << c;
        if (ramase > 0) std::cout << " | STATUS: ACTIV (" << ramase << " zile)\n";
        else std::cout << " | STATUS: EXPIRAT\n";
    }
    void cautareID() const {
        int idCautat;
        std::cout << "Id client: ";
        std::cin >> idCautat;
        if (idCautat > 0 && idCautat <= nr) afisareStatus(bazaDate[idCautat - 1]);
        else std::cout << "Id-ul nu exista.\n";
    }
    void simuleazaTimp() {
        int zile;
        std::cout << "Cate zile vrei sa treaca? ";
        std::cin >> zile;
        ziSistem += zile;
        while (ziSistem > 30) {
            ziSistem -= 30;
            lunaSistem++;
        }
        std::cout << "Data noua:" << ziSistem << "/" << lunaSistem << std::endl;
    }
    void afisareActivi() const {
        std::cout << std::endl;
        std::cout << "Abonamente active";
        std::cout << std::endl;
        for (int i = 0; i < nr; i++) {
            if (bazaDate[i].getZileRamase(ziSistem, lunaSistem) > 0) afisareStatus(bazaDate[i]);
        }
    }
    void istoric() const {
        std::cout << std::endl;
        std::cout << "Istoric Clienti";
        std::cout << std::endl;
        for (int i = 0; i < nr; i++) afisareStatus(bazaDate[i]);
    }
};
int main() {
    SalaSport sala;
    sala.afiseazaRegulament();
    int opt, sub;
    do {
        std::cout << "1.GESTIUNE";
        std::cout << std::endl;
        std::cout << "2.TIMP";
        std::cout << std::endl;
        std::cout << "3.PANOU BENEFICII";
        std::cout << std::endl;
        std::cout << "0.IESIRE";
        std::cout << std::endl;
        std::cin >> opt;
        if (opt == 1) {
            do {
                std::cout << "1.Adauga";
                std::cout << std::endl;
                std::cout << "2.Cautare";
                std::cout << std::endl;
                std::cout << "3.Activi";
                std::cout << std::endl;
                std::cout << "4.Tot ";
                std::cout << std::endl;
                std::cout << "5.Reactivare Abonament";
                std::cout << std::endl;
                std::cout << "6.Inapoi";
                std::cout << std::endl;
                std::cin >> sub;
                if (sub == 1) sala.adauga();
                else if (sub == 2) sala.cautareID();
                else if (sub == 3) sala.afisareActivi();
                else if (sub == 4) sala.istoric();
                else if (sub == 5) sala.activareID();
            } while (sub != 6);
        } else if (opt == 2) {
            sala.simuleazaTimp();
        } else if (opt == 3) {
            sala.afiseazaBeneficii();
        }
    } while (opt);
    return 0;
}