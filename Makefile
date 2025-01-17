# Define the directories
BIN_DIR = bin
BUILD_DIR = build
INCLUDE_DIR = include
SRC_DIR = src

# Define the source files
SRCS = main.cpp $(wildcard $(SRC_DIR)/*.cpp)

# Define the object files in the build directory
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Define the executable
EXEC = $(BIN_DIR)/main

# Define the compiler and flags
CXX = g++
CXX_FLAGS = -Wall -Wextra -Werror -O2 -std=c++17 -I$(INCLUDE_DIR)

# Define the build rules
all: $(EXEC)

# Rule to link the executable
$(EXEC): $(OBJS)
	$(CXX) -o $@ $^

# Rule to compile object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)  # Create build directory if it doesn't exist
	$(CXX) -c $(CXX_FLAGS) -o $@ $<

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(BUILD_DIR)  # Create build directory if it doesn't exist
	$(CXX) -c $(CXX_FLAGS) -o $@ $<

# Clean up
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
	mkdir -p $(BUILD_DIR) $(BIN_DIR)


# Run the server
run: $(EXEC)
	./$(EXEC)

.PHONY: all clean run
