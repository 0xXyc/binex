#include <stdio.h>
#include <string.h>

const char* hacked()
{
    const char* local_flag = {"XYC{H0wD1d1G3tH3r3?!}"};

    printf("This is a secret function.\n");
    printf("Access level 0 is required. All attempts to access will be logged.\n");
    printf("Oh yeah, here's your flag: %s\n", local_flag);

    return local_flag;

}

char * flag = "XYC{H0wD1d1G3tH3r3?!}";

int main()
{

    char code[16];
    int access = 0;

    printf("Please enter the secret code: \n");
    gets(code);
    fflush(stdout);

    if(strcmp(code, "1337") == 0)
    {
        flag = hacked();

        access = 1;
    }

    else
    {
        printf("Access denied, silent alarm has been triggered!\n");
    }

    if(access)
    {
        printf("Authentication successful as root (access level=%d) \n", access);
        printf("You are root, granting access... \nAccess granted, welcome root.\n");
        printf("Wow, you realized we could overflow the buffer and you could still get the flag? Nice.\nHere's your flag: %s", flag);
    }

    else
    {
        printf("Authentication failed as root (access level=%d)\n", access);
    }

    return 0;

}