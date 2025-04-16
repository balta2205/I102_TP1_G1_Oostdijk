#ifndef POCION_H
#define POCION_H

#include "Items.h"

class Pociones : public Item_mag{
private:
    const std::string subtipo = "Pocion"; // Subtipo de arma.
    const std::vector<std::string> Mezclas = {"Resistencia al Fuego", "Fuerza", "Debilidad", "Fatiga"}; // Mezclas de pociones.

public:
    // Constructor.
    Pociones(int ataque, int energia, int durabilidad, int nivel, int duracion);

    // Getters para los atributos.
    const std::string get_subtipo() override;
    int get_energia() override;
    int get_duracion() override;
    std::vector<std::string> get_mezclas();

    // Ataques.
    void ataque_primario() override;
    void ataque_secundario() override;
};

#endif