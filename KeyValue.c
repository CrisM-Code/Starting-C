/*
    This program is a Key-Value Store. The user will enter commands such as 'Set', 'Get', and 'Del' in order to work
    with the store. The Keys and Values will be saved to a file possibly through encryption for persistence.
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char key[9];
    char value[50];
} Store;

Store store[23];


void user_input();
void hashfunt();

int main() {

    while (1) {
        printf(">");

    }


    return 0;
}

void user_input() {

}



