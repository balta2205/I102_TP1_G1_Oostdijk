#include "Factory.h"

std::unique_ptr<Arma> PersonajeFactory::crearArma(Armas_lista arma){ 
    switch (arma) {
        case Armas_lista::null : return nullptr;    
        case Armas_lista::BASTON : return std::make_unique<Baston>(25, 5, 100, 15, 0);
        case Armas_lista::LIBROHECHIZO : return std::make_unique<Libro_Hechizos>(35, 10, 100, 20, 5);
        case Armas_lista::POCION : return std::make_unique<Pociones>(15, 5, 100, 15, 3);
        case Armas_lista::AMULETO : return std::make_unique<Amuletos>(20, 8, 100, 10, 7);
        case Armas_lista::HACHA_S : return std::make_unique<Hacha_simple>(30, 7, 100, 18, 13, 5);
        case Armas_lista::HACHA_D : return std::make_unique<Hacha_doble>(40, 10, 100, 25, 15, 5);
        case Armas_lista::ESPADA : return std::make_unique<Espada>(35, 8, 100, 20, 5, 7);
        case Armas_lista::LANZA : return std::make_unique<Lanza>(25, 6, 100, 15, 15, 10);
        case Armas_lista::GARROTE : return std::make_unique<Garrote>(20, 7, 100, 18, 10, 5);
        default: return nullptr;
    }
};

std::unique_ptr<Personaje> PersonajeFactory::crearPersonajeArmado(Personas personaje, std::pair<std::unique_ptr<Arma>, std::unique_ptr<Arma>> armas) {
    switch (personaje){
        case Personas::null : return nullptr;
        case Personas::HECHICERO : return std::make_unique<Hechicero>(250, 50, 150, 100, 10, std::make_pair(std::move(armas.first), std::move(armas.second)));
        case Personas::CONJURADOR : return std::make_unique<Conjurador>(250, 50, 150, 100, 10, std::make_pair(std::move(armas.first), std::move(armas.second)));
        case Personas::BRUJO : return std::make_unique<Brujo>(250, 50, 150, 100, 10, std::make_pair(std::move(armas.first), std::move(armas.second)));
        case Personas::NIGROMANTE : return std::make_unique<Nigromante>(250, 50, 150, 100, 10, std::make_pair(std::move(armas.first), std::move(armas.second)));
        case Personas::BARBARO : return std::make_unique<Barbaro>(300, 150, 50, 100, 10, std::make_pair(std::move(armas.first), std::move(armas.second)));
        case Personas::PALADIN : return std::make_unique<Paladin>(300, 150, 50, 100, 10, std::make_pair(std::move(armas.first), std::move(armas.second)));
        case Personas::CABALLERO : return std::make_unique<Caballero>(300, 150, 50, 100, 10, std::make_pair(std::move(armas.first), std::move(armas.second)));
        case Personas::MERCENARIO : return std::make_unique<Mercenario>(300, 150, 50, 100, 10, std::make_pair(std::move(armas.first), std::move(armas.second)));
        case Personas::GLADIADOR : return std::make_unique<Gladiador>(300, 150, 50, 100, 10, std::make_pair(std::move(armas.first), std::move(armas.second)));
        default: return nullptr;
    }
};

std::unique_ptr<Personaje> PersonajeFactory::crearPersonaje(Personas personaje) {
    return PersonajeFactory::crearPersonajeArmado(personaje, std::make_pair(nullptr, nullptr));
}