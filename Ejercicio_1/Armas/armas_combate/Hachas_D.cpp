#include "Hachas_D.h"

// Constructor de la clase Hacha_doble.
Hacha_doble::Hacha_doble(int ataque, int velocidad, int durabilidad, int nivel, int peso, int alcance) :
    Armas_comb(ataque, durabilidad, nivel, velocidad, peso, alcance) {}
 
// Getters de los atributos.
const std::string Hacha_doble::get_subtipo() {return this->subtipo;}
int Hacha_doble::get_velocidad() {return this->velocidad;}
int Hacha_doble::get_peso() {return this->peso;}
int Hacha_doble::get_alcance() {return this->alcance;}

// Ataques.
void Hacha_doble::ataque_primario() {std::cout << "Ataca con el hacha doble." << std::endl;}
void Hacha_doble::ataque_secundario() {std::cout << "Golpe cargado con el hacha doble." << std::endl;}