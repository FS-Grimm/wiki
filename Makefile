# Compilador y flags
CXX := g++
CXXFLAGS := -ggdb3 -O2 -Wall -Wextra -std=c+++17 -Wmissing-prototypes

# Nombre del ejecutable final
TARGET := wiki

# Buscar todos los .c en el directorio actual y subdirectorios
SOURCES := $(shell find . -name "*.cpp" -not -path "./cmake-build-debug/*")
# Generar la lista de objetos correspondiente
OBJECTS := $(SOURCES:.c=.o)

# Regla por defecto
all: $(TARGET)

# Linkeo final
$(TARGET): $(OBJECTS)
	$(CXX) $(CFLAGS) -o $@ $(OBJECTS)

# Regla genérica para compilar cada .c en su .o
%.o: %.c
	$(CXX) $(CFLAGS) -c $< -o $@

# Ejecutar
run: $(TARGET)
	./$(TARGET)

# Limpieza
clean:
	rm -f $(OBJECTS) $(TARGET) core vgcore.*

.PHONY: all clean run
