#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define NMAX 100

double factorial(int);
double taylorint(int n, double x);
double taylorint(int n, double x){
	static double sum=0;
	double accuracy = 1.0E-10;
	static int iteration = 0; 
	double term;
	//int sign = -1; 
	term = pow(-1, iteration)*pow(x,iteration+n+1)/(factorial(iteration)*(iteration+n+1));
	if(fabs(term) > accuracy){
		iteration +=1; 
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
	static double tayvals[NMAX+1];
	//static double recurvals[NMAX+1];
	int i = 0;
	for (int n = nmin; n<=nmax; n++){
		tayvals[i] = taylorint(n, 1.0);
		i++;
	}
	return tayvals; 
}

int main(){	
	double *taylorvals;

	taylorvals = integral_recur(1, 100); 
	for(int j =0; j<NMAX; j++){
		printf("%f\n", integralvals[j] );
	}
}


	
		

