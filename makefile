# Project name
EXEC=StealthFiles2Flicks

# Directories
SRC_DIR=./src
INC_DIR=./includes
BUILD_DIR=./build

# Find all files with respective extensions
CPP_SOURCE=$(wildcard $(SRC_DIR)/*.cpp)
HPP_SOURCE=$(wildcard $(INC_DIR)/*.hpp)
BUILD=$(CPP_SOURCE:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Compiler
CC=g++

# Flags para compilação
LDFLAGS=-lopencv_core -lopencv_imgproc -lopencv_imgcodecs -lopencv_highgui -lssl -lcrypto
CC_FLAGS=-c			\
		-W 			\
		-Wall 		\
		-ansi 		\
		-pedantic 		\
		-I$(INC_DIR)

# Criação de link e execução de compilação
all: objFolder $(EXEC)

# Marca o local de geração do executável/compilado
$(EXEC): $(BUILD)
	@ echo 'Building binary using G++ linker: $@'
	$(CC) $^ -o $@ $(LDFLAGS)
	@ echo 'Finisih building binary on : $@'
	@ echo ''

$(BUILD_DIR)/%.o:  $(SRC_DIR)/%.cpp
	@ echo 'Building target using G++ compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@ $(LDFLAGS)
	@ echo ''

objFolder:
	@ mkdir -p $(BUILD_DIR)

clean:
	@ rm -rf $(BUILD_DIR)/*.o $(EXEC) *~
	@ rmdir $(BUILD_DIR)

.PHONY: all clean
