#!/usr/bin/python3
def is_palindrome(number):
    # Convert number to string and check if it reads the same forwards and backwards
    return str(number) == str(number)[::-1]

largest_palindrome = 0

# Iterate through all possible products of two 3-digit numbers
for i in range(100, 1000):
    for j in range(i, 1000):
        product = i * j
        if is_palindrome(product) and product > largest_palindrome:
            largest_palindrome = product

# Save the result to a file
with open('102-result', 'w') as file:
    file.write(str(largest_palindrome))
