#ifndef HECHICERO_H
#define HECHICERO_H

#include "Magos.h"

class Hechicero : public Magos {
private:
    const std::string subtipo = "Hechicero"; // Subtipo de Mago, siempre es Hechicero.
    const std::string arma_especial = "Baston"; // Arma especial del Hechicero, siempre es Baston, haria mas daño con este arma.

public: 
    // Constructor
    Hechicero(int vida, int defensa_fisica, int defensa_magica, int mana, int nivel, std::pair<std::unique_ptr<Arma>, std::unique_ptr<Arma>> armas);

    // Getters para los atributos.
    const std::string get_subtipo() override;
    const std::string get_arma_especial() override;
};
#endif