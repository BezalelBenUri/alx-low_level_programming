#!/bin/bash

# Get the list of all .c files in the current directory
c_files=$(find . -name "*.c")

# Create a dynamic library called liball.so
gcc -fPIC -shared -o liball.so $c_files

# Print a success message
echo "Successfully created liball.so"
