#ifndef BARBARO_H
#define BARBARO_H

#include "Guerreros.h"

class Barbaro : public Guerreros { 
private:
    const std::string subtipo = "Barbaro";
    const std::string arma_especial = "Hacha Simple";

public:
    Barbaro(int vida, int defensa_fisica, int defensa_magica, int stamina, int nivel, std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas);

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