#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// #define f(x)(x*x+1)
#define f(x)(x*sin(x))


int main(){
	double a=0.0,b=2.0,h;
	int n=100;
	h=(b-a)/10;
	
	double x[n+1],y[n+1],yd[n+1];
	
	// for(int i=0;i<n+1;i++){
	// 	scanf("%lf %lf",&x[i],&y[i]);
	// }
	for(int i=0;i<=n;i++){
		x[i]=a+i*h;
	}
	for(int i=0;i<=n;i++){
		y[i]=f(x[i]);
	}
	
	//calculate and store forward difference quotient.
	yd[0]=((y[1])-(y[0]))/((x[1])-(x[0]));

	//now calculate back-ward difference quotient
	yd[n]=(y[n]-y[n-1])/(x[n]-x[n-1]);


	//calculate central difference quotients
	
	for(int i=1;i<n;i++){
		yd[i]=(y[i+1]-y[i-1])/(x[i+1]-x[i-1]);
	}
	
	
	 printf("i\tx[i]\t\tf(x[i])\t\tf'(x[i])\n");
	// printf("\"i\",\"x[i]\",\"f(x[i])\",\"f'(x[i])\"\n");
	 printf("-------------------------------------------------\n");
	
	for(int i=0;i<n+1;i++){
		 printf("%d\t%lf\t%lf\t%lf\n",i,x[i],y[i],yd[i]);
		// printf("%d,%lf,%lf,%lf\n",i,x[i],y[i],yd[i]);
	
	}
	
	
		
	
	
	


}
