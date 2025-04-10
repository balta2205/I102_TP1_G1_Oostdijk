#include "Magos.h"

Magos::Magos(int vida, int defensa_fisica, int defensa_magica, int mana, int nivel, std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas):
        vida(vida), defensa_fisica(defensa_fisica), defensa_magica(defensa_magica), mana(mana), nivel(nivel), armas(armas) {}

// Getters para los atributos.
const std::string Magos::get_tipo() {return this->tipo;}

int Magos::get_vida() {return this->vida;}
int Magos::get_defensa_fisica() {return this->defensa_fisica;}
int Magos::get_defensa_magica() {return this->defensa_magica;}
int Magos::get_nivel() {return this->nivel;}
std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> Magos::get_armas() {return this->armas;}

// Setters para los atributos.
void Magos::set_vida(int vida) {this->vida = vida;}
void Magos::set_defensa_fisica(int defensa_fisica) {this->defensa_fisica = defensa_fisica;}
void Magos::set_defensa_magica(int defensa_magica) {this->defensa_magica = defensa_magica;}
void Magos::set_nivel(int nivel) {this->nivel = nivel;}



