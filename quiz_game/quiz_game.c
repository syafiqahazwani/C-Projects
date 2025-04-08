#include <stdio.h>
#include <ctype.h>

int main() {
    // Question and option sets
    char questions[][100] = {
        "1. From which anime is Uzumaki Naruto?: ",
        "2. From which anime is Sakata Gintoki?: ",
        "3. From which anime is Edogawa Conan?: ",
        "4. From which anime is Monkey D Luffy?: ",
        "5. From which anime is Midoriya Izuku?: ",
        "6. From which anime is Kamado Tanjiro?: ",
        "7. From which anime is Itadori Yuji?: ",
        "8. From which anime is Asta?: "
    };

    char options[][100] = {
        "A. Detective Conan", "B. One Piece", "C. Naruto", "D. Gintama",
        "A. Detective Conan", "B. One Piece", "C. Naruto", "D. Gintama",
        "A. Detective Conan", "B. One Piece", "C. Naruto", "D. Gintama",
        "A. Detective Conan", "B. One Piece", "C. Naruto", "D. Gintama",
        "A. Black Clover", "B. Kimetsu no Yaiba", "C. Jujutsu Kaisen", "D. Boku no Hero Academia",
        "A. Black Clover", "B. Kimetsu no Yaiba", "C. Jujutsu Kaisen", "D. Boku no Hero Academia",
        "A. Black Clover", "B. Kimetsu no Yaiba", "C. Jujutsu Kaisen", "D. Boku no Hero Academia",
        "A. Black Clover", "B. Kimetsu no Yaiba", "C. Jujutsu Kaisen", "D. Boku no Hero Academia"
    };

    char answers[8] = {'C', 'D', 'A', 'B', 'D', 'B', 'C', 'A'};
    int numberOfQuestions = sizeof(questions) / sizeof(questions[0]);

    char guess;
    int score = 0;  // Initialize score to 0

    printf("QUIZ GAME\n");

    for (int i = 0; i < numberOfQuestions; i++) {
        printf("***************\n");
        printf("%s\n", questions[i]);
        printf("***************\n");

        // Print the options for each question
        for (int j = i * 4; j < (i * 4) + 4; j++) {
            printf("%s\n", options[j]);
        }

        printf("Answer: ");
        // Fix input issue by consuming any leftover newline characters
        fflush(stdin);
        scanf(" %c", &guess);  // Add a space before %c to skip any leftover newline

        guess = toupper(guess);

        if (guess == answers[i]) {
            printf("CORRECT!\n");
            score++;
        } else {
            printf("WRONG!\n");
        }
    }

    printf("***************\n");
    printf("FINAL SCORE: %d/%d\n", score, numberOfQuestions);
    printf("***************\n");

    return 0;
}
