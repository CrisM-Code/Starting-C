#include <stdio.h>
#define MAX_HISTORY 100
#define MAX_LEN 100

typedef struct {
    char problem[MAX_LEN];
} Main;

Main main_history[MAX_HISTORY];
int count = 0;

typedef struct {
    int a;
    int b;
    char op;
    int result;
} History;

typedef struct {
    int a;
    char op1;
    int b;
    char op2;
} History2;

History2 history2[MAX_HISTORY];

History history[MAX_HISTORY];
int history_count = 0;

FILE *fp;

void main_menu();
void basic_math();
void settings();
void scientific_math();
void conversions();
int user_choice();
int first_num();
int second_num();
//void save_file();
void save_history(int a, int b, char op, int result);
void save_history2(int a, char op1, int b, char op2);
void view_history();

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
                basic_math();
                break;
            case 2:
                scientific_math();
                break;
            case 3:
                conversions();
                break;
            case 4:
                settings();
                break;
            default:
                printf("Invalid Input!\n");
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
            printf("\nExiting to Main Menu...\n");
            break;
        }
        
        switch (choice2) {
            case 1: {
                int x = first_num();
                int y = second_num();
                int result = x + y;
                printf("%i + %i = %i\n", x, y, result);
                save_history(x , y, "+", result);
                break;
            }
            case 2: {
                int x = first_num();
                int y = second_num();
                int result = x - y;
                printf("%i - %i = %i\n", x, y, result);
                save_history(x, y, "-", result);
                break;
            }
            case 3:  {
                int x = first_num();
                int y = second_num();
                int result = x * y;
                printf("%i x %i = %i\n", x, y, result);
                save_history(x, y, "*", result);
                break;
            }
            case 4: {
                int x = first_num();
                int y = second_num();
                if (y == 0) {
                    printf("Error: Division by zero!\n");
                    break;
                }
                int result = x / y;
                printf("%i / %i = %i\n", x, y, (x/y));
                save_history(x, y, "/", result);
                break;
            }
            default: {
                printf("Invalid Input!\n");
                break;
            }
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
            printf("\nExiting to Main Menu...");
            break;
        }

        switch (choice3) {
            case 1: {
                printf("Enter temp in Fahrenheit: ");
                float x;
                scanf("%f", &x);
                float temp = 5/9 * (x-32);
                printf("%f F = %f C\n", x, temp);
                save_history2(x, "F", temp, "C");
                break;
            }
            case 2: {
                printf("Enter temp in Celsius: ");
                float x;
                scanf("%f", &x);
                float temp = 9/5 * x + 32;
                printf("%f C = %f F\n", x, temp);
                save_history2(x, "C", temp, "F");
                break;
            }
            case 3: {
                printf("Enter length in Feet: ");
                float x;
                scanf("%f", &x);
                float length = x * 12;
                printf("%f ft = %f in\n", x, length);
                save_history2(x, "ft", length, "in");
                break;
            }
            case 4: {
                printf("Enter length in Inches: ");
                float x;
                scanf("%f", &x);
                float length = x / 12;
                printf("%f in = %f ft\n", x, length);
                save_history2(x, "in", length, "ft");
                break;
            }
            case 5: {
                printf("Enter weight in pounds: ");
                float x;
                scanf("%f", &x);
                float weight = x / 2.2;
                printf("%f lb = %f kg\n", x, weight);
                save_history2(x, "lb", weight, "kg");
                break;
            }
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
    int v;
    printf("Enter a number: ");
    scanf("%i", &v);
    return v;
}

int second_num(void) {
    int b;
    printf("Enter a number: ");
    scanf("%i", &b);
    return b;
}

/*
void save_file() {
    fp = fopen("CalcHistory.txt", "w");
    if (fp == NULL) {
        printf("File Error!\n");
        return;
    }

    for (int i = 0; i < history_count; i++) {
        fprintf("CalcHistory.txt", "%i|%s\n", (i + 1), history[i].history);
    }

    fclose(fp);
} */

void save_history(int a, int b, char op, int result) {
    if (history_count < MAX_HISTORY) {
        history[history_count].a = a;
        history[history_count].b = b;
        history[history_count].op = op;
        history[history_count].result = result;
        main_history[history_count].problem == "%i %c %i = %i\n", a, b, op, result;
        history_count++;
    } else {
        printf("History is full!\n");
    }
    
}

void save_history2(int a, char op1, int b, char op2) {
    if(history_count < MAX_HISTORY) {
        history2[history_count].a = a;
        history2[history_count].op1 = op1;
        history2[history_count].b = b;
        history2[history_count].op2 = op2;
        main_history[history_count].problem == "%i %c = %i %c\n", a, op1, b, op2;
        history_count++;
    } else {
        printf("History is full!\n");
    }
}

void view_history() {
    if (history_count == 0) {
        printf("History is empty.\n");
    }
    for (int i = 0; i < history_count; i++) {
        printf("%s\n", main_history[i].problem);
    }
}