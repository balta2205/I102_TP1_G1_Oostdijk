// Includes Armas de Combate
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_2/Armas/armas_combate/Hachas_S.h"
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_2/Armas/armas_combate/Hachas_D.h"
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_2/Armas/armas_combate/Espadas.h"
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_2/Armas/armas_combate/Lanzas.h"
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_2/Armas/armas_combate/Garrotes.h"

// Includes Items Magicos
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_2/Armas/items_magicos/Bastones.h"
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_2/Armas/items_magicos/LibroHechizos.h"
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_2/Armas/items_magicos/Pociones.h"
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_2/Armas/items_magicos/Amuletos.h"

// Includes Guerreros
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_2/Personajes/guerreros/Barbaros.h"
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_2/Personajes/guerreros/Paladines.h"
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_2/Personajes/guerreros/Caballeros.h"
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_2/Personajes/guerreros/Mercenarios.h"
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_2/Personajes/guerreros/Gladiadores.h"

// Includes Magos
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_2/Personajes/magos/Hechiceros.h"
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_2/Personajes/magos/Conjuradores.h"
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_2/Personajes/magos/Brujos.h"
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_2/Personajes/magos/Nigromantes.h"

// Includes
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <random>
#include <cstdlib>
#include <ctime>

enum class Personas {HECHICERO, CONJURADOR, BRUJO, NIGROMANTE, BARBARO, PALADIN, CABALLERO, MERCENARIO, GLADIADOR};

#ifndef ARMAS_LISTA
#define ARMAS_LISTA
enum class Armas_lista {null, BASTON, LIBROHECHIZO, POCION, AMULETO, HACHA_S, HACHA_D, ESPADA, LANZA, GARROTE};
#endif 

class PersonajeFactory {
public:
    static std::shared_ptr<Arma> crearArma(Armas_lista arma);
    static std::shared_ptr<Personaje> crearPersonaje(Personas personaje);
    static std::shared_ptr<Personaje> crearPersonajeArmado(Personas personaje, std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas);
};