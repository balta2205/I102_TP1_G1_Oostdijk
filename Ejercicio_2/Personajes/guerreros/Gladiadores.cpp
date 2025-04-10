#include "Gladiadores.h"

Gladiador::Gladiador(int vida, int defensa_fisica, int defensa_magica, int stamina, int nivel, std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas)
: Guerreros(vida, defensa_fisica, defensa_magica, stamina, nivel, armas) {}

const std::string Gladiador::get_subtipo(){return this->subtipo;}

int Gladiador::get_stamina(){return this->stamina;}

void Gladiador::set_stamina(int stamina){this->stamina = stamina;}

void Gladiador::golpe_fuerte(){
    std::cout << "Eligio golpe fuerte" << std::endl; 
}

void Gladiador::golpe_rapido(){
    std::cout << "Eligio golpe rapido" << std::endl;
}

void Gladiador::defensa_golpe(){
    std::cout << "Eligio defensa golpe" << std::endl;
}