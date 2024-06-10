#include<stdio.h>
#include<stdlib.h>
# define EPSILON 10e-6

double func(double x){
    return x*x*x-x*x+2;
}

void bisection(double a,double b){

    if(func(a)*func(b)>=0){
        printf("You have not assumed right a and b\n");
        return;
    }

    double c;

    while((b-a)>=EPSILON){
        //calculate mid
        c=(a+b)/2;
        

        if(func(c)==0){
            break;
        }
        else if(func(c)*func(a)<0){
            b=c;
        }
        else a=c;

    }

    printf("root is %lf\n",c);


}

int main(){

    //initial value assumed;
    double a=-200,b=300;
    bisection(a,b);
    return 0;
}