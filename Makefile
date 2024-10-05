# Nome do executável
TARGET = bin/engine

# Compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -Wall -std=c++17

# Diretórios
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin
LIB_DIR = /usr/local/lib

# Bibliotecas
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lglfw -lGLEW -lGL -lm

# Arquivos fonte (todos os arquivos .cpp da pasta src/)
SRCS = $(shell find $(SRC_DIR) -name '*.cpp')

# Arquivos objeto gerados a partir dos fontes
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Regra padrão
all: $(BIN_DIR) $(TARGET)

# Cria o diretório bin se não existir
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Regra para compilar o projeto
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -L$(LIB_DIR) -o $@ $^ $(LIBS)

# Regra para compilar arquivos .cpp e garantir que os diretórios do obj sejam criados
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)  # Cria os diretórios necessários
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Limpeza dos arquivos objetos e do executável
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Regra para rodar o programa
run: $(TARGET)
	./$(TARGET)
