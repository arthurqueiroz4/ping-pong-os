# Nome do executável ou arquivo principal
TARGET = main

# Diretórios
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Fontes e objetos
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Regras padrão
all: $(BIN_DIR)/$(TARGET)

# Linkagem final
$(BIN_DIR)/$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

# Compilação de cada arquivo .c em .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos gerados
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Executa o binário gerado
run: all
	./$(BIN_DIR)/$(TARGET)

# Regra para testes (você pode customizar isso)
test: $(BIN_DIR)/$(TARGET)
	@echo "Rodando testes..."

.PHONY: all clean run test

