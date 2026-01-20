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

char command[4];
char text[15];
char key2[10];

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
            int index = hash_function(key2);
            printf("%s\n", store[index].Value);
            //printf("Value Count = %i\n", value_count);
        } 

        //If the user enters the set function then they can set a value to a key
        else if (strcmp(command, "set") == 0) {

            //This checks if the storage is full
            if (value_count >= 23) {
                printf("Storage is full!\n");
                //printf("Value Count = %i\n", value_count);
                break;
            }
            
            //First, this turns the key into a hash number. That number will be the array index
            int index = hash_function(key2);
            store[index].index = index;

            //Second, it asks the user to enter a value. That value will get saved to the store struct
            printf("Enter a Value: ");
            fgets(store[index].Value, sizeof(store[index].Value), stdin);
            store[index].Value[strcspn(store[index].Value, "\n")] = '\0';
            
            //Third, it prints value has been saved and increments the value count
            printf("Value has been saved!\n");
            value_count++;
            //printf("Value Count = %i\n", value_count);
            
            //This line will copy the key to the store struct
            strcpy(store[index].key, key2);
            fp = fopen("KeyValue.txt", "a");
            
            fprintf(fp, "Index: %i Key: %s Value: %s\n", store[index].index, store[index].key, store[index].Value);
            
            fclose(fp);
        } 

        //The del command will assign the users value with empty. I haven't figured out a better way yet
        //Possibly, I can use pointers and reference the unused values as NULL
        else if (strcmp(command, "del")==0) {
            int index = hash_function(key2);
            strcpy(store[index].Value, "Empty\n");
            fp = fopen("KeyValue.txt", "w");
            for (int i = 0; i < value_count; i++) {
                fprintf(fp, "Index: %i Key: %s Value: %s\n", store[value_count].index, key2, store[index].Value);
            }
            fclose(fp);
        } 

        //This prints a help menu explaining the program. Similar to a Linux or Git terminal
        else if (strcmp(text, "help")==0) {
            printf("==== Help Menu ====\n\nset: enter set <key> and you will be able to enter a value to store\n");
            printf("get: enter get <key> and the value associated with the key will be returned.\n");
            printf("del: enter del <key> and the value associated with the key will be deleted.\n");
        } else {

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

        value_count++;
    }
    fclose(fp);

    //Debugging
    /*
    printf("Parsed idx=%d\n", idx);
    printf("Parsed key=%s\n", store[idx].key);
    printf("Parsed value=%s\n", store[idx].Value);
    */
}