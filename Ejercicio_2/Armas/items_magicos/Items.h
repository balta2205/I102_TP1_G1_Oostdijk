#ifndef ITEMS
#define ITEMS
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_2/Armas/armas.h"
#include <iostream>
#include <string>

enum class subtipos_magicos {Baston, Libro_hechizo, Pocion, Amuleto};
enum class tipos {Item_mag, Arma_Comb};


class Item_mag : public Arma{
protected:
    const std::string tipo = "Item_mag";
    int ataque;
    int energia;
    int durabilidad;
    int nivel;

public:

    // Destructor.
    virtual ~Item_mag() = default;

    // Getters.
    const std::string get_tipo() override;
    int get_ataque() override;
    int get_energia() override;
    int get_durabilidad() override;
    int get_nivel() override;

    // Getter Virtual para subtipo
    virtual const std::string get_subtipo() = 0;

    // Movimientos.
    virtual void ataque_primario() = 0;
    virtual void ataque_secundario() = 0;
};

#endif