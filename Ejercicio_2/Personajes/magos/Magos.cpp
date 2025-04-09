#include "Magos.h"

// Getters para los atributos.
const std::string Magos::get_tipo() {return tipo;}

int Magos::get_vida() {return vida;}
int Magos::get_defensa_fisica() {return defensa_fisica;}
int Magos::get_defensa_magica() {return defensa_magica;}
int Magos::get_nivel() {return nivel;}

// Setters para los atributos.
void Magos::set_vida(int vida) {this->vida = vida;}
void Magos::set_defensa_fisica(int defensa_fisica) {this->defensa_fisica = defensa_fisica;}
void Magos::set_defensa_magica(int defensa_magica) {this->defensa_magica = defensa_magica;}
void Magos::set_nivel(int nivel) {this->nivel = nivel;}



