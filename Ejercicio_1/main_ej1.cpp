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

int main(){

    // Se inicializan las Armas
    std::shared_ptr<Baston> baston = std::make_shared<Baston>(25, 5, 100, 15, 0);
    std::shared_ptr<Libro_Hechizos> libro_hechizo = std::make_shared<Libro_Hechizos>(85, 10, 100, 20, 5);
    std::shared_ptr<Pociones> pocion = std::make_shared<Pociones>(15, 5, 100, 15, 3);
    std::shared_ptr<Amuletos> amuleto = std::make_shared<Amuletos>(20, 8, 100, 10, 7);
    std::shared_ptr<Hacha_simple> hacha_s = std::make_shared<Hacha_simple>(30, 7, 100, 18, 13, 5);
    std::shared_ptr<Hacha_doble> hacha_d = std::make_shared<Hacha_doble>(40, 10, 100, 25, 15, 5);
    std::shared_ptr<Espada> espada = std::make_shared<Espada>(35, 8, 100, 20, 5, 7);
    std::shared_ptr<Lanza> lanza = std::make_shared<Lanza>(25, 6, 100, 15, 15, 10);
    std::shared_ptr<Garrote> garrote = std::make_shared<Garrote>(20, 7, 100, 18, 10, 5);

    // Ejemplo de armas para crear personajes
    std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas = std::make_pair(hacha_s, hacha_d);

    // Se inicializan los personajes
    std::shared_ptr<Hechicero> hechicero = std::make_shared<Hechicero>(250, 50, 150, 100, 10, armas);
    std::shared_ptr<Conjurador> conjurador = std::make_shared<Conjurador>(250, 50, 150, 100, 10, armas);
    std::shared_ptr<Brujo> brujo = std::make_shared<Brujo>(250, 50, 150, 100, 10, armas);
    std::shared_ptr<Nigromante> nigromante = std::make_shared<Nigromante>(250, 50, 150, 100, 10, armas);
    std::shared_ptr<Barbaro> barbaro = std::make_shared<Barbaro>(300, 150, 50, 100, 10, armas);
    std::shared_ptr<Paladin> paladin = std::make_shared<Paladin>(300, 150, 50, 100, 10, armas);
    std::shared_ptr<Caballero> caballero = std::make_shared<Caballero>(300, 150, 50, 100, 10, armas);
    std::shared_ptr<Mercenario> mercenario = std::make_shared<Mercenario>(300, 150, 50, 100, 10, armas);
    std::shared_ptr<Gladiador> gladiador = std::make_shared<Gladiador>(300, 150, 50, 100, 10, armas);

    // Mostrar estadisticas de los personajes
    // Tipo Mago
    std::cout << "==================" << std::endl;
    std::cout << "Subtipo: " << hechicero->get_subtipo() << std::endl;
    std::cout << "==================" << std::endl;
    std::cout << "Estadisticas: " << std::endl;
    std::cout << "    Vida: " << hechicero->get_vida() << std::endl;
    std::cout << "    Defensa Magica: " << hechicero->get_defensa_magica() << std::endl;
    std::cout << "    Defensa Fisica: " << hechicero->get_defensa_fisica() << std::endl;
    std::cout << "    Mana: " << hechicero->get_mana() << std::endl;
    std::cout << "    Nivel: " << hechicero->get_nivel() << std::endl;
    std::cout << "    Arma Especial: " << hechicero->get_arma_especial() << std::endl;

    // Tipo Guerrero
    std::cout << "\n================" << std::endl;
    std::cout << "Subtipo: " << barbaro->get_subtipo() << std::endl;
    std::cout << "================" << std::endl;
    std::cout << "Estadisticas: " << std::endl;
    std::cout << "    Vida: " << barbaro->get_vida() << std::endl;
    std::cout << "    Defensa Magica: " << barbaro->get_defensa_magica() << std::endl;
    std::cout << "    Defensa Fisica: " << barbaro->get_defensa_fisica() << std::endl;
    std::cout << "    Stamina: " << barbaro->get_stamina() << std::endl;
    std::cout << "    Nivel: " << barbaro->get_nivel() << std::endl;
    std::cout << "    Arma Especial: " << barbaro->get_arma_especial() << std::endl;

    // Mostrar estadisticas de las armas
    //Tipo Item Magico
    std::cout << "\n====================" << std::endl;
    std::cout << "Arma elegida: " << baston->get_subtipo() << std::endl;
    std::cout << "====================" << std::endl;
    std::cout << "Estadisticas: " << std::endl;
    std::cout << "    Ataque: " << baston->get_ataque() << std::endl;
    std::cout << "    Energia: " << baston->get_energia() << std::endl;
    std::cout << "    Durabilidad: " << baston->get_durabilidad() << std::endl;
    std::cout << "    Nivel: " << baston->get_nivel() << std::endl;
    std::cout << "    Duracion: " << baston->get_duracion() << std::endl;

    // Tipo Armas de Combate
    std::cout << "\n==========================" << std::endl;
    std::cout << "Arma elegida: " << hacha_s->get_subtipo() << std::endl;
    std::cout << "==========================" << std::endl;
    std::cout << "Estadisticas: " << std::endl;
    std::cout << "    Ataque: " << hacha_s->get_ataque() << std::endl;
    std::cout << "    Velocidad: " << hacha_s->get_velocidad() << std::endl;
    std::cout << "    Durabilidad: " << hacha_s->get_durabilidad() << std::endl;
    std::cout << "    Nivel: " << hacha_s->get_nivel() << std::endl;
    std::cout << "    Peso: " << hacha_s->get_peso() << std::endl;
    std::cout << "    Alcance: " << hacha_s->get_alcance() << std::endl;
}