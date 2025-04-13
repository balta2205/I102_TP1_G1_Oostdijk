#include "Factory.h"

int numero_aleatorio(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

std::shared_ptr<Arma> random_arma(){
    int tipo_arma = numero_aleatorio(0, 8);
    switch (tipo_arma) {
        case 0: return PersonajeFactory::crearArma(Armas_lista::BASTON);
        case 1: return PersonajeFactory::crearArma(Armas_lista::LIBROHECHIZO);
        case 2: return PersonajeFactory::crearArma(Armas_lista::POCION);
        case 3: return PersonajeFactory::crearArma(Armas_lista::AMULETO);
        case 4: return PersonajeFactory::crearArma(Armas_lista::HACHA_S);
        case 5: return PersonajeFactory::crearArma(Armas_lista::HACHA_D);
        case 6: return PersonajeFactory::crearArma(Armas_lista::ESPADA);
        case 7: return PersonajeFactory::crearArma(Armas_lista::LANZA);
        case 8: return PersonajeFactory::crearArma(Armas_lista::GARROTE);
        default: return nullptr;
    }
}

std::shared_ptr<Personaje> random_personaje_mago(std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas) {
    int tipo_mago = numero_aleatorio(0, 3);
    switch (tipo_mago) {
        case 0: return PersonajeFactory::crearPersonajeArmado(Personas::HECHICERO, armas);
        case 1: return PersonajeFactory::crearPersonajeArmado(Personas::CONJURADOR, armas);
        case 2: return PersonajeFactory::crearPersonajeArmado(Personas::BRUJO, armas);
        case 3: return PersonajeFactory::crearPersonajeArmado(Personas::NIGROMANTE, armas);
        default: return nullptr;
    }
}

std::shared_ptr<Personaje> random_personaje_guerrero(std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas) {
    int tipo_guerrero = numero_aleatorio(0, 4);
    switch (tipo_guerrero) {
        case 0: return PersonajeFactory::crearPersonajeArmado(Personas::BARBARO, armas);
        case 1: return PersonajeFactory::crearPersonajeArmado(Personas::PALADIN, armas);
        case 2: return PersonajeFactory::crearPersonajeArmado(Personas::CABALLERO, armas);
        case 3: return PersonajeFactory::crearPersonajeArmado(Personas::MERCENARIO, armas);
        case 4: return PersonajeFactory::crearPersonajeArmado(Personas::GLADIADOR, armas);
        default: return nullptr;
    }
}

void crear_personajes(std::vector<std::shared_ptr<Personaje>>& guerreros, int cant_guerreros, std::vector<std::shared_ptr<Personaje>>& magos, int cant_magos) {
    for (int i = 0; i < cant_guerreros; ++i) {
        int cant_armas = numero_aleatorio(0, 2);
        std::shared_ptr<Arma> arma1 = (cant_armas > 0) ? random_arma() : nullptr;
        std::shared_ptr<Arma> arma2 = (cant_armas > 1) ? random_arma() : nullptr;

        std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas = std::make_pair(arma1, arma2);
        std::shared_ptr<Personaje> guerrero = random_personaje_guerrero(armas);
        if(guerrero) guerreros.push_back(guerrero);
    }

    for (int i = 0; i < cant_magos; ++i) {
        int cant_armas = numero_aleatorio(0, 2);
        std::shared_ptr<Arma> arma1 = (cant_armas > 0) ? random_arma() : nullptr;
        std::shared_ptr<Arma> arma2 = (cant_armas > 1) ? random_arma() : nullptr;
        
        std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> armas = std::make_pair(arma1, arma2);
        std::shared_ptr<Personaje> mago = random_personaje_mago(armas);
        if(mago) magos.push_back(mago);
    }
};

void mostrar_personaje(const std::shared_ptr<Personaje>& personaje){
    if (!personaje) {std::cout << "nullptr" << std::endl; return;}

    std::cout << personaje->get_tipo() << ": " << personaje->get_subtipo() << std::endl;
    std::cout << "   Vida: " << personaje->get_vida() << std::endl;
    std::cout << "   Defensa Fisica: " << personaje->get_defensa_fisica() << std::endl;
    std::cout << "   Defensa Mágica: " << personaje->get_defensa_magica() << std::endl;

    std::cout << "   Armas:" << std::endl;
    auto armas = personaje->get_armas();
    
    std::cout << "       Arma 1: ";
    if (armas.first) {
        std::cout << armas.first->get_subtipo() << std::endl;
        std::cout << "\t   Daño: " << armas.first->get_ataque() << std::endl;
        std::cout << "\t   Durabilidad: " << armas.first->get_durabilidad() << std::endl;
    } 
    else {std::cout << "No hay" << std::endl;}
    
    std::cout << "\n       Arma 2: ";
    if (armas.second) {
        std::cout << armas.second->get_subtipo() << std::endl;
        std::cout << "\t   Daño: " << armas.second->get_ataque() << std::endl;
        std::cout << "\t   Durabilidad: " << armas.second->get_durabilidad() << std::endl;
    } 
    else {std::cout << "No hay" << std::endl;}

    std::cout << "---------------------------------------------" << std::endl;
}

void imprimir_personajes(const std::vector<std::shared_ptr<Personaje>>& guerreros, const std::vector<std::shared_ptr<Personaje>>& magos) {
    for (const auto& guerrero : guerreros) {mostrar_personaje(guerrero);}
    for (const auto& mago : magos) {mostrar_personaje(mago);}
}
