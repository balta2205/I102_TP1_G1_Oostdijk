#ifndef CONJURADORE
#define CONJURADORE

#include "Magos.h"

class Conjurador : public Magos {
private:
    const std::string subtipo = "Conjurador";
    const std::string arma_especial = "Libro de Hechizos";

public:
    Conjurador(int vida, int defensa, int mana, int nivel);

    const std::string get_subtipo() override;
    int get_mana() override;
    void atacar() override;
    void descansar() override;
};

#endif