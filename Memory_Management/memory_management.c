#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 10
#define SHRINK_SIZE 6
#define MAX_EMAIL_LENGTH 100

// Function to display student emails
void displayEmails(char **emails, int count) {
    printf("\n--- Student Email Addresses ---\n");
    for (int i = 0; i < count; i++) {
        printf("Student %d: %s\n", i + 1, emails[i]);
    }
    printf("-------------------------------\n");
}

// Function to free all allocated memory
void freeMemory(char **emails, int count) {
    for (int i = 0; i < count; i++) {
        free(emails[i]);
        emails[i] = NULL;
    }
    free(emails);
}

int main() {
    char **studentEmails;
    char buffer[MAX_EMAIL_LENGTH];
    int i;
    
    printf("=== STUDENT EMAIL MANAGEMENT SYSTEM ===\n");
    printf("2023 May Cohort\n\n");
    
    // Allocate memory for 10 student email pointers using malloc
    printf("Allocating memory for %d students...\n", INITIAL_SIZE);
    studentEmails = (char **)malloc(INITIAL_SIZE * sizeof(char *));
    
    if (studentEmails == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    printf("Memory allocated successfully at address: %p\n", (void *)studentEmails);
    
    // Input email addresses for 10 students
    printf("\nEnter email addresses for %d students:\n", INITIAL_SIZE);
    for (i = 0; i < INITIAL_SIZE; i++) {
        printf("Student %d email: ", i + 1);
        scanf("%s", buffer);
        
        // Allocate memory for each email string using malloc
        studentEmails[i] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        
        if (studentEmails[i] == NULL) {
            printf("Memory allocation failed for student %d!\n", i + 1);
            // Free previously allocated memory
            for (int j = 0; j < i; j++) {
                free(studentEmails[j]);
            }
            free(studentEmails);
            return 1;
        }
        
        strcpy(studentEmails[i], buffer);
    }
    
    // Display all 10 student emails
    printf("\n=== INITIAL DATA ===");
    displayEmails(studentEmails, INITIAL_SIZE);
    
    printf("\nCurrent number of emails: %d students\n", INITIAL_SIZE);
    
    // Shrink the array from 10 to 6 students
    printf("\n=== SHRINKING MEMORY ===\n");
    printf("Reducing cohort size from %d to %d students...\n", INITIAL_SIZE, SHRINK_SIZE);
    
    // Free memory for students 7-10 (indices 6-9)
    printf("Freeing memory for students %d to %d...\n", SHRINK_SIZE + 1, INITIAL_SIZE);
    for (i = SHRINK_SIZE; i < INITIAL_SIZE; i++) {
        free(studentEmails[i]);
        studentEmails[i] = NULL;
    }
    
    // Reallocate the array to smaller size using realloc
    printf("Reallocating array to smaller size...\n");
    char **temp = (char **)realloc(studentEmails, SHRINK_SIZE * sizeof(char *));
    
    if (temp == NULL) {
        printf("Reallocation failed! Keeping original allocation.\n");
        // Original data is still intact
    } else {
        studentEmails = temp;
        printf("Memory successfully shrunk!\n");
    }
    
    // Display remaining 6 student emails
    printf("\n=== AFTER SHRINKING ===");
    displayEmails(studentEmails, SHRINK_SIZE);
    
    printf("\nUpdated number of emails: %d students\n", SHRINK_SIZE);
    
    // Free all remaining memory
    printf("\n=== CLEANUP ===\n");
    printf("Freeing all remaining allocated memory...\n");
    freeMemory(studentEmails, SHRINK_SIZE);
    
    printf("All memory freed successfully!\n");
    printf("Program completed.\n");
    
    return 0;
}
