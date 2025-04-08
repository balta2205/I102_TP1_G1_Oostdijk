#include "Pociones.h"

Pociones::Pociones(int ataque, int energia, int durabilidad, int nivel){
    this->ataque = ataque;
    this->energia = energia;
    this->durabilidad = durabilidad;
    this->nivel = nivel;
}

const std::string Pociones::get_subtipo(){ return subtipo;}

void Pociones::ataque_primario(){
    std::cout << "Se toma una pocion de defensa." << std::endl;
}

void Pociones::ataque_secundario(){
    std::cout << "Arroja una pocion de ataque." << std::endl;
}