#ifndef MAGOS
#define MAGOS

#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_2/Personajes/personajes.h"
#include <iostream>
#include <string>

class Magos : public Personaje{
protected: 
    const std::string tipo = "Mago";
    int vida;
    int defensa;
    int mana;
    int nivel;

public:
    virtual ~Magos() = default;

    const std::string get_tipo() override;
    int get_vida() override;
    int get_defensa() override;
    int get_nivel() override;

    // Getters Virtuales
    virtual const std::string get_subtipo() = 0;
    virtual int get_mana() = 0;

    // Movimientos.
    virtual void atacar() = 0;
    virtual void descansar() = 0;
};

#endif