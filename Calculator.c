#include <stdio.h>

void Multiplation(int x, int y) {
    int answer = x * y;
    printf("\n%i * %i = %i\n", x, y, answer);
}

void Addition(int x, int y) {
    int answer = x + y;
    printf("\n%i + %i = %i\n", x, y, answer);
}

void Subtraction(int x, int y) {
    int answer = x - y;
    printf("\n%i - %i = %i\n", x, y, answer);
}

void Division(int x, int y) {
    int answer = x / y;
    printf("\n%i / %i = %i\n", x, y, answer);
}

void menu_page();

int main() {

    int choice;
    while (1) {
        menu_page();
        scanf("%i", &choice);

        if (choice == 0) {
            printf("Exiting Program...\n");
            break;
        }

        int x, y;
        printf("\nEnter the first number: ");
        scanf("%i", &x);

        printf("\nEnter the second number: ");
        scanf("%i", &y);

        switch (choice) {
            case 1: 
                Addition(x, y);
                break;
            case 2: 
                Subtraction(x, y);
                break;
            case 3:
                Multiplation(x, y);
                break;
            case 4:
                Division(x, y);
                break;
            default:
                printf("Error: Invalid choice\n");
                break;
        }
    }
    return 0;
}

void menu_page() {
    printf("\n\n\n==== Calculator Menu ====\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("0. Quit\n");
    printf("Choose an option: ");
}
