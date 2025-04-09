#include "Hachas_S.h"

Hacha_simple::Hacha_simple(int ataque, int velocidad, int durabilidad, int nivel, int peso, int alcance){
    this->ataque = ataque;
    this->velocidad = velocidad;
    this->durabilidad = durabilidad;
    this->nivel = nivel;
    this->peso = peso;
    this->alcance = alcance;
}

const std::string Hacha_simple::get_subtipo() {return subtipo;}

void Hacha_simple::ataque_primario(){
    std::cout << "Ataca con el hacha simple." << std::endl;
}

void Hacha_simple::ataque_secundario(){
    std::cout << "Golpe cargado con el hacha simple." << std::endl;
}