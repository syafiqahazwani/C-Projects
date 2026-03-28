#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[100];
    char author[100];
    int available;
};

struct Book library[MAX_BOOKS];
int bookCount = 0;

// Function to load books from file
void loadBooks() {
    FILE *file = fopen("library.dat", "rb");
    if (file != NULL) {
        fread(&bookCount, sizeof(int), 1, file);
        fread(library, sizeof(struct Book), bookCount, file);
        fclose(file);
    }
}

// Function to save books to file
void saveBooks() {
    FILE *file = fopen("library.dat", "wb");
    fwrite(&bookCount, sizeof(int), 1, file);
    fwrite(library, sizeof(struct Book), bookCount, file);
    fclose(file);
}

// Function to add a book
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }
    printf("Enter Book ID: ");
    scanf("%d", &library[bookCount].id);
    getchar();
    printf("Enter Book Title: ");
    fgets(library[bookCount].title, 100, stdin);
    strtok(library[bookCount].title, "\n");
    
    printf("Enter Author Name: ");
    fgets(library[bookCount].author, 100, stdin);
    strtok(library[bookCount].author, "\n");

    library[bookCount].available = 1;
    bookCount++;
    saveBooks();
    printf("Book added successfully!\n");
}

// Function to display all books
void displayBooks() {
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }
    printf("\nLibrary Books:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("ID: %d | Title: %s | Author: %s | Available: %s\n", 
               library[i].id, library[i].title, library[i].author, 
               library[i].available ? "Yes" : "No");
    }
}

// Function to search for a book by ID
void searchBook() {
    int id;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            printf("Book Found!\nTitle: %s | Author: %s | Available: %s\n",
                   library[i].title, library[i].author, 
                   library[i].available ? "Yes" : "No");
            return;
        }
    }
    printf("Book not found.\n");
}

// Function to delete a book by ID
void deleteBook() {
    int id, index = -1;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Book not found!\n");
        return;
    }

    for (int i = index; i < bookCount - 1; i++) {
        library[i] = library[i + 1];
    }
    bookCount--;
    saveBooks();
    printf("Book deleted successfully!\n");
}

// Main menu function
void mainMenu() {
    int choice;
    loadBooks();
    while (1) {
        printf("\n*** Library Management System ***\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: saveBooks(); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
}

int main() {
    mainMenu();
    return 0;
}
