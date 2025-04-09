#include "Nigromantes.h"

Nigromante::Nigromante(int vida, int defensa_fisica, int defensa_magica, int mana, int nivel){
    this->vida = vida;
    this->defensa_fisica = defensa_fisica;
    this->defensa_magica = defensa_magica;
    this->mana = mana;
    this->nivel = nivel;
}

const std::string Nigromante::get_subtipo(){return subtipo;}

int Nigromante::get_mana(){return mana;}

void Nigromante::set_mana(int mana) {this->mana = mana;}

void Nigromante::golpe_fuerte(){
    std::cout << "Eligio golpe fuerte" << std::endl; 
}

void Nigromante::golpe_rapido(){
    std::cout << "Eligio golpe rapido" << std::endl;
}

void Nigromante::defensa_golpe(){
    std::cout << "Eligio defensa golpe" << std::endl;
}