#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<gsl/gsl_integration.h>
#include"gslInt.c"
#include "timer.c"
#include"adjust.c"
#include"recur.c"

#define NMAX 100
int main(){	
	double vals1[NMAX+1], vals2[NMAX+1];
	
	integralGen(1,100, vals2);
	integral_recur(1, 100, vals1);
	printf("n	Recursion	gsl\n"); 
	for(int j =1; j<NMAX+1; j++){
		printf("%d	%f	%f\n",j,vals1[j], vals2[j]);
	}

	int count1 = 1000;
        double timea;
        double timea1;
        double tmin = 1.;
        double tmax = 2.;

        do
        {
                timer_start ();
                for (int i = 0; i <count1; i++){
                        integral_recur(1, 100, vals1);
                }
                timea = timer_stop ();
                timea1 = timea / count1;
                printf ("Recursion: %10.2f usec %10.6f sec %10d\n",
                timea1 * 1.e6, timea, count1);
                count1 = adjust_rep_count (count1, timea, tmin, tmax);
        }
	while ((timea >tmax) || (timea < tmin));
	int count2 = 1000;
        double timeb;
        double timeb1;

        do
        {
                timer_start ();
                for (int i = 0; i <count2; i++){
                        integralGen(1,100, vals2);
                }
                timeb = timer_stop ();
                timeb1 = timeb / count2;
                printf ("gsl Integration:  %10.2f usec %10.6f sec %10d\n",
                timeb1 * 1.e6, timeb, count2);
                count2 = adjust_rep_count (count2, timeb, tmin, tmax);
        }
        while ((timeb > tmax) || (timeb < tmin));

}	
		
