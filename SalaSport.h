#ifndef SALASPORT_H
#define SALASPORT_H
#include "Client.h"
#include "Exceptii.h"
#include <vector>
class SalaSport {
    std::vector<Client> bazaDate;
    std::tm dataCurenta;
    bool dataSetata = false;
    static int contor;

public:
    void afisareData() const {
        std::cout << ">>> Data curenta sistem: " << dataCurenta.tm_mday << "/"
                  << dataCurenta.tm_mon + 1 << "/" << dataCurenta.tm_year + 1900 << std::endl;
    }

    void setareData(int z, int l, int a) {
        std::tm test = {0, 0, 0, z, l - 1, a - 1900};
        std::tm copie = test; std::mktime(&copie);
        if (copie.tm_mday != z || copie.tm_mon != (l - 1)) throw DataInvalidaException();
        dataCurenta = test; dataSetata = true;
        std::cout << ">>> Data setata cu succes!" << std::endl;
    }

    void adaugaClient(std::string nume, int tip) {
        if(!dataSetata) throw DataNesetataException();
        std::unique_ptr<Abonament> ab;
        if(tip == 1) ab = std::make_unique<SpartanPlatinum>();
        else if(tip == 2) ab = std::make_unique<Spartan>();
        else ab = std::make_unique<Luptator>();
        bazaDate.emplace_back(nume, ++contor, std::move(ab), dataCurenta);
        std::cout << ">>> Abonament adaugat cu succes!" << std::endl;
    }

    void avanseazaTimp(int z) {
        if(!dataSetata) throw DataNesetataException();
        dataCurenta.tm_mday += z; std::mktime(&dataCurenta);
        afisareData();
    }

    void reactivare(int id) {
        if(!dataSetata) throw DataNesetataException();
        for(auto& c : bazaDate) {
            if(c.getId() == id) { c.reactivare(dataCurenta);
            std::cout << ">>> Abonament reactivat cu succes!" << std::endl;
            afisareData(); return; }
        }
        throw IdInexistentException();
    }

    void cautaId(int id) {
        if(!dataSetata) throw DataNesetataException();
        for(auto& c : bazaDate) { if(c.getId() == id) { c.afisare(dataCurenta); return; } }
        throw IdInexistentException();
    }

    void istoric() {
        if(!dataSetata) throw DataNesetataException();
        for(auto& c : bazaDate) c.afisare(dataCurenta);
    }
};
int SalaSport::contor = 0;
#endif