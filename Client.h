#ifndef CLIENT_H
#define CLIENT_H

#include "Abonament.h"
#include <ctime>
#include <string>
#include <iostream>
#include <memory>

class Client {
    std::string nume;
    int id;
    std::unique_ptr<Abonament> tipAb;
    std::tm dataActivare;
    bool areReducereReactivare = false;

public:
    Client(std::string n, int i, std::unique_ptr<Abonament> ab, std::tm data)
        : nume(n), id(i), tipAb(std::move(ab)), dataActivare(data) {}

    Client(const Client& other) : nume(other.nume), id(other.id),
        tipAb(other.tipAb->clone()), dataActivare(other.dataActivare),
        areReducereReactivare(other.areReducereReactivare) {}

    friend void swap(Client& first, Client& second) noexcept {
        using std::swap;
        swap(first.nume, second.nume);
        swap(first.id, second.id);
        swap(first.tipAb, second.tipAb);
        swap(first.dataActivare, second.dataActivare);
        swap(first.areReducereReactivare, second.areReducereReactivare);
    }
    Client& operator=(Client other) { swap(*this, other); return *this; }

    bool esteExpirat(const std::tm& dataSistem) const {
        std::tm start = dataActivare;
        std::tm acum = dataSistem;
        std::time_t tStart = std::mktime(&start);
        std::time_t tAcum = std::mktime(&acum);
        return (std::difftime(tAcum, tStart) / (24 * 3600)) > 30;
    }
    void reactivare(std::tm dataNoua) {
        std::tm startVechi = dataActivare;
        std::tm acum = dataNoua;
        std::time_t tVechi = std::mktime(&startVechi);
        std::time_t tAcum = std::mktime(&acum);
        double zileDeLaUltimaActivare = std::difftime(tAcum, tVechi) / (24 * 3600);
        if (zileDeLaUltimaActivare > 120) {
            areReducereReactivare = false;
            std::cout << ">>> Reducerea de 10% s-a pierdut (au trecut > 90 zile de la expirare).\n";
        } else {
            areReducereReactivare = true;
            std::cout << ">>> Abonament reactivat cu reducere de 10%.\n";
        }

        dataActivare = dataNoua;
    }
    double calculeazaPretFinal() const {
        double pret = tipAb->calculeazaPretFinal();
        return areReducereReactivare ? pret * 0.9 : pret;
    }
    int getId() const { return id; }
    void afisare(const std::tm& dataSistem) const {
        std::cout << "ID: " << id << " | Nume: " << nume << " | Activare: "
                  << dataActivare.tm_mday << "/" << dataActivare.tm_mon + 1 << "/" << dataActivare.tm_year + 1900
                  << " | ";
        tipAb->afiseazaDetalii();
        std::cout << " | Pret: " << calculeazaPretFinal() << " RON";
        std::cout << (esteExpirat(dataSistem) ? " | [EXPIRAT]" : " | [ACTIV]");
        if (areReducereReactivare) std::cout << " (-10%)";
        std::cout << std::endl;
    }
};
#endif