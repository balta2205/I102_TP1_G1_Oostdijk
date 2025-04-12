#include "Mercenarios.h"

// Constructor
Mercenario::Mercenario(int vida, int defensa_fisica, int defensa_magica, int stamina, int nivel, std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas)
: Guerreros(vida, defensa_fisica, defensa_magica, stamina, nivel, armas) {}

// Getters para los atributos.
const std::string Mercenario::get_subtipo() {return this->subtipo;}
const std::string Mercenario::get_arma_especial() {return this->arma_especial;}
int Mercenario::get_stamina() {return this->stamina;}

// Setters para los atributos.
void Mercenario::set_stamina(int stamina) {this->stamina = stamina;}