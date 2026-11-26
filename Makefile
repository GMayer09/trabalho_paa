# Compilador e flags
CXX = g++
# -Iinclude aponta para a pasta de headers (#include "sorts.hpp")
CXXFLAGS = -Wall -Wextra -O2 -std=c++17 -Iinclude

# Pastas e nome do executável
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
TARGET = $(BUILD_DIR)/programa

# Arquivos fonte e headers
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
HDRS = $(wildcard $(INC_DIR)/*.hpp)

# Regra principal
all: $(TARGET)

# Compilação direta de todos os .cpp para o binário dentro de build/ (sem .o e sem .d)
$(TARGET): $(SRCS) $(HDRS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(SRCS)

# Cria a pasta build/ se não existir
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compila e executa
run: all
	./$(TARGET)

# Limpa a pasta build e o binário gerado
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all run clean