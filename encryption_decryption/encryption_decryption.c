#include <stdio.h>
#include <stdlib.h>

#define KEY 0xAA // Encryption key 

// Function to encrypt/decrypt a file using XOR method
void encryptDecryptFile(const char *inputFile, const char *outputFile) {
    FILE *fin = fopen(inputFile, "rb");
    FILE *fout = fopen(outputFile, "wb");

    if (!fin || !fout) {
        printf("Error opening files!\n");
        return;
    }

    char ch;
    while (fread(&ch, sizeof(char), 1, fin)) {
        ch ^= KEY; // XOR encryption
        fwrite(&ch, sizeof(char), 1, fout);
    }

    fclose(fin);
    fclose(fout);
    printf("Operation completed successfully!\n");
}

int main() {
    int choice;
    char inputFile[100], outputFile[100];

    while (1) {
        printf("\n*** File Encryption & Decryption ***\n");
        printf("1. Encrypt a File\n");
        printf("2. Decrypt a File\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear input buffer

        switch (choice) {
        case 1:
            printf("Enter file to encrypt: ");
            scanf("%s", inputFile);
            printf("Enter output encrypted file: ");
            scanf("%s", outputFile);
            encryptDecryptFile(inputFile, outputFile);
            break;

        case 2:
            printf("Enter encrypted file to decrypt: ");
            scanf("%s", inputFile);
            printf("Enter output decrypted file: ");
            scanf("%s", outputFile);
            encryptDecryptFile(inputFile, outputFile); // Same function decrypts
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
