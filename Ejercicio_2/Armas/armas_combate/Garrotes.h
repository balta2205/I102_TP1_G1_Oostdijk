#ifndef GARROTE
#define GARROTE

#include "Armas_comb.h"

class Garrote : public Armas_comb {
private: 
    const std::string subtipo = "Lanza";
    
public:
    // Constructor
    Garrote(int ataque, int velocidad, int durabilidad, int nivel, int peso, int alcance);

    // Metodos
    const std::string get_subtipo() override;
    void ataque_primario() override;
    void ataque_secundario() override;
};

#endif