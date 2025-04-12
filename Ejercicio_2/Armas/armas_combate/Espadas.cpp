#include "Espadas.h"

// Constructor de la clase Espada.
Espada::Espada(int ataque, int velocidad, int durabilidad, int nivel, int peso, int alcance) :
Armas_comb(ataque, durabilidad, nivel, velocidad, peso, alcance) {}

// Getters de los atributos.
const std::string Espada::get_subtipo() {return this->subtipo;}
int Espada::get_velocidad() {return this->velocidad;}
int Espada::get_peso() {return this->peso;}
int Espada::get_alcance() {return this->alcance;}

// Ataques.
void Espada::ataque_primario() {std::cout << "Ataca con la espada" << std::endl;}
void Espada::ataque_secundario() {std::cout << "Golpe cargado con la espada." << std::endl;}