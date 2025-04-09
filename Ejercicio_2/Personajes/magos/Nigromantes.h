#ifndef NIGROMANTE
#define NIGROMANTE

#include "Magos.h"

class Nigromante : public Magos {
private:
    const std::string subtipo = "Nigromante";
    const std::string arma_especial = "Amuleto";

public: 
    Nigromante(int vida, int defensa, int mana, int nivel);

    const std::string get_subtipo() override;
    int get_mana() override;
    void atacar() override;
    void descansar() override;
};

#endif