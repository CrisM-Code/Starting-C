/*
    This program is a Key-Value Store. The user will enter commands such as 'Set', 'Get', and 'Del' in order to work
    with the store. The Keys and Values will be saved to a file possibly through encryption for persistence.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fp;


typedef struct {
    char Value[30];
    char key[10];
} Store;

Store store[23];
int value_count = 0;

//Hash function to turn the Key into an index number for array reference
unsigned int hash_function(char *name) {
    int length = strlen(name);
    unsigned int count = 0;
    for (int i = 0; i < length; i++){
        count += name[i];
        count = count%23;
    }
    return count;
}

void load_values();

char command[4];
char text[15];
char key2[10];

int main(void) {

    load_values();
    
    while (1) {
        printf(">");
        fgets(text, sizeof(text), stdin);
        text[strcspn(text, "\n")] = '\0';

        if (strcmp(text, "quit")==0) {
            printf("Exiting Program...\n");
            break;
        }

        sscanf(text, "%3s %9s", command, key2);

        if (strcmp(command, "get") == 0) {
            int index = hash_function(key2);
            printf("%s", store[index].Value);
        } 
        else if (strcmp(command, "set") == 0) {
            if (value_count >= 23) {
                printf("Storage is full!\n");
                break;
            }
            
            int index = hash_function(key2);
            printf("Enter a Value: ");
            fgets(store[index].Value, sizeof(store[index].Value), stdin);
            printf("Value has been saved!\n");
            value_count++;
            strcpy(store[index].key, key2);
            fp = fopen("KeyValue.txt", "w");
            for (int i = 0; i < 23; i++) {
                fprintf(fp, "Key: %s Value: %s\n", store[i].key, store[i].Value);
            }
            fclose(fp);
        } 
        else if (strcmp(command, "del")==0) {
            int index = hash_function(key2);
            strcpy(store[index].Value, "Empty\n");
            fp = fopen("KeyValue.txt", "w");
            for (int i = 0; i < value_count; i++) {
                fprintf(fp, "Key: %s Value: %s\n", key2, store[index].Value);
            }
            fclose(fp);
        } 
        else if (strcmp(text, "help")==0) {
            printf("==== Help Menu ====\n\nset: enter set <key> and you will be able to enter a value to store\n");
            printf("get: enter get <key> and the value associated with the key will be returned.\n");
            printf("del: enter del <key> and the value associated with the key will be deleted.\n");
        } else {
            printf("Error!\n");
        }
    }
    
    

    
    return 0;
}

void load_values() {
    fp = fopen("KeyValue.txt", "r");
    char line[40];
    for (int j = 0; j < 23; j++) {
        while (fgets(line, sizeof(line), fp) && value_count < 23) {
            sscanf(line, "Key: %9s Value: %29s[^\n]\n", key2, store[value_count].Value);
            value_count++;
        }
    }
    fclose(fp);

}