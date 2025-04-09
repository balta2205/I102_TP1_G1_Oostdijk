#include "Garrotes.h"

Garrote::Garrote(int ataque, int velocidad, int durabilidad, int nivel, int peso, int alcance){
    this->ataque = ataque;
    this->velocidad = velocidad;
    this->durabilidad = durabilidad;
    this->nivel = nivel;
    this->peso = peso;
    this->alcance = alcance;
}

const std::string Garrote::get_subtipo() {return subtipo;}

void Garrote::ataque_primario(){
    std::cout << "Ataca con la garrote" << std::endl;
}

void Garrote::ataque_secundario(){
    std::cout << "Golpe cargado con la garrote." << std::endl;
}