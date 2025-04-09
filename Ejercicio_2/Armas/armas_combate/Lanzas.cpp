#include "Lanzas.h"

Lanza::Lanza(int ataque, int velocidad, int durabilidad, int nivel, int peso, int alcance){
    this->ataque = ataque;
    this->velocidad = velocidad;
    this->durabilidad = durabilidad;
    this->nivel = nivel;
    this->peso = peso;
    this->alcance = alcance;
}

const std::string Lanza::get_subtipo() {return subtipo;}

void Lanza::ataque_primario(){
    std::cout << "Ataca con la lanza" << std::endl;
}

void Lanza::ataque_secundario(){
    std::cout << "Golpe cargado con la lanza." << std::endl;
}