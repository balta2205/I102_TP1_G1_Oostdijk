#ifndef MAGOS_H
#define MAGOS_H

#include "../personajes.h"

class Magos : public Personaje{
protected: 
    const std::string tipo = "Mago"; // Siempre es tipo Mago, no se puede cambiar.
    int vida;
    int defensa_fisica;
    int defensa_magica;
    int nivel;
    int mana; // Atributo exclusivo de los magos.

    // Armas del mago, se guardan como un par de shared_ptr.
    std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas;

public:
    Magos(int vida, int defensa_fisica, int defensa_magica, int nivel, int mana, std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas);
    virtual ~Magos() = default; 

    // Getters para los atributos.
    const std::string get_tipo() override;
    int get_vida() override;
    int get_defensa_fisica() override;
    int get_defensa_magica() override;
    int get_nivel() override;
    std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> get_armas() override;

    // Setters para los atributos.
    void set_vida(int vida) override;
    void set_defensa_fisica(int defensa_fisica) override;
    void set_defensa_magica(int defensa_magica) override;
    void set_nivel(int nivel) override;

    // Movimientos.
    void golpe_fuerte() override;
    void golpe_rapido() override;
    void defensa_golpe() override;
    
    // Getters Virtuales
    virtual int get_mana() = 0;
    virtual void set_mana(int mana) = 0;
};

#endif