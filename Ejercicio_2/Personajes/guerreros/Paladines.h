#ifndef PALADIN_H
#define PALADIN_H

#include "Guerreros.h"

class Paladin : public Guerreros {
private:
    const std::string subtipo = "Paladin";
    const std::string arma_especial = "Hacha Doble";

public:
    Paladin(int vida, int defensa_fisica, int defensa_magica, int stamina, int nivel, std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas);

    const std::string get_subtipo() override;
    int get_stamina() override;
    void set_stamina(int stamina) override;
    int get_mana() override{ return 0; }
    void golpe_fuerte() override;
    void golpe_rapido() override;
    void defensa_golpe() override;
    const std::string get_arma_especial() override;
};

#endif
