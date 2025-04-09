#ifndef HECHICERO
#define HECHICERO

#include "Magos.h"

class Hechicero : public Magos {
private:
    const std::string subtipo = "Hechicero";
    const std::string arma_especial = "Baston";

public: 
    Hechicero(int vida, int defensa, int mana, int nivel);

    const std::string get_subtipo() override;
    int get_mana() override;
    void atacar() override;
    void descansar() override;
};

#endif