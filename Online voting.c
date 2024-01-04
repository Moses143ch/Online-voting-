include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Candidate {
    char name[50];
    int votes;
};

struct Voter {
    char username[50];
    char password[50];
    int hasVoted;
};


int authenticateVoter(struct Voter* voters, int numVoters, char* username, char* password) {
    for (int i = 0; i < numVoters; ++i) {
        if (strcmp(voters[i].username, username) == 0 && strcmp(voters[i].password, password) == 0) {
            if (voters[i].hasVoted == 0) {
                voters[i].hasVoted = 1;
                return 1; 
            } else {
                return -1; 
            }
        }
    }
    return 0; 
}

// Function to vote for a candidate
void vote(struct Candidate* candidates, int numCandidates, int candidateIndex) {
    candidates[candidateIndex].votes++;
}

// Main function
int main() {
    // Sample data initialization
    struct Candidate candidates[3];
    strcpy(candidates[0].name, "Candidate A");
    candidates[0].votes = 0;
    strcpy(candidates[1].name, "Candidate B");
    candidates[1].votes = 0;
    strcpy(candidates[2].name, "Candidate C");
    candidates[2].votes = 0;

    struct Voter voters[2];
    strcpy(voters[0].username, "user1");
    strcpy(voters[0].password, "pass1");
    voters[0].hasVoted = 0;

    strcpy(voters[1].username, "user2");
    strcpy(voters[1].password, "pass2");
    voters[1].hasVoted = 0;

    
    char username[50];
    char password[50];
    int authenticated = 0;

    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    authenticated = authenticateVoter(voters, 2, username, password);

    if (authenticated == 1) {
      
        printf("Candidates:\n");
        for (int i = 0; i < 3; ++i) {
            printf("%d. %s\n", i + 1, candidates[i].name);
        }

        
        int voteChoice;
        printf("Enter the number of the candidate you want to vote for: ");
        scanf("%d", &voteChoice);

    
        vote(candidates, 3, voteChoice - 1);

        printf("Thank you for voting!\n");
    } else if (authenticated == -1) {
        printf("You have already voted. Each voter can vote only once.\n");
    } else {
        printf("Authentication failed. Check your username and password.\n");
    }

    return 0;
}
