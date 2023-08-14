Can you find out how much money you need to send to the bank to make it overflow?

This one is a bit weird... The buffer in the stack gets allocated in a strange way, so you may need to send more than you thought!

Compile: gcc 00.c -o 00 -m32 -fno-stack-protector -z execstack -no-pie -g