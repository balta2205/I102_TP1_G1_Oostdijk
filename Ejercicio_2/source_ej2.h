#ifndef SOURCE_EJ2_H
#define SOURCE_EJ2_H

#include "Factory.h"

// Declaraciones de funciones
int numero_aleatorio(int min, int max);
std::shared_ptr<Arma> random_arma();
std::shared_ptr<Personaje> random_personaje_mago(std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas);
std::shared_ptr<Personaje> random_personaje_guerrero(std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas);
void crear_personajes(std::vector<std::shared_ptr<Personaje>>& guerreros, int cant_guerreros, std::vector<std::shared_ptr<Personaje>>& magos, int cant_magos);
void mostrar_personaje(const std::shared_ptr<Personaje>& personaje);
void imprimir_personajes(const std::vector<std::shared_ptr<Personaje>>& guerreros, const std::vector<std::shared_ptr<Personaje>>& magos);

#endif