#ifndef POCION
#define POCION

#include "Items.h"
#include <vector>

class Pociones : public Item_mag{
private:
    const std::string subtipo = "Pocion";
    const std::vector<std::string> Mezclas = {"Resistencia al Fuego", "Fuerza", "Debilidad", "Fatiga"};

public:
    // Constructor.
    Pociones(int ataque, int energia, int durabilidad, int nivel);

    const std::string get_subtipo() override;
    void ataque_primario() override;
    void ataque_secundario() override;
};

#endif