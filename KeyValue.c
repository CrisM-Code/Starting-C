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

//Hash function to turn the Key into an index number for array reference
unsigned int hash(const char *key) {
    unsigned int h = 0;
    while (*key) {
        h += (unsigned char)*key;  // add ASCII value
        key++;
    }
    return h;
}


int main(void) {

    char command[3];
    char key[10];
    char text[15];
    
    while (1) {
        printf(">");
        fgets(text, sizeof(text), stdin);
        text[strcspn(text, "\n")] = '\0';

        if (strcmp(text, "quit")==0) {
            printf("Exiting Program...\n");
            break;
        }

        sscanf(text, "%3s %10s", command, key);

        if (strcmp(command, "get") == 0) {
            int index = hash(key)%23;
            printf("%s", store[index].Value);
        } 
        else if (strcmp(command, "set") == 0) {
            int index = hash(key)%23;
            printf("Enter a Value: ");
            fgets(store[index].Value, sizeof(store[index].Value), stdin);
            printf("Value has been saved!\n");
            value_count++;
        } 
        else if (strcmp(command, "del")==0) {
            int index = hash(key)%23;
            strcpy(store[index].Value, "Empty");
        }
        else {
            printf("Error!\n");
        }
    }
    
    

    
    return 0;
}
