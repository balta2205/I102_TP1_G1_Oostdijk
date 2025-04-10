#ifndef PERSONAJES
#define PERSONAJES

#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_2/Armas/armas.h"

#include <iostream>
#include <string>
#include <memory>
#include <utility>

#ifndef ARMAS_LISTA
#define ARMAS_LISTA

enum class Armas_lista {null, BASTON, LIBROHECHIZO, POCION, AMULETO, HACHA_S, HACHA_D, ESPADA, LANZA, GARROTE};

#endif // ARMAS_LISTA

class Personaje {
public:
    // Destructor
    virtual ~Personaje() = default;

    // Getters para los atributos.
    virtual const std::string get_tipo() = 0;
    virtual int get_vida() = 0;
    virtual int get_defensa_fisica() = 0;
    virtual int get_defensa_magica() = 0;
    virtual int get_nivel() = 0;
    virtual std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> get_armas() = 0;

    // Setters para los atributos.
    virtual void set_vida(int vida) = 0;
    virtual void set_defensa_fisica(int defensa_fisica) = 0;
    virtual void set_defensa_magica(int defensa_magica) = 0;
    virtual void set_nivel(int nivel) = 0;
    
};

#endif