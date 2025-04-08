#ifndef LIBROSDEHECHIZOS
#define LIBROSDEHECHIZOS

#include "Items.h" 
#include <vector>

class Libro_Hechizos : public Item_mag {
private:
    const std::string subtipo = "Libro de Hechizos";
    const std::vector<std::string> hechizos = {"Veneno", "Fuego", "Curacion", "Proteccion"};

public: 
    Libro_Hechizos(int ataque, int energia, int durabilidad, int nivel);
    const std::string get_subtipo() override;
    void ataque_primario() override;
    void ataque_secundario() override;
};

#endif