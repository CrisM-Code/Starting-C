/*
    This program is a Key-Value Store. The user will enter commands such as 'Set', 'Get', and 'Del' in order to work
    with the store. The Keys and Values will be saved to a file possibly through encryption for persistence.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char Value[30];
} Store;

Store store[23];
int value_count = 0;



int main(void) {

    char command[5];
    char key[10];
    char text[15];
    char* end;
    int x;
    printf(">");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    sscanf(text, "%5s %10s", command, key);

    
    printf("\n%s\n", key);
    long index = strtol(key, &end, 10);
    printf("\n%li\n", index);
    //printf("Value: %s\n", store[index].Value);
    

    
    return 0;
}
