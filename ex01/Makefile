CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX98FLAGS = -std=c++98
SRC_DIR = src
INC_DIR = include
# List of source files in the source directory
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
# Executable name and the main source file
EXECUTABLE = phonebook
MAIN = main.cpp

# Additional include and library paths
INCLUDE = -I/usr/include/c++/11 -I/usr/include/x86_64-linux-gnu/c++/11
LIB_PATH = -L /usr/lib/gcc/x86_64-linux-gnu/11

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRCS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -I$(INC_DIR) $^ -o $@ $(LIB_PATH)

.PHONY: clean
clean:
	rm -rf $(EXECUTABLE)

.PHONY: re
re: clean all

.PHONY: fclean
fclean: clean