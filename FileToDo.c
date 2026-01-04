#include <stdio.h>
#include <string.h>


#define MAX_TASK 50
#define MAX_LEN 100

typedef struct {
    char text[MAX_LEN];
    int completed;      
} Task;

Task tasks[MAX_TASK]; 
int task_count = 0;

FILE *fptr;


void menu_page();
void add_task();
void view_task();
void del_task();
void complete();



int main() {

    int user_choice;
    while (1) {      
        menu_page();

        scanf("%i", &user_choice);
        while (getchar() != '\n');  
        printf("\n");

        
        if (user_choice == 0) {
            printf("Exiting Program...");
            printf("\n");
            break;
        }
        
       
        switch (user_choice) {
            case 1: 
                add_task();
                break;
            case 2:
                view_task();
                break;
            case 3: 
                complete();
                break;
            case 4: 
                del_task();
                break;
            default:
                printf("Invalid Input!\n");
                break;
        }
    }
    
    return 0;
}


void menu_page() {
    printf("\n==== TO-DO List ====\n\n");
    printf("1. Add Task\n");
    printf("2. View Task\n");
    printf("3. Mark Task as complete\n");
    printf("4. Delete Task\n");
    printf("0. Exit\n");
    printf("Choose an option: ");
}


void add_task() {
    if (task_count >= MAX_TASK) {
        printf("Task list is full!\n");
        return;
    }

    printf("\nEnter task: ");

    if (fgets(tasks[task_count].text,           
                sizeof(tasks[task_count].text),
                stdin) == NULL) {
            printf("Input error.\n");
            return;
    }

    tasks[task_count].text[strcspn(tasks[task_count].text, "\n")] = '\0'; 
     if (strlen(tasks[task_count].text) == 0) {  
        printf("Task cannot be empty.\n");
        return;
    }

    fptr = fopen("ToDo.txt", "w");
    for (int i = 0; i < task_count; i++) {
        fprintf(fptr, "%i|%s", tasks[i].completed, tasks[i].text);
    }
    fclose(fptr);

    tasks[task_count].completed = 0;
    task_count++;
}


void view_task() {
    if (task_count == 0) {
        printf("No tasks.\n");
        return;
    }

    for (int i = 0; i < task_count; i++) {
        printf("%d. [%c] %s\n",
                i + 1,
                tasks[i].completed ? 'x' : ' ',   
                tasks[i].text);                  
    }
}


void complete() {
    printf("\nWhich task did you complete? ");
    int choice;
    scanf("%i", &choice);
    while (getchar() != '\n');

    if (choice < 0 || choice > task_count) {
        printf("\nInvalid Input!\n");
        return;
    }
    choice--;
    tasks[choice].completed = 1;

    fptr = fopen("ToDo.txt", "w");
    for (int i = 0; i < task_count; i++) {
        fprintf(fptr, "%i|%s", tasks[i].completed, tasks[i].text);
    }
    fclose(fptr);
}


void del_task() {
    int choice;
    printf("\nWhat task do you want to delete? ");
    scanf("%i", &choice);

    if (choice < 0 || choice > task_count) {
        printf("\nInvalid Input!\n");
        return;
    }

    choice--;       
    for (int i = choice; i < task_count - 1; i++) {  
        tasks[i] = tasks[i + 1];
    }

    task_count--;

    fptr = fopen("ToDo.txt", "w");
    for (int i = 0; i < task_count; i++) {
        fprintf(fptr, "%i|%s", tasks[i].completed, tasks[i].text);
    }
    fclose(fptr);

    printf("Task deleted.\n");
}
