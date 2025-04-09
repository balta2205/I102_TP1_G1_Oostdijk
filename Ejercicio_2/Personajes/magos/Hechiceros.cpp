#include "Hechiceros.h"

Hechicero::Hechicero(int vida, int defensa_fisica, int defensa_magica, int mana, int nivel){
    this->vida = vida;
    this->defensa_fisica = defensa_fisica;
    this->defensa_magica = defensa_magica;
    this->mana = mana;
    this->nivel = nivel;
}

const std::string Hechicero::get_subtipo(){return subtipo;}

int Hechicero::get_mana(){return mana;}

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