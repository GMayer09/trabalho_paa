# Compilador e flags
CXX = g++
# -Iinclude aponta para a pasta de headers (#include "sorts.hpp")
CXXFLAGS = -Wall -Wextra -O2 -std=c++17 -Iinclude

# Pastas e nome do executável
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

ifeq ($(OS),Windows_NT)
    TARGET = $(BUILD_DIR)/programa.exe
    MKDIR = if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
    RMDIR = if exist $(BUILD_DIR) rmdir /s /q $(BUILD_DIR)
    RUN_TARGET = $(BUILD_DIR)\programa.exe
else
    TARGET = $(BUILD_DIR)/programa
    MKDIR = mkdir -p $(BUILD_DIR)
    RMDIR = rm -rf $(BUILD_DIR)
    RUN_TARGET = ./$(TARGET)
endif

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
	$(MKDIR)

# Compila e executa
run: all
	$(RUN_TARGET)

# Limpa a pasta build e o binário gerado
clean:
	$(RMDIR)

.PHONY: all run clean
