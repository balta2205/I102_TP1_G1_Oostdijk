#ifndef BARBARO_H
#define BARBARO_H

#include "Guerreros.h"

class Barbaro : public Guerreros { 
private:
    const std::string subtipo = "Barbaro"; // Subtipo de Guerrero, siempre es Barbaro.
    const std::string arma_especial = "Hacha Simple"; // Arma especial del Barbaro, siempre es Hacha Simple, haria mas daño con este arma.

public:
    // Constructor
    Barbaro(int vida, int defensa_fisica, int defensa_magica, int stamina, int nivel, std::pair<std::unique_ptr<Arma>, std::unique_ptr<Arma>> armas);

    // Getters para los atributos.
    const std::string get_subtipo() override;
    const std::string get_arma_especial() override;
};
#endif