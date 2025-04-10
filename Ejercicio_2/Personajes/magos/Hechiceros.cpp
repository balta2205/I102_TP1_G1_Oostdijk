#include "Hechiceros.h"

Hechicero::Hechicero(int vida, int defensa_fisica, int defensa_magica, int mana, int nivel, std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas): 
    Magos(vida, defensa_fisica, defensa_magica, mana, nivel, armas){}

const std::string Hechicero::get_subtipo(){return this->subtipo;}

int Hechicero::get_mana(){return this->mana;}

void Hechicero::set_mana(int mana) {this->mana = mana;}

void Hechicero::golpe_fuerte(){
    std::cout << "Eligio golpe fuerte" << std::endl; 
}

void Hechicero::golpe_rapido(){
    std::cout << "Eligio golpe rapido" << std::endl;
}

void Hechicero::defensa_golpe(){
    std::cout << "Eligio defensa golpe" << std::endl;
}