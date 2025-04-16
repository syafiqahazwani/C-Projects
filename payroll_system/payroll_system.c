#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct payroll
{
    int id;
    char name[50];
    int age;
    char department[30];
    float salary;
};

struct payroll payrolls[100];
int employeeCount = 0;

void mainMenu(){
    printf("\n*** Employee Payroll Management ***\n");
    printf("1. Add Employee\n");
    printf("2. View All Employees\n");
    printf("3. Update Employee\n");
    printf("4. Delete Employee\n");
    printf("5. Generate PaySlip\n");
    printf("6. Save & Exit\n");
    printf("Enter your Choice: ");
}

void addEmployee()
{
    printf("Enter Employee ID: ");
    scanf("%d", &payrolls[employeeCount].id);
    printf("Enter Employee Name: ");
    getchar();
    fgets(payrolls[employeeCount].name, 50, stdin);
    payrolls[employeeCount].name[strcspn(payrolls[employeeCount].name, "\n")] = '\0';

    printf("Enter Age: ");
    scanf("%d", &payrolls[employeeCount].age);

    printf("Enter Department: ");
    getchar();
    fgets(payrolls[employeeCount].department, 30, stdin);
    payrolls[employeeCount].department[strcspn(payrolls[employeeCount].department, "\n")] = '\0';

    printf("Enter Salary: ");
    scanf("%f", &payrolls[employeeCount].salary);
    employeeCount++;
    printf("Employee added Successfully\n");
}

void viewEmployee()
{
    printf("\n*** Employee List ***\n");

    for(int i = 0; i < employeeCount; i++)
    {
        printf("EmployeeID:%d, Name:%s, Age:%d, Department:%s, Salary:%.2f\n",
               payrolls[i].id, payrolls[i].name, payrolls[i].age, payrolls[i].department, payrolls[i].salary);
    }
}

void updateEmployee()
{
    int id, index = -1;
    printf("Enter Employee ID to Update: ");
    scanf("%d", &id);

    for(int i = 0; i < employeeCount; i++)
    {
        if(payrolls[i].id == id)
        {
            index = i;
            break;
        }
    }

    if(index != -1)
    {
        printf("Updating details for Employee ID: %d\n", id);
        printf("Enter New Name: ");
        getchar();
        fgets(payrolls[index].name, 50, stdin);
        payrolls[index].name[strcspn(payrolls[index].name, "\n")] = '\0';

        printf("Enter New Age: ");
        scanf("%d", &payrolls[index].age);

        printf("Enter New Department: ");
        getchar();
        fgets(payrolls[index].department, 30, stdin);
        payrolls[index].department[strcspn(payrolls[index].department, "\n")] = '\0';

        printf("Enter New Salary: ");
        scanf("%f", &payrolls[index].salary);

        printf("Employee details updated Successfully\n");
    }
    else
    {
        printf("Employee not found.\n");
    }
}

void deleteEmployee()
{
    int id, index = -1;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);

    for(int i = 0; i < employeeCount; i++)
    {
        if(payrolls[i].id == id)
        {
            index = i;
            break;
        }
    }

    if(index != -1)
    {
        for(int i = index; i < employeeCount - 1; i++)
        {
            payrolls[i] = payrolls[i + 1];
        }
        employeeCount--;
        printf("Employee deleted successfully\n");
    }
    else
    {
        printf("Employee not found\n");
    }
}

void generatePayslip(){
    float totalSalary = 0, tax, netSalary;

    for(int i = 0; i < employeeCount; i++) {
        totalSalary += payrolls[i].salary;
    }
    tax = totalSalary * 0.1;
    netSalary = totalSalary - tax;

    printf("\n-- Payroll Summary --\n");
    printf("Total Salary: %.2f\n", totalSalary);
    printf("Tax: %.2f\n", tax);
    printf("Net Salary: %.2f\n", netSalary);
}

void saveFile()
{
    FILE *file = fopen("employee.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for(int i = 0; i < employeeCount; i++)
    {
        fprintf(file, "%d,%s,%d,%s,%.2f\n", payrolls[i].id, payrolls[i].name, payrolls[i].age, payrolls[i].department, payrolls[i].salary);
    }
    fclose(file);
    printf("Data Saved Successfully\n");
}

int main()
{
    int choice;
    while (1)
    {
        mainMenu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addEmployee();
                break;
            case 2:
                viewEmployee();
                break;
            case 3:
                updateEmployee();
                break;
            case 4:
                deleteEmployee();
                break;
            case 5:
                generatePayslip();
                break;
            case 6:
                saveFile();
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}
