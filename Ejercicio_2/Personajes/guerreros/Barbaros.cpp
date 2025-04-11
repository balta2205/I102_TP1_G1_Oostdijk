#include "Barbaros.h"

Barbaro::Barbaro(int vida, int defensa_fisica, int defensa_magica, int stamina, int nivel, std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas)
: Guerreros(vida, defensa_fisica, defensa_magica, stamina, nivel, armas) {}

const std::string Barbaro::get_subtipo(){return this->subtipo;}

int Barbaro::get_stamina(){return this->stamina;}

void Barbaro::set_stamina(int stamina){this->stamina = stamina;}

const std::string Barbaro::get_arma_especial(){return this->arma_especial;}

void Barbaro::golpe_fuerte(){
    std::cout << "Eligio golpe fuerte" << std::endl; 
}

void Barbaro::golpe_rapido(){
    std::cout << "Eligio golpe rapido" << std::endl;
}

void Barbaro::defensa_golpe(){
    std::cout << "Eligio defensa golpe" << std::endl;
}