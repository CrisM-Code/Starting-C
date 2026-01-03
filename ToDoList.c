//This program is a To-Do List with a menu page with different options. It is pretty much foolproof and works fine. Some of the code has been written by AI,
//but I have written most by myself. There are a lot of new concepts in here such as the #define and Structs.
//Everything here is going to be placed on GitHub as practice

#include <stdio.h>


//the #define will replace MAX_TASK with 50 whenever it is written in the program
#define MAX_TASK 50
#define MAX_LEN 100

//This is for the task. Each task will have a text with max length of 100 and a completed check mark. 
typedef struct {
    char text[MAX_LEN];
    int completed;      //0 = completed & 1 = not completed
} Task;

Task tasks[MAX_TASK]; //The structure from above is used to make an array. Each value in tasks will be the value of Task
int task_count = 0;


//For readability, I declared the functions here and defined them below the main function
void menu_page();
void add_task();
void view_task();
void del_task();
void complete();



int main() {
     
    int user_choice;
    while (1) {          //Just like the calculator program, I while (1) to keep the program running until the user enters 0
        menu_page();

        scanf("%i", &user_choice);
        while (getchar() != '\n');  //This line is confusing and i have to do research on it but it gets rid of a new line i guess
        printf("\n");

        //If the user enters 0, the while loop will quit and go to return 0; at the bottom of the main function
        if (user_choice == 0) {
            printf("Exiting Program...");
            printf("\n");
            break;
        }
        
        //Switch statements which are pretty basic. The default is in case a user enters a number not on the menu and will print "Invalid Input"
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

//I made the menu page a function so the code in main looks more readable
void menu_page() {
    printf("\n==== TO-DO List ====\n\n");
    printf("1. Add Task\n");
    printf("2. View Task\n");
    printf("3. Mark Task as complete\n");
    printf("4. Delete Task\n");
    printf("0. Exit\n");
    printf("Choose an option: ");
}

//This is the most complicated one. The one i wrote works, but this has Input error checks
void add_task() {
    if (task_count >= MAX_TASK) {
        printf("Task list is full!\n");
        return;
    }

    printf("\nEnter task: ");

    if (fgets(tasks[task_count].text,           //Note: here the fget is used for a value of a string in an array. the function still works even though it is inside the if statement
                sizeof(tasks[task_count].text),
                stdin) == NULL) {
            printf("Input error.\n");
            return;
    }

    tasks[task_count].text[strcspn(tasks[task_count].text, "\n")] = '\0'; //Note this line is for the fgets functions. it deletes the newline created by fgets. it is necessary to have

     if (strlen(tasks[task_count].text) == 0) {  //This checks if the length of the string is 0. I wanted this here to avoid empty tasks
        printf("Task cannot be empty.\n");
        return;
    }

    tasks[task_count].completed = 0;
    task_count++;
}

//This is pretty simple except for the tasks completed part.
void view_task() {
    if (task_count == 0) {
        printf("No tasks.\n");
        return;
    }

    for (int i = 0; i < task_count; i++) {
        printf("%d. [%c] %s\n",
                i + 1,
                tasks[i].completed ? 'x' : ' ',   //Short-hand If-Else statemnt. If completed is 0 then the 0 means false so it will print the blank space,
                tasks[i].text);                   // but if the number is any number but 0, then it is true and will print X
    }
}

//This will change the value of the Task completed variable to 1 to mark as completed
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
}

//This function deletes a task by moving the indexs
void del_task() {
    int choice;
    printf("\nWhat task do you want to delete? ");
    scanf("%i", &choice);

    if (choice < 0 || choice > task_count) {
        printf("\nInvalid Input!\n");
        return;
    }

    choice--;       //Whichever number that the user chooses is decremented by 1.
    for (int i = choice; i < task_count - 1; i++) {   //task count is also decremented by 1 and each task is moved up by 1
        tasks[i] = tasks[i + 1];
    }

    task_count--;

    printf("Task deleted.\n");
}
