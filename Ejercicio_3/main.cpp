#include "Factory.h"
#include "source.cpp"

int main(){
    srand(time(0));

    std::vector<std::shared_ptr<Personaje>> guerreros;
    std::vector<std::shared_ptr<Personaje>> magos;   

    int cant_guerreros = numero_aleatorio(3, 7);
    int cant_magos = numero_aleatorio(3, 7);

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Se crearon " << cant_guerreros << " guerreros y " << cant_magos << " magos." << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    crear_personajes(guerreros, cant_guerreros, magos, cant_magos);

    imprimir_personajes(guerreros, magos);

}
