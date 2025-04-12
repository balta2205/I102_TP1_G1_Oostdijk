#include "Pociones.h"

// Constructor.
Pociones::Pociones(int ataque, int energia, int durabilidad, int nivel, int duracion) :
    Item_mag(ataque, durabilidad, nivel, energia, duracion){} 

// Getters para los atributos.
const std::string Pociones::get_subtipo() {return this->subtipo;}
int Pociones::get_energia() {return this->energia;}
int Pociones::get_duracion() {return this->duracion;}
std::vector<std::string> Pociones::get_mezclas() {return this->Mezclas;}

// Ataques.
void Pociones::ataque_primario() {std::cout << "Se toma una pocion de defensa." << std::endl;}
void Pociones::ataque_secundario() {std::cout << "Arroja una pocion de ataque." << std::endl;}