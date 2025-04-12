#include "../Ejercicio_3/Factory.h"

void Limpiar_terminal(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void mostrar_personajes(Personas elegido);

void mostrar_estadisticas_personajes(Personas opcion);

void mostrar_estadisticas_armas(Armas_lista opcion);

std::shared_ptr<Arma> elegir_arma(Personas personaje, bool is_guerrero);

int main(){
    int n, m; 
    bool opcion_invalida = false, is_guerrero = true;
    std::string tipo_enemigo;
    Personas opcion = Personas::null;
    
    while(true){ 
        Limpiar_terminal();

        if(opcion_invalida) std::cout << "Opcion invalida, por favor intente de nuevo." << std::endl;
        else std::cout << "Bienvenido a la batalla de personajes!" << std::endl;

        mostrar_personajes(opcion);
        std::cin >> n;
        if(n > 1 && n < 5) is_guerrero = false;
        opcion = static_cast<Personas>(n);
        if(n < 1 || n > 10) {opcion_invalida = true; continue;}

        Limpiar_terminal();
        mostrar_estadisticas_personajes(opcion);

        std::cout << "Quiere quedarse con este personaje? [1]. Si, salir. [2]. No, volver al menu." << std::endl;
        std::cin >> m;
        if(m == 1) {Limpiar_terminal(); break;} 
        else {n = 0; opcion_invalida = false; continue;}
    }

    std::shared_ptr<Arma> amigo_arma1 = elegir_arma(opcion, is_guerrero); 
    std::shared_ptr<Arma> amigo_arma2;
    while(true){
        Limpiar_terminal();
        std::cout << "Elija su segundo arma, no puede ser igual al arma 1. " << std::endl;
        amigo_arma2 = elegir_arma(opcion, is_guerrero);
        if (amigo_arma1->get_subtipo() == amigo_arma2->get_subtipo()){std::cout << "Arma 1 y Arma 2 son iguales, elija otra arma." << std::endl; continue;}
        else {Limpiar_terminal(); break;}
    }
    std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> amigo_par = {amigo_arma1, amigo_arma2};
    std::shared_ptr<Personaje> amigo = PersonajeFactory::crearPersonajeArmado(opcion, amigo_par);
    // IMPRIMIR TODO LO AMIGO Y PREGUNTAR DE SEGUIR AL ENEMIGO
    std::shared_ptr<Arma> enemigo_arma1 = nullptr; std::shared_ptr<Arma> enemigo_arma2 = nullptr;
    std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> enemigo_par = {enemigo_arma1, enemigo_arma2};
    std::shared_ptr<Personaje> enemigo = nullptr;
    m = numero_aleatorio(1,2);
    if(m == 1){
        std::cout << "El enemigo es un Guerrero!" << std::endl;
        enemigo_arma1 = random_arma_guerrero();
        enemigo_arma2 = random_arma_guerrero();
        enemigo_par = {enemigo_arma1, enemigo_arma2};
        enemigo = random_personaje_guerrero(enemigo_par);
        tipo_enemigo = enemigo->get_tipo();
    }
    else{
        std::cout << "El enemigo es un Mago!" << std::endl;
        enemigo_arma1 = random_arma_mago();
        enemigo_arma2 = random_arma_mago();
        enemigo_par = {enemigo_arma1, enemigo_arma2};
        enemigo = random_personaje_mago(enemigo_par);
        tipo_enemigo = enemigo->get_tipo();
    }

    if(tipo_enemigo == "Mago") {std::shared_ptr<Magos> enemigo = std::dynamic_pointer_cast<Magos>(enemigo);}
    else {std::shared_ptr<Guerreros> enemigo = std::dynamic_pointer_cast<Guerreros>(enemigo);}

    std::string subtipo = enemigo->get_subtipo();
    Limpiar_terminal();
    std::cout << subtipo << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    if(tipo_enemigo == "Guerrero"){
        switch(subtipo[0]){
            case 'B':{ // Barbaro
                std::shared_ptr<Barbaro> enemigo = std::dynamic_pointer_cast<Barbaro>(enemigo);
                break;}
            case 'P':{ // Paladin
                std::shared_ptr<Paladin> enemigo = std::dynamic_pointer_cast<Paladin>(enemigo);
                break;}
            case 'C':{ // Caballero
                std::shared_ptr<Caballero> enemigo = std::dynamic_pointer_cast<Caballero>(enemigo);
                break;}
            case 'M':{ // Mercenario
                std::shared_ptr<Mercenario> enemigo = std::dynamic_pointer_cast<Mercenario>(enemigo);
                break;}
            case 'G':{ // Gladiador
                std::shared_ptr<Gladiador> enemigo = std::dynamic_pointer_cast<Gladiador>(enemigo);
                break;}
            default:{ // Invalido
                std::cout << "Tipo de Guerrero invalido." << std::endl;
                break;} 
        }
    }
    else{
        switch(subtipo[0]){
            case 'H':{ // Hechicero
                std::shared_ptr<Hechicero> enemigo = std::dynamic_pointer_cast<Hechicero>(enemigo);
                break;}
            case 'C':{ // Conjurador
                std::shared_ptr<Conjurador> enemigo = std::dynamic_pointer_cast<Conjurador>(enemigo);
                break;}
            case 'B':{ // Brujo
                std::shared_ptr<Brujo> enemigo = std::dynamic_pointer_cast<Brujo>(enemigo);
                break;}
            case 'N':{ // Nigromante
                std::shared_ptr<Nigromante> enemigo = std::dynamic_pointer_cast<Nigromante>(enemigo);
                break;}
            default:{ // Invalido
                std::cout << "Tipo de Mago invalido." << std::endl;
                break;}
        }
    }


    std::cout << "El enemigo de tipo Mago: " << enemigo->get_subtipo() << " tiene las siguientes estadisticas: " << std::endl;
    std::cout << "\tVida: " << enemigo->get_vida() << std::endl;
    std::cout << "\tDefensa Magica: " << enemigo->get_defensa_magica() << std::endl;
    std::cout << "\tDefensa Fisica: " << enemigo->get_defensa_fisica() << std::endl;


    // if(tipo_enemigo == "Mago")std::cout << "\tMana: " << enemigo->get_mana() << std::endl;
    // else std::cout << "\tStamina: " << enemigo->get_stamina() << std::endl;


    std::cout << "\tArma Especial: " << enemigo->get_arma_especial() << std::endl;
    std::cout << "\tArma 1: " << enemigo->get_armas().first->get_subtipo() << std::endl;
    std::cout << "\tNivel: " << enemigo->get_nivel() << std::endl;
      
}

void mostrar_personajes(Personas elegido){      
    std::cout << "Elija su personaje:" << std::endl;
    std::cout << "\tMagos: " << std::endl;
    std::cout << "\t\t[1]. Hechicero \n\t\t[2]. Conjurador \n\t\t[3]. Brujo \n\t\t[4]. Nigromante" << std::endl;
    std::cout << "\tGuerreros " << std::endl;
    std::cout << "\n\t\t[5]. Barbaro \n\t\t[6]. Paladin \n\t\t[7]. Caballero \n\t\t[8]. Mercenario \n\t\t[9]. Gladiador" << std::endl;
    std::cout << "\t\t[10]. Salir, (debe estar seleccionado algun personaje) Personaje seleccionado: ";
    if(elegido == Personas::null) {std::cout << "Ninguno" << std::endl;} 
    else std::cout << "" << std::endl;
    std::cout << "Inserte opcion para ver estadisticas: ";
}

void mostrar_estadisticas_personajes(Personas opcion){
    switch(opcion){
        case Personas::HECHICERO :{
            std::cout << "Personaje elegido: Hechicero" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "\tVida: 250" << std::endl;
            std::cout << "\tDefensa Magica: 150" << std::endl;
            std::cout << "\tDefensa Fisica: 50" << std::endl;
            std::cout << "\tMana: 100" << std::endl;
            std::cout << "\tNivel: 10" << std::endl;
            std::cout << "\t Arma Especial: BASTON" << std::endl;
            break;}
        case Personas::CONJURADOR :{
            std::cout << "Personaje elegido: Conjurador" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "\tVida: 250" << std::endl;
            std::cout << "\tDefensa Magica: 150" << std::endl;
            std::cout << "\tDefensa Fisica: 50" << std::endl;
            std::cout << "\tMana: 100" << std::endl;
            std::cout << "\tNivel: 10" << std::endl;
            std::cout << "\t Arma Especial: LIBRO DE HECHIZOS" << std::endl;
            break;}
        case Personas::BRUJO :{
            std::cout << "Personaje elegido: Brujo" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "\tVida: 250" << std::endl;
            std::cout << "\tDefensa Magica: 150" << std::endl;
            std::cout << "\tDefensa Fisica: 50" << std::endl;
            std::cout << "\tMana: 100" << std::endl;
            std::cout << "\tNivel: 10" << std::endl;
            std::cout << "\t Arma Especial: POCION" << std::endl;
            break;}
        case Personas::NIGROMANTE :{
            std::cout << "Personaje elegido: Nigromante" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "\tVida: 250" << std::endl;
            std::cout << "\tDefensa Magica: 150" << std::endl;
            std::cout << "\tDefensa Fisica: 50" << std::endl;
            std::cout << "\tMana: 100" << std::endl;
            std::cout << "\tNivel: 10" << std::endl;
            std::cout << "\t Arma Especial: AMULETO" << std::endl;
            break;}
        case Personas::BARBARO :{
            std::cout << "Personaje elegido: Barbaro" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "\tVida: 300" << std::endl;
            std::cout << "\tDefensa Magica: 50" << std::endl;
            std::cout << "\tDefensa Fisica: 150" << std::endl;
            std::cout << "\tMana: 100" << std::endl;
            std::cout << "\tNivel: 10" << std::endl;
            std::cout << "\t Arma Especial: HACHA SIMPLE" << std::endl;
            break;}
        case Personas::PALADIN :{
            std::cout << "Personaje elegido: Paladin" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "\tVida: 300" << std::endl;
            std::cout << "\tDefensa Magica: 50" << std::endl;
            std::cout << "\tDefensa Fisica: 150" << std::endl;
            std::cout << "\tMana: 100" << std::endl;
            std::cout << "\tNivel: 10" << std::endl;
            std::cout << "\t Arma Especial: HACHA DOBLE" << std::endl;
            break;}
        case Personas::CABALLERO :{
            std::cout << "Personaje elegido: Caballero" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "\tVida: 300" << std::endl;
            std::cout << "\tDefensa Magica: 50" << std::endl;
            std::cout << "\tDefensa Fisica: 150" << std::endl;
            std::cout << "\tMana: 100" << std::endl;
            std::cout << "\tNivel: 10" << std::endl;
            std::cout << "\t Arma Especial: ESPADA" << std::endl;
            break;}
        case Personas::MERCENARIO :{
            std::cout << "Personaje elegido: Mercenario" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "\tVida: 300" << std::endl;
            std::cout << "\tDefensa Magica: 50" << std::endl;
            std::cout << "\tDefensa Fisica: 150" << std::endl;
            std::cout << "\tMana: 100" << std::endl;
            std::cout << "\tNivel: 10" << std::endl;
            std::cout << "\t Arma Especial: LANZA" << std::endl;
            break;}
        case Personas::GLADIADOR :{
            std::cout << "Personaje elegido: Gladiador" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "\tVida: 300" << std::endl;
            std::cout << "\tDefensa Magica: 50" << std::endl;
            std::cout << "\tDefensa Fisica: 150" << std::endl;
            std::cout << "\tMana: 100" << std::endl;
            std::cout << "\tNivel: 10" << std::endl;
            std::cout << "\t Arma Especial: GARROTE" << std::endl;
            break;}
        default :{
            std::cout << "Opcion invalida, por favor intente de nuevo." << std::endl;
            break;}
    }
}

void mostrar_estadisticas_armas(Armas_lista opcion){
    switch(opcion){         
        case Armas_lista::BASTON :{
            std::cout << "Arma elegida: Baston" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "\tAtaque: 85" << std::endl;
            std::cout << "\tEnergia: 10" << std::endl;
            std::cout << "\tDurabilidad: 100" << std::endl;
            std::cout << "\tNivel: 20" << std::endl;
            std::cout << "\tDuracion: 0" << std::endl;
        } 
        case Armas_lista::LIBROHECHIZO :{
            std::cout << "Arma elegida: Libro de Hechizos" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "\tAtaque: 85" << std::endl;
            std::cout << "\tEnergia: 10" << std::endl;
            std::cout << "\tDurabilidad: 100" << std::endl;
            std::cout << "\tNivel: 20" << std::endl;
            std::cout << "\tDuracion: 5" << std::endl;
        }
        case Armas_lista::POCION :{
            std::cout << "Arma elegida: Pocion" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "\tAtaque: 60" << std::endl;
            std::cout << "\tEnergia: 5" << std::endl;
            std::cout << "\tDurabilidad: 100" << std::endl;
            std::cout << "\tNivel: 20" << std::endl;
            std::cout << "\tDuracion: 3" << std::endl;
        } 
        case Armas_lista::AMULETO :{
            std::cout << "Arma elegida: Amuleto" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "\tAtaque: 70" << std::endl;
            std::cout << "\tEnergia: 8" << std::endl;
            std::cout << "\tDurabilidad: 100" << std::endl;
            std::cout << "\tNivel: 20" << std::endl;
            std::cout << "\tDuracion: 7" << std::endl;
        } 
        case Armas_lista::HACHA_S :{
            std::cout << "Arma elegida: Hacha Simple" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "\tAtaque: 80" << std::endl;
            std::cout << "\tVelocidad: 7" << std::endl;
            std::cout << "\tDurabilidad: 100" << std::endl;
            std::cout << "\tNivel: 18" << std::endl;
            std::cout << "\tPeso: 13" << std::endl;
            std::cout << "\tAlcance: 5" << std::endl;
        } 
        case Armas_lista::HACHA_D :{
            std::cout << "Arma elegida: Hacha Doble" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "\tAtaque: 90" << std::endl;
            std::cout << "\tVelocidad: 10" << std::endl;
            std::cout << "\tDurabilidad: 100" << std::endl;
            std::cout << "\tNivel: 25" << std::endl;
            std::cout << "\tPeso: 15" << std::endl;
            std::cout << "\tAlcance: 5" << std::endl;
        }
        case Armas_lista::ESPADA :{
            std::cout << "Arma elegida: Espada" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "\tAtaque: 85" << std::endl;
            std::cout << "\tVelocidad: 8" << std::endl;
            std::cout << "\tDurabilidad: 100" << std::endl;
            std::cout << "\tNivel: 20" << std::endl;
            std::cout << "\tPeso: 5" << std::endl;
            std::cout << "\tAlcance: 7" << std::endl;
        } 
        case Armas_lista::LANZA :{
            std::cout << "Arma elegida: Lanza" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "\tAtaque: 75" << std::endl;
            std::cout << "\tVelocidad: 6" << std::endl;
            std::cout << "\tDurabilidad: 100" << std::endl;
            std::cout << "\tNivel: 15" << std::endl;
            std::cout << "\tPeso: 15" << std::endl;
            std::cout << "\tAlcance: 10" << std::endl;
        } 
        case Armas_lista::GARROTE :{
            std::cout << "Arma elegida: Garrote" << std::endl;
            std::cout << "Estadisticas: " << std::endl;
            std::cout << "\tAtaque: 80" << std::endl;
            std::cout << "\tVelocidad: 7" << std::endl;
            std::cout << "\tDurabilidad: 100" << std::endl;
            std::cout << "\tNivel: 18" << std::endl;
            std::cout << "\tPeso: 10" << std::endl;
            std::cout << "\tAlcance: 5" << std::endl;
        } 
        default :{
            std::cout << "Opcion invalida, por favor intente de nuevo." << std::endl;
            break;}
    }
}

std::shared_ptr<Arma> elegir_arma(Personas personaje, bool is_guerrero){
    std::shared_ptr<Personaje> pj = PersonajeFactory::crearPersonaje(personaje);
    Armas_lista arma_tipo;
    while(true){
        if (is_guerrero){
            std::shared_ptr<Guerreros> guerrero = std::dynamic_pointer_cast<Guerreros>(pj);
            std::cout << "Su personaje es tipo Guerrero:" << guerrero->get_subtipo() << std::endl;
            std::cout << "Elija su arma 1: " << std::endl;
            std::cout << "\t[1]. Hacha Simple \n\t[2]. Hacha Doble \n\t[3]. Espada \n\t[4]. Lanza \n\t[5]. Garrote" << std::endl;
            std::cout << "Inserte opcion para ver estadisticas: ";
            int n; std::cin >> n;
            arma_tipo = static_cast<Armas_lista>(n + 5);
            Limpiar_terminal();
            mostrar_estadisticas_armas(arma_tipo);
            std::cout << "Quiere quedarse con este arma? [1]. Si, salir. [2]. No, volver al menu." << std::endl;
            int m; std::cin >> m;
            if(m == 1) break;
        }
        else{
            std::shared_ptr<Magos> mago = std::dynamic_pointer_cast<Magos>(pj);
            std::cout << "Su personaje es tipo Mago: " << mago->get_subtipo() << std::endl;
            std::cout << "Elija su arma: " << std::endl;
            std::cout << "\t[1]. Baston \n\t[2]. Libro de hechizos \n\t[3]. Pocion \n\t[4]. Amuleto" << std::endl;
            std::cout << "Inserte opcion para ver estadisticas: ";
            int n; std::cin >> n;
            arma_tipo = static_cast<Armas_lista>(n);
            Limpiar_terminal();
            mostrar_estadisticas_armas(arma_tipo);
            std::cout << "Quiere quedarse con este arma? [1]. Si, salir. [2]. No, volver al menu." << std::endl;
            int m; std::cin >> m;
            if(m == 1) break;
        }
    }
    Limpiar_terminal();
    return PersonajeFactory::crearArma(arma_tipo);;
}

