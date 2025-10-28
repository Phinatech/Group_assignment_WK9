#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAMES 20
#define MAX_LENGTH 50

// Function pointer type for comparison functions
typedef int (*CompareFunc)(const char*, const char*);

// Comparison function for ascending order
int compareAscending(const char *name1, const char *name2) {
    return strcmp(name1, name2);
}

// Comparison function for descending order
int compareDescending(const char *name1, const char *name2) {
    return strcmp(name2, name1);
}

// Bubble sort function using function pointer
void bubbleSort(char names[][MAX_LENGTH], int count, CompareFunc compare) {
    int i, j;
    char temp[MAX_LENGTH];
    
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (compare(names[j], names[j + 1]) > 0) {
                // Swap names[j] and names[j + 1]
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
}

// Function to convert string to lowercase for comparison
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char names[MAX_NAMES][MAX_LENGTH];
    char choice[10];
    CompareFunc compareFunction;
    
    printf("=== NAME SORTING PROGRAM ===\n");
    printf("Please enter 20 full names:\n");
    printf("----------------------------\n");
    
    // Clear input buffer
    getchar();
    
    // Input 20 names from user
    for (int i = 0; i < MAX_NAMES; i++) {
        printf("Enter name %d: ", i + 1);
        fgets(names[i], MAX_LENGTH, stdin);
        
        // Remove newline character if present
        size_t len = strlen(names[i]);
        if (len > 0 && names[i][len - 1] == '\n') {
            names[i][len - 1] = '\0';
        }
    }
    
    printf("\n----------------------------\n");
    printf("Enter 'asc' for ascending order or 'desc' for descending order: ");
    scanf("%s", choice);
    
    // Convert choice to lowercase for case-insensitive comparison
    toLowerCase(choice);
    
    // Select comparison function based on user input
    if (strcmp(choice, "asc") == 0) {
        compareFunction = compareAscending;
        printf("\nSorting in ASCENDING order...\n");
    } else if (strcmp(choice, "desc") == 0) {
        compareFunction = compareDescending;
        printf("\nSorting in DESCENDING order...\n");
    } else {
        printf("\nInvalid input! Defaulting to ASCENDING order...\n");
        compareFunction = compareAscending;
    }
    
    // Perform bubble sort using function pointer
    bubbleSort(names, MAX_NAMES, compareFunction);
    
    printf("\nSorted names:\n");
    printf("----------------------------\n");
    for (int i = 0; i < MAX_NAMES; i++) {
        printf("%2d. %s\n", i + 1, names[i]);
    }
    
    return 0;
}
