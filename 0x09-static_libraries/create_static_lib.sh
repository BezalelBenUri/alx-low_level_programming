#!/bin/bash

# Compile all .c files into object files
gcc -Wall -Werror -Wextra -pedantic -c *.c

# Create the static library from the object files
ar rcs liball.a *.o

# Clean up the object file
rm -f *.o
