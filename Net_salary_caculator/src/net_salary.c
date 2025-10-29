#include "salary.h"

bool net_salary(const double *gross, double *net_out,
                double *tax, double *med, double *mat, double *ssf) {
    if (!gross || !net_out || !tax || !med || !mat || !ssf) return false;
    if (*gross < 0.0) return false;

    calc_tax(gross, tax);
    calc_med_insurance(gross, med);
    calc_maternity(gross, mat);
    calc_social_security(gross, ssf);

    double total = *tax + *med + *mat + *ssf;
    *net_out = *gross - total;
    return true;
}