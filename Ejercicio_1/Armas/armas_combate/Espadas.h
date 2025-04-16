#ifndef ESPADA_H
#define ESPADA_H

#include "Armas_comb.h"

class Espada : public Armas_comb {
private: 
    const std::string subtipo = "Espada"; // Subtipo de arma.
    
public:
    // Constructor.
    Espada(int ataque, int velocidad, int durabilidad, int nivel, int peso, int alcance);

    // Getters para los atributos.
    const std::string get_subtipo() override;
    int get_velocidad() override;
    int get_peso() override;
    int get_alcance() override;

    // Ataques.
    void ataque_primario() override;
    void ataque_secundario() override;
};

#endif