#include<stdio.h>
#include<stdlib.h>
#include<math.h>
# define EPSILON 10.0e-6

double func(double x){
    // return x*x*x-x*x+2;
    return x*x*x+4*x*x-10;
}


void false_Pos(double a,double b){

    int flag=0;

    if(func(a)*func(b)>=0){
        printf("You have not assumed right a and b\n");
        exit(0);
    }

    double c;

    while(fabs(b-a)>=EPSILON){
        
    c = (a*func(b) - b*func(a))/ (func(b) - func(a));
 

        if(fabs(func(c))<EPSILON){
            printf("Root: %lf",c);
            flag=1;
            break;
        }
        else if(func(c)*func(a)<0){
            b=c;
        }
        else a=c;

    }

    if(!flag) printf("no root\n");

   


}

int main(){

    //initial value assumed;
    double a=-200,b=300;
    double a1=1.25,b1=1.5;
    false_Pos(a1,b1);
    return 0;
}