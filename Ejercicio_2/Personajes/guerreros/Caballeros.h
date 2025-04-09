#ifndef CABALLERO
#define CABALLERO

#include "Guerreros.h"

class Caballero : public Guerreros { 
private:
    const std::string subtipo = "Caballero";
    const std::string arma_especial = "Espada";

public:
    Caballero(int vida, int defensa_fisica, int defensa_magica, int stamina, int nivel);

    const std::string get_subtipo() override;
    int get_stamina() override;
    void set_stamina(int stamina) override;
    void golpe_fuerte() override;
    void golpe_rapido() override;
    void defensa_golpe() override;
};

#endif