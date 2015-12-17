#include<stdio.h>
#include<math.h>

#define E (exp(1))
void integral_recur(int nmin, int nmax, double vals[]);
void integral_recur(int nmin, int nmax, double vals[]){
        vals[nmax]=.003678;
        for (int n = nmax-1; n>=nmin; n--){
                vals[n]=(vals[n+1]+1/E)/(n+1);
        }
}

