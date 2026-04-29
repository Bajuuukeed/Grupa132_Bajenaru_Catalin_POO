#ifndef ABONAMENT_H
#define ABONAMENT_H
#include <iostream>
#include <memory>
class Abonament {
protected:
    double pretBaza;
public:
    Abonament(double p) : pretBaza(p) {}
    virtual ~Abonament() = default;
    virtual double calculeazaPretFinal() const = 0;
    virtual void afiseazaDetalii() const = 0;
    virtual std::unique_ptr<Abonament> clone() const = 0;
};
class Spartan : public Abonament {
public:
    Spartan() : Abonament(150.0) {}
    double calculeazaPretFinal() const override { return pretBaza; }
    void afiseazaDetalii() const override { std::cout << "Spartan"; }
    std::unique_ptr<Abonament> clone() const override { return std::make_unique<Spartan>(*this); }
};

class SpartanPlatinum : public Abonament {
public:
    SpartanPlatinum() : Abonament(220.0) {}
    double calculeazaPretFinal() const override { return pretBaza * 0.9; }
    void afiseazaDetalii() const override { std::cout << "Platinum"; }
    std::unique_ptr<Abonament> clone() const override { return std::make_unique<SpartanPlatinum>(*this); }
};

class Luptator : public Abonament {
public:
    Luptator() : Abonament(100.0) {}
    double calculeazaPretFinal() const override { return pretBaza; }
    void afiseazaDetalii() const override { std::cout << "Luptator"; }
    std::unique_ptr<Abonament> clone() const override { return std::make_unique<Luptator>(*this); }
};
#endif