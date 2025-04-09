# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

# Executable name
TARGET = matrix_program

# Source files
SRCS = main.cpp

# Default rule: Build the program
all: $(TARGET)

# Linking step
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)