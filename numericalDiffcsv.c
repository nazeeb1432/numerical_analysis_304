#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define f(x)(x*x+1)


int main(){
	double a=0.0,b=2.0,h;
	int n=10;
	h=(b-a)/2;
	
	double x[n+1],y[n+1],yd[n+1];
	
	for(int i=0;i<n+1;i++){
		scanf("%lf %lf",&x[i],&y[i]);
	}
	//calculate and store forward difference quotient.
	yd[0]=((y[1])-(y[0]))/((x[1])-(x[0]));
	//calculate central difference quotients
	
	for(int i=1;i<n;i++){
		yd[i]=(y[i+1]-y[i])/(x[i+1]-x[i]);
	}
	//now calculate back-ward difference quotient
	yd[n]=(y[n]-y[n-1])/(x[n]-x[n-1]);
	
	printf("i\tx[i]\t\tf(x[i])\t\tf'(x[i])\n");
	printf("-------------------------------------------------\n");
	
	for(int i=0;i<n+1;i++){
		printf("%d\t%lf\t%lf\t%lf\n",i,x[i],y[i],yd[i]);
	
	}
	
	
		
	
	
	


}
