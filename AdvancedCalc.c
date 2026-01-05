#include <stdio.h>

void main_menu();
void basic_math();
void settings();
void scientific_math();
void conversion();
int user_choice();

int main() {

    int choice;
    while (1) {
        main_menu();
        choice = user_choice();
        
        if (!choice) {
            printf("Exiting Program...\n");
            break;
        }

        
    }
    
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

void settings() {
    printf("\n===== Settings =====");
    printf("1. See history\n");
    printf("2. Clear History\n");
    printf("3. Save to a File\n");
    printf("0. Quit\n");
    printf("Choose an option: ");
}

void conversions() {
    printf("\n==== Conversions ====\n\n");
    printf("1. Temperature (F to C)\n");
    printf("2. Temperature (C to F)\n");
    printf("3. Feet to Inches\n");
    printf("4. Inches to Feet\n");
    printf("5. Pounds to Kilos\n");
    printf("0. Quit\n");
    printf("Choose an option: ");
}

void scientific_math() {
    printf("\n==== Scientific/Utility ====\n\n");
    printf("1. Quadratic Equation\n");
    printf("2. Square Root\n");
    printf("3. LCM\n");
    printf("4. Power\n");
    printf("5. Factorial\n");
    printf("0. Quit\n");
    printf("Choose an option: ");

}

int user_choice(void) {
    int x;
    scanf("%i", &x);
    while (getchar() != '\n');
    return x;
}