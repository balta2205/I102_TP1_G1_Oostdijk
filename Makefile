HEADERS = -I Ejercicio_1/Personajes/ \
          -I Ejercicio_1/Personajes/magos/ \
          -I Ejercicio_1/Personajes/guerreros/ \
          -I Ejercicio_1/Armas/ \
          -I Ejercicio_1/Armas/armas_combate/ \
          -I Ejercicio_1/Armas/items_magicos/ \
          -I . \
          -I Ejercicio_2/ \
          -I Ejercicio_3/

SRC_COMMON = Ejercicio_1/Personajes/magos/*.cpp \
             Ejercicio_1/Personajes/guerreros/*.cpp \
             Ejercicio_1/Armas/armas_combate/*.cpp \
             Ejercicio_1/Armas/items_magicos/*.cpp

SRC_EJ2 = Ejercicio_2/Factory.cpp Ejercicio_2/source_ej2.cpp
SRC_EJ3 = Ejercicio_2/Factory.cpp Ejercicio_2/source_ej2.cpp Ejercicio_3/source_ej3.cpp

ej1:
	g++ -std=c++17 -Wall -Wextra $(HEADERS) -g Ejercicio_1/main_ej1.cpp $(SRC_COMMON) -o ejercicio1
	./ejercicio1

ej2:
	g++ -std=c++17 -Wall -Wextra $(HEADERS) -g Ejercicio_2/main_ej2.cpp $(SRC_COMMON) $(SRC_EJ2) -o ejercicio2
	./ejercicio2

ej3:
	g++ -std=c++17 -Wall -Wextra $(HEADERS) -g Ejercicio_3/main_ej3.cpp $(SRC_COMMON) $(SRC_EJ3) -o ejercicio3
	./ejercicio3

clean:
	rm -f ejercicio1 ejercicio2 ejercicio3
	rm -rf *.dSYM/
