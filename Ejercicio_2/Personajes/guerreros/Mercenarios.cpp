#include "Mercenarios.h"

Mercenario::Mercenario(int vida, int defensa_fisica, int defensa_magica, int stamina, int nivel, std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas)
: Guerreros(vida, defensa_fisica, defensa_magica, stamina, nivel, armas) {}

const std::string Mercenario::get_subtipo(){return this->subtipo;}

int Mercenario::get_stamina(){return this->stamina;}

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