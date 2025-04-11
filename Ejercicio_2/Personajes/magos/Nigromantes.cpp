#include "Nigromantes.h"

Nigromante::Nigromante(int vida, int defensa_fisica, int defensa_magica, int mana, int nivel, std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas): 
    Magos(vida, defensa_fisica, defensa_magica, mana, nivel, armas){}

const std::string Nigromante::get_subtipo(){return this->subtipo;}

int Nigromante::get_mana(){return this->mana;}

void Nigromante::set_mana(int mana) {this->mana = mana;}

const std::string Nigromante::get_arma_especial(){return this->arma_especial;}

void Nigromante::golpe_fuerte(){
    std::cout << "Eligio golpe fuerte" << std::endl; 
}

void Nigromante::golpe_rapido(){
    std::cout << "Eligio golpe rapido" << std::endl;
}

void Nigromante::defensa_golpe(){
    std::cout << "Eligio defensa golpe" << std::endl;
}