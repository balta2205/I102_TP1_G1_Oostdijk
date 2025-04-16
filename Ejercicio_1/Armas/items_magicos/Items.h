#ifndef ITEMS_H
#define ITEMS_H

#include "../armas.h"

class Item_mag : public Arma{
protected:
    const std::string tipo = "Item Magico"; // Tipo de arma.
    int ataque;
    int durabilidad;
    int nivel;
    int energia; // Atributo especifico de los items magicos.
    int duracion; // Atributo especifico de los items magicos.

public:
    Item_mag(int ataque, int durabilidad, int nivel, int energia, int duracion);
    virtual ~Item_mag() = default;

    // Getters.
    const std::string get_tipo() override;
    int get_ataque() override;
    int get_durabilidad() override;
    int get_nivel() override;
    virtual int get_energia() = 0; // Solo las armas tipo item magico tendran este atributo.
    virtual int get_duracion() = 0; // Solo las armas tipo item magico tendran este atributo.
};

#endif