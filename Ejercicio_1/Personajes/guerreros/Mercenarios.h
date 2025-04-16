#ifndef MERCENARIO_H
#define MERCENARIO_H

#include "Guerreros.h"

class Mercenario : public Guerreros { 
private:
    const std::string subtipo = "Mercenario"; // Subtipo de Guerrero, siempre es Mercenario.
    const std::string arma_especial = "Lanza"; //  Arma especial del Mercenario, siempre es Lanza, haria mas daño con este arma.

public:
    // Constructor
    Mercenario(int vida, int defensa_fisica, int defensa_magica, int stamina, int nivel, std::pair<std::unique_ptr<Arma>, std::unique_ptr<Arma>> armas);

    // Getters para los atributos.
    const std::string get_subtipo() override;
    const std::string get_arma_especial() override;
};
#endif