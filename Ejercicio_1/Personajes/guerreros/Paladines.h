#ifndef PALADIN_H
#define PALADIN_H

#include "Guerreros.h"

class Paladin : public Guerreros {
private:
    const std::string subtipo = "Paladin"; // Subtipo de Guerrero, siempre es Paladin.
    const std::string arma_especial = "Hacha Doble"; // Arma especial del Paladin, siempre es Hacha Doble, haria mas daño con este arma.

public:
    // Constructor
    Paladin(int vida, int defensa_fisica, int defensa_magica, int stamina, int nivel, std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas);

    // Getters para los atributos.
    const std::string get_subtipo() override;
    const std::string get_arma_especial() override;
};
#endif
