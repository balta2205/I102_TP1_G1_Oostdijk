#ifndef SOURCE_EJ2_H
#define SOURCE_EJ2_H

#include "Factory.h"

// Declaraciones de funciones del main.cpp
int numero_aleatorio(int min, int max);

/* Hay dos funciones para crear armas, una para magos y otra para guerreros, porque se considera que las armas de combate 
son especificos de los guerreros y los items magicos son especificos de los magos.*/
std::unique_ptr<Arma> random_arma();

/* Hay dos funciones para crear personajes para poder aleatorizar que tipo de guerreros y magos crear.*/
std::unique_ptr<Personaje> random_personaje_mago(std::pair<std::unique_ptr<Arma>, std::unique_ptr<Arma>> armas);
std::unique_ptr<Personaje> random_personaje_guerrero(std::pair<std::unique_ptr<Arma>, std::unique_ptr<Arma>> armas);
void crear_personajes(std::vector<std::unique_ptr<Personaje>>& guerreros, int cant_guerreros, std::vector<std::unique_ptr<Personaje>>& magos, int cant_magos);
void mostrar_personaje(const std::unique_ptr<Personaje>& personaje);
void imprimir_personajes(const std::vector<std::unique_ptr<Personaje>>& guerreros, const std::vector<std::unique_ptr<Personaje>>& magos);

#endif