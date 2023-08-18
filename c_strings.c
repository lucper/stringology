#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    /* %s -- char * 
     * %c -- int (char repr)
     * %d -- int */

    int x0 = 40;
    char x1 = 'a';
    printf("'a' = %d 'a' = %c\n40 = %d 40 = %c\n", x1, x1, x0, x0);

    unsigned char x2 = 'a';
    printf("%d %c\n", x2, x2);

    unsigned char *x3 = "teste";
    printf("%s\n", x3);

    // Illegal
    //unsigned char *x4 = {'t', 'e', 's', 't', 'e'};
    //printf("%s\n", x4);

    unsigned char x4[5] = {'t', 'e', 's', 't', 'e'};
    printf("%s\n", x4);

    printf("a %d  A %d  t %d  T %d  g %d  G %d  c %d  C %d\n", 'a', 'A', 't', 'T', 'g', 'G', 'c', 'C');

    int n = 5;
    unsigned char **x5 = malloc(n * sizeof(unsigned char*)); // matriz 2-dimensional de NÚMEROS (0..255)
    // how to construct array of 'unsigned char*'? i.e. array of strings where each char in number
    // here it is:

    char **strings;
    int total = 0;

    printf("Enter number of strings: ");
    scanf("%d", &total);

    strings = malloc(total * sizeof(char *));

    char buffer[10]; // at most 10-length strings
    int length = 0;

    while (getchar() != '\n') ; // flush input stream

    for (int i = 0; i < total; ++i) {
        fgets(buffer, 10, stdin);
        length = strlen(buffer); // e.g. buffer = "abc\n"
        buffer[length-1] = '\0'; // remove \n
        strings[i] = malloc(length * sizeof(char));
        strcpy(strings[i], buffer); // store string in allocated space
    }

    printf("Resulting strings:\n");
    for (int i = 0; i < total; ++i)
        printf("strings[%d] = %s\n", i, strings[i]);
}
