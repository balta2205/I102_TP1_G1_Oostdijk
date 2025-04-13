#ifndef ARMAS_COMB_H
#define ARMAS_COMB_H

#include "../armas.h"

class Armas_comb : public Arma {
protected:
    const std::string tipo = "Armas de Combate"; // Tipo de arma
    int ataque;
    int durabilidad;
    int nivel;
    int velocidad; // Atributo especifico de las armas de combate y constante ya que la velocidad no cambia
    int peso; // Atributo especifico de las armas de combate y constante ya que el peso no cambia
    int alcance; // Atributo especifico de las armas de combate y constante ya que el alcance no cambia

public:
    Armas_comb(int ataque, int durabilidad, int nivel, int velocidad, int peso, int alcance);
    virtual ~Armas_comb() = default;
    
    // Getters.
    const std::string get_tipo() override;
    int get_ataque() override;
    int get_durabilidad() override;
    int get_nivel() override;
    virtual int get_velocidad() = 0; // Solo las armas tipo armas de combate tendran este atributo.
    virtual int get_peso() = 0; // Solo las armas tipo armas de combate tendran este atributo.
    virtual int get_alcance() = 0; // Solo las armas tipo armas de combate tendran este atributo.
};
#endif