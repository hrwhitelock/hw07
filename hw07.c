#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<gsl/gsl_integration.h>
#include"gslInt.c"
#include "timer.c"
#include"adjust.c"

#define NMAX 100
#define E (exp(1))
double factorial(int);
double taylorint(int n, double x);
double taylorint(int n, double x){
	static double sum=0;
	double accuracy = 1.0E-10;
	static int iteration = 0; 
	double term;
	int sign = 1;
	double top = pow(x, n+1); 
	double bottom = n+1; 
	term = sign*top/bottom; 
	if(fabs(term) > accuracy){
		iteration +=1; 
		top *=x; 
		bottom = factorial(iteration)*(iteration + n +1);
		return sum+term+taylorint(n, x); 
	}
	else{
		iteration = 0; 
		return sum;
	} 
}
double factorial(int n)
{
  if (n == 0)
    return 1;
  else
    return(n * factorial(n-1));
}
double* integral_recur(int nmin, int nmax);
double* integral_recur(int nmin, int nmax){
	static double vals[NMAX+1];
	vals[nmax]=.003678;
	for (int n = nmax-1; n>=nmin; n--){
		vals[n]=(vals[n+1]+1/E)/(n+1);
	}
	return vals; 
}

int main(){	
	double *vals1, *vals2;
	
	vals2 = integralGen(1,100);
	vals1 = integral_recur(1, 100);
	printf("n	taylor	Recursion\n"); 
	for(int j =1; j<NMAX+1; j++){
		printf("%d	%f	%f	%f\n",j, taylorint(j,1.0),vals1[j], vals2[j]);
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
                        vals1 = integral_recur(1, 100);
                }
                timea = timer_stop ();
                timea1 = timea / count1;
                printf (" %10.2f usec %10.6f sec %10d\n",
                timea1 * 1.e6, timea, count1);
                count1 = adjust_rep_count (count1, timea, tmin, tmax);
        }
        while ((timea > tmax) || (timea < tmin));
        int count2 = 1000;
        double timeb;
        double timeb1;

        do
        {
                timer_start ();
                for (int i = 0; i <count2; i++){
                        vals2 = integralGen(1,100);
                }
                timeb = timer_stop ();
                timeb1 = timeb / count2;
                printf (" %10.2f usec %10.6f sec %10d\n",
                timeb1 * 1.e6, timeb, count2);
                count2 = adjust_rep_count (count2, timeb, tmin, tmax);
        }
        while ((timeb > tmax) || (timeb < tmin));
        int count3 = 1000;
        double timec;
        double timec1;

        do
        {
                timer_start ();
                for (int i = 0; i <count3; i++){
			for(int j =0; j<101; j++){
 			taylorInt(j, 1);
			}               
		}
                timec = timer_stop ();
                timec1 = timec / count3;
                printf (" %10.2f usec %10.6f sec %10d\n",
                timec1 * 1.e6, timec, count3);
                count3 = adjust_rep_count (count3, timec, tmin, tmax);
        }
        while ((timec > tmax) || (timec < tmin));

}


	
		

