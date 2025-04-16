#include "Brujos.h" 

// Constructor
Brujo::Brujo(int vida, int defensa_fisica, int defensa_magica, int mana, int nivel, std::pair<std::unique_ptr<Arma>, std::unique_ptr<Arma>> armas): 
    Magos(vida, defensa_fisica, defensa_magica, mana, nivel, std::move(armas)){}

// Getters para los atributos.
const std::string Brujo::get_subtipo(){return this->subtipo;}
const std::string Brujo::get_arma_especial(){return this->arma_especial;}