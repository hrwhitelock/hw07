#include<stdio.h>
#include<stdlib.h>
#include<math.h>


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



