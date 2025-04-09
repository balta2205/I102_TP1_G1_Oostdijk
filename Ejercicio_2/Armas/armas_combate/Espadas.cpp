#include "Espadas.h"

Espada::Espada(int ataque, int velocidad, int durabilidad, int nivel, int peso, int alcance){
    this->ataque = ataque;
    this->velocidad = velocidad;
    this->durabilidad = durabilidad;
    this->nivel = nivel;
    this->peso = peso;
    this->alcance = alcance;
}

const std::string Espada::get_subtipo() {return subtipo;}

void Espada::ataque_primario(){
    std::cout << "Ataca con la espada" << std::endl;
}

void Espada::ataque_secundario(){
    std::cout << "Golpe cargado con la espada." << std::endl;
}