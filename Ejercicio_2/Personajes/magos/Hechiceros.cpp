#include "Hechiceros.h"

Hechicero::Hechicero(int vida, int defensa, int mana, int nivel){
    this->vida = vida;
    this->defensa = defensa;
    this->mana = mana;
    this->nivel = nivel;
}

const std::string Hechicero::get_subtipo(){return subtipo;}

int Hechicero::get_mana(){return mana;}

void Hechicero::atacar(){
    std::cout << "Eligio atacar" << std::endl; 
}

void Hechicero::descansar(){
    std::cout << "Eligio descansar" << std::endl;
}