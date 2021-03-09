# Cross-compiler
CC = g++

# C building settings
CFLAGS = -O2 -std=c++14
LIBS = ``

# C++ source and object files
C_DIR = src
C_SRC = $(wildcard $(C_DIR)/*.cpp)
C_OBJ = $(C_SRC:$(C_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Object files directory
OBJ_DIR = obj
_dummy := $(shell mkdir -p obj)

# Header source files
INC_DIR = include
HEADERS_SRC = $(wildcard $(INC_DIR)/*.hpp)

# All object files
OBJ = $(C_OBJ)

# Executable kernel file
EXEC = T1-MP

.PHONY: all
all: $(EXEC)

$(EXEC): $(OBJ)
	@echo "Checking with cppcheck"
	cppcheck --enable=warning ./src
	
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
	
	@echo "Running Valgrind profiler"
	valgrind --leak-check=full ./T1-MP
	
$(OBJ_DIR)/%.o: $(C_DIR)/%.cpp $(HEADERS_SRC)
	$(CC) $(CFLAGS) -I./$(INC_DIR) -c $< -o $@
		
.PHONY: clean
clean:
	-rm -f $(EXEC) $(OBJ_DIR)/*.o

.PHONY: print
print:
	@echo C src: $(C_SRC)
	@echo Obj: $(OBJ)
	@echo Exec: $(EXEC)
	@echo Header: $(HEADERS_SRC)