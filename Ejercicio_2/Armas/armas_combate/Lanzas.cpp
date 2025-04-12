#include "Lanzas.h"

// Constructor de la clase Lanza
Lanza::Lanza(int ataque, int velocidad, int durabilidad, int nivel, int peso, int alcance) :
    Armas_comb(ataque, durabilidad, nivel, velocidad, peso, alcance) {}

// Getters para los atributos.
const std::string Lanza::get_subtipo() {return this->subtipo;}
int Lanza::get_velocidad() {return this->velocidad;}
int Lanza::get_peso() {return this->peso;}
int Lanza::get_alcance() {return this->alcance;}

// Ataques.
void Lanza::ataque_primario() {std::cout << "Ataca con la lanza" << std::endl;}
void Lanza::ataque_secundario() {std::cout << "Golpe cargado con la lanza." << std::endl;}