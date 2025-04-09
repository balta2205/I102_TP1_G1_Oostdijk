#include "Caballeros.h"

Caballero::Caballero(int vida, int defensa_fisica, int defensa_magica, int stamina, int nivel){
    this->vida = vida;
    this->defensa_fisica = defensa_fisica;
    this->defensa_magica = defensa_magica;
    this->stamina = stamina;
    this->nivel = nivel;
}

const std::string Caballero::get_subtipo(){return subtipo;}

int Caballero::get_stamina(){return stamina;}

void Caballero::set_stamina(int stamina){this->stamina = stamina;}

void Caballero::golpe_fuerte(){
    std::cout << "Eligio golpe fuerte" << std::endl; 
}

void Caballero::golpe_rapido(){
    std::cout << "Eligio golpe rapido" << std::endl;
}

void Caballero::defensa_golpe(){
    std::cout << "Eligio defensa golpe" << std::endl;
}