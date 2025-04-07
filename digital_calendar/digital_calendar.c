#include<stdio.h>

#define TRUE 1
#define FALSE 0

int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *months[] = {
    "",
    "\n\n\nJanuary",
    "\n\n\nFebruary",
    "\n\n\nMarch",
    "\n\n\nApril",
    "\n\n\nMay",
    "\n\n\nJune",
    "\n\n\nJuly",
    "\n\n\nAugust",
    "\n\n\nSeptember",
    "\n\n\nOctober",
    "\n\n\nNovember",
    "\n\n\nDecember",
};

int inputyear(void) {
    int year;
    printf("Please enter a year (example: 1999): ");
    scanf("%d", &year);
    return year;
}

int determineleapyear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        days_in_month[2] = 29; // February has 29 days
        return TRUE;
    } else {
        days_in_month[2] = 28; // February has 28 days
        return FALSE;
    }
}

int determinedaycode(int year) {
    int daycode;
    int d1, d2, d3;

    // Calculate the daycode using Zeller's Congruence
    d1 = (year - 1) / 4;
    d2 = (year - 1) / 100;
    d3 = (year - 1) / 400;
    daycode = (year + d1 - d2 + d3) % 7;
    return daycode;
}

void calendar(int year, int daycode) {
    int month, day;
    for (month = 1; month <= 12; month++) {
        printf("%s", months[month]);
        printf("\n\nSun Mon Tue Wed Thu Fri Sat\n");

        // Correct the position for the first date
        for (day = 1; day <= daycode; day++) {
            printf("    "); // Space for previous days
        }

        // Print all the dates for one month
        for (day = 1; day <= days_in_month[month]; day++) {
            printf("%2d  ", day); // Print the day number

            // If it's Saturday, print a newline to start the next row
            if ((day + daycode) % 7 == 0) {
                printf("\n");
            }
        }
        // Set the position for the next month
        daycode = (daycode + days_in_month[month]) % 7;

        // Add a newline after each month's calendar
        printf("\n\n");
    }
}

int main(void) {
    int year, daycode, leapyear;
    year = inputyear();
    daycode = determinedaycode(year);
    determineleapyear(year);
    calendar(year, daycode);
    return 0;
}
