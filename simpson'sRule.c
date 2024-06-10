#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define f(x)(x*x+1)


int main(){

    double a=0.0,b=2.0,h,Sum_X=0.0,Sum_O=0.0,Sum_E=0.0,I;

    FILE *fp;
    fp=fopen("trapezoidalInput.txt","r");

	int n=10;
	h=(b-a)/10;

    double x[n+1],y[n+1];
    
    for(int i=0;i<n+1;i++){
        fscanf(fp,"%lf %lf",&x[i],&y[i]);
    }
    fclose(fp);

    Sum_X=y[0]+y[n];

    for(int j=1;j<n;j++){
        if(j%2==0) Sum_E+=y[j];
        else Sum_O+=y[j];
    }

    I=h*(Sum_X+4*Sum_O+2*Sum_E)/3;

    printf("Simpson's 1/3rd Rule.................\n");
    printf("Integral value =%lf\n",I);
    printf(".....................................\n");

    

    return 0;
}