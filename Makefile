# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

# Source files and object files
SRC_FILES = $(wildcard src/*.cpp src/gui/*.cpp)
OBJ_FILES = $(SRC_FILES:src/%.cpp=%.o)

# Target executable
TARGET = file_explorer

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o $(TARGET)

# Rule to build object files
%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJ_FILES) $(TARGET)

# Phony targets
.PHONY: all clean
