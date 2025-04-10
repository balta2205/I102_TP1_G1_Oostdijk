#ifndef ESPADA_H
#define ESPADA_H

#include "Armas_comb.h"

class Espada : public Armas_comb {
private: 
    const std::string subtipo = "Espada";
    
public:
    // Constructor
    Espada(int ataque, int velocidad, int durabilidad, int nivel, int peso, int alcance);

    // Metodos
    const std::string get_subtipo() override;
    void ataque_primario() override;
    void ataque_secundario() override;
};

#endif