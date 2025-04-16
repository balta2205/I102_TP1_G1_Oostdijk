#ifndef AMULETO_H
#define AMULETO_H

#include "Items.h"

class Amuletos : public Item_mag{
private: 
    const std::string subtipo = "Amuleto"; // Subtipo de arma.
    const std::vector<std::string> materiales = {"Oro", "Plata", "Bronce", "Hierro"}; // Materiales de amuletos.

public: 
    // Constructor.
    Amuletos(int ataque, int energia, int durabilidad, int nivel, int duracion);

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