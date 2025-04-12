#include "Amuletos.h"

// Constructor.
Amuletos::Amuletos(int ataque, int energia, int durabilidad, int nivel, int duracion) :
    Item_mag(ataque, durabilidad, nivel, energia, duracion) {}

// Getters para los atributos.
const std::string Amuletos::get_subtipo() {return this->subtipo;}
int Amuletos::get_energia() {return this->energia;}
int Amuletos::get_duracion() {return this->duracion;}
std::vector<std::string> Amuletos::get_materiales() {return this->materiales;}

// Ataques.
void Amuletos::ataque_primario() {std::cout << "Activa el amuleto" << std::endl;}
void Amuletos::ataque_secundario() {std::cout << "Desactiva el amuleto." << std::endl;}