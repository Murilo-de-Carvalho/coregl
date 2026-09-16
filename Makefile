CC = g++

EXEC = core
CXXFLAGS = -std=c++14 -Wpedantic -Wall -Wextra -Werror -g -fno-omit-frame-pointer -mno-omit-leaf-frame-pointer -lGL -lGLU -lglut -lm -lX11 -O2
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

# MAIN BUILD
$(EXEC): $(OBJ)
	@$(CC) $(CXXFLAGS) $(OBJ) -o $(EXEC)
	@rm *.o

%.o: %.cpp
	@$(CC) $(CXXFLAGS) -c $< -o $@

run: $(EXEC)
	@./$(EXEC)

clean:
	@rm $(EXEC)