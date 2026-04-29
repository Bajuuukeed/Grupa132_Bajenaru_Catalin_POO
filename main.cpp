#include "SalaSport.h"
#include <limits> // Necesar pentru numeric_limits

int main() {
    SalaSport sala;
    int opt, sub;

    do {
        std::cout << "\n====================\n  MENIU PRINCIPAL\n====================\n";
        std::cout << "1. GESTIUNE CLIENT\n2. TIMP SI DATA\n0. IESIRE\nAlegeti: ";
        std::cin >> opt;
        if (opt == 1) {
            do {
                std::cout << "\n--- GESTIUNE ---\n1.Adauga\n2.Cautare\n3.Istoric\n4.Reactivare (-10%)\n5.Inapoi\nAlegeti: ";
                std::cin >> sub;
                try {
                    if (sub == 1) {
                        std::string n; int t;
                        std::cout << "Nume complet: ";
                        std::cin.get(); // Consumă newline-ul rămas în buffer
                        std::getline(std::cin, n); // Citește "Bajenaru Catalin" corect

                        std::cout << "Tip (1-Platinum, 2-Spartan, 3-Luptator): ";
                        std::cin >> t;
                        sala.adaugaClient(n, t);
                    }
                    else if (sub == 2) {
                        int id; std::cout << "ID: "; std::cin >> id;
                        sala.cautaId(id);
                    }
                    else if (sub == 3) sala.istoric();
                    else if (sub == 4) {
                        int id; std::cout << "ID pentru reactivare: "; std::cin >> id;
                        sala.reactivare(id);
                    }
                } catch (const GymException& e) { std::cerr << "\n!!! " << e.what() << " !!!\n"; }
            } while (sub != 5);
        }
        else if (opt == 2) {
            std::cout << "\n--- TIMP ---\n1.Setare Data Initiala\n2.Avansare Zile\nAlegeti: ";
            std::cin >> sub;
            try {
                if (sub == 1) {
                    int z, l, a; std::cout << "Zi Luna An (ex: 20 5 2025): ";
                    std::cin >> z >> l >> a;
                    sala.setareData(z, l, a);
                }
                else if (sub == 2) {
                    int z; std::cout << "Cate zile trec? "; std::cin >> z;
                    sala.avanseazaTimp(z);
                }
            } catch (const GymException& e) { std::cerr << "\n!!! " << e.what() << " !!!\n"; }
        }
    } while (opt != 0);

    return 0;
}