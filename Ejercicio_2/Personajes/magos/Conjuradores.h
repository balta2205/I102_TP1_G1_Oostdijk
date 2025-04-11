#ifndef CONJURADOR_H
#define CONJURADOR_H

#include "Magos.h"

class Conjurador : public Magos {
private:
    const std::string subtipo = "Conjurador";
    const std::string arma_especial = "Libro de Hechizos";

public:
    Conjurador(int vida, int defensa_fisica, int defensa_magica, int mana, int nivel, std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas);

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