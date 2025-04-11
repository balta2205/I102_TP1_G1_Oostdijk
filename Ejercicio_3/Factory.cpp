#include "Factory.h"

std::shared_ptr<Arma> PersonajeFactory::crearArma(Armas_lista arma){ 
    switch (arma) {
        case Armas_lista::null : return nullptr;
        
        case Armas_lista::BASTON : return std::make_shared<Baston>(75, 5, 100, 15);

        case Armas_lista::LIBROHECHIZO : return std::make_shared<Libro_Hechizos>(85, 10, 100, 20);

        case Armas_lista::POCION : return std::make_shared<Pociones>(60, 5, 100, 15);

        case Armas_lista::AMULETO : return std::make_shared<Amuletos>(70, 8, 100, 10);

        case Armas_lista::HACHA_S : return std::make_shared<Hacha_simple>(80, 7, 100, 18, 13, 5);

        case Armas_lista::HACHA_D : return std::make_shared<Hacha_doble>(90, 10, 100, 25, 15, 5);

        case Armas_lista::ESPADA : return std::make_shared<Espada>(85, 8, 100, 20, 5, 7);

        case Armas_lista::LANZA : return std::make_shared<Lanza>(75, 6, 100, 15, 15, 10);

        case Armas_lista::GARROTE : return std::make_shared<Garrote>(80, 7, 100, 18, 10, 5);

        default: return nullptr;
    }
};

std::shared_ptr<Personaje> PersonajeFactory::crearPersonajeArmado(Personas personaje, std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas) {
    
    switch (personaje){
        case Personas::null : return nullptr;

        case Personas::HECHICERO : return std::make_shared<Hechicero>(250, 50, 150, 100, 10, armas);

        case Personas::CONJURADOR : return std::make_shared<Conjurador>(250, 50, 150, 100, 10, armas);

        case Personas::BRUJO : return std::make_shared<Brujo>(250, 50, 150, 100, 10, armas);

        case Personas::NIGROMANTE : return std::make_shared<Nigromante>(250, 50, 150, 100, 10, armas);

        case Personas::BARBARO : return std::make_shared<Barbaro>(300, 150, 50, 100, 10, armas);

        case Personas::PALADIN : return std::make_shared<Paladin>(300, 150, 50, 100, 10, armas);

        case Personas::CABALLERO : return std::make_shared<Caballero>(300, 150, 50, 100, 10, armas);

        case Personas::MERCENARIO : return std::make_shared<Mercenario>(300, 150, 50, 100, 10, armas);

        case Personas::GLADIADOR : return std::make_shared<Gladiador>(300, 150, 50, 100, 10, armas);

        default: return nullptr;
    }
};

std::shared_ptr<Personaje> PersonajeFactory::crearPersonaje(Personas personaje) {
    return PersonajeFactory::crearPersonajeArmado(personaje, std::make_pair(nullptr, nullptr));
}