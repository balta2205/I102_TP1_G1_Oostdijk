#include "Guerreros.h"

// Getters para los atributos.
const std::string Guerreros::get_tipo(){return tipo;}
int Guerreros::get_vida(){return vida;}
int Guerreros::get_defensa_fisica(){return defensa_fisica;}
int Guerreros::get_defensa_magica(){return defensa_magica;}
int Guerreros::get_nivel(){return nivel;}

// Setters para los atributos.
void Guerreros::set_vida(int vida){this->vida = vida;}
void Guerreros::set_defensa_fisica(int defensa_fisica){this->defensa_fisica = defensa_fisica;}
void Guerreros::set_defensa_magica(int defensa_magica){this->defensa_magica = defensa_magica;}
void Guerreros::set_nivel(int nivel){this->nivel = nivel;}

