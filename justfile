CC := 'g++'

SRC_DIR := 'src'
BUILD_DIR := 'build'
EXAMPLES_DIR := 'examples'

TEST_BUILD_DIR := f'{{BUILD_DIR}}/test'
LIB_BUILD_DIR := f'{{BUILD_DIR}}/lib'
EXAMPLES_BUILD_DIR := f'{{BUILD_DIR}}/examples'

CPPFLAGS := '-std=c++14 -Wpedantic -Wall -Wextra -Werror -g -fno-omit-frame-pointer -mno-omit-leaf-frame-pointer -lGL -lGLU -lglut -lm -lX11 -O2'

# Makes so that it lists every recipe instead of running the first one
# When no command is given after "just"
set default-list := true
build-test:
    @mkdir -p '{{TEST_BUILD_DIR}}'
    @for file in `echo {{SRC_DIR}}/*.cpp`; do \
        FILE=`echo "$file" | sed "s/.*\///"`;\
        {{CC}} {{CPPFLAGS}} -c $file -o {{TEST_BUILD_DIR}}/${FILE%.cpp}.o;\
    done

    @{{CC}} {{CPPFLAGS}} {{TEST_BUILD_DIR}}/*.o -o {{TEST_BUILD_DIR}}/test
    @rm {{TEST_BUILD_DIR}}/*.o

build-example name:
    @mkdir -p '{{EXAMPLES_BUILD_DIR}}'
    @for file in `echo {{EXAMPLES_DIR}}/*.cpp`; do \
        FILE=`echo "$file" | sed "s/.*\///"`;\
        {{CC}} {{CPPFLAGS}} -c $file -o {{EXAMPLES_BUILD_DIR}}/${FILE%.cpp}.o;\
    done

    @{{CC}} {{CPPFLAGS}} {{EXAMPLES_BUILD_DIR}}/*.o -o {{EXAMPLES_BUILD_DIR}}/{{name}}
    @rm {{EXAMPLES_BUILD_DIR}}/*.o

build-lib:
    @mkdir -p '{{LIB_BUILD_DIR}}'
    @for file in `echo {{SRC_DIR}}/*.cpp`; do \
        FILE=`echo "$file" | sed "s/.*\///"`;\
        {{CC}} {{CPPFLAGS}} -c $file -o {{LIB_BUILD_DIR}}/${FILE%.cpp}.o;\
    done

    @ar rcs {{LIB_BUILD_DIR}}/libcoregl.a {{LIB_BUILD_DIR}}/*.o
    @rm {{LIB_BUILD_DIR}}/*.o

run-test: build-test
    @./{{TEST_BUILD_DIR}}/test

run-example name: (build-example name)
    @./{{EXAMPLES_BUILD_DIR}}/name

# TODO: install recipe

clean:
    @rm -rf '{{BUILD_DIR}}'