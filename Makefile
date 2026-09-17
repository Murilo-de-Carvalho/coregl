CC = g++

TEST_EXEC = test
CXXFLAGS = -std=c++14 -Wpedantic -Wall -Wextra -Werror -g -fno-omit-frame-pointer -mno-omit-leaf-frame-pointer -lGL -lGLU -lglut -lm -lX11 -O2
BUILD_DIR = build
SRC_DIR = src
EXAMPLES_DIR = examples

SRC_SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_SRC = $(SRC:.cpp=.o)

# TODO: Remake this
# TEST BUILD
$(EXEC): $(OBJ)
	@$(CC) $(CXXFLAGS) $(OBJ) -o $(EXEC)
	@rm *.o

%.o: %.cpp
	@$(CC) $(CXXFLAGS) -c $< -o $@

run: $(EXEC)
	@./$(EXEC)

clean:
	@rm $(EXEC)