#ifndef FACTORY_H
#define FACTORY_H

// Include utilities
#include "../utilities.h"
#include "../Ejercicio_1/Personajes/personajes.h"
#include "../Ejercicio_1/Armas/armas.h"

// Includes Armas de Combate
#include "../Ejercicio_1/Armas/armas_combate/Armas_comb.h"
#include "../Ejercicio_1/Armas/armas_combate/Hachas_S.h"
#include "../Ejercicio_1/Armas/armas_combate/Hachas_D.h"
#include "../Ejercicio_1/Armas/armas_combate/Espadas.h"
#include "../Ejercicio_1/Armas/armas_combate/Lanzas.h"
#include "../Ejercicio_1/Armas/armas_combate/Garrotes.h"

// Includes Items Magicos
#include "../Ejercicio_1/Armas/items_magicos/Items.h"
#include "../Ejercicio_1/Armas/items_magicos/Bastones.h"
#include "../Ejercicio_1/Armas/items_magicos/LibroHechizos.h"
#include "../Ejercicio_1/Armas/items_magicos/Pociones.h"
#include "../Ejercicio_1/Armas/items_magicos/Amuletos.h"

// Includes Guerreros
#include "../Ejercicio_1/Personajes/guerreros/Guerreros.h"
#include "../Ejercicio_1/Personajes/guerreros/Barbaros.h"
#include "../Ejercicio_1/Personajes/guerreros/Paladines.h"
#include "../Ejercicio_1/Personajes/guerreros/Caballeros.h"
#include "../Ejercicio_1/Personajes/guerreros/Mercenarios.h"
#include "../Ejercicio_1/Personajes/guerreros/Gladiadores.h"

// Includes Magos
#include "../Ejercicio_1/Personajes/magos/Magos.h"
#include "../Ejercicio_1/Personajes/magos/Hechiceros.h"
#include "../Ejercicio_1/Personajes/magos/Conjuradores.h"
#include "../Ejercicio_1/Personajes/magos/Brujos.h"
#include "../Ejercicio_1/Personajes/magos/Nigromantes.h"

// Clase PersonajeFactory -> Factory para crear personajes y armas
class PersonajeFactory {
public:
    static std::unique_ptr<Arma> crearArma(Armas_lista arma);
    static std::unique_ptr<Personaje> crearPersonaje(Personas personaje);
    static std::unique_ptr<Personaje> crearPersonajeArmado(Personas personaje, std::pair<std::unique_ptr<Arma>, std::unique_ptr<Arma>> armas);
};

#endif