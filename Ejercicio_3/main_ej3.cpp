#include "source_ej3.h"

int main(){
    int n, m; 
    bool opcion_invalida = false, is_guerrero = true;
    std::string tipo_enemigo;
    Personas opcion = Personas::null;
    srand(time(0));
    
    // Inicio de simulacion, se elige personaje.
    while(true){ 
        Limpiar_terminal();

        if(opcion_invalida) {
            std::cout << "============================================" << std::endl;
            std::cout << "Opcion invalida, por favor intente de nuevo." << std::endl;
            std::cout << "============================================" << std::endl;
        }
        else {
            std::cout << "======================================" << std::endl;
            std::cout << "Bienvenido a la batalla de personajes!" << std::endl;
            std::cout << "======================================" << std::endl;
        }

        mostrar_personajes(opcion);
        std::cin >> n;
        if(n == 10) {std::cout << "Gracias por jugar!" << std::endl; return 0;}
        if(n > 1 && n < 5) is_guerrero = false;
        opcion = static_cast<Personas>(n);
        if(n < 1 || n > 10) {opcion_invalida = true; continue;}

        Limpiar_terminal();
        mostrar_estadisticas_personajes(opcion);
        std::cout << "============================================================================" << std::endl;
        std::cout << "Quiere quedarse con este personaje? [1]. Si, salir. [2]. No, volver al menu." << std::endl;
        std::cin >> m;
        if(m == 1) {Limpiar_terminal(); break;} 
        else {n = 0; opcion_invalida = false; continue;}
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Seleccion de armas
    std::unique_ptr<Arma> amigo_arma1 = elegir_arma(opcion, is_guerrero); 
    std::unique_ptr<Arma> amigo_arma2;
    Limpiar_terminal();
    while(true){
        std::cout << "====================================================" << std::endl;
        std::cout << "Arma 1: " << amigo_arma1->get_subtipo() << std::endl;
        std::cout << "====================================================" << std::endl;
        std::cout << "\nElija su segundo arma, no puede ser igual al arma 1. " << std::endl;
        amigo_arma2 = elegir_arma(opcion, is_guerrero);
        if (amigo_arma1->get_subtipo() == amigo_arma2->get_subtipo()){
            Limpiar_terminal();
            std::cout << "=============================================" << std::endl;
            std::cout << "Arma 1 y Arma 2 son iguales, elija otra arma." << std::endl; 
            std::cout << "=============================================" << std::endl;
            continue;}
        else {Limpiar_terminal(); break;}
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Imprimir todo sobre el amigo
    std::pair<std::unique_ptr<Arma>, std::unique_ptr<Arma>> amigo_par = {std::move(amigo_arma1), std::move(amigo_arma2)};
    std::shared_ptr<Personaje> amigo = PersonajeFactory::crearPersonajeArmado(opcion, {std::move(amigo_par.first), std::move(amigo_par.second)});

    if(amigo->get_tipo() == "Mago"){
        std::cout << "==================================" << std::endl;
        std::cout << "Tu personaje seleccionado es: " << amigo->get_tipo() << std::endl;
        std::cout << "==================================" << std::endl;
        mostrar_estadisticas_personajes(opcion, amigo);
        std::cout << "    Arma 1: " << amigo->get_armas().first->get_subtipo();
        if(amigo->get_armas().first->get_tipo() == "Item Magico") std::cout << " (+10% de daño)";
        if(amigo->get_arma_especial() == amigo->get_armas().first->get_subtipo()) std::cout << " (+5% de daño)";
        else std::cout << std::endl;
        std::cout << "\n    Arma 2: " << amigo->get_armas().second->get_subtipo();
        if(amigo->get_armas().second->get_tipo() == "Item Magico") std::cout << " (+10% de daño)";
        if(amigo->get_arma_especial() == amigo->get_armas().second->get_subtipo()) std::cout << " (+5% de daño)" << std::endl;
    }
    else{
        std::cout << "======================================" << std::endl;
        std::cout << "Tu personaje seleccionado es: " << amigo->get_tipo() << std::endl;
        std::cout << "======================================" << std::endl;
        mostrar_estadisticas_personajes(opcion, amigo);
        std::cout << "    Arma 1: " << amigo->get_armas().first->get_subtipo();
        if(amigo->get_armas().first->get_tipo() == "Armas de Combate") std::cout << " (+10% de daño)";
        if(amigo->get_arma_especial() == amigo->get_armas().first->get_subtipo()) std::cout << " (+5% de daño)";
        else std::cout << std::endl;
        std::cout << "\n    Arma 2: " << amigo->get_armas().second->get_subtipo();
        if(amigo->get_armas().second->get_tipo() == "Armas de Combate") std::cout << " (+10% de daño)";
        if(amigo->get_arma_especial() == amigo->get_armas().second->get_subtipo()) std::cout << " (+5% de daño)" << std::endl;
    }
    std::cout << "\n=============================================" << std::endl;
    std::cout << "Desea continuar al enemigo? [1]. Si, [2]. No." << std::endl;
    std::cin >> m;
    if(m == 2) {std::cout << "Gracias por jugar!" << std::endl; return 0;}
    Limpiar_terminal();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Imprimir todo sobre el enemigo
    std::unique_ptr<Arma> enemigo_arma1 = nullptr; std::unique_ptr<Arma> enemigo_arma2 = nullptr;
    std::shared_ptr<Personaje> enemigo = nullptr;
    m = numero_aleatorio(1,2);
    if(m == 1){
        std::cout << "==========================" << std::endl;
        std::cout << "El enemigo es un Guerrero!" << std::endl;
        std::cout << "==========================" << std::endl;
        enemigo_arma1 = random_arma();
        enemigo_arma2 = random_arma();
        enemigo = random_personaje_guerrero({std::move(enemigo_arma1), std::move(enemigo_arma2)});
        tipo_enemigo = enemigo->get_tipo();
    }
    else{
        std::cout << "======================" << std::endl;
        std::cout << "El enemigo es un Mago!" << std::endl;
        std::cout << "======================" << std::endl;
        enemigo_arma1 = random_arma();
        enemigo_arma2 = random_arma();
        if (enemigo_arma1->get_subtipo() == enemigo_arma2->get_subtipo()){
            enemigo_arma2 = random_arma();
        }
        enemigo = random_personaje_mago({std::move(enemigo_arma1), std::move(enemigo_arma2)});
        tipo_enemigo = enemigo->get_tipo();
    }

    if(tipo_enemigo == "Mago") {
        std::cout << "El enemigo de tipo Mago: " << enemigo->get_subtipo() << ", tiene las siguientes estadisticas: " << std::endl;
        Personas opcion = string_a_persona(enemigo->get_subtipo());
        mostrar_estadisticas_personajes(opcion, enemigo);
        std::cout << "\tArma 1: " << enemigo->get_armas().first->get_subtipo();
        if(enemigo->get_armas().first->get_tipo() == "Item Magico") std::cout << " (+10% de daño)";
        if(enemigo->get_arma_especial() == enemigo->get_armas().first->get_subtipo()) std::cout << " (+5% de daño)";
        else std::cout << std::endl;
        std::cout << "\tArma 2: " << enemigo->get_armas().second->get_subtipo();
        if(enemigo->get_armas().second->get_tipo() == "Item Magico") std::cout << " (+10% de daño)";
        if(enemigo->get_arma_especial() == enemigo->get_armas().second->get_subtipo()) std::cout << " (+5% de daño)";
        
    }
    else {
        std::cout << "El enemigo de tipo Guerrero: " << enemigo->get_subtipo() << " tiene las siguientes estadisticas: " << std::endl;
        Personas opcion = string_a_persona(enemigo->get_subtipo());
        mostrar_estadisticas_personajes(opcion, enemigo);
        std::cout << "\tArma 1: " << enemigo->get_armas().first->get_subtipo();
        if(enemigo->get_armas().first->get_tipo() == "Armas de Combate") std::cout << " (+10% de daño)";
        if(enemigo->get_arma_especial() == enemigo->get_armas().first->get_subtipo()) std::cout << " (+5% de daño)";
        else std::cout << std::endl;
        std::cout << "\tArma 2: " << enemigo->get_armas().second->get_subtipo();
        if(enemigo->get_armas().second->get_tipo() == "Armas de Combate") std::cout << " (+10% de daño)";
        if(enemigo->get_arma_especial() == enemigo->get_armas().second->get_subtipo()) std::cout << " (+5% de daño)" << std::endl;
    } 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Enfrentamiento
    std::cout << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Desea continuar a la batalla? [1]. Si, [2]. No." << std::endl;
    std::cin >> m;
    if(m == 2) {std::cout << "Gracias por jugar!" << std::endl; return 0;}
    Limpiar_terminal();
    std::cout << "==========================" << std::endl;
    std::cout << "REGLAS DEL ENFRENTAMIENTO:" << std::endl;
    std::cout << "==========================" << std::endl;
    std::cout << "Cada personaje tiene 3 movimientos: Golpe Fuerte, Golpe Rapido y Defensa Golpe." << std::endl;
    std::cout << "     El “Golpe Fuerte” le gana al “Golpe Rápido”." << std::endl;
    std::cout << "     El “Golpe Rápido” le gana a la “Defensa y Golpe”." << std::endl;
    std::cout << "     El “Defensa y Golpe” le gana al “Golpe Fuerte”." << std::endl;
    std::cout << "     En caso de que los dos personajes realicen la misma acción, ningún personaje recibirá daño y se pasa a la siguiente ronda de elección." << std::endl;
    std::cout << "\nEl personaje que llegue a 0 de vida pierde." << std::endl;
    std::cout << "===========================================" << std::endl;
    std::cout << "Desea dar inicio a la batalla? [1]. Si, [2]. No." << std::endl;
    std::cin >> m;
    if(m == 2) {std::cout << "Gracias por jugar!" << std::endl; return 0;}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Inicio del enfrentamiento
    Ataques ataque_amigo = Ataques::null;
    Limpiar_terminal();
    std::cout << "====================" << std::endl;
    std::cout << "Comienza la batalla!" << std::endl;
    std::cout << "====================" << std::endl;
    do{
        if(ataque_amigo != Ataques::null){
            std::cout << "====================" << std::endl;
            std::cout << "Siguiente ronda....." << std::endl;
            std::cout << "====================" << std::endl;
        }
        std::cout << "======MARCADOR======" << std::endl;
        std::cout << "Amigo: " << amigo->get_vida() << std::endl;
        std::cout << "Enemigo: " << enemigo->get_vida() << std::endl;
        std::cout << "====================" << std::endl;
        std::cout << "Elija su ataque: [1]. Golpe Fuerte, [2]. Golpe Rapido, [3]. Defensa Golpe. Elige: ";
        int a; std::cin >> a;
        std::cout << std::endl;
        std::cout << "===================================================================================";
        if(a < 1 || a > 3) {std::cout << "\nOpcion invalida, por favor intente de nuevo.\n" << std::endl; continue;}
        ataque_amigo = static_cast<Ataques>(a);
        std::cout << "\nEl amigo ha elegido: ";
        switch(ataque_amigo){
            case Ataques::GOLPE_FUERTE :{
                std::cout << "Golpe Fuerte" << std::endl;
                break;}
            case Ataques::GOLPE_RAPIDO :{
                std::cout << "Golpe Rapido" << std::endl;
                break;}
            case Ataques::DEFENSA_GOLPE :{
                std::cout << "Defensa Golpe" << std::endl;
                break;}
            default :{
                std::cout << "Opcion invalida, por favor intente de nuevo." << std::endl;
                continue;}
        }
        Ataques ataque_enemigo = random_ataque_enemigo();
        std::cout << "El enemigo ha elegido: "; 
        switch(ataque_enemigo){
            case Ataques::GOLPE_FUERTE :{
                std::cout << "Golpe Fuerte" << std::endl;
                break;}
            case Ataques::GOLPE_RAPIDO :{
                std::cout << "Golpe Rapido" << std::endl;
                break;}
            case Ataques::DEFENSA_GOLPE :{
                std::cout << "Defensa Golpe" << std::endl;
                break;}
            default :{
                std::cout << "Opcion invalida, por favor intente de nuevo." << std::endl;
                continue;}
        }
        std::cout << "===================================================================================\n" << std::endl;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Resultados de la ronda
        std::shared_ptr<Personaje> ganador = definir_ganador(amigo, enemigo, ataque_amigo, ataque_enemigo);

        if(ganador == nullptr){
            std::cout << "Ambos contrincantes han realizado el mismo ataque, ¡HAY EMPATE!. Siguiente ronda." << std::endl;
            continue;
        }
        else if(ganador == amigo){
            switch(ataque_amigo){
                case Ataques::GOLPE_FUERTE :{
                    std::cout << "¡¡El amigo ha realizado un Golpe Fuerte con " << amigo->get_armas().first->get_subtipo() << " mientras que el enemigo ha realizado un Golpe Rapido!!" << std::endl;
                    
                    if(amigo->get_armas().first->get_tipo() == "Armas de Combate" && amigo->get_tipo() == "Guerrero") {
                        if(amigo->get_arma_especial() == amigo->get_armas().first->get_subtipo()) {
                            std::cout << "Daño extra por arma especial: x1.15" << std::endl;
                            std::cout << "El enemigo ha recibido " << amigo->get_armas().first->get_ataque()*1.15 << " de daño." << std::endl;
                            enemigo->set_vida(enemigo->get_vida() - amigo->get_armas().first->get_ataque()*1.15);
                        }
                        else {
                            std::cout << "Daño extra por arma especial: x1.1" << std::endl;
                            std::cout << "El enemigo ha recibido " << amigo->get_armas().first->get_ataque()*1.1 << " de daño." << std::endl;
                            enemigo->set_vida(enemigo->get_vida() - amigo->get_armas().first->get_ataque()*1.1);
                        }
                    }
                    else if(amigo->get_armas().first->get_tipo() == "Item Magico" && amigo->get_tipo() == "Mago") {
                        if(amigo->get_arma_especial() == amigo->get_armas().first->get_subtipo()) {
                            std::cout << "Daño extra por arma especial: x1.15" << std::endl;
                            std::cout << "El enemigo ha recibido " << amigo->get_armas().first->get_ataque()*1.15 << " de daño." << std::endl;
                            enemigo->set_vida(enemigo->get_vida() - amigo->get_armas().first->get_ataque()*1.15);
                        }
                        else {
                            std::cout << "Daño extra por arma especial: x1.1" << std::endl;
                            std::cout << "El enemigo ha recibido " << amigo->get_armas().first->get_ataque()*1.1 << " de daño." << std::endl;
                            enemigo->set_vida(enemigo->get_vida() - amigo->get_armas().first->get_ataque()*1.1);
                        }
                    }
                    else {
                        std::cout << "El enemigo ha recibido " << amigo->get_armas().first->get_ataque() << " de daño." << std::endl;
                        enemigo->set_vida(enemigo->get_vida() - amigo->get_armas().first->get_ataque());
                    }
                    break;}
                case Ataques::GOLPE_RAPIDO :{
                    std::cout << "¡¡El amigo ha realizado un Golpe Rapido con " << amigo->get_armas().first->get_subtipo() << " mientras que el enemigo ha realizado un Defensa Golpe!!" << std::endl;
                    std::cout << "El enemigo ha recibido " << amigo->get_armas().second->get_ataque() << " de daño." << std::endl;
                    if(amigo->get_armas().first->get_tipo() == "Armas de Combate" && amigo->get_tipo() == "Guerrero") {
                        if(amigo->get_arma_especial() == amigo->get_armas().first->get_subtipo()) {
                            std::cout << "Daño extra por arma especial: x1.15" << std::endl;
                            std::cout << "El enemigo ha recibido " << amigo->get_armas().first->get_ataque()*1.15 << " de daño." << std::endl;
                            enemigo->set_vida(enemigo->get_vida() - amigo->get_armas().first->get_ataque()*1.15);
                        }
                        else {
                            std::cout << "Daño extra por arma especial: x1.1" << std::endl;
                            std::cout << "El enemigo ha recibido " << amigo->get_armas().first->get_ataque()*1.1 << " de daño." << std::endl;
                            enemigo->set_vida(enemigo->get_vida() - amigo->get_armas().first->get_ataque()*1.1);
                        }
                    }
                    else if(amigo->get_armas().first->get_tipo() == "Item Magico" && amigo->get_tipo() == "Mago") {
                        if(amigo->get_arma_especial() == amigo->get_armas().first->get_subtipo()) {
                            std::cout << "Daño extra por arma especial: x1.15" << std::endl;
                            std::cout << "El enemigo ha recibido " << amigo->get_armas().first->get_ataque()*1.15 << " de daño." << std::endl;
                            enemigo->set_vida(enemigo->get_vida() - amigo->get_armas().first->get_ataque()*1.15);
                        }
                        else {
                            std::cout << "Daño extra por arma especial: x1.1" << std::endl;
                            std::cout << "El enemigo ha recibido " << amigo->get_armas().first->get_ataque()*1.1 << " de daño." << std::endl;
                            enemigo->set_vida(enemigo->get_vida() - amigo->get_armas().first->get_ataque()*1.1);
                        }
                    }
                    else {
                        std::cout << "El enemigo ha recibido " << amigo->get_armas().first->get_ataque() << " de daño." << std::endl;
                        enemigo->set_vida(enemigo->get_vida() - amigo->get_armas().first->get_ataque());
                    }
                    break;}
                case Ataques::DEFENSA_GOLPE :{
                    std::cout << "¡¡El amigo ha realizado un Defensa Golpe con " << amigo->get_armas().first->get_subtipo() << " mientras que el enemigo ha realizado un Golpe Fuerte!!" << std::endl;
                    if(amigo->get_armas().first->get_tipo() == "Armas de Combate" && amigo->get_tipo() == "Guerrero") {
                        if(amigo->get_arma_especial() == amigo->get_armas().first->get_subtipo()) {
                            std::cout << "Daño extra por arma especial: x1.15" << std::endl;
                            std::cout << "El enemigo ha recibido " << amigo->get_armas().first->get_ataque()*1.15 << " de daño." << std::endl;
                            enemigo->set_vida(enemigo->get_vida() - amigo->get_armas().first->get_ataque()*1.15);
                        }
                        else {
                            std::cout << "Daño extra por arma especial: x1.1" << std::endl;
                            std::cout << "El enemigo ha recibido " << amigo->get_armas().first->get_ataque()*1.1 << " de daño." << std::endl;
                            enemigo->set_vida(enemigo->get_vida() - amigo->get_armas().first->get_ataque()*1.1);
                        }
                    }
                    else if(amigo->get_armas().first->get_tipo() == "Item Magico" && amigo->get_tipo() == "Mago") {
                        if(amigo->get_arma_especial() == amigo->get_armas().first->get_subtipo()) {
                            std::cout << "Daño extra por arma especial: x1.15" << std::endl;
                            std::cout << "El enemigo ha recibido " << amigo->get_armas().first->get_ataque()*1.15 << " de daño." << std::endl;
                            enemigo->set_vida(enemigo->get_vida() - amigo->get_armas().first->get_ataque()*1.15);
                        }
                        else {
                            std::cout << "Daño extra por arma especial: x1.1" << std::endl;
                            std::cout << "El enemigo ha recibido " << amigo->get_armas().first->get_ataque()*1.1 << " de daño." << std::endl;
                            enemigo->set_vida(enemigo->get_vida() - amigo->get_armas().first->get_ataque()*1.1);
                        }
                    }
                    else {
                        std::cout << "El enemigo ha recibido " << amigo->get_armas().first->get_ataque() << " de daño." << std::endl;
                        enemigo->set_vida(enemigo->get_vida() - amigo->get_armas().first->get_ataque());
                    }
                    break;}
                default :{
                    std::cout << "Opcion invalida, por favor intente de nuevo." << std::endl;
                    continue;}
            }
            std::cout << "El amigo ha ganado esta ronda!\n" << std::endl;
        }
        else{
            auto arma_enemiga = enemigo->get_armas().first;
            int random = numero_aleatorio(1,2);
            if(random == 2) arma_enemiga = enemigo->get_armas().second;
            switch(ataque_enemigo){
                case Ataques::GOLPE_FUERTE :{
                    std::cout << "¡¡El enemigo ha realizado un Golpe Fuerte con " << arma_enemiga->get_subtipo() << " mientras que el amigo ha realizado un Golpe Rapido!!" << std::endl;
                    if(arma_enemiga->get_tipo() == "Armas de Combate" && enemigo->get_tipo() == "Guerrero") {
                        if(enemigo->get_arma_especial() == arma_enemiga->get_subtipo()) {
                            std::cout << "Daño extra por arma especial: x1.15" << std::endl;
                            std::cout << "El amigo ha recibido " << arma_enemiga->get_ataque()*1.15 << " de daño." << std::endl;
                            amigo->set_vida(amigo->get_vida() - arma_enemiga->get_ataque()*1.15);
                        }
                        else {
                            std::cout << "Daño extra por arma especial: x1.1" << std::endl;
                            std::cout << "El amigo ha recibido " << arma_enemiga->get_ataque()*1.1 << " de daño." << std::endl;
                            amigo->set_vida(amigo->get_vida() - arma_enemiga->get_ataque()*1.1);
                        }
                    }
                    else if(arma_enemiga->get_tipo() == "Item Magico" && enemigo->get_tipo() == "Mago") {
                        if(enemigo->get_arma_especial() == arma_enemiga->get_subtipo()) {
                            std::cout << "Daño extra por arma especial: x1.15" << std::endl;
                            std::cout << "El amigo ha recibido " << arma_enemiga->get_ataque()*1.15 << " de daño." << std::endl;
                            amigo->set_vida(amigo->get_vida() - arma_enemiga->get_ataque()*1.15);
                        }
                        else {
                            std::cout << "Daño extra por arma especial: x1.1" << std::endl;
                            std::cout << "El amigo ha recibido " << arma_enemiga->get_ataque()*1.1 << " de daño." << std::endl;
                            amigo->set_vida(amigo->get_vida() - arma_enemiga->get_ataque()*1.1);
                        }
                    }
                    else {
                        std::cout << "El amigo ha recibido " << arma_enemiga->get_ataque() << " de daño." << std::endl;
                        amigo->set_vida(amigo->get_vida() - arma_enemiga->get_ataque());
                    }
                    break;}
                case Ataques::GOLPE_RAPIDO :{
                    std::cout << "¡¡El enemigo ha realizado un Defensa Golpe con " << arma_enemiga->get_subtipo() << " mientras que el amigo ha realizado un Golpe Fuerte!!" << std::endl;
                    if(arma_enemiga->get_tipo() == "Armas de Combate" && enemigo->get_tipo() == "Guerrero") {
                        if(enemigo->get_arma_especial() == arma_enemiga->get_subtipo()) {
                            std::cout << "Daño extra por arma especial: x1.15" << std::endl;
                            std::cout << "El amigo ha recibido " << arma_enemiga->get_ataque()*1.15 << " de daño." << std::endl;
                            amigo->set_vida(amigo->get_vida() - arma_enemiga->get_ataque()*1.15);
                        }
                        else {
                            std::cout << "Daño extra por arma especial: x1.1" << std::endl;
                            std::cout << "El amigo ha recibido " << arma_enemiga->get_ataque()*1.1 << " de daño." << std::endl;
                            amigo->set_vida(amigo->get_vida() - arma_enemiga->get_ataque()*1.1);
                        }
                    }
                    else if(arma_enemiga->get_tipo() == "Item Magico" && enemigo->get_tipo() == "Mago") {
                        if(enemigo->get_arma_especial() == arma_enemiga->get_subtipo()) {
                            std::cout << "Daño extra por arma especial: x1.15" << std::endl;
                            std::cout << "El amigo ha recibido " << arma_enemiga->get_ataque()*1.15 << " de daño." << std::endl;
                            amigo->set_vida(amigo->get_vida() - arma_enemiga->get_ataque()*1.15);
                        }
                        else {
                            std::cout << "Daño extra por arma especial: x1.1" << std::endl;
                            std::cout << "El amigo ha recibido " << arma_enemiga->get_ataque()*1.1 << " de daño." << std::endl;
                            amigo->set_vida(amigo->get_vida() - arma_enemiga->get_ataque()*1.1);
                        }
                    }
                    else {
                        std::cout << "El amigo ha recibido " << arma_enemiga->get_ataque() << " de daño." << std::endl;
                        amigo->set_vida(amigo->get_vida() - arma_enemiga->get_ataque());
                    }
                    break;}
                case Ataques::DEFENSA_GOLPE :{
                    std::cout << "¡¡El enemigo ha realizado un Defensa Golpe con " << arma_enemiga->get_subtipo() << " mientras que el amigo ha realizado un Golpe Fuerte!!" << std::endl;
                    if(arma_enemiga->get_tipo() == "Armas de Combate" && enemigo->get_tipo() == "Guerrero") {
                        if(enemigo->get_arma_especial() == arma_enemiga->get_subtipo()) {
                            std::cout << "Daño extra por arma especial: x1.15" << std::endl;
                            std::cout << "El amigo ha recibido " << arma_enemiga->get_ataque()*1.15 << " de daño." << std::endl;
                            amigo->set_vida(amigo->get_vida() - arma_enemiga->get_ataque()*1.15);
                        }
                        else {
                            std::cout << "Daño extra por arma especial: x1.1" << std::endl;
                            std::cout << "El amigo ha recibido " << arma_enemiga->get_ataque()*1.1 << " de daño." << std::endl;
                            amigo->set_vida(amigo->get_vida() - arma_enemiga->get_ataque()*1.1);
                        }
                    }
                    else if(arma_enemiga->get_tipo() == "Item Magico" && enemigo->get_tipo() == "Mago") {
                        if(enemigo->get_arma_especial() == arma_enemiga->get_subtipo()) {
                            std::cout << "Daño extra por arma especial: x1.15" << std::endl;
                            std::cout << "El amigo ha recibido " << arma_enemiga->get_ataque()*1.15 << " de daño." << std::endl;
                            amigo->set_vida(amigo->get_vida() - arma_enemiga->get_ataque()*1.15);
                        }
                        else {
                            std::cout << "Daño extra por arma especial: x1.1" << std::endl;
                            std::cout << "El amigo ha recibido " << arma_enemiga->get_ataque()*1.1 << " de daño." << std::endl;
                            amigo->set_vida(amigo->get_vida() - arma_enemiga->get_ataque()*1.1);
                        }
                    }
                    else {
                        std::cout << "El amigo ha recibido " << arma_enemiga->get_ataque() << " de daño." << std::endl;
                        amigo->set_vida(amigo->get_vida() - arma_enemiga->get_ataque());
                    }
                    break;}
                default :{
                    std::cout << "Opcion invalida, por favor intente de nuevo." << std::endl;
                    continue;}
            }
            std::cout << "El enemigo ha ganado esta ronda!\n" << std::endl;
        }
    }while(amigo->get_vida() >= 0 && enemigo->get_vida() >= 0);


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Fin del enfrentamiento
    std::cout << "============MARCADOR============" << std::endl;
    if(amigo->get_vida() <= 0) {std::cout << "\tAmigo: 0" << std::endl;} else {std::cout << "\tAmigo: " << amigo->get_vida() << std::endl;}
    if(enemigo->get_vida() <= 0) {std::cout << "\tEnemigo: 0" << std::endl;} else {std::cout << "\tEnemigo: " << enemigo->get_vida() << std::endl;}
    std::cout << "================================" << std::endl;
        
    if(amigo->get_vida() <= 0) {
        std::cout << "\nEL GANADOR DEL ENFRENTAMIENTO ES EL ENEMIGO!\n" << std::endl;
    } else if(enemigo->get_vida() <= 0) {
        std::cout << "\nEL GANADOR DEL ENFRENTAMIENTO ES EL AMIGO!\n" << std::endl;
    }
    
    std::cout << "Fin del juego." << std::endl;
    std::cout << "Gracias por jugar!" << std::endl;
}   
