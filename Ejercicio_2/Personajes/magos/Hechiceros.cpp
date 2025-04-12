#include "Hechiceros.h"

// Constructor
Hechicero::Hechicero(int vida, int defensa_fisica, int defensa_magica, int mana, int nivel, std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas): 
    Magos(vida, defensa_fisica, defensa_magica, mana, nivel, armas){}

// Getters para los atributos.
const std::string Hechicero::get_subtipo(){return this->subtipo;}
const std::string Hechicero::get_arma_especial(){return this->arma_especial;}
int Hechicero::get_mana(){return this->mana;}

// Setters para los atributos.
void Hechicero::set_mana(int mana) {this->mana = mana;}