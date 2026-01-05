#include <stdio.h>

void main_menu();
void basic_math();
void settings();
void scientific_math();
void conversion();
int user_choice();
int first_num();
int second_num();

int main() {

    int choice;
    while (1) {
        main_menu();
        choice = user_choice();
        
        if (!choice) {
            printf("Exiting Program...\n");
            break;
        }

        switch (choice) {
            case 1:
                
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
    int choice2;
    while (1) {
        printf("\n\n==== Calculator Menu ====\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("0. Quit\n");
        printf("Choose an option: ");
        choice2 = user_choice();
    
        if (!choice2) {
            printf("Exiting to Main Menu...");
            break;
        }
        
        switch (choice2) {
            case 1: 
                int x = first_num();
                int y = second_num();
                printf("%i + %i = %i\n", x, y, (x + y));
                break;
            case 2:
                int x = first_num();
                int y = second_num();
                printf("%i - %i = %i\n", x, y, (x - y));
                break;
            case 3: 
                int x = first_num();
                int y = second_num();
                printf("%i x %i = %i\n", x, y, (x*y));
                break;
            case 4:
                int x = first_num();
                int y = second_num();
                printf("%i / %i = %i\n", x, y, (x/y));
                break;
            default:
                printf("Invalid Input!\n");
                break;
        }
    }
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
    int choice3;
    while (1) {
        printf("\n==== Conversions ====\n\n");
        printf("1. Temperature (F to C)\n");
        printf("2. Temperature (C to F)\n");
        printf("3. Feet to Inches\n");
        printf("4. Inches to Feet\n");
        printf("5. Pounds to Kilos\n");
        printf("0. Quit\n");
        printf("Choose an option: ");
        choice3 = user_choice();

        if (!choice3) {
            printf("Exiting to Main Menu...");
            break;
        }

        switch (choice3) {
            case 1:
                printf("Enter temp in Fahrenheit: ");
                float x;
                scanf("%f", &x);
                float temp = 5/9 * (x-32);
                printf("%f F = %f C\n", x, temp);
                break;
            case 2:
                printf("Enter temp in Celsius: ");
                float x;
                scanf("%f", &x);
                float temp = 9/5 * x + 32;
                printf("%f C = %f F\n", x, temp);
                break;
            case 3:
                printf("Enter length in Feet: ");
                float x;
                scanf("%f", &x);
                float length = x * 12;
                printf("%f ft = %f in\n", x, length);
                break;
            case 4:
                printf("Enter length in Inches: ");
                float x;
                scanf("%f", &x);
                float length = x / 12;
                printf("%f in = %f ft\n", x, length);
                break;
            case 5: 
                printf("Enter weight in pounds: ");
                float x;
                scanf("%f", &x);
                float weight = x / 2.2;
                printf("%f ft = %f in\n", x, weight);
                break;
            default:
                printf("Invalid Input!\n");
                break;
        }

    }
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

int first_num(void) {
    int x;
    printf("Enter a number: ");
    scanf("%i", &x);
    return x;
}

int second_num(void) {
    int y;
    printf("Enter a number: ");
    scanf("%i", &y);
    return y;
}