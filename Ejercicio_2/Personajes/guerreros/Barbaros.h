#ifndef BARBARO
#define BARBARO

#include "Guerreros.h"

class Barbaro : public Guerreros { 
private:
    const std::string subtipo = "Barbaro";
    const std::string arma_especial = "Hacha Simple";

public:
    Barbaro(int vida, int defensa_fisica, int defensa_magica, int stamina, int nivel);

    const std::string get_subtipo() override;
    int get_stamina() override;
    void set_stamina(int stamina) override;
    void golpe_fuerte() override;
    void golpe_rapido() override;
    void defensa_golpe() override;
};

#endif