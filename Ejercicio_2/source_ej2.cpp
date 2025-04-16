#include "source_ej2.h"

int numero_aleatorio(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

std::unique_ptr<Arma> random_arma(){
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

std::unique_ptr<Personaje> random_personaje_mago(std::pair<std::unique_ptr<Arma>, std::unique_ptr<Arma>> armas) {
    int tipo_mago = numero_aleatorio(0, 3);
    switch (tipo_mago) {
        case 0: return PersonajeFactory::crearPersonajeArmado(Personas::HECHICERO, std::make_pair(std::move(armas.first), std::move(armas.second)));
        case 1: return PersonajeFactory::crearPersonajeArmado(Personas::CONJURADOR, std::make_pair(std::move(armas.first), std::move(armas.second)));
        case 2: return PersonajeFactory::crearPersonajeArmado(Personas::BRUJO, std::make_pair(std::move(armas.first), std::move(armas.second)));
        case 3: return PersonajeFactory::crearPersonajeArmado(Personas::NIGROMANTE, std::make_pair(std::move(armas.first), std::move(armas.second)));
        default: return nullptr;
    }
}

std::unique_ptr<Personaje> random_personaje_guerrero(std::pair<std::unique_ptr<Arma>, std::unique_ptr<Arma>> armas) {
    int tipo_guerrero = numero_aleatorio(0, 4);
    switch (tipo_guerrero) {
        case 0: return PersonajeFactory::crearPersonajeArmado(Personas::BARBARO, std::make_pair(std::move(armas.first), std::move(armas.second)));
        case 1: return PersonajeFactory::crearPersonajeArmado(Personas::PALADIN, std::make_pair(std::move(armas.first), std::move(armas.second)));
        case 2: return PersonajeFactory::crearPersonajeArmado(Personas::CABALLERO, std::make_pair(std::move(armas.first), std::move(armas.second)));
        case 3: return PersonajeFactory::crearPersonajeArmado(Personas::MERCENARIO, std::make_pair(std::move(armas.first), std::move(armas.second)));
        case 4: return PersonajeFactory::crearPersonajeArmado(Personas::GLADIADOR, std::make_pair(std::move(armas.first), std::move(armas.second)));
        default: return nullptr;
    }
}

void crear_personajes(std::vector<std::unique_ptr<Personaje>>& guerreros, int cant_guerreros, std::vector<std::unique_ptr<Personaje>>& magos, int cant_magos) {
    for (int i = 0; i < cant_guerreros; ++i) {
        int cant_armas = numero_aleatorio(0, 2);
        std::unique_ptr<Arma> arma1 = (cant_armas > 0) ? random_arma() : nullptr;
        std::unique_ptr<Arma> arma2 = (cant_armas > 1) ? random_arma() : nullptr;

        std::unique_ptr<Personaje> guerrero = random_personaje_guerrero(std::make_pair(std::move(arma1), std::move(arma2)));
        if(guerrero) guerreros.push_back(std::move(guerrero));
    }

    for (int i = 0; i < cant_magos; ++i) {
        int cant_armas = numero_aleatorio(0, 2);
        std::unique_ptr<Arma> arma1 = (cant_armas > 0) ? random_arma() : nullptr;
        std::unique_ptr<Arma> arma2 = (cant_armas > 1) ? random_arma() : nullptr;
        
        std::unique_ptr<Personaje> mago = random_personaje_mago(std::make_pair(std::move(arma1), std::move(arma2)));
        if(mago) magos.push_back(std::move(mago));
    }
};

void mostrar_personaje(const std::unique_ptr<Personaje>& personaje){
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
        std::cout << "\t    Ataque: " << armas.first->get_ataque() << std::endl;
        std::cout << "\t    Durabilidad: " << armas.first->get_durabilidad() << std::endl;
        std::cout << "\t    Nivel: " << armas.first->get_nivel() << std::endl;
        if(armas.first->get_tipo() == "Item Magico") {
            auto aux = dynamic_cast<Item_mag*>(armas.first);
            std::cout << "\t    Energia: " << aux->get_energia() << std::endl;
            std::cout << "\t    Duracion: " << aux->get_duracion() << std::endl;
        }
        else{
            auto aux = dynamic_cast<Armas_comb*>(armas.first);
            std::cout << "\t    Velocidad: " << aux->get_velocidad() << std::endl;
            std::cout << "\t    Peso: " << aux->get_peso() << std::endl;
            std::cout << "\t    Alcance: " << aux->get_alcance() << std::endl;
        }
    } 
    else {std::cout << "No hay" << std::endl;}
    
    std::cout << "\n       Arma 2: ";
    if (armas.second) {
        std::cout << armas.second->get_subtipo() << std::endl;
        std::cout << "\t    Ataque: " << armas.second->get_ataque() << std::endl;
        std::cout << "\t    Durabilidad: " << armas.second->get_durabilidad() << std::endl;
        std::cout << "\t    Nivel: " << armas.second->get_nivel() << std::endl;
        if(armas.second->get_tipo() == "Item Magico") {
            auto aux = dynamic_cast<Item_mag*>(armas.second);
            std::cout << "\t    Energia: " << aux->get_energia() << std::endl;
            std::cout << "\t    Duracion: " << aux->get_duracion() << std::endl;
        }
        else{
            auto aux = dynamic_cast<Armas_comb*>(armas.second);
            std::cout << "\t    Velocidad: " << aux->get_velocidad() << std::endl;
            std::cout << "\t    Peso: " << aux->get_peso() << std::endl;
            std::cout << "\t    Alcance: " << aux->get_alcance() << std::endl;
        }
    } 
    else {std::cout << "No hay" << std::endl;}

    std::cout << "---------------------------------------------" << std::endl;
}

void imprimir_personajes(const std::vector<std::unique_ptr<Personaje>>& guerreros, const std::vector<std::unique_ptr<Personaje>>& magos) {
    for (const auto& guerrero : guerreros) {mostrar_personaje(guerrero);}
    for (const auto& mago : magos) {mostrar_personaje(mago);}
}
