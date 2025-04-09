#include "Paladines.h"

Paladin::Paladin(int vida, int defensa_fisica, int defensa_magica, int stamina, int nivel){
    this->vida = vida;
    this->defensa_fisica = defensa_fisica;
    this->defensa_magica = defensa_magica;
    this->stamina = stamina;
    this->nivel = nivel;
}

const std::string Paladin::get_subtipo(){return subtipo;}

int Paladin::get_stamina(){return stamina;}

void Paladin::set_stamina(int stamina){this->stamina = stamina;}

void Paladin::golpe_fuerte(){
    std::cout << "Eligio golpe fuerte" << std::endl; 
}

void Paladin::golpe_rapido(){
    std::cout << "Eligio golpe rapido" << std::endl;
}

void Paladin::defensa_golpe(){
    std::cout << "Eligio defensa golpe" << std::endl;
}