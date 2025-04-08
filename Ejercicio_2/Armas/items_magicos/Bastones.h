#ifndef BASTONES
#define BASTONES

#include "Items.h"

class Baston : public Item_mag {
private: 
    const std::string subtipo = "Baston";

public: 
    // Constructor
    Baston(int ataque, int energia, int durabilidad, int nivel);

    // Métodos 
    const std::string get_subtipo() override;
    void ataque_primario() override;
    void ataque_secundario() override;
};

#endif