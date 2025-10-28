#ifndef SALARY_H
#define SALARY_H

#include <stdbool.h>

/* Deduction calculators (input via *gross; outputs via result pointer) */
void calc_tax(const double *gross, double *tax_out);
void calc_med_insurance(const double *gross, double *med_out);   /* 5% */
void calc_maternity(const double *gross, double *mat_out);       /* 0.3% */
void calc_social_security(const double *gross, double *ssf_out); /* 3% */

/* Aggregator: computes all deductions and net salary */
bool net_salary(const double *gross, double *net_out,
                double *tax, double *med, double *mat, double *ssf);

#endif /* SALARY_H */