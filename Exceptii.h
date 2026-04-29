#ifndef EXCEPTII_H
#define EXCEPTII_H
#include <exception>
#include <string>

class GymException : public std::exception {
    std::string mesaj;
public:
    GymException(std::string m) : mesaj(m) {}
    const char* what() const noexcept override { return mesaj.c_str(); }
};

class DataInvalidaException : public GymException { public: DataInvalidaException() : GymException("Data invalida!") {} };
class DataNesetataException : public GymException { public: DataNesetataException() : GymException("Seteaza data actuala!") {} };
class IdInexistentException : public GymException { public: IdInexistentException() : GymException("ID inexistent!") {} };
#endif