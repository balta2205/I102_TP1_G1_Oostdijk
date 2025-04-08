#ifndef AMULETOS
#define AMULETOS

#include "Items.h"

class Amuletos : public Item_mag{
private: 
    const std::string subtipo = "Amuleto";

public: 
    // Constructor.
    Amuletos(int ataque, int energia, int durabilidad, int nivel);

    const std::string get_subtipo() override;
    void ataque_primario() override;
    void ataque_secundario() override;
};

#endif