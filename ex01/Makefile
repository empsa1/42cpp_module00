CXX = g++
CXXFLAGS = -Wall -Wextra -Werror
CXX98FLAGS = -std=c++98

SRC_DIR = src
INC_DIR = include

# List of source files in the source directory
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Executable name and the main source file
EXECUTABLE = phonebook
MAIN = main.cpp

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRCS)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) $^ -o $@

.PHONY: clean

clean:
	rm -rf $(EXECUTABLE)

.PHONY: re

re: clean all

.PHONY: fclean

fclean: clean