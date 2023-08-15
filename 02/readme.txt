This is a typical ret2win challenge. We must return to another function in order to win.
    - Notice how our special function is not contained within main(), but is still in the program
    - We must be sure to find main()'s return address and overwrite it with another function's address

Be sure to utilize the command 'pwn template' to structure your exploit for this challenge!

Compile: gcc 02.c -o 02 -m32 -fno-stack-protector -z execstack -no-pie -g