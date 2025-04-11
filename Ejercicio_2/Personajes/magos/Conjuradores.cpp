#include "Conjuradores.h"

Conjurador::Conjurador(int vida, int defensa_fisica, int defensa_magica,  int mana, int nivel, std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas): 
    Magos(vida, defensa_fisica, defensa_magica, mana, nivel, armas){}

const std::string Conjurador::get_subtipo(){return this->subtipo;}

int Conjurador::get_mana(){return this->mana;}

void Conjurador::set_mana(int mana) {this->mana = mana;}

const std::string Conjurador::get_arma_especial(){return this->arma_especial;}

void Conjurador::golpe_fuerte(){
    std::cout << "Eligio golpe fuerte" << std::endl; 
}

void Conjurador::golpe_rapido(){
    std::cout << "Eligio golpe rapido" << std::endl;
}

void Conjurador::defensa_golpe(){
    std::cout << "Eligio defensa golpe" << std::endl;
}