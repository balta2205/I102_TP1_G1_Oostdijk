#include "Conjuradores.h"

Conjurador::Conjurador(int vida, int defensa_fisica, int defensa_magica,  int mana, int nivel){
    this->vida = vida;
    this->defensa_fisica = defensa_fisica;
    this->defensa_magica = defensa_magica;
    this->mana = mana;
    this->nivel = nivel;
}

const std::string Conjurador::get_subtipo(){return subtipo;}

int Conjurador::get_mana(){return mana;}

void Conjurador::set_mana(int mana) {this->mana = mana;}

void Conjurador::golpe_fuerte(){
    std::cout << "Eligio golpe fuerte" << std::endl; 
}

void Conjurador::golpe_rapido(){
    std::cout << "Eligio golpe rapido" << std::endl;
}

void Conjurador::defensa_golpe(){
    std::cout << "Eligio defensa golpe" << std::endl;
}