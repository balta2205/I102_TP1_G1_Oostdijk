#ifndef ARMAS
#define ARMAS

#include <iostream>
#include <string>

class Arma {
public:
    // Destructor
    virtual ~Arma() = default;

    // Getters para los atributos.
    virtual const std::string get_tipo() = 0;
    virtual const std::string get_subtipo() = 0;
    virtual int get_ataque() = 0;
    virtual int get_durabilidad() = 0;
    virtual int get_nivel() = 0;
};

#endif