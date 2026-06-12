#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_QUESTIONS 5
#define MAX_LINE 100

typedef struct {
    char question[MAX_LINE];
    char optionA[MAX_LINE];
    char optionB[MAX_LINE];
    char optionC[MAX_LINE];
    char optionD[MAX_LINE];
    char correct_ans;
} QuizQuestion;

void loadQuestions(QuizQuestion q[]) {
    strcpy(q[0].question, "What is the size of an int data type in C usually?");
    strcpy(q[0].optionA, "2 bytes");
    strcpy(q[0].optionB, "4 bytes");
    strcpy(q[0].optionC, "8 bytes");
    strcpy(q[0].optionD, "1 byte");
    q[0].correct_ans = 'B';

    strcpy(q[1].question, "Who is the father of C language?");
    strcpy(q[1].optionA, "Bjarne Stroustrup");
    strcpy(q[1].optionB, "James Gosling");
    strcpy(q[1].optionC, "Dennis Ritchie");
    strcpy(q[1].optionD, "Guido van Rossum");
    q[1].correct_ans = 'C';

    strcpy(q[2].question, "Which of the following is a valid format specifier for a float?");
    strcpy(q[2].optionA, "%d");
    strcpy(q[2].optionB, "%c");
    strcpy(q[2].optionC, "%f");
    strcpy(q[2].optionD, "%s");
    q[2].correct_ans = 'C';

    strcpy(q[3].question, "Which keyword is used to prevent any changes in the variable?");
    strcpy(q[3].optionA, "const");
    strcpy(q[3].optionB, "static");
    strcpy(q[3].optionC, "volatile");
    strcpy(q[3].optionD, "register");
    q[3].correct_ans = 'A';

    strcpy(q[4].question, "Which symbol is used as a statement terminator in C?");
    strcpy(q[4].optionA, ":");
    strcpy(q[4].optionB, ".");
    strcpy(q[4].optionC, ";");
    strcpy(q[4].optionD, ",");
    q[4].correct_ans = 'C';
}

void printHeader() {
    printf("=========================================\n");
    printf("        WELCOME TO THE C QUIZ GAME       \n");
    printf("=========================================\n");
    printf("Answer the following 5 questions to test \n");
    printf("your C programming knowledge!\n\n");
}

void saveScore(int score, int total) {
    FILE *file = fopen("score.txt", "w");
    if (file != NULL) {
        fprintf(file, "Your final score: %d/%d\n", score, total);
        fclose(file);
        printf("Note: Your score has been saved to 'score.txt'.\n");
    } else {
        printf("Error: Could not open file to save score.\n");
    }
}

int main() {
    QuizQuestion q[MAX_QUESTIONS];
    int score = 0;
    char answer;

    loadQuestions(q);
    printHeader();

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("Question %d: %s\n", i + 1, q[i].question);
        printf("A. %s\n", q[i].optionA);
        printf("B. %s\n", q[i].optionB);
        printf("C. %s\n", q[i].optionC);
        printf("D. %s\n", q[i].optionD);

        // Loop to clear buffer and ensure we get proper character input
        while (1) {
            printf("\nYour Answer (A, B, C, or D): ");
            scanf(" %c", &answer);
            
            // Convert to uppercase for robustness
            if (answer >= 'a' && answer <= 'z') {
                answer = answer - 32;
            }

            if (answer >= 'A' && answer <= 'D') {
                break;
            } else {
                printf("Invalid input. Please enter A, B, C, or D.\n");
            }
        }

        if (answer == q[i].correct_ans) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect! The correct answer was %c.\n\n", q[i].correct_ans);
        }
    }

    printf("=========================================\n");
    printf("               GAME OVER                 \n");
    printf("=========================================\n");
    printf("You scored %d out of %d!\n", score, MAX_QUESTIONS);

    switch(score) {
        case 5:
            printf("Excellent! You are a C master.\n");
            break;
        case 4:
            printf("Great job! Almost perfect.\n");
            break;
        case 3:
            printf("Good! But you can improve.\n");
            break;
        default:
            printf("Keep practicing C fundamentals!\n");
            break;
    }

    saveScore(score, MAX_QUESTIONS);

    return 0;
}
