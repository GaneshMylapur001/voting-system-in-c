#include <stdio.h>
#include <string.h>

#define PASSWORD "12345"

int main() {
    int votes[5] = {0}; 
    char candidates[5][20] = {"candidate 1", "candidate 2", "candidate 3", "candidate 4", "candidate 5"};
    char password[20];
    int choice, i, voting = 1;

    printf("Enter password to access voting system: ");
    scanf("%s", password);

    if (strcmp(password, PASSWORD) != 0) {
        printf("Incorrect password. Access denied.\n");
        return 0;
    }

    while (voting) {
        printf("\n---------- Voting System ----------\n");
        printf("Please vote for your candidate:\n");
        for (i = 0; i < 5; i++) {
            printf("%d. %s\n", i + 1, candidates[i]);
        }
        printf("6. Show Results\n");
        printf("7. Exit\n");
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 5) {
            votes[choice - 1]++;
            printf("Thank you for voting!\n");
        } else if (choice == 6) {
            printf("\n---------- Voting Results ----------\n");
            for (i = 0; i < 5; i++) {
                printf("%s: %d votes\n", candidates[i], votes[i]);
            }
        } else if (choice == 7) {
            voting = 0;
            printf("Exiting the voting system. Goodbye!\n");
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
