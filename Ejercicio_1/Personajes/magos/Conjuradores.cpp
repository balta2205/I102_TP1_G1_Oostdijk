#include "Conjuradores.h"

// Constructor
Conjurador::Conjurador(int vida, int defensa_fisica, int defensa_magica,  int mana, int nivel, std::pair<std::unique_ptr<Arma>, std::unique_ptr<Arma>> armas): 
    Magos(vida, defensa_fisica, defensa_magica, mana, nivel, std::move(armas)){}

// Getters para los atributos.
const std::string Conjurador::get_subtipo(){return this->subtipo;}
const std::string Conjurador::get_arma_especial(){return this->arma_especial;}