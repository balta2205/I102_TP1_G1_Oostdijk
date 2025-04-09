#ifndef LANZA
#define LANZA

#include "Armas_comb.h"

class Lanza : public Armas_comb {
private: 
    const std::string subtipo = "Lanza";
    
public:
    // Constructor
    Lanza(int ataque, int velocidad, int durabilidad, int nivel, int peso, int alcance);

    // Metodos
    const std::string get_subtipo() override;
    void ataque_primario() override;
    void ataque_secundario() override;
};

#endif