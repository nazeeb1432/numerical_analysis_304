#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define EPS 10.0e-6
#define  f(x)(x*x*x+4*x*x-10)

void secant(double x0,double x1){

    double x2;
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("ITER\t\tx0\t\t\tx1\t\t\tx2\t\t\tf(x0)\t\t\tf(x1)\t\t\tf(x2)\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for(int i=1;i<=30;i++){
        x2=(x0*f(x1)-x1*f(x0))/(f(x1)-f(x0));

        printf("%d\t\t%lf\t\t%lf\t\t%lf\t\t%lf\t\t%lf\t\t%lf\n",i,x0,x1,x2,f(x0),f(x1),f(x2));

        if(fabs(f(x2))<EPS){
            printf("Approximate root:%lf\n",x2);
            break;
        }
        else{
            x0=x1;
            x1=x2;
        }
    }
}

int main(){
    double x0,x1;
    printf("Enter initial two guesses:");
    scanf("%lf %lf",&x0,&x1);

    secant(x0,x1);
}

