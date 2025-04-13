#ifndef PERSONAJES
#define PERSONAJES

#include "../Armas/armas.h"
#include "../../utilities.h"

class Personaje {
public:
    // Destructor
    virtual ~Personaje() = default;

    // Getters para los atributos.
    virtual const std::string get_tipo() = 0; // Tipo de personaje (Guerreros o Magos)
    virtual const std::string get_subtipo() = 0; // Subtipo de personaje (Barbaros, Hechiceros, Nigromantes, etc)
    virtual int get_vida() = 0; 
    virtual int get_defensa_fisica() = 0;
    virtual int get_defensa_magica() = 0;
    virtual int get_nivel() = 0;

    virtual std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> get_armas() = 0; // Devuelve un par de armas (arma principal y arma secundaria)
    virtual const std::string get_arma_especial() = 0; // Devuelve el nombre del arma especial, haria mas daño y es especifico a cada subtipo.
    
    // Setters para los atributos.
    virtual void set_vida(int vida) = 0;
    virtual void set_defensa_fisica(int defensa_fisica) = 0;
    virtual void set_defensa_magica(int defensa_magica) = 0;
    virtual void set_nivel(int nivel) = 0; 
    
    // Movimientos.
    virtual void golpe_fuerte() = 0;
    virtual void golpe_rapido() = 0;
    virtual void defensa_golpe() = 0;
};

#endif