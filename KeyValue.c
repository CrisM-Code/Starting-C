/*
    This program is a Key-Value Store. The user will enter commands such as 'Set', 'Get', and 'Del' in order to work
    with the store. The Keys and Values will be saved to a file for persistence.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fp;


typedef struct {
    char Value[30];
    char key[10];
    int index;
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
int find_key(char *key);

char command[5];
char text[15];
char key2[10];
int used[23] = {0};

int main(void) {

    load_values();
    
    while (1) {

        //Gets the user input
        printf(">");
        fgets(text, sizeof(text), stdin);
        text[strcspn(text, "\n")] = '\0';

        //If user enters 'quit' then the program will stop
        if (strcmp(text, "quit")==0) {
            printf("Exiting Program...\n");
            break;
        }

        //This scans the input and assigns values
        sscanf(text, "%3s %9s", command, key2);

        //If the user enters the get function then they can retrieve the value
        if (strcmp(command, "get") == 0) {
            int idx = find_key(key2);

            if (idx == -1)
                printf("Key not found\n");
            else
                printf("%s\n", store[idx].Value);
        } 

        //If the user enters the set function then they can set a value to a key
        else if (strcmp(command, "set") == 0) {

            //This checks if the storage is full
            if (value_count >= 23) {
                printf("Storage is full!\n");
                break;
            }
            
            //First, this turns the key into a hash number. That number will be the array index
            int index = hash_function(key2);

            //Second, it asks the user to enter a value. That value will get saved to the store struct
            for (int x = 0; x < 23; x++) {
                int idx = (index + x) % 23;

                if (used[idx] != 1) {
                    store[idx].index = idx;
                    printf("Enter a Value: ");
                    fgets(store[idx].Value, sizeof(store[idx].Value), stdin);
                    store[idx].Value[strcspn(store[idx].Value, "\n")] = '\0';
                    used[idx] = 1;

                    //Third, it prints value has been saved and increments the value count
                    printf("Value has been saved!\n");
                    value_count++;
                    
                    //This line will copy the key to the store struct
                    strcpy(store[idx].key, key2);
                    fp = fopen("KeyValue.txt", "a");
                    
                    fprintf(fp, "Index: %i Key: %s Value: %s\n", store[idx].index, store[idx].key, store[idx].Value);
                    
                    fclose(fp);
                    break;

                }
            }
        } 

        //The del command will assign the users value with 2 to mark it has been used previously but is now open
        else if (strcmp(command, "del")==0) {


            int idx = find_key(key2);

            if (idx == -1) {
                printf("Key not found\n");
                continue;
            }

            used[idx] = 2;          // tombstone
            store[idx].Value[0] = '\0';
            store[idx].key[0] = '\0';

            value_count--;

            printf("Deleted\n");

            // Rewrite file
            fp = fopen("KeyValue.txt", "w");

            for (int i = 0; i < 23; i++) {
                if (used[i] == 1) {
                    fprintf(fp, "Index: %i Key: %s Value: %s\n",
                        i, store[i].key, store[i].Value);
                }
            }

            fclose(fp);


        } 
        else {

            //In case the user enters something that is not part of the program
            printf("Error!\n");
        }
    }
    
    return 0;
}

//Scans the file and recreates it for persistence
void load_values() {
    fp = fopen("KeyValue.txt", "r");
    char line[40];
    int idx;
    char text[15];
    char key[10];

    while (fgets(line, sizeof(line), fp) && value_count < 23) {
        sscanf(line, "Index: %i Key: %9s Value: %29[^\n]\n", &idx, key, text);
        store[idx].index = idx;
        strcpy(store[idx].key, key);
        strcpy(store[idx].Value, text);
        used[idx] = 1;
        value_count++;
    }
    fclose(fp);

}

//Finds the index for the key
int find_key(char *key) {
    int start = hash_function(key);

    for (int i = 0; i < 23; i++) {
        int idx = (start + i) % 23;

        if (used[idx] == 0)
            return -1;

        if (used[idx] == 1 && strcmp(store[idx].key, key) == 0)
            return idx;
    }
    return -1;
}