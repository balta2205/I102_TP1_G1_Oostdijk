#include "Mercenarios.h"

Mercenario::Mercenario(int vida, int defensa_fisica, int defensa_magica, int stamina, int nivel){
    this->vida = vida;
    this->defensa_fisica = defensa_fisica;
    this->defensa_magica = defensa_magica;
    this->stamina = stamina;
    this->nivel = nivel;
}

const std::string Mercenario::get_subtipo(){return subtipo;}

int Mercenario::get_stamina(){return stamina;}

void Mercenario::set_stamina(int stamina){this->stamina = stamina;}

void Mercenario::golpe_fuerte(){
    std::cout << "Eligio golpe fuerte" << std::endl; 
}

void Mercenario::golpe_rapido(){
    std::cout << "Eligio golpe rapido" << std::endl;
}

void Mercenario::defensa_golpe(){
    std::cout << "Eligio defensa golpe" << std::endl;
}