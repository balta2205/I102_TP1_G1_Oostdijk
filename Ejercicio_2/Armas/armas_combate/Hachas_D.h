#ifndef HACHAS_D
#define HACHAS_D

#include "Armas_comb.h"

class Hacha_doble : public Armas_comb{
private: 
    const std::string subtipo = "Hacha doble";
    
public:
    // Constructor
    Hacha_doble(int ataque, int velocidad, int durabilidad, int nivel, int peso, int alcance);

    // Metodos
    const std::string get_subtipo() override;
    void ataque_primario() override;
    void ataque_secundario() override;
};

#endif