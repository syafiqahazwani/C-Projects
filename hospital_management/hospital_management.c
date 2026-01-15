#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store patient information
struct Patient {
    int id;
    char name[50];
    int age;
    char disease[50];
    char doctor[50];
};

// Function prototypes
void addPatient();
void viewPatients();
void searchPatient();
void updatePatient();
void deletePatient();
void saveToFile();

// Global variables
struct Patient patients[100];
int patientCount = 0;

void mainMenu() {
    printf("\n*** Hospital Management System ***\n");
    printf("1. Add Patient\n");
    printf("2. View All Patients\n");
    printf("3. Search Patient by ID\n");
    printf("4. Update Patient Details\n");
    printf("5. Delete Patient\n");
    printf("6. Save & Exit\n");
    printf("Enter your choice: ");
}

void addPatient() {
    printf("\nEnter Patient ID: ");
    scanf("%d", &patients[patientCount].id);
    getchar(); // Clear newline character

    printf("Enter Name: ");
    fgets(patients[patientCount].name, 50, stdin);
    patients[patientCount].name[strcspn(patients[patientCount].name, "\n")] = '\0';

    printf("Enter Age: ");
    scanf("%d", &patients[patientCount].age);
    getchar();

    printf("Enter Disease: ");
    fgets(patients[patientCount].disease, 50, stdin);
    patients[patientCount].disease[strcspn(patients[patientCount].disease, "\n")] = '\0';

    printf("Enter Doctor's Name: ");
    fgets(patients[patientCount].doctor, 50, stdin);
    patients[patientCount].doctor[strcspn(patients[patientCount].doctor, "\n")] = '\0';

    patientCount++;
    printf("Patient added successfully!\n");
}

void viewPatients() {
    printf("\n*** List of Patients ***\n");
    for (int i = 0; i < patientCount; i++) {
        printf("ID: %d | Name: %s | Age: %d | Disease: %s | Doctor: %s\n",
               patients[i].id, patients[i].name, patients[i].age,
               patients[i].disease, patients[i].doctor);
    }
}

void searchPatient() {
    int id, found = 0;
    printf("\nEnter Patient ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            printf("Patient Found!\n");
            printf("ID: %d | Name: %s | Age: %d | Disease: %s | Doctor: %s\n",
                   patients[i].id, patients[i].name, patients[i].age,
                   patients[i].disease, patients[i].doctor);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Patient not found!\n");
    }
}

void updatePatient() {
    int id, found = 0;
    printf("\nEnter Patient ID to update: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            printf("Enter New Name: ");
            fgets(patients[i].name, 50, stdin);
            patients[i].name[strcspn(patients[i].name, "\n")] = '\0';

            printf("Enter New Age: ");
            scanf("%d", &patients[i].age);
            getchar();

            printf("Enter New Disease: ");
            fgets(patients[i].disease, 50, stdin);
            patients[i].disease[strcspn(patients[i].disease, "\n")] = '\0';

            printf("Enter New Doctor's Name: ");
            fgets(patients[i].doctor, 50, stdin);
            patients[i].doctor[strcspn(patients[i].doctor, "\n")] = '\0';

            printf("Patient record updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Patient not found!\n");
    }
}

void deletePatient() {
    int id, index = -1;
    printf("\nEnter Patient ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < patientCount - 1; i++) {
            patients[i] = patients[i + 1];
        }
        patientCount--;
        printf("Patient deleted successfully!\n");
    } else {
        printf("Patient not found!\n");
    }
}

void saveToFile() {
    FILE *file = fopen("patients.txt", "w");
    if (!file) {
        printf("Error saving data!\n");
        return;
    }

    for (int i = 0; i < patientCount; i++) {
        fprintf(file, "%d,%s,%d,%s,%s\n",
                patients[i].id, patients[i].name, patients[i].age,
                patients[i].disease, patients[i].doctor);
    }
    fclose(file);
    printf("Data saved successfully!\n");
}

int main() {
    int choice;

    while (1) {
        mainMenu();
        scanf("%d", &choice);
        getchar(); // Clear input buffer

        switch (choice) {
        case 1:
            addPatient();
            break;
        case 2:
            viewPatients();
            break;
        case 3:
            searchPatient();
            break;
        case 4:
            updatePatient();
            break;
        case 5:
            deletePatient();
            break;
        case 6:
            saveToFile();
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
