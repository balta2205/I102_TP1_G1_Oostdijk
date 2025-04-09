#ifndef PALADIN
#define PALADIN

#include "Guerreros.h"

class Paladin : public Guerreros {
private:
    const std::string subtipo = "Paladin";
    const std::string arma_especial = "Hacha Doble";

public:
    Paladin(int vida, int defensa_fisica, int defensa_magica, int stamina, int nivel);

    const std::string get_subtipo() override;
    int get_stamina() override;
    void set_stamina(int stamina) override;
    void golpe_fuerte() override;
    void golpe_rapido() override;
    void defensa_golpe() override;
};

#endif
