#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define EPS 10.0e-6
#define f(x) (x*x*x+4*x*x-10)//=0
#define g(x) (0.5*sqrt(10-x*x*x))
// #define g(x) (cbrt(10-4*x*x))


void fixed_point(double x0){

    printf("x0: %lf \n",x0);

    for(int i=0;i<100;i++){
        double x1=g(x0);
        
        printf("x0:%lf\tx1=%lf\n",x0,x1);

    if(fabs(f(x1))<EPS){
        printf("Approximate root is %lf\n",x1);
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

    fixed_point(x0);
    
    return 0;
}