#include "salary.h"

void calc_tax(const double *gross, double *tax_out) {
    double g = *gross;
    double t = 0.0;

    if (g <= 100.0) {
        t = 0.0;
    } else if (g <= 300.0) {
        t = 0.20 * g;
    } else {
        t = 0.28 * g;
    }
    *tax_out = t;
}

void calc_med_insurance(const double *gross, double *med_out) {
    *med_out = 0.05 * (*gross);
}

void calc_maternity(const double *gross, double *mat_out) {
    *mat_out = 0.003 * (*gross); /* 0.3% = 0.003 */
}

void calc_social_security(const double *gross, double *ssf_out) {
    *ssf_out = 0.03 * (*gross);
}