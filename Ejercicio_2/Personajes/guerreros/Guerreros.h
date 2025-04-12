#ifndef GUERREROS_H
#define GUERREROS_H

#include "../personajes.h"

class Guerreros : public Personaje{
protected: 
    const std::string tipo = "Guerrero"; // Siempre es tipo Guerrero, no se puede cambiar.
    int vida;
    int defensa_fisica;
    int defensa_magica;
    int nivel;
    int stamina; // Atributo exclusivo de los guerreros.

    // Armas del guerrero, se guardan como un par de shared_ptr.
    std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas;

public:
    Guerreros(int vida, int defensa_fisica, int defensa_magica, int nivel, int stamina, std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas);
    virtual ~Guerreros() = default;

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
    virtual int get_stamina() = 0;
    virtual void set_stamina(int stamina) = 0;
};

#endif