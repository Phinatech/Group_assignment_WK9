#include <stdio.h>
#include "salary.h"

int main(void) {
    double gross;
    printf("Enter gross salary in USD: ");
    if (scanf("%lf", &gross) != 1) {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }

    double net = 0.0, tax = 0.0, med = 0.0, mat = 0.0, ssf = 0.0;
    if (!net_salary(&gross, &net, &tax, &med, &mat, &ssf)) {
        fprintf(stderr, "Error computing net salary. Check input.\n");
        return 1;
    }

    printf("\n--- Salary Breakdown ---\n");
    printf("Gross Salary:         $%.2f\n", gross);
    printf("Tax:                  $%.2f\n", tax);
    printf("Medication Insurance: $%.2f\n", med);
    printf("Maternity Leave:      $%.2f\n", mat);
    printf("Social Security Fund: $%.2f\n", ssf);
    printf("-------------------------------\n");
    printf("Net Salary:           $%.2f\n", net);
    return 0;
}