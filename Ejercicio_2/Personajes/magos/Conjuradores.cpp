#include "Conjuradores.h"

const std::string Conjurador::get_subtipo(){return subtipo;}

int Conjurador::get_mana(){return mana;}

void Conjurador::atacar(){
    std::cout << "Eligio atacar" << std::endl; 
}

void Conjurador::descansar(){
    std::cout << "Eligio descansar" << std::endl;
}