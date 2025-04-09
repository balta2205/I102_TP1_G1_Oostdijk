#include "Brujos.h" 

Brujo::Brujo(int vida, int defensa, int mana, int nivel){
    this->vida = vida;
    this->defensa = defensa;
    this->mana = mana;
    this->nivel = nivel;
}

const std::string Brujo::get_subtipo(){return subtipo;}

int Brujo::get_mana(){return mana;}

void Brujo::atacar(){
    std::cout << "Eligio atacar" << std::endl; 
}

void Brujo::descansar(){
    std::cout << "Eligio descansar" << std::endl;
}