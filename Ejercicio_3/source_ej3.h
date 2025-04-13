#ifndef SOURCE_EJ3_H
#define SOURCE_EJ3_H

#include "../Ejercicio_2/source_ej2.h"
#include "../Ejercicio_2/Factory.h"
#include "../utilities.h"

// Declaraciones de funciones del Ejercicio 3.

void Limpiar_terminal(); // Limpia la terminal.
void mostrar_personajes(Personas elegido); // Despliega el menu de personajes.
// Sobrecargue la funcion para mostrar estadisticas de personajes para poder usarla en el menu de personajes y con estadisticas especificas de cada personaje.
void mostrar_estadisticas_personajes(Personas opcion); // Despliega las estadisticas de los personajes.
void mostrar_estadisticas_personajes(Personas opcion, std::shared_ptr<Personaje> clase); // Despliega las estadisticas de los personajes.
void mostrar_estadisticas_armas(Armas_lista opcion); // Despliega las estadisticas de las armas.
std::shared_ptr<Arma> elegir_arma(Personas personaje, bool is_guerrero); // Despliega el menu de armas y devuelve la seleccionada.
Ataques random_ataque_enemigo(); // Devuelve un ataque aleatorio del enemigo.
std::shared_ptr<Personaje> definir_ganador(std::shared_ptr<Personaje> amigo, std::shared_ptr<Personaje> enemigo, Ataques ataque_amigo, Ataques ataque_enemigo);
Personas string_a_persona(const std::string& str); // Convierte un string a un enum de tipo Personas.
std::string persona_a_string(Personas persona); // Convierte un enum de tipo Personas a un string.

#endif