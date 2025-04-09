#include "Gladiadores.h"

Gladiador::Gladiador(int vida, int defensa_fisica, int defensa_magica, int stamina, int nivel){
    this->vida = vida;
    this->defensa_fisica = defensa_fisica;
    this->defensa_magica = defensa_magica;
    this->stamina = stamina;
    this->nivel = nivel;
}

const std::string Gladiador::get_subtipo(){return subtipo;}

int Gladiador::get_stamina(){return stamina;}

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