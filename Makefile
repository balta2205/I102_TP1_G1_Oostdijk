CXX = g++
CXXFLAGS = -std=c++17 -Wall -g
INCLUDES = -I.

# Carpetas
SRC_DIR = .
OBJ_DIR = obj

# Archivos fuente
SRC_EJ2 = \
  $(wildcard ./Ejercicio_1/Armas/*/*.cpp) \
  $(wildcard ./Ejercicio_1/Personajes/*/*.cpp) \
  ./Ejercicio_2/Factory.cpp \
  ./Ejercicio_2/source_ej2.cpp \
  ./Ejercicio_2/main_ej2.cpp

SRC_EJ3 = \
  $(wildcard ./Ejercicio_1/Armas/*/*.cpp) \
  $(wildcard ./Ejercicio_1/Personajes/*/*.cpp) \
  ./Ejercicio_2/Factory.cpp \
  ./Ejercicio_3/source_ej3.cpp \
  ./Ejercicio_3/main_ej3.cpp

# Archivos objeto
OBJ_EJ2 = $(patsubst %.cpp,$(OBJ_DIR)/%.h,$(SRC_EJ2))
OBJ_EJ3 = $(patsubst %.cpp,$(OBJ_DIR)/%.h,$(SRC_EJ3))

# Ejecutables
BIN_EJ2 = ej2
BIN_EJ3 = ej3

all: $(BIN_EJ2) $(BIN_EJ3)

$(BIN_EJ2): $(OBJ_EJ2)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BIN_EJ3): $(OBJ_EJ3)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Regla para compilar objetos
$(OBJ_DIR)/%.cpp.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_EJ2) $(BIN_EJ3)
