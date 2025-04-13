#ifndef BASTON_H
#define BASTON_H

#include "Items.h"

class Baston : public Item_mag {
private: 
    const std::string subtipo = "Baston"; // Subtipo de arma.
    const std::vector<std::string> materiales = {"Roble", "Cerezo", "Abeto", "Nogal"}; // Materiales de baston.

public: 
    // Constructor
    Baston(int ataque, int energia, int durabilidad, int nivel, int duracion);

    // Getters para los atributos.
    const std::string get_subtipo() override;
    int get_energia() override;
    int get_duracion() override;
    std::vector<std::string> get_materiales();

    // Ataques.
    void ataque_primario() override;
    void ataque_secundario() override;
};
#endif