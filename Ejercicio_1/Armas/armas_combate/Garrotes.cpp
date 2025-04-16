#include "Garrotes.h"

// Constructor de la clase Garrote.
Garrote::Garrote(int ataque, int velocidad, int durabilidad, int nivel, int peso, int alcance) :
    Armas_comb(ataque, durabilidad, nivel, velocidad, peso, alcance) {}

// Getters de los atributos.
const std::string Garrote::get_subtipo() {return this->subtipo;}
int Garrote::get_velocidad() {return this->velocidad;}
int Garrote::get_peso() {return this->peso;}
int Garrote::get_alcance() {return this->alcance;}
 
// Ataques.
void Garrote::ataque_primario() {std::cout << "Ataca con la garrote" << std::endl;}
void Garrote::ataque_secundario() {std::cout << "Golpe cargado con la garrote." << std::endl;}