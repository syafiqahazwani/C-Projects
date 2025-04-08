#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>  // For getch()

#define FILENAME "users.dat"

// Structure to store user information
typedef struct {
    char username[50];
    char password[50];  // Hashed password
} User;

// Function prototypes
void signup();
void login();
void enterPassword(char password[]);
void hashPassword(char password[], char hashed[]);

int main() {
    int choice;
    while (1) {
        printf("\n======== LOGIN / SIGNUP SYSTEM ========\n");
        printf("1. Signup\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear input buffer

        switch (choice) {
            case 1:
                signup();
                break;
            case 2:
                login();
                break;
            case 3:
                printf("Exiting... Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to handle user signup
void signup() {
    FILE *file = fopen(FILENAME, "ab");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    User newUser;
    char password[50], hashedPassword[50];

    printf("\n===== SIGNUP =====\n");
    printf("Enter username: ");
    scanf("%s", newUser.username);
    
    printf("Enter password: ");
    enterPassword(password);

    // Hash the password before storing
    hashPassword(password, hashedPassword);
    strcpy(newUser.password, hashedPassword);

    fwrite(&newUser, sizeof(User), 1, file);
    fclose(file);

    printf("\nSignup successful! You can now login.\n");
}

// Function to handle user login
void login() {
    FILE *file = fopen(FILENAME, "rb");
    if (!file) {
        printf("No users found! Please signup first.\n");
        return;
    }

    User user;
    char username[50], password[50], hashedPassword[50];
    int found = 0;

    printf("\n===== LOGIN =====\n");
    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    enterPassword(password);

    // Hash the entered password
    hashPassword(password, hashedPassword);

    // Check the file for matching credentials
    while (fread(&user, sizeof(User), 1, file)) {
        if (strcmp(user.username, username) == 0 && strcmp(user.password, hashedPassword) == 0) {
            found = 1;
            break;
        }
    }
    fclose(file);

    if (found) {
        printf("\nLogin successful! Welcome, %s.\n", username);
    } else {
        printf("\nInvalid username or password! Please try again.\n");
    }
}

// Function to securely enter password with '*' masking
void enterPassword(char password[]) {
    int i = 0;
    char ch;
    while (1) {
        ch = getch();  // Get single character input
        if (ch == 13) {  // Enter key pressed
            password[i] = '\0';
            break;
        } else if (ch == 8 && i > 0) {  // Backspace handling
            i--;
            printf("\b \b");
        } else if (i < 49) {  // Limit password length
            password[i++] = ch;
            printf("*");
        }
    }
}

// Simple hashing function (Not for real-world use)
void hashPassword(char password[], char hashed[]) {
    int i;
    for (i = 0; password[i] != '\0'; i++) {
        hashed[i] = password[i] + 2;  // Simple encryption (Caesar Cipher)
    }
    hashed[i] = '\0';
}
