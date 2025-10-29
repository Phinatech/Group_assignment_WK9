#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAMES 20
#define MAX_LENGTH 50

// Define function pointer type for comparison functions
typedef int (*CompareFunc)(const char*, const char*);

// ---------------------------
// Case-insensitive comparison
// ---------------------------
int ciCmp(const char *a, const char *b)
{
    unsigned char ca, cb;
    while (*a && *b)
    {
        ca = (unsigned char)tolower((unsigned char)*a);
        cb = (unsigned char)tolower((unsigned char)*b);
        if (ca != cb)
            return (ca < cb) ? -1 : 1;
        a++;
        b++;
    }
    // Return difference if one string ends first
    return (*a == *b) ? 0 : (*a ? 1 : -1);
}

// Ascending and descending comparison functions
int compareAscending(const char *name1, const char *name2)
{
    return ciCmp(name1, name2);
}

int compareDescending(const char *name1, const char *name2)
{
    return ciCmp(name2, name1);
}

// ---------------------------
// Bubble sort implementation
// ---------------------------
void bubbleSort(char names[][MAX_LENGTH], int count, CompareFunc compare)
{
    char temp[MAX_LENGTH];
    int swapped;

    for (int i = 0; i < count - 1; i++)
    {
        swapped = 0;
        for (int j = 0; j < count - i - 1; j++)
        {
            if (compare(names[j], names[j + 1]) > 0)
            {
                // Swap names[j] and names[j + 1]
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
                swapped = 1;
            }
        }
        if (!swapped)
            break; // Stop early if no swaps made
    }
}

// ---------------------------
// Helper function to lowercase
// ---------------------------
void toLowerCase(char *str)
{
    for (int i = 0; str[i]; i++)
        str[i] = (char)tolower((unsigned char)str[i]);
}

// ---------------------------
// Main Program
// ---------------------------
int main(void)
{
    char names[MAX_NAMES][MAX_LENGTH];
    char choice[10];
    CompareFunc compareFunction;

    printf("=== NAME SORTING PROGRAM ===\n");
    printf("Please enter 20 full names:\n");
    printf("----------------------------\n");

    // Input 20 names
    for (int i = 0; i < MAX_NAMES; i++)
    {
        printf("Enter name %d: ", i + 1);
        if (!fgets(names[i], MAX_LENGTH, stdin))
        {
            fprintf(stderr, "Input error.\n");
            return 1;
        }

        // Remove newline character if present
        size_t len = strlen(names[i]);
        if (len > 0 && names[i][len - 1] == '\n')
            names[i][len - 1] = '\0';
    }

    printf("\n----------------------------\n");
    printf("Enter 'asc' for ascending order or 'desc' for descending order: ");
    if (scanf("%9s", choice) != 1)
    {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }

    toLowerCase(choice);

    // Select function based on user choice
    if (strcmp(choice, "asc") == 0)
    {
        compareFunction = compareAscending;
        printf("\nSorting in ASCENDING order...\n");
    }
    else if (strcmp(choice, "desc") == 0)
    {
        compareFunction = compareDescending;
        printf("\nSorting in DESCENDING order...\n");
    }
    else
    {
        printf("\nInvalid choice! Defaulting to ASCENDING order...\n");
        compareFunction = compareAscending;
    }

    // Sort names using bubble sort and function pointer
    bubbleSort(names, MAX_NAMES, compareFunction);

    // Print results
    printf("\nSorted names:\n");
    printf("----------------------------\n");
    for (int i = 0; i < MAX_NAMES; i++)
    {
        printf("%2d. %s\n", i + 1, names[i]);
    }

    return 0;
}