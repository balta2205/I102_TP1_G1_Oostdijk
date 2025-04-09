#ifndef ARMAS_COMB
#define ARMAS_COMB
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_2/Armas/armas.h"
#include <iostream>
#include <string>

class Armas_comb : public Arma {
protected:
    const std::string tipo = "Armas de Combate";
    int ataque;
    int velocidad;
    int durabilidad;
    int nivel;
    int peso;
    int alcance;

public:
    virtual ~Armas_comb() = default;
    
    // Getters.
    const std::string get_tipo() override;
    int get_ataque() override;
    int get_velocidad();
    int get_durabilidad() override;
    int get_nivel() override;
    int get_peso();
    int get_alcance();

    // Getter Virtual para subtipo
    virtual const std::string get_subtipo() = 0;

    // Movimientos.
    virtual void ataque_primario() = 0;
    virtual void ataque_secundario() = 0;
};

#endif