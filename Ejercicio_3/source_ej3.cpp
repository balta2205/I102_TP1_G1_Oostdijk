#ifndef SOURCE_EJ3
#define SOURCE_EJ3

#include "main_ej3.h"


void Limpiar_terminal(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

Ataques random_ataque_enemigo(){
    return static_cast<Ataques>(numero_aleatorio(1, 3));
}

std::shared_ptr<Personaje> definir_ganador(std::shared_ptr<Personaje> amigo, std::shared_ptr<Personaje> enemigo, Ataques ataque_amigo, Ataques ataque_enemigo){
    if(ataque_amigo == Ataques::DEFENSA_GOLPE && ataque_enemigo == Ataques::DEFENSA_GOLPE) {return nullptr;}
    else if(ataque_amigo == Ataques::DEFENSA_GOLPE && ataque_enemigo == Ataques::GOLPE_RAPIDO) {return nullptr;}
    else if(ataque_amigo == Ataques::GOLPE_RAPIDO && ataque_enemigo == Ataques::GOLPE_FUERTE) {return nullptr;}
    else if(ataque_amigo == Ataques::GOLPE_FUERTE && ataque_enemigo == Ataques::GOLPE_RAPIDO) {return amigo;}
    else if(ataque_amigo == Ataques::GOLPE_RAPIDO && ataque_enemigo == Ataques::DEFENSA_GOLPE) {return amigo;}
    else if(ataque_amigo == Ataques::DEFENSA_GOLPE && ataque_enemigo == Ataques::GOLPE_FUERTE) {return amigo;}
    else{return enemigo;}
}

Personas string_a_persona(const std::string& str) {
    static const std::unordered_map<std::string, Personas> mapa = {
        {"Hechicero", Personas::HECHICERO},
        {"Conjurador", Personas::CONJURADOR},
        {"Brujo", Personas::BRUJO},
        {"Nigromante", Personas::NIGROMANTE},
        {"Barbaro", Personas::BARBARO},
        {"Paladin", Personas::PALADIN},
        {"Caballero", Personas::CABALLERO},
        {"Mercenario", Personas::MERCENARIO},
        {"Gladiador", Personas::GLADIADOR}
    };

    auto it = mapa.find(str);
    if (it != mapa.end()) {return it->second;}
    else {throw std::invalid_argument("String no reconocido para enum Personas");}
}

std::string persona_a_string(Personas persona) {
    static const std::unordered_map<Personas, std::string> mapa = {
        {Personas::HECHICERO, "Hechicero"},
        {Personas::CONJURADOR, "Conjurador"},
        {Personas::BRUJO, "Brujo"},
        {Personas::NIGROMANTE, "Nigromante"},
        {Personas::BARBARO, "Barbaro"},
        {Personas::PALADIN, "Paladin"},
        {Personas::CABALLERO, "Caballero"},
        {Personas::MERCENARIO, "Mercenario"},
        {Personas::GLADIADOR, "Gladiador"}
    };

    auto it = mapa.find(persona);
    if (it != mapa.end()) { return it->second; }
    else { return "Desconocido"; }
}

void mostrar_personajes(Personas elegido){      
    std::cout << "Elija su personaje:" << std::endl;
    std::cout << "    Magos: " << std::endl;
    std::cout << "\t[1]. Hechicero \n\t[2]. Conjurador \n\t[3]. Brujo \n\t[4]. Nigromante" << std::endl;
    std::cout << "\n    Guerreros: " << std::endl;
    std::cout << "\t[5]. Barbaro \n\t[6]. Paladin \n\t[7]. Caballero \n\t[8]. Mercenario \n\t[9]. Gladiador" << std::endl;
    std::cout << "\t[10]. Salir, (debe estar seleccionado algun personaje) Personaje seleccionado: ";
    if(elegido == Personas::null) {std::cout << "Ninguno" << std::endl;} 
    else std::cout << persona_a_string(elegido) << std::endl;
    std::cout << "================================================================================================" << std::endl;
    std::cout << "Inserte opcion para ver estadisticas: ";
}

void mostrar_estadisticas_personajes(Personas opcion){
    switch(opcion){
        case Personas::HECHICERO :{
            std::cout << "============================" << std::endl;
            std::cout << "Personaje elegido: Hechicero" << std::endl;
            std::cout << "============================" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "    Vida: 250" << std::endl;
            std::cout << "    Defensa Magica: 150" << std::endl;
            std::cout << "    Defensa Fisica: 50" << std::endl;
            std::cout << "    Mana: 100" << std::endl;
            std::cout << "    Nivel: 10" << std::endl;
            std::cout << "    Arma Especial: BASTON" << std::endl;
            break;}
        case Personas::CONJURADOR :{
            std::cout << "=============================" << std::endl;
            std::cout << "Personaje elegido: Conjurador" << std::endl;
            std::cout << "=============================" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "    Vida: 250" << std::endl;
            std::cout << "    Defensa Magica: 150" << std::endl;
            std::cout << "    Defensa Fisica: 50" << std::endl;
            std::cout << "    Mana: 100" << std::endl;
            std::cout << "    Nivel: 10" << std::endl;
            std::cout << "    Arma Especial: LIBRO DE HECHIZOS" << std::endl;
            break;}
        case Personas::BRUJO :{
            std::cout << "========================" << std::endl;
            std::cout << "Personaje elegido: Brujo" << std::endl;
            std::cout << "========================" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "    Vida: 250" << std::endl;
            std::cout << "    Defensa Magica: 150" << std::endl;
            std::cout << "    Defensa Fisica: 50" << std::endl;
            std::cout << "    Mana: 100" << std::endl;
            std::cout << "    Nivel: 10" << std::endl;
            std::cout << "    Arma Especial: POCION" << std::endl;
            break;}
        case Personas::NIGROMANTE :{
            std::cout << "=============================" << std::endl;
            std::cout << "Personaje elegido: Nigromante" << std::endl;
            std::cout << "=============================" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "    Vida: 250" << std::endl;
            std::cout << "    Defensa Magica: 150" << std::endl;
            std::cout << "    Defensa Fisica: 50" << std::endl;
            std::cout << "    Mana: 100" << std::endl;
            std::cout << "    Nivel: 10" << std::endl;
            std::cout << "    Arma Especial: AMULETO" << std::endl;
            break;}
        case Personas::BARBARO :{
            std::cout << "==========================" << std::endl;
            std::cout << "Personaje elegido: Barbaro" << std::endl;
            std::cout << "==========================" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "    Vida: 300" << std::endl;
            std::cout << "    Defensa Magica: 50" << std::endl;
            std::cout << "    Defensa Fisica: 150" << std::endl;
            std::cout << "    Mana: 100" << std::endl;
            std::cout << "    Nivel: 10" << std::endl;
            std::cout << "    Arma Especial: HACHA SIMPLE" << std::endl;
            break;}
        case Personas::PALADIN :{
            std::cout << "==========================" << std::endl;
            std::cout << "Personaje elegido: Paladin" << std::endl;
            std::cout << "==========================" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "    Vida: 300" << std::endl;
            std::cout << "    Defensa Magica: 50" << std::endl;
            std::cout << "    Defensa Fisica: 150" << std::endl;
            std::cout << "    Mana: 100" << std::endl;
            std::cout << "    Nivel: 10" << std::endl;
            std::cout << "    Arma Especial: HACHA DOBLE" << std::endl;
            break;}
        case Personas::CABALLERO :{
            std::cout << "============================" << std::endl;
            std::cout << "Personaje elegido: Caballero" << std::endl;
            std::cout << "============================" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "    Vida: 300" << std::endl;
            std::cout << "    Defensa Magica: 50" << std::endl;
            std::cout << "    Defensa Fisica: 150" << std::endl;
            std::cout << "    Mana: 100" << std::endl;
            std::cout << "    Nivel: 10" << std::endl;
            std::cout << "    Arma Especial: ESPADA" << std::endl;
            break;}
        case Personas::MERCENARIO :{
            std::cout << "=============================" << std::endl;
            std::cout << "Personaje elegido: Mercenario" << std::endl;
            std::cout << "=============================" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "    Vida: 300" << std::endl;
            std::cout << "    Defensa Magica: 50" << std::endl;
            std::cout << "    Defensa Fisica: 150" << std::endl;
            std::cout << "    Mana: 100" << std::endl;
            std::cout << "    Nivel: 10" << std::endl;
            std::cout << "    Arma Especial: LANZA" << std::endl;
            break;}
        case Personas::GLADIADOR :{
            std::cout << "============================" << std::endl;
            std::cout << "Personaje elegido: Gladiador" << std::endl;
            std::cout << "============================" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "    Vida: 300" << std::endl;
            std::cout << "    Defensa Magica: 50" << std::endl;
            std::cout << "    Defensa Fisica: 150" << std::endl;
            std::cout << "    Mana: 100" << std::endl;
            std::cout << "    Nivel: 10" << std::endl;
            std::cout << "    Arma Especial: GARROTE" << std::endl;
            break;}
        default :{
            std::cout << "============================================" << std::endl;
            std::cout << "Opcion invalida, por favor intente de nuevo." << std::endl;
            std::cout << "============================================" << std::endl;
            break;}
    }
}

void mostrar_estadisticas_personajes(Personas opcion, std::shared_ptr<Personaje> clase){
    switch(opcion){
        case Personas::HECHICERO :{
            auto subclase = std::dynamic_pointer_cast<Hechicero>(clase);
            std::cout << "==================" << std::endl;
            std::cout << "Subtipo: " << subclase->get_subtipo() << std::endl;
            std::cout << "==================" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "    Vida: " << subclase->get_vida() << std::endl;
            std::cout << "    Defensa Magica: " << subclase->get_defensa_magica() << std::endl;
            std::cout << "    Defensa Fisica: " << subclase->get_defensa_fisica() << std::endl;
            std::cout << "    Mana: " << subclase->get_mana() << std::endl;
            std::cout << "    Nivel: " << subclase->get_nivel() << std::endl;
            std::cout << "    Arma Especial: " << subclase->get_arma_especial() << std::endl;
            break;}
        case Personas::CONJURADOR :{
            auto subclase = std::dynamic_pointer_cast<Conjurador>(clase);
            std::cout << "===================" << std::endl;
            std::cout << "Subtipo: " << subclase->get_subtipo() << std::endl;
            std::cout << "=============================" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "    Vida: " << subclase->get_vida() << std::endl;
            std::cout << "    Defensa Magica: " << subclase->get_defensa_magica() << std::endl;
            std::cout << "    Defensa Fisica: " << subclase->get_defensa_fisica() << std::endl;
            std::cout << "    Mana: " << subclase->get_mana() << std::endl;
            std::cout << "    Nivel: " << subclase->get_nivel() << std::endl;
            std::cout << "    Arma Especial: " << subclase->get_arma_especial() << std::endl;
            break;}
        case Personas::BRUJO :{
            std::cout << "==============" << std::endl;
            auto subclase = std::dynamic_pointer_cast<Brujo>(clase);
            std::cout << "==============" << std::endl;
            std::cout << "Subtipo: " << subclase->get_subtipo() << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "    Vida: " << subclase->get_vida() << std::endl;
            std::cout << "    Defensa Magica: " << subclase->get_defensa_magica() << std::endl;
            std::cout << "    Defensa Fisica: " << subclase->get_defensa_fisica() << std::endl;
            std::cout << "    Mana: " << subclase->get_mana() << std::endl;
            std::cout << "    Nivel: " << subclase->get_nivel() << std::endl;
            std::cout << "    Arma Especial: " << subclase->get_arma_especial() << std::endl;
            break;}
        case Personas::NIGROMANTE :{
            auto subclase = std::dynamic_pointer_cast<Nigromante>(clase);
            std::cout << "===================" << std::endl;
            std::cout << "Subtipo: " << subclase->get_subtipo() << std::endl;
            std::cout << "===================" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "    Vida: " << subclase->get_vida() << std::endl;
            std::cout << "    Defensa Magica: " << subclase->get_defensa_magica() << std::endl;
            std::cout << "    Defensa Fisica: " << subclase->get_defensa_fisica() << std::endl;
            std::cout << "    Mana: " << subclase->get_mana() << std::endl;
            std::cout << "    Nivel: " << subclase->get_nivel() << std::endl;
            std::cout << "    Arma Especial: " << subclase->get_arma_especial() << std::endl;
            break;}
        case Personas::BARBARO :{
            std::cout << "================" << std::endl;
            auto subclase = std::dynamic_pointer_cast<Barbaro>(clase);
            std::cout << "================" << std::endl;
            std::cout << "Subtipo: " << subclase->get_subtipo() << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "    Vida: " << subclase->get_vida() << std::endl;
            std::cout << "    Defensa Magica: " << subclase->get_defensa_magica() << std::endl;
            std::cout << "    Defensa Fisica: " << subclase->get_defensa_fisica() << std::endl;
            std::cout << "    Stamina: " << subclase->get_stamina() << std::endl;
            std::cout << "    Nivel: " << subclase->get_nivel() << std::endl;
            std::cout << "    Arma Especial: " << subclase->get_arma_especial() << std::endl;
            break;}
        case Personas::PALADIN :{
            auto subclase = std::dynamic_pointer_cast<Paladin>(clase);
            std::cout << "================" << std::endl;
            std::cout << "Subtipo: " << subclase->get_subtipo() << std::endl;
            std::cout << "================" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "    Vida: " << subclase->get_vida() << std::endl;
            std::cout << "    Defensa Magica: " << subclase->get_defensa_magica() << std::endl;
            std::cout << "    Defensa Fisica: " << subclase->get_defensa_fisica() << std::endl;
            std::cout << "    Stamina: " << subclase->get_stamina() << std::endl;
            std::cout << "    Nivel: " << subclase->get_nivel() << std::endl;
            std::cout << "    Arma Especial: " << subclase->get_arma_especial() << std::endl;
            break;}
        case Personas::CABALLERO :{
            auto subclase = std::dynamic_pointer_cast<Caballero>(clase);
            std::cout << "==================" << std::endl;
            std::cout << "Subtipo: " << subclase->get_subtipo() << std::endl;
            std::cout << "==================" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "    Vida: " << subclase->get_vida() << std::endl;
            std::cout << "    Defensa Magica: " << subclase->get_defensa_magica() << std::endl;
            std::cout << "    Defensa Fisica: " << subclase->get_defensa_fisica() << std::endl;
            std::cout << "    Stamina: " << subclase->get_stamina() << std::endl;
            std::cout << "    Nivel: " << subclase->get_nivel() << std::endl;
            std::cout << "    Arma Especial: " << subclase->get_arma_especial() << std::endl;
            break;}
        case Personas::MERCENARIO :{
            auto subclase = std::dynamic_pointer_cast<Mercenario>(clase);
            std::cout << "===================" << std::endl;
            std::cout << "Subtipo: " << subclase->get_subtipo() << std::endl;
            std::cout << "===================" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "    Vida: " << subclase->get_vida() << std::endl;
            std::cout << "    Defensa Magica: " << subclase->get_defensa_magica() << std::endl;
            std::cout << "    Defensa Fisica: " << subclase->get_defensa_fisica() << std::endl;
            std::cout << "    Stamina: " << subclase->get_stamina() << std::endl;
            std::cout << "    Nivel: " << subclase->get_nivel() << std::endl;
            std::cout << "    Arma Especial: " << subclase->get_arma_especial() << std::endl;
            break;}
        case Personas::GLADIADOR :{
            auto subclase = std::dynamic_pointer_cast<Gladiador>(clase);
            std::cout << "==================" << std::endl;
            std::cout << "Subtipo: " << subclase->get_subtipo() << std::endl;
            std::cout << "==================" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "    Vida: " << subclase->get_vida() << std::endl;
            std::cout << "    Defensa Magica: " << subclase->get_defensa_magica() << std::endl;
            std::cout << "    Defensa Fisica: " << subclase->get_defensa_fisica() << std::endl;
            std::cout << "    Stamina: " << subclase->get_stamina() << std::endl;
            std::cout << "    Nivel: " << subclase->get_nivel() << std::endl;
            std::cout << "    Arma Especial: " << subclase->get_arma_especial() << std::endl;
            break;}
        default :{
            std::cout << "Opcion invalida, por favor intente de nuevo." << std::endl;
            break;}
    }
}

void mostrar_estadisticas_armas(Armas_lista opcion){
    switch(opcion){         
        case Armas_lista::BASTON :{
            std::cout << "====================" << std::endl;
            std::cout << "Arma elegida: Baston" << std::endl;
            std::cout << "====================" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "    Ataque: 85" << std::endl;
            std::cout << "    Energia: 10" << std::endl;
            std::cout << "    Durabilidad: 100" << std::endl;
            std::cout << "    Nivel: 20" << std::endl;
            std::cout << "    Duracion: 0" << std::endl;
            break;
        } 
        case Armas_lista::LIBROHECHIZO :{
            std::cout << "===============================" << std::endl;
            std::cout << "Arma elegida: Libro de Hechizos" << std::endl;
            std::cout << "===============================" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "    Ataque: 85" << std::endl;
            std::cout << "    Energia: 10" << std::endl;
            std::cout << "    Durabilidad: 100" << std::endl;
            std::cout << "    Nivel: 20" << std::endl;
            std::cout << "    Duracion: 5" << std::endl;
            break;
        }
        case Armas_lista::POCION :{
            std::cout << "====================" << std::endl;
            std::cout << "Arma elegida: Pocion" << std::endl;
            std::cout << "====================" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "    Ataque: 60" << std::endl;
            std::cout << "    Energia: 5" << std::endl;
            std::cout << "    Durabilidad: 100" << std::endl;
            std::cout << "    Nivel: 20" << std::endl;
            std::cout << "    Duracion: 3" << std::endl;
            break;
        } 
        case Armas_lista::AMULETO :{
            std::cout << "=====================" << std::endl;
            std::cout << "Arma elegida: Amuleto" << std::endl;
            std::cout << "=====================" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "    Ataque: 70" << std::endl;
            std::cout << "    Energia: 8" << std::endl;
            std::cout << "    Durabilidad: 100" << std::endl;
            std::cout << "    Nivel: 20" << std::endl;
            std::cout << "    Duracion: 7" << std::endl;
            break;
        } 
        case Armas_lista::HACHA_S :{
            std::cout << "==========================" << std::endl;
            std::cout << "Arma elegida: Hacha Simple" << std::endl;
            std::cout << "==========================" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "    Ataque: 80" << std::endl;
            std::cout << "    Velocidad: 7" << std::endl;
            std::cout << "    Durabilidad: 100" << std::endl;
            std::cout << "    Nivel: 18" << std::endl;
            std::cout << "    Peso: 13" << std::endl;
            std::cout << "    Alcance: 5" << std::endl;
            break;
        } 
        case Armas_lista::HACHA_D :{
            std::cout << "=========================" << std::endl;
            std::cout << "Arma elegida: Hacha Doble" << std::endl;
            std::cout << "=========================" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "    Ataque: 90" << std::endl;
            std::cout << "    Velocidad: 10" << std::endl;
            std::cout << "    Durabilidad: 100" << std::endl;
            std::cout << "    Nivel: 25" << std::endl;
            std::cout << "    Peso: 15" << std::endl;
            std::cout << "    Alcance: 5" << std::endl;
            break;
        }
        case Armas_lista::ESPADA :{
            std::cout << "====================" << std::endl;
            std::cout << "Arma elegida: Espada" << std::endl;
            std::cout << "====================" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "    Ataque: 85" << std::endl;
            std::cout << "    Velocidad: 8" << std::endl;
            std::cout << "    Durabilidad: 100" << std::endl;
            std::cout << "    Nivel: 20" << std::endl;
            std::cout << "    Peso: 5" << std::endl;
            std::cout << "    Alcance: 7" << std::endl;
            break;
        } 
        case Armas_lista::LANZA :{
            std::cout << "===================" << std::endl;
            std::cout << "Arma elegida: Lanza" << std::endl;
            std::cout << "===================" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "    Ataque: 75" << std::endl;
            std::cout << "    Velocidad: 6" << std::endl;
            std::cout << "    Durabilidad: 100" << std::endl;
            std::cout << "    Nivel: 15" << std::endl;
            std::cout << "    Peso: 15" << std::endl;
            std::cout << "    Alcance: 10" << std::endl;
            break;
        } 
        case Armas_lista::GARROTE :{
            std::cout << "=====================" << std::endl;
            std::cout << "Arma elegida: Garrote" << std::endl;
            std::cout << "=====================" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "    Ataque: 80" << std::endl;
            std::cout << "    Velocidad: 7" << std::endl;
            std::cout << "    Durabilidad: 100" << std::endl;
            std::cout << "    Nivel: 18" << std::endl;
            std::cout << "    Peso: 10" << std::endl;
            std::cout << "    Alcance: 5" << std::endl;
            break;
        } 
        default :{
            std::cout << "============================================" << std::endl;
            std::cout << "Opcion invalida, por favor intente de nuevo." << std::endl;
            std::cout << "============================================" << std::endl;
            break;}
    }
}

std::shared_ptr<Arma> elegir_arma(Personas personaje, bool is_guerrero){
    std::shared_ptr<Personaje> pj = PersonajeFactory::crearPersonaje(personaje);
    Armas_lista arma_tipo;
    while(true){
        if (is_guerrero){
            std::shared_ptr<Guerreros> guerrero = std::dynamic_pointer_cast<Guerreros>(pj);
            std::cout << "===========================================================================" << std::endl;
            std::cout << "Su personaje es tipo Guerrero: " << guerrero->get_subtipo() << ". \nHara un 10% mas daño con armas de tipo: Armas de Combate. \nAdemas el " 
                      << guerrero->get_subtipo() << " se especializa en armas de tipo: " << guerrero->get_arma_especial() 
                      << ". \nPor lo que hacen un 15% mas de daño con la misma." << std::endl;
            std::cout << "===========================================================================" << std::endl;
            std::cout << "Elija su arma 1: " << std::endl;
            std::cout << "    Items Magicos: \n   \t[1]. Baston \n   \t[2]. Libro de hechizos \n    \t[3]. Pocion \n    \t[4]. Amuleto \n\n" 
                      << "    Armas de Combate: \n    \t[5]. Hacha Simple \n    \t[6]. Hacha Doble \n    \t[7]. Espada \n    \t[8]. Lanza \n    \t[9]. Garrote" << std::endl;
            
            std::cout << "===========================================================================" << std::endl;
            std::cout << "Inserte opcion para ver estadisticas: ";
            int n; std::cin >> n;
            if(n < 1 || n > 9) {
                Limpiar_terminal();
                std::cout << "============================================" << std::endl;
                std::cout << "Opcion invalida, por favor intente de nuevo." << std::endl;
                std::cout << "============================================" << std::endl; 
                continue;}
            arma_tipo = static_cast<Armas_lista>(n);
            Limpiar_terminal();
            mostrar_estadisticas_armas(arma_tipo);
            std::cout << "=======================================================================" << std::endl;
            std::cout << "Quiere quedarse con este arma? [1]. Si, salir. [2]. No, volver al menu." << std::endl;
            int m; std::cin >> m;
            if(m == 1) break;
            if(n != 2) {
                Limpiar_terminal();
                std::cout << "============================================" << std::endl;
                std::cout << "Opcion invalida, por favor intente de nuevo." << std::endl;
                std::cout << "============================================" << std::endl; 
                continue;}
        }
        else{
            std::shared_ptr<Magos> mago = std::dynamic_pointer_cast<Magos>(pj);
            std::cout << "===========================================================================" << std::endl;
            std::cout << "Su personaje es tipo Mago:" << mago->get_subtipo() << ". \nHara un 10% mas daño con armas de tipo: Armas de Combate. Ademas los : " 
                      << mago->get_subtipo() << " se especializan en armas de tipo: " << mago->get_arma_especial() 
                      << ". \nPor lo que hacen un 15% mas de daño con la misma." << std::endl;
            std::cout << "===========================================================================" << std::endl;
            std::cout << "Elija su arma: " << std::endl;
            std::cout << "\tItems Magicos: \n\t\t[1]. Baston \n\t\t[2]. Libro de hechizos \n\t\t[3]. Pocion \n\t\t[4]. Amuleto \n\n\tArmas de Combate: \n\t\t[5]. Hacha Simple \n\t\t[6]. Hacha Doble \n\t\t[7]. Espada \n\t\t[8]. Lanza \n\t\t[9]. Garrote" << std::endl;
            std::cout << "===========================================================================" << std::endl;
            std::cout << "Inserte opcion para ver estadisticas: ";
            int n; std::cin >> n;
            if(n < 1 || n > 9) {
                Limpiar_terminal();
                std::cout << "============================================" << std::endl;
                std::cout << "Opcion invalida, por favor intente de nuevo." << std::endl;
                std::cout << "============================================" << std::endl; 
                continue;}
            arma_tipo = static_cast<Armas_lista>(n);
            Limpiar_terminal();
            mostrar_estadisticas_armas(arma_tipo);
            std::cout << "=======================================================================" << std::endl;
            std::cout << "Quiere quedarse con este arma? [1]. Si, salir. [2]. No, volver al menu." << std::endl;
            int m; std::cin >> m;
            if(m == 1) break;
            if(n != 2) {
                Limpiar_terminal();
                std::cout << "============================================" << std::endl;
                std::cout << "Opcion invalida, por favor intente de nuevo." << std::endl;
                std::cout << "============================================" << std::endl; 
                continue;}
        }
    }
    Limpiar_terminal();
    return PersonajeFactory::crearArma(arma_tipo);
}

#endif