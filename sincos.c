#include<stdio.h>
#include<math.h>

#define PI 3.1416

int main(){

	int n=100;
	double a=0,b=2*PI,h,x;
	
	x=a;
	h=(b-a)/100;
	
	printf("\"x\",\"sin(x)\",\"cos(x)\"\n");
	printf("%0.3lf,%0.3lf,%0.3lf\n",x,sin(x),cos(x));
	
	for(int i=1;i<=100;i++){
	    
	    x=x+h;
	    printf("%0.3lf,%0.3lf,%0.3lf\n",x,sin(x),cos(x));
	
	}
	


}
