#ifndef BRUJO
#define BRUJO

#include "Magos.h"

class Brujo : public Magos {
private: 
    const std::string subtipo = "Brujo";
    const std::string arma_especial = "Pocion";
public:
    Brujo(int vida, int defensa, int mana, int nivel);

    const std::string get_subtipo() override;
    int get_mana() override;
    void atacar() override;
    void descansar() override;
};

#endif
