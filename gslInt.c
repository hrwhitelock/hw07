#include <stdio.h>
#include <math.h>
#include <gsl/gsl_integration.h>
#define NMAX 100


double f (double x, void *params);
double f (double x, void *params)
{
    double n = *(double *) params;
    double f = exp (-x) * pow (x, n);

    return f;
}
void integralGen (int nmin, int nmax, double vals[]);
void integralGen (int nmin, int nmax, double vals[])
{
    double result, error;
    double a = 0., b = 1.;
    double abserr = 1.e-9, relerr = 1.e-9;
    double n;
    size_t np = 1000;
    gsl_integration_workspace *w = gsl_integration_workspace_alloc (np);

    gsl_function F;

    F.function = &f;

    for (int i = nmin; i <= nmax; i++)
    {
        n = (double) i;
        F.params = &n;

        gsl_integration_qag (&F, a, b, abserr, relerr, np, GSL_INTEG_GAUSS15,
            w, &result, &error);
        vals[i] = result;

    }

    gsl_integration_workspace_free (w);
}
