#ifndef BRUJO_H
#define BRUJO_H

#include "Magos.h"

class Brujo : public Magos {
private: 
    const std::string subtipo = "Brujo";
    const std::string arma_especial = "Pocion";
public:
    Brujo(int vida, int defensa_fisica, int defensa_magica, int mana, int nivel, std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas);

    const std::string get_subtipo() override;
    int get_mana() override;
    void set_mana(int mana) override;
    int get_stamina() override { return 0; }
    void golpe_fuerte() override;
    void golpe_rapido() override;
    void defensa_golpe() override;
    const std::string get_arma_especial() override;

};

#endif
