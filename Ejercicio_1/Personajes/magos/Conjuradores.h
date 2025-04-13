#ifndef CONJURADOR_H
#define CONJURADOR_H

#include "Magos.h"

class Conjurador : public Magos {
private:
    const std::string subtipo = "Conjurador"; // Subtipo de Mago, siempre es Conjurador.
    const std::string arma_especial = "Libro de Hechizos"; // Arma especial del Conjurador, siempre es Libro de Hechizos, haria mas daño con este arma.

public:
    // Constructor
    Conjurador(int vida, int defensa_fisica, int defensa_magica, int mana, int nivel, std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas);

    // Getters para los atributos.
    const std::string get_subtipo() override;
    const std::string get_arma_especial() override;
};
#endif