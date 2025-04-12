#include "Armas_comb.h"

// Constructor de la clase Armas_comb.
Armas_comb::Armas_comb(int ataque, int durabilidad, int nivel, int velocidad, int peso, int alcance) {
    this->ataque = ataque;
    this->durabilidad = durabilidad;
    this->nivel = nivel;
    this->velocidad = velocidad;
    this->peso = peso;
    this->alcance = alcance;
}

// Getters de los atributos.
const std::string Armas_comb::get_tipo() {return this->tipo;};
int Armas_comb::get_ataque() {return this->ataque;};
int Armas_comb::get_durabilidad() {return this->durabilidad;};
int Armas_comb::get_nivel() {return this->nivel;};