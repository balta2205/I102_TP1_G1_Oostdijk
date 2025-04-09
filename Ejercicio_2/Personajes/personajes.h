#ifndef PERSONAJES
#define PERSONAJES

#include <iostream>
#include <string>

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

    // Setters para los atributos.
    virtual void set_vida(int vida) = 0;
    virtual void set_defensa_fisica(int defensa_fisica) = 0;
    virtual void set_defensa_magica(int defensa_magica) = 0;
    virtual void set_nivel(int nivel) = 0;
    
};

#endif