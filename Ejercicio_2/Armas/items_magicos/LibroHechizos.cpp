#include "LibroHechizos.h"

Libro_Hechizos::Libro_Hechizos(int ataque, int energia, int durabilidad, int nivel){
    this->ataque = ataque;
    this->energia = energia;
    this->durabilidad = durabilidad;
    this->nivel = nivel;
}

const std::string Libro_Hechizos::get_subtipo(){ return subtipo;}

void Libro_Hechizos::ataque_primario(){
    std::cout << "El libro de hechizos lanza un hechizo de ataque!" << std::endl;
}

void Libro_Hechizos::ataque_secundario(){
    std::cout << "El libro de hechizos lanza un hechizo de defensa!" << std::endl;
}