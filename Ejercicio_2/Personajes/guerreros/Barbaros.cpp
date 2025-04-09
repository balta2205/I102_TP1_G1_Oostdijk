#include "Barbaros.h"

Barbaro::Barbaro(int vida, int defensa_fisica, int defensa_magica, int stamina, int nivel){
    this->vida = vida;
    this->defensa_fisica = defensa_fisica;
    this->defensa_magica = defensa_magica;
    this->stamina = stamina;
    this->nivel = nivel;
}

const std::string Barbaro::get_subtipo(){return subtipo;}

int Barbaro::get_stamina(){return stamina;}

void Barbaro::set_stamina(int stamina){this->stamina = stamina;}

void Barbaro::golpe_fuerte(){
    std::cout << "Eligio golpe fuerte" << std::endl; 
}

void Barbaro::golpe_rapido(){
    std::cout << "Eligio golpe rapido" << std::endl;
}

void Barbaro::defensa_golpe(){
    std::cout << "Eligio defensa golpe" << std::endl;
}