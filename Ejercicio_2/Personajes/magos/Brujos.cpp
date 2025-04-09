#include "Brujos.h" 

Brujo::Brujo(int vida, int defensa_fisica, int defensa_magica, int mana, int nivel){
    this->vida = vida;
    this->defensa_fisica = defensa_fisica;
    this->defensa_magica = defensa_magica;
    this->mana = mana;
    this->nivel = nivel;
}

const std::string Brujo::get_subtipo(){return subtipo;}

int Brujo::get_mana(){return mana;}

void Brujo::set_mana(int mana) {this->mana = mana;}

void Brujo::golpe_fuerte(){
    std::cout << "Eligio golpe fuerte" << std::endl; 
}

void Brujo::golpe_rapido(){
    std::cout << "Eligio golpe rapido" << std::endl;
}

void Brujo::defensa_golpe(){
    std::cout << "Eligio defensa golpe" << std::endl;
}