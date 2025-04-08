#include "Bastones.h"

Baston::Baston(int ataque, int energia, int durabilidad, int nivel){
    this->ataque = ataque;
    this->energia = energia;
    this->durabilidad = durabilidad;
    this->nivel = nivel;
}

const std::string Baston::get_subtipo() {return subtipo;}

void Baston::ataque_primario() {
    std::cout << "El bastón lanza un rayo arcano." << std::endl;
}

void Baston::ataque_secundario() {
    std::cout << "El bastón genera una barrera mágica." << std::endl;
}
