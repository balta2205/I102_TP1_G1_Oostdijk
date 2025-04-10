#ifndef HACHA_S_H
#define HACHA_S_H

#include "Armas_comb.h"

class Hacha_simple : public Armas_comb {
private: 
    const std::string subtipo = "Hacha simple";
    
public:
    // Constructor
    Hacha_simple(int ataque, int velocidad, int durabilidad, int nivel, int peso, int alcance);

    // Metodos
    const std::string get_subtipo() override;
    void ataque_primario() override;
    void ataque_secundario() override;
};

#endif