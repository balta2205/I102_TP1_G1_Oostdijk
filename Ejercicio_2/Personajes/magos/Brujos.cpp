#include "Brujos.h" 

Brujo::Brujo(int vida, int defensa_fisica, int defensa_magica, int mana, int nivel, std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas): 
    Magos(vida, defensa_fisica, defensa_magica, mana, nivel, armas){}

const std::string Brujo::get_subtipo(){return this->subtipo;}

int Brujo::get_mana(){return this->mana;}

void Brujo::set_mana(int mana) {this->mana = mana;}

const std::string Brujo::get_arma_especial(){return this->arma_especial;}

void Brujo::golpe_fuerte(){
    std::cout << "Eligio golpe fuerte" << std::endl; 
}

void Brujo::golpe_rapido(){
    std::cout << "Eligio golpe rapido" << std::endl;
}

void Brujo::defensa_golpe(){
    std::cout << "Eligio defensa golpe" << std::endl;
}