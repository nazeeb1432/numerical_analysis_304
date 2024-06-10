#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

#define EPS 10.0e-6

# define f(x)(sqrt(x))
# define g(x)(x*x)

#define h(x)(f(x)-g(x))

double a=0.0,c,h,I1,I2,Sum_X=0.0,Sum_O=0.0,Sum_E=0.0;
int n=10;

double bisection(double a,double b){//these a and b are the bounds for  bisection

    int N=100;
    if(h(a)*h(b)>0)exit(0);

    for(int i=1;i<=N;i++){
         c=(a+b)/2;  
        // c=(a*f(b)-b*f(a))/(f(b)-f(a));  
        if(fabs(h(c))<EPS){
            printf("\nroot in bisection %lf\n",c);
            return c;
        }

        if(h(c)*h(a)<=0){
            b=c;
        }
        else a=c;
    }

}

double simpsons(double x[],double y[]){

     Sum_X=y[0]+y[n];

    for(int j=1;j<n;j++){
        if(j%2==0) Sum_E+=y[j];
        else Sum_O+=y[j];
    }

    double I=h*(Sum_X+4*Sum_O+2*Sum_E)/3;

    return I;
}

int main(){
    double intersection;//f(x)-g(x) 

    intersection=bisection(1,2.5);//x er kon value er jonno h(x) er value 0

    double x[n+1],y[n+1],y2[n+1];
    h=(intersection-a)/n;

    
    for(int i=0;i<n+1;i++){
        x[i]=a+i*h;
    }
    for(int i=0;i<n+1;i++){
        y[i]=f(x[i]);
    }
    for(int i=0;i<n+1;i++){
        y2[i]=g(x[i]);
    }

    I1=simpsons(x,y);
    I2=simpsons(x,y2);

    printf("Area:\n");
    printf("%lf\n",fabs(I1-I2));

    return 0;
}