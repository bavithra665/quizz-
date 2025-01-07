#include <stdio.h>
#include <string.h>

// Define constants
#define MAX_QUESTIONS 5

// Question structure
struct Question {
    char question[256];
    char options[4][100];
    char correctOption; // 'A', 'Ba', 'C', 'D'
};

// Function declarations
void initializeQuestions(struct Question quiz[], int size);
void takeQuiz(struct Question quiz[], int size);
int checkAnswer(char userAnswer, char correctAnswer);

int main() {
    struct Question quiz[MAX_QUESTIONS];
    int choice;

    // Initialize quiz questions
    initializeQuestions(quiz, MAX_QUESTIONS);

    while (1) {
        // Display menu
        printf("\nQuiz Management System\n");
        printf("1. Take Quiz\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                takeQuiz(quiz, MAX_QUESTIONS);
                break;
            case 2:
                printf("Exiting... Thank you!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Initialize questions
void initializeQuestions(struct Question quiz[], int size) {
    strcpy(quiz[0].question, "What is the capital of France?");
    strcpy(quiz[0].options[0], "A. Paris");
    strcpy(quiz[0].options[1], "B. London");
    strcpy(quiz[0].options[2], "C. Berlin");
    strcpy(quiz[0].options[3], "D. Madrid");
    quiz[0].correctOption = 'A';

    strcpy(quiz[1].question, "Who wrote 'Hamlet'?");
    strcpy(quiz[1].options[0], "A. Charles Dickens");
    strcpy(quiz[1].options[1], "B. William Shakespeare");
    strcpy(quiz[1].options[2], "C. J.K. Rowling");
    strcpy(quiz[1].options[3], "D. Mark Twain");
    quiz[1].correctOption = 'B';

    strcpy(quiz[2].question, "What is 5 + 3?");
    strcpy(quiz[2].options[0], "A. 5");
    strcpy(quiz[2].options[1], "B. 8");
    strcpy(quiz[2].options[2], "C. 10");
    strcpy(quiz[2].options[3], "D. 15");
    quiz[2].correctOption = 'B';

    strcpy(quiz[3].question, "Which planet is known as the Red Planet?");
    strcpy(quiz[3].options[0], "A. Earth");
    strcpy(quiz[3].options[1], "B. Venus");
    strcpy(quiz[3].options[2], "C. Mars");
    strcpy(quiz[3].options[3], "D. Jupiter");
    quiz[3].correctOption = 'C';

    strcpy(quiz[4].question, "Which programming language is this quiz written in?");
    strcpy(quiz[4].options[0], "A. Python");
    strcpy(quiz[4].options[1], "B. Java");
    strcpy(quiz[4].options[2], "C. C");
    strcpy(quiz[4].options[3], "D. C++");
    quiz[4].correctOption = 'C';
}

// Take quiz
void takeQuiz(struct Question quiz[], int size) {
    char userAnswer;
    int score = 0;

    printf("\nStarting Quiz...\n");
    for (int i = 0; i < size; i++) {
        printf("\nQuestion %d: %s\n", i + 1, quiz[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", quiz[i].options[j]);
        }
        printf("Your answer (A/B/C/D): ");
        scanf(" %c", &userAnswer);

        if (checkAnswer(userAnswer, quiz[i].correctOption)) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong. The correct answer is %c.\n", quiz[i].correctOption);
        }
    }

    printf("\nQuiz Completed! Your score: %d/%d\n", score, size);
}

// Check if the answer is correct
int checkAnswer(char userAnswer, char correctAnswer) {
    return (userAnswer == correctAnswer);
}
