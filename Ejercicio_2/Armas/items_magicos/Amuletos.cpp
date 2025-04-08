#include "Amuletos.h"

Amuletos::Amuletos(int ataque, int energia, int durabilidad, int nivel){
    this->ataque = ataque;
    this->energia = energia;
    this->durabilidad = durabilidad;
    this->nivel = nivel;
}

const std::string Amuletos::get_subtipo(){ return subtipo;}

void Amuletos::ataque_primario(){
    std::cout << "Activa el amuleto" << std::endl;
}

void Amuletos::ataque_secundario(){
    std::cout << "Desactiva el amuleto." << std::endl;
}