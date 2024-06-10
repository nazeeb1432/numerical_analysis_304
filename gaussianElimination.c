#include <stdio.h>
#include<math.h>
#define NMAX 4
#define EPS 1e-6
int main(){
    double pivot,mp;
    int p;

     double x[NMAX][NMAX+1]={{1,-1,2,-1,-8},{2,-2,3,-3,-20},{1,1,1,0,-2},{1,-1,4,3,4}};
   // double x[NMAX][NMAX+1]={{1,-1,0,0,-160},{0,1,-1,0,240},{0,0,1,-1,-600},{1,0,0,-1,-520}};

    for( int i=0;i<NMAX;i++){
        for(int j=0;j<NMAX+1;j++){
            printf("%0.1lf\t",x[i][j]);
        }printf("\n");
    }

    printf("After\n");

    for(int i=0;i<NMAX-1;i++){
        pivot=x[i][i];
        if(fabs(pivot)<EPS){
            for(p=i+1;p<NMAX;p++){
                if(x[p][i]!=0.0) break;
            }
            for(int a=0;a<NMAX+1;a++){//swap
                int temp=x[i][a];
                x[i][a]=x[p][a];
                x[p][a]=temp;
            }
        }
        for(int j=i+1;j<NMAX;j++){
            pivot=x[i][i];
            mp=x[j][i]/pivot;
            for(int k=0;k<NMAX+1;k++){
                x[j][k]-=mp*x[i][k];
            }
        }
    }

     for(int i=0;i<NMAX;i++){
        for(int j=0;j<NMAX+1;j++){
            printf("%0.1lf\t",x[i][j]);
        }printf("\n");
    }
    printf("\n");
    
    if(fabs(x[NMAX-1][NMAX-1])<EPS){
        printf("Solutuon does not exist\n");
        exit(1);
    }

    for(int i=NMAX-1; i>0; i--){
        pivot = x[i][i];
        for(int j=i-1; j>=0; j--){
            mp=x[j][i]/pivot;
            for(int k=0; k<NMAX+1; k++){
                x[j][k]-=x[i][k]*mp;
            }
        }
    }

    // for(int i=NMAX-1;i>0;i--){
    //     pivot=x[i][i];
    //     for(int j=i-1;j>=0;j--){
    //          mp=x[j][i]/pivot;
    //         for(int k=0;k<NMAX+1;k++){
    //             x[j][k]-=mp*x[i][k];
    //         }
    //     }
    // }

    printf("After 2:\n");
     for(int i=0;i<NMAX;i++){
        for(int j=0;j<NMAX+1;j++){
            printf("%0.1lf\t",x[i][j]);
        }printf("\n");
    }
    printf("\n");

    for(int i=0;i<NMAX;i++){
        x[i][NMAX]/=x[i][i];
        x[i][i]/=x[i][i];
    }    

    printf("After 3:\n");
     for(int i=0;i<NMAX;i++){
        for(int j=0;j<NMAX+1;j++){
            printf("%0.1lf\t",x[i][j]);
        }printf("\n");
    }
    printf("\n");
    
}