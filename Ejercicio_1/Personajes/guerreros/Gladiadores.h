#ifndef GLADIADOR_H
#define GLADIADOR_H

#include "Guerreros.h"

class Gladiador : public Guerreros { 
private:
    const std::string subtipo = "Gladiador"; // Subtipo de Guerrero, siempre es Gladiador.
    const std::string arma_especial = "Garrote"; // Arma especial del Gladiador, siempre es Garrote, haria mas daño con este arma.

public:
    // Constructor
    Gladiador(int vida, int defensa_fisica, int defensa_magica, int stamina, int nivel, std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas);

    // Getters para los atributos.
    const std::string get_subtipo() override;
    const std::string get_arma_especial() override;
};
#endif