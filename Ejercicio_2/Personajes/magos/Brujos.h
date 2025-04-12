#ifndef BRUJO_H
#define BRUJO_H

#include "Magos.h"

class Brujo : public Magos {
private: 
    const std::string subtipo = "Brujo"; // Subtipo de Mago, siempre es Brujo.
    const std::string arma_especial = "Pocion"; // Arma especial del Brujo, siempre es Pocion, haria mas daño con este arma.
public:
    // Constructor
    Brujo(int vida, int defensa_fisica, int defensa_magica, int mana, int nivel, std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas);

    // Getters para los atributos.
    const std::string get_subtipo() override;
    const std::string get_arma_especial() override;
    int get_mana() override;

    // Setters para los atributos.
    void set_mana(int mana) override;
};
#endif
