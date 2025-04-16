#include "Guerreros.h"

// Constructor de la clase Guerreros.
Guerreros::Guerreros(int vida, int defensa_fisica, int defensa_magica, int nivel, int stamina, std::pair<std::unique_ptr<Arma>, std::unique_ptr<Arma>> armas)
    : vida(vida), defensa_fisica(defensa_fisica), defensa_magica(defensa_magica), nivel(nivel), stamina(stamina), armas(std::move(armas)) {}

// Getters para los atributos.
const std::string Guerreros::get_tipo() {return this->tipo;}
int Guerreros::get_vida() {return this->vida;}
int Guerreros::get_defensa_fisica() {return this->defensa_fisica;}
int Guerreros::get_defensa_magica() {return this->defensa_magica;}
int Guerreros::get_nivel() {return this->nivel;}
int Guerreros::get_stamina() {return this->stamina;}
std::pair<Arma*, Arma*> Guerreros::get_armas() {return { armas.first.get(), armas.second.get() };}

// Setters para los atributos.
void Guerreros::set_vida(int vida) {this->vida = vida;}
void Guerreros::set_defensa_fisica(int defensa_fisica) {this->defensa_fisica = defensa_fisica;}
void Guerreros::set_defensa_magica(int defensa_magica) {this->defensa_magica = defensa_magica;}
void Guerreros::set_nivel(int nivel) {this->nivel = nivel;}
void Guerreros::set_stamina(int stamina) {this->stamina = stamina;}

// Movimientos.
void Guerreros::golpe_fuerte() {std::cout << "Eligio golpe fuerte" << std::endl;}
void Guerreros::golpe_rapido() {std::cout << "Eligio golpe rapido" << std::endl;}
void Guerreros::defensa_golpe() {std::cout << "Eligio defensa golpe" << std::endl;}