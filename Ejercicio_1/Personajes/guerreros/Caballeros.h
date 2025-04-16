#ifndef CABALLERO_H
#define CABALLERO_H

#include "Guerreros.h"

class Caballero : public Guerreros { 
private:
    const std::string subtipo = "Caballero"; // Subtipo de Guerrero, siempre es Caballero. 
    const std::string arma_especial = "Espada"; // Arma especial del Caballero, siempre es Espada, haria mas daño con este arma.

public:
    // Constructor
    Caballero(int vida, int defensa_fisica, int defensa_magica, int stamina, int nivel, std::pair<std::unique_ptr<Arma>, std::unique_ptr<Arma>> armas);

    // Getters para los atributos.
    const std::string get_subtipo() override;
    const std::string get_arma_especial() override;
};
#endif