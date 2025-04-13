#include "Items.h" 

// Constructor de la clase Item_mag.
Item_mag::Item_mag(int ataque, int durabilidad, int nivel, int energia, int duracion) {
    this->ataque = ataque;
    this->durabilidad = durabilidad;
    this->nivel = nivel;
    this->energia = energia;
    this->duracion = duracion;
}

// Getters de los atributos.
const std::string Item_mag::get_tipo() {return tipo;}
int Item_mag::get_ataque() {return ataque;}
int Item_mag::get_durabilidad() {return durabilidad;}
int Item_mag::get_nivel() {return nivel;}