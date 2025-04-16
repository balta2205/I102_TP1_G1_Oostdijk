#ifndef LIBRO_HECHIZO_H
#define LIBRO_HECHIZO_H

#include "Items.h" 

class Libro_Hechizos : public Item_mag {
private:
    const std::string subtipo = "Libro de Hechizos"; // Subtipo de arma.
    const std::vector<std::string> hechizos = {"Veneno", "Fuego", "Curacion", "Proteccion"}; // Hechizos de libro de hechizos.

public: 
    // Constructor.
    Libro_Hechizos(int ataque, int energia, int durabilidad, int nivel, int duracion);
    
    // Getters para los atributos.
    const std::string get_subtipo() override;
    int get_energia() override;
    int get_duracion() override;
    std::vector<std::string> get_hechizos();

    // Ataques.
    void ataque_primario() override;
    void ataque_secundario() override;
};

#endif