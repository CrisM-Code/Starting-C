#include <stdio.h>
#include <string.h>

#define MAX_TASK 50
#define MAX_LEN 100

typedef struct {
    char text[MAX_LEN];
    int completed;      //0 = completed & 1 = not completed
} Task;

Task tasks[MAX_TASK];
int task_count = 0;

void menu_page();
void add_task();
void view_task();
void del_task();
void complete();


int main(){
    menu_page();
    
    return 0;
}

void menu_page() {
    printf("==== TO-DO List ====\n\n");
    printf("1. Add Task\n");
    printf("2. View Task\n");
    printf("3. Mark Task as complete\n");
    printf("4. Delete Task\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

void add_task() {
    printf("What task");
}

