#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define EPS 10.0e-6

#define  f(x)(x*x*x+4*x*x-10)
#define fprime(x)(3*x*x+8*x)

void newton_raphson(double x0){

    for(int i=0;i<=30;i++){
        double x1;
        x1=x0-(f(x0)/fprime(x0));

        printf("x0:%lf\tx1:%lf\tf(x1):%lf\n",x0,x1,f(x1));

        if(fabs(f(x1))<EPS){
            printf("approximate root: %lf\n",x1);
            break;
        }
        else{
            x0=x1;
        }
    }
}

int main(){
    double x0;
    printf("Enter initial guess:");
    scanf("%lf",&x0);

    newton_raphson(x0);
}
