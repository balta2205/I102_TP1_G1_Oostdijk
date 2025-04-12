#ifndef ARMAS
#define ARMAS

#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/utilities.h"

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

    // Movimientos.
    virtual void ataque_primario() = 0;
    virtual void ataque_secundario() = 0;
};

#endif