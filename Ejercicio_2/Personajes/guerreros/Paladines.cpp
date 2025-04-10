#include "Paladines.h"

Paladin::Paladin(int vida, int defensa_fisica, int defensa_magica, int stamina, int nivel, std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas)
    : Guerreros(vida, defensa_fisica, defensa_magica, stamina, nivel, armas) {}

const std::string Paladin::get_subtipo(){return this->subtipo;}

int Paladin::get_stamina(){return this->stamina;}

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