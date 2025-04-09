#include "Hachas_D.h"

Hacha_doble::Hacha_doble(int ataque, int velocidad, int durabilidad, int nivel, int peso, int alcance){
    this->ataque = ataque;
    this->velocidad = velocidad;
    this->durabilidad = durabilidad;
    this->nivel = nivel;
    this->peso = peso;
    this->alcance = alcance;
}

const std::string Hacha_doble::get_subtipo() {return subtipo;}

void Hacha_doble::ataque_primario(){
    std::cout << "Ataca con el hacha doble." << std::endl;
}

void Hacha_doble::ataque_secundario(){
    std::cout << "Golpe cargado con el hacha doble." << std::endl;
}