#include "Caballeros.h"

Caballero::Caballero(int vida, int defensa_fisica, int defensa_magica, int stamina, int nivel, std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas)
: Guerreros(vida, defensa_fisica, defensa_magica, stamina, nivel, armas) {}

const std::string Caballero::get_subtipo(){return this->subtipo;}

int Caballero::get_stamina(){return this->stamina;}

void Caballero::set_stamina(int stamina){this->stamina = stamina;}

const std::string Caballero::get_arma_especial(){return this->arma_especial;}

void Caballero::golpe_fuerte(){
    std::cout << "Eligio golpe fuerte" << std::endl; 
}

void Caballero::golpe_rapido(){
    std::cout << "Eligio golpe rapido" << std::endl;
}

void Caballero::defensa_golpe(){
    std::cout << "Eligio defensa golpe" << std::endl;
}