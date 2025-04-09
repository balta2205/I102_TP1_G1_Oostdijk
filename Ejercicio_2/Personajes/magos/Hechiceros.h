#ifndef HECHICERO
#define HECHICERO

#include "Magos.h"

class Hechicero : public Magos {
private:
    const std::string subtipo = "Hechicero";
    const std::string arma_especial = "Baston";

public: 
    Hechicero(int vida, int defensa_fisica, int defensa_magica, int mana, int nivel);

    const std::string get_subtipo() override;
    int get_mana() override;
    void set_mana(int mana) override;
    void golpe_fuerte() override;
    void golpe_rapido() override;
    void defensa_golpe() override;
};

#endif