#include <stdio.h>

void main_menu();
void basic_math();
void history();
void advanced_math();

int main() {
    main_menu();
    basic_math();
    return 0;
}

void main_menu() {
    printf("\n===== MAIN MENU ====\n\n");
    printf("1. Basic Calculator\n");
    printf("2. Scientific/Utility\n");
    printf("3. Unit Conversion\n");
    printf("4. Settings\n");
    printf("0. Exit\n");
    printf("Choose an option: ");
}

void basic_math() {
    printf("\n\n==== Calculator Menu ====\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("0. Quit\n");
    printf("Choose an option: ");
}