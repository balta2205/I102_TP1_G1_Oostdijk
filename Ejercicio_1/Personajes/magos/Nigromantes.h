#ifndef NIGROMANTE_H
#define NIGROMANTE_H

#include "Magos.h"

class Nigromante : public Magos {
private:
    const std::string subtipo = "Nigromante"; // Subtipo de Mago, siempre es Nigromante.
    const std::string arma_especial = "Amuleto"; // Arma especial del Nigromante, siempre es Amuleto, haria mas daño con este arma.

public: 
    // Constructor
    Nigromante(int vida, int defensa_fisica, int defensa_magica, int mana, int nivel, std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas);

    // Getters para los atributos.
    const std::string get_subtipo() override; 
    const std::string get_arma_especial() override;
};
#endif