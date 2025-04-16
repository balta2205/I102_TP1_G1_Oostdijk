#include "LibroHechizos.h"

// Constructor.
Libro_Hechizos::Libro_Hechizos(int ataque, int energia, int durabilidad, int nivel, int duracion) :
    Item_mag(ataque, durabilidad, nivel, energia, duracion){} 
 
// Getters para los atributos.
const std::string Libro_Hechizos::get_subtipo() {return this->subtipo;}
int Libro_Hechizos::get_energia() {return this->energia;}
int Libro_Hechizos::get_duracion() {return this->duracion;}
std::vector<std::string> Libro_Hechizos::get_hechizos() {return this->hechizos;}

// Ataques.
void Libro_Hechizos::ataque_primario() {std::cout << "El libro de hechizos lanza un hechizo de ataque!" << std::endl;}
void Libro_Hechizos::ataque_secundario(){std::cout << "El libro de hechizos lanza un hechizo de defensa!" << std::endl;}