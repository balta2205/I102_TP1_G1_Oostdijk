#ifndef HACHA_D_H
#define HACHA_D_H

#include "Armas_comb.h"

class Hacha_doble : public Armas_comb{
private: 
    const std::string subtipo = "Hacha doble"; // Subtipo de arma.
    
public:
    // Constructor
    Hacha_doble(int ataque, int velocidad, int durabilidad, int nivel, int peso, int alcance);

    // Getters para los atributos.
    const std::string get_subtipo() override;
    int get_velocidad() override;
    int get_peso() override;
    int get_alcance() override;

    // Ataques.
    void ataque_primario() override;
    void ataque_secundario() override;
};

#endif