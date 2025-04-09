#ifndef MAGOS
#define MAGOS

#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_2/Personajes/personajes.h"
#include <iostream>
#include <string>

class Magos : public Personaje{
protected: 
    const std::string tipo = "Mago";
    int vida;
    int defensa_fisica;
    int defensa_magica;
    int mana;
    int nivel;

public:
    virtual ~Magos() = default; 

    // Getters para los atributos.
    const std::string get_tipo() override;
    int get_vida() override;
    int get_defensa_fisica() override;
    int get_defensa_magica() override;
    int get_nivel() override;

    // Setters para los atributos.
    void set_vida(int vida) override;
    void set_defensa_fisica(int defensa_fisica) override;
    void set_defensa_magica(int defensa_magica) override;
    void set_nivel(int nivel) override;
    
    // Getters Virtuales
    virtual const std::string get_subtipo() = 0;
    virtual int get_mana() = 0;
    virtual void set_mana(int mana) = 0;

    // Movimientos.
    virtual void golpe_fuerte() = 0;
    virtual void golpe_rapido() = 0;
    virtual void defensa_golpe() = 0;


};

#endif