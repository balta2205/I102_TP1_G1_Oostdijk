#ifndef FACTORY_H
#define FACTORY_H

// Include utilities
#include "../utilities.h"

// Includes Armas de Combate
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_1/Armas/armas_combate/Hachas_S.h"
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_1/Armas/armas_combate/Hachas_D.h"
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_1/Armas/armas_combate/Espadas.h"
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_1/Armas/armas_combate/Lanzas.h"
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_1/Armas/armas_combate/Garrotes.h"

// Includes Items Magicos
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_1/Armas/items_magicos/Bastones.h"
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_1/Armas/items_magicos/LibroHechizos.h"
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_1/Armas/items_magicos/Pociones.h"
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_1/Armas/items_magicos/Amuletos.h"

// Includes Guerreros
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_1/Personajes/guerreros/Barbaros.h"
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_1/Personajes/guerreros/Paladines.h"
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_1/Personajes/guerreros/Caballeros.h"
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_1/Personajes/guerreros/Mercenarios.h"
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_1/Personajes/guerreros/Gladiadores.h"

// Includes Magos
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_1/Personajes/magos/Hechiceros.h"
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_1/Personajes/magos/Conjuradores.h"
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_1/Personajes/magos/Brujos.h"
#include "/root/snap/Paradigmas/I102_TP1_G1_Oostdijk/Ejercicio_1/Personajes/magos/Nigromantes.h"

// Clase PersonajeFactory -> Factory para crear personajes y armas
class PersonajeFactory {
public:
    static std::shared_ptr<Arma> crearArma(Armas_lista arma);
    static std::shared_ptr<Personaje> crearPersonaje(Personas personaje);
    static std::shared_ptr<Personaje> crearPersonajeArmado(Personas personaje, std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas);
};
#endif

// Declaraciones de funciones del main.cpp
int numero_aleatorio(int min, int max);

/* Hay dos funciones para crear armas, una para magos y otra para guerreros, porque se considera que las armas de combate 
son especificos de los guerreros y los items magicos son especificos de los magos.*/
std::shared_ptr<Arma> random_arma();

/* Hay dos funciones para crear personajes para poder aleatorizar que tipo de guerreros y magos crear.*/
std::shared_ptr<Personaje> random_personaje_mago(std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas);
std::shared_ptr<Personaje> random_personaje_guerrero(std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas);
void crear_personajes(std::vector<std::shared_ptr<Personaje>>& guerreros, int cant_guerreros, std::vector<std::shared_ptr<Personaje>>& magos, int cant_magos);
void mostrar_personaje(const std::shared_ptr<Personaje>& personaje);
void imprimir_personajes(const std::vector<std::shared_ptr<Personaje>>& guerreros, const std::vector<std::shared_ptr<Personaje>>& magos);