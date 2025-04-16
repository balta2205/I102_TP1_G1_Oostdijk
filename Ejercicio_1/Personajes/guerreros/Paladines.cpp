#include "Paladines.h"

// Constructor
Paladin::Paladin(int vida, int defensa_fisica, int defensa_magica, int stamina, int nivel, std::pair<std::unique_ptr<Arma>, std::unique_ptr<Arma>> armas)
    : Guerreros(vida, defensa_fisica, defensa_magica, stamina, nivel, std::move(armas)) {}

// Getters para los atributos.
const std::string Paladin::get_subtipo() {return this->subtipo;}
const std::string Paladin::get_arma_especial() {return this->arma_especial;}