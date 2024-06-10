#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


#define EPS 10.0e-6
#define f(x) (x*x*x+4*x*x-10)

int main(){

    int n=100,i;
    double a=1.25,b=1.5,c;

    if(f(a)*f(b)>0)exit(0);
    printf("------------------------------------------------------------------------------------------\n");
    printf("ITER        a         b             c             f(a)              f(b)              f(c)\n");
    printf("------------------------------------------------------------------------------------------\n");

    for(int i=1;i<=n;i++){
        c = (a*f(b) - b*f(a))/ (f(b) - f(a));

        printf("%d      %lf     %lf     %lf     %lf         %lf         %lf\n",i,a,b,c,f(a),f(b),f(c));    

        if(fabs(f(c))<EPS){
            printf("root-%lf",c);
            break;
        }

        if(f(c)*f(a)<0){
            b=c;
        }
        else a=c;
    }

    return 0;
}