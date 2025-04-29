#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 5

char candidates[MAX_CANDIDATES][20] = {"candidate 1", "candidate 2", "candidate 3", "candidate 4", "candidate 5"};
int votes[MAX_CANDIDATES] = {0};

void castVote() {
    int choice;
    int i;
    printf("\n---------- Voting Menu ----------\n");
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%d. %s\n", i + 1, candidates[i]);
    }
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= MAX_CANDIDATES) {
        votes[choice - 1]++;
        printf("Vote casted to %s!\n", candidates[choice - 1]);
    } else {
        printf("Invalid choice. Vote not counted.\n");
    }
}

void showResults() {
	int i;
    printf("\n---------- Voting Results ----------\n");
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i], votes[i]);
    }

    int maxVotes = votes[0];
    int winnerIndex = 0;

    for (i = 1; i < MAX_CANDIDATES; i++) {
        if (votes[i] > maxVotes) {
            maxVotes = votes[i];
            winnerIndex = i;
        }
    }

    printf("\n>>> %s has won the election with %d votes! <<<\n", candidates[winnerIndex], maxVotes);
}

int main() 
{
    char password[20];
    int option;
    char adminPass[] = "admin123";
    char loginPass[] = "12345";

    printf("Enter system password to activate EVM: ");
    scanf("%s", password);

    if (strcmp(password, loginPass) != 0) {
        printf("Access Denied! Wrong password.\n");
        return 0;
    }

    while (1) {
        printf("\n\n---------- Voting System Menu ----------\n");
        printf("1. Vote\n");
        printf("2. Admin Login (View Results)\n");
        printf("3. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                castVote();
                break;
            case 2: {
                char adminInput[20];
                printf("Enter admin password: ");
                scanf("%s", adminInput);
                if (strcmp(adminInput, adminPass) == 0) {
                    showResults();
                } else {
                    printf("Wrong admin password! Access denied.\n");
                }
                break;
            }
            case 3:
                printf("Thank you for using the voting system!\n");
                return 0;
            default:
                printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}
