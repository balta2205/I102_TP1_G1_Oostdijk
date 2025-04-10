# Compilador y flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

# Buscar todos los .cpp en subdirectorios
SRCS := $(shell find Ejercicio_2 Ejercicio_3 -name "*.cpp")

# Ejecutable
TARGET = juego

# Incluir todos los directorios con headers
INCLUDES := $(shell find Ejercicio_2 Ejercicio_3 -type d -printf "-I%s ")

# Regla principal
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

# Limpieza
clean:
	rm -f $(TARGET)
