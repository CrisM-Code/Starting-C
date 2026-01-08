#include <stdio.h>
#include <math.h>
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
    float a;
    char op1;
    float b;
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
void save_file();
void save_history(int a, int b, char op, int result);
void save_history2(float a, char op1, float b, char op2);
void view_history();
void clear_history();

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
                save_history(x , y, '+', result);
                break;
            }
            case 2: {
                int x = first_num();
                int y = second_num();
                int result = x - y;
                printf("%i - %i = %i\n", x, y, result);
                save_history(x, y, '-', result);
                break;
            }
            case 3:  {
                int x = first_num();
                int y = second_num();
                int result = x * y;
                printf("%i x %i = %i\n", x, y, result);
                save_history(x, y, '*', result);
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
                save_history(x, y, '/', result);
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
    int choice4;
    while (1) {
        printf("\n===== Settings =====\n\n");
        printf("1. See history\n");
        printf("2. Clear History\n");
        printf("3. Save to a File\n");
        printf("0. Quit\n");
        printf("Choose an option: ");
        choice4 = user_choice();

        if (!choice4) {
            printf("\nExiting to Main Menu...\n");
            break;
        }

        switch (choice4) {
            case 1:
                view_history();
                break;
            case 2:
                clear_history();
                break;
            case 3:
                save_file();
                break;
            default:
                printf("Invalid Input!\n");
                break;
        }
    }
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
                float temp = (5.0f/9.0f) * (x-32);
                printf("%f F = %f C\n", x, temp);
                save_history2(x, 'F', temp, 'C');
                break;
            }
            case 2: {
                printf("Enter temp in Celsius: ");
                float x;
                scanf("%f", &x);
                float temp = (9.0f/5.0f) * x + 32;
                printf("%f C = %f F\n", x, temp);
                save_history2(x, 'C', temp, 'F');
                break;
            }
            case 3: {
                printf("Enter length in Feet: ");
                float x;
                scanf("%f", &x);
                float length = x * 12;
                printf("%f ft = %f in\n", x, length);
                save_history2(x, 'F', length, 'I');
                break;
            }
            case 4: {
                printf("Enter length in Inches: ");
                float x;
                scanf("%f", &x);
                float length = x / 12;
                printf("%f in = %f ft\n", x, length);
                save_history2(x, 'I', length, 'F');
                break;
            }
            case 5: {
                printf("Enter weight in pounds: ");
                float x;
                scanf("%f", &x);
                float weight = x / 2.2;
                printf("%f lb = %f kg\n", x, weight);
                save_history2(x, 'P', weight, 'K');
                break;
            }
            default:
                printf("Invalid Input!\n");
                break;
        }

    }
}

void scientific_math() {
    int choice5;
    while (1) {
        printf("\n==== Scientific/Utility ====\n\n");
        printf("1. Quadratic Equation\n");
        printf("2. Square Root\n");
        printf("3. Power\n");
        printf("4. Factorial\n");
        printf("0. Quit\n");
        printf("Choose an option: ");

        choice5 = user_choice();

        if (!choice5) {
            printf("Exiting to Main Menu...\n");
            break;
        }

        switch (choice5) {
            case 1: {
                double a, b, c;
                printf("Enter a: ");
                scanf("%lf", &a);
                if (a == 0) {
                    printf("Not a Quadratic Equation (a cannot be 0)");
                    break;
                }
                printf("Enter b: ");
                scanf("%lf", &b);
                printf("Enter c: ");
                scanf("%lf", &c);
                double disc = (b*b) - (4*a*c);
                 if (disc > 0) {
                    double x1 = (-b + sqrt(disc)) / (2*a);
                    double x2 = (-b - sqrt(disc)) / (2*a);

                    printf("Roots: %.2f and %.2f\n", x1, x2);

                    snprintf(
                        main_history[history_count].problem,
                        MAX_LEN,
                        "%.2fx^2 + %.2fx + %.2f = 0 -> x = %.2f, %.2f",
                        a, b, c, x1, x2
                    );
                }
                else if (disc == 0) {
                    double x = -b / (2*a);
                    printf("Root: %.2f\n", x);

                    snprintf(
                        main_history[history_count].problem,
                        MAX_LEN,
                        "%.2fx^2 + %.2fx + %.2f = 0 -> x = %.2f",
                        a, b, c, x
                    );
                }
                else {
                    double real = -b / (2*a);
                    double imag = sqrt(-disc) / (2*a);

                    printf("Roots: %.2f ± %.2fi\n", real, imag);

                    snprintf(
                        main_history[history_count].problem,
                        MAX_LEN,
                        "%.2fx^2 + %.2fx + %.2f = 0 -> %.2f ± %.2fi",
                        a, b, c, real, imag
                    );
                }

                history_count++;
                break;
            }
            case 2: {
                float x, result;
                printf("Enter a number: ");
                scanf("%f", &x);
                result = sqrt(x);
                printf("Square Root of %f is %f\n", x, result);
                snprintf(main_history[history_count].problem, MAX_LEN, "Sqaure root of %f is %f", x, result);
                history_count++;
                break;
            }
            case 3: {
                float x, y, result;
                printf("Enter base number: ");
                scanf("%f", &x);
                printf("Enter exponent: ");
                scanf("%f", &y);
                
                result = pow(x, y);
                printf("%f to the power of %f is %f\n", x, y, result);
                snprintf(main_history[history_count].problem, MAX_LEN, "%f to the power of %f is %f", x, y, result);
                history_count++;
                break;
            }
            case 4: {
                int x, result;
                printf("Enter a number: ");
                scanf("%i", &x);

                result = x;
                int n = x -1;
                for (int i = 0; i < n; i++) {
                   result *= n;
                   n--; 
                }
                printf("%i! = %i\n", x, result);
                snprintf(main_history[history_count].problem, MAX_LEN, "%i! = %i", x, result);
                history_count++;
                break;
            }
            default:
                printf("Invalid Input!\n");
                break;
        }
    }
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


void save_file() {
    fp = fopen("CalcHistory.txt", "w");
    if (fp == NULL) {
        printf("File Error!\n");
        return;
    }

    for (int i = 0; i < history_count; i++) {
        fprintf(fp, "%s\n", main_history[i].problem);
    }

    fclose(fp);
    printf("History saved to \"CalcHistory.txt\"");
} 

void save_history(int a, int b, char op, int result) {
    if (history_count < MAX_HISTORY) {
        history[history_count].a = a;
        history[history_count].b = b;
        history[history_count].op = op;
        history[history_count].result = result;
        snprintf(main_history[history_count].problem, MAX_LEN, "%i %c %i = %i", a, op, b, result);
        history_count++;
    } else {
        printf("History is full!\n");
    }
    
}

void save_history2(float a, char op1, float b, char op2) {
    if(history_count < MAX_HISTORY) {
        history2[history_count].a = a;
        history2[history_count].op1 = op1;
        history2[history_count].b = b;
        history2[history_count].op2 = op2;
        snprintf(main_history[history_count].problem, MAX_LEN, "%f %c = %f %c", a, op1, b, op2);
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

void clear_history() {
    history_count = 0;
    printf("History Deleted!\n");
}