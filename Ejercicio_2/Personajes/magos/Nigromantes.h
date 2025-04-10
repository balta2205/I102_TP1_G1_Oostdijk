#ifndef NIGROMANTE_H
#define NIGROMANTE_H

#include "Magos.h"

class Nigromante : public Magos {
private:
    const std::string subtipo = "Nigromante";
    const std::string arma_especial = "Amuleto";

public: 
    Nigromante(int vida, int defensa_fisica, int defensa_magica, int mana, int nivel, std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas);

    const std::string get_subtipo() override;
    int get_mana() override;
    void set_mana(int mana) override;
    void golpe_fuerte() override;
    void golpe_rapido() override;
    void defensa_golpe() override;
};

#endif