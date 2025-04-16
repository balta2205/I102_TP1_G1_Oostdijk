#include "Bastones.h"

// Constructor.
Baston::Baston(int ataque, int energia, int durabilidad, int nivel, int duracion) :
    Item_mag(ataque, durabilidad, nivel, energia, duracion) {}

// Getters para los atributos.
const std::string Baston::get_subtipo() {return this->subtipo;}
int Baston::get_energia() {return this->energia;}
int Baston::get_duracion() {return this->duracion;}
std::vector<std::string> Baston::get_materiales() {return this->materiales;}

// Ataques.
void Baston::ataque_primario() {std::cout << "El bastón lanza un rayo arcano." << std::endl;}
void Baston::ataque_secundario() {std::cout << "El bastón genera una barrera mágica." << std::endl;}
 