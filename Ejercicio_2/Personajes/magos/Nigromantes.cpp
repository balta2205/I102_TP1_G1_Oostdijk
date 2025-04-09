#include "Nigromantes.h"

Nigromante::Nigromante(int vida, int defensa, int mana, int nivel){
    this->vida = vida;
    this->defensa = defensa;
    this->mana = mana;
    this->nivel = nivel;
}

const std::string Nigromante::get_subtipo(){return subtipo;}

int Nigromante::get_mana(){return mana;}

void Nigromante::atacar(){
    std::cout << "Eligio atacar" << std::endl; 
}

void Nigromante::descansar(){
    std::cout << "Eligio descansar" << std::endl;
}