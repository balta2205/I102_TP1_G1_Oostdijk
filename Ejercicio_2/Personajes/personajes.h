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
    virtual int get_defensa() = 0;
    virtual int get_nivel() = 0;
    
};

#endif