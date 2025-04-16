#include "Hachas_S.h"

// Constructor de la clase Hacha_simple.
Hacha_simple::Hacha_simple(int ataque, int velocidad, int durabilidad, int nivel, int peso, int alcance) :
    Armas_comb(ataque, durabilidad, nivel, velocidad, peso, alcance) {}

// Getters para los atributos.
const std::string Hacha_simple::get_subtipo() {return this->subtipo;}
int Hacha_simple::get_velocidad() {return this->velocidad;}
int Hacha_simple::get_peso() {return this->peso;}
int Hacha_simple::get_alcance() {return this->alcance;}

// Getters para los atributos especificos de las armas de combate.
void Hacha_simple::ataque_primario() {std::cout << "Ataca con el hacha simple." << std::endl;}
void Hacha_simple::ataque_secundario() {std::cout << "Golpe cargado con el hacha simple." << std::endl;}