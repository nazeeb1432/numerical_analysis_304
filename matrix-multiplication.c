#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 50
int main(){

    int a[N][N],b[N][N],c[N][N],i,j,k,m,n,p,q,sum;
    printf("Enter rows and column for first matrix:\n");
    scanf("%d %d",&m,&n);
    // printf("Enter first matrix:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            // scanf("%d",&a[i][j]);
            a[i][j]=rand()%20;
        }
    }
    printf("Enter rows and column for second matrix:\n");
    scanf("%d %d",&p,&q);
    // printf("Enter second matrix:\n");
    for(i=0;i<p;i++){
        for(j=0;j<q;j++){
            // scanf("%d",&b[i][j]);
            b[i][j]=rand()%30;
        }
    }
    printf("\nfirst matrix is :\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d\t",a[i][j]);
        }printf("\n");
    }
    printf("\nSecond matrix is :\n");
    for(i=0;i<p;i++){
        for(j=0;j<q;j++){
            printf("%d\t",b[i][j]);
        }printf("\n");
    }
    if(n!=p){
        printf("Cannot multiply");

    }else{//The ulltimate c matrix,order-m*q;
        for(i=0;i<m;i++){
            for(j=0;j<q;j++){
                sum=0;
                for(k=0;k<n;k++){//n->the common order
                    sum=sum+a[i][k]*b[k][j];
                }c[i][j]=sum;
            }
        }
        printf("multiplication is :\n");
         for(i=0;i<m;i++){
            for(j=0;j<q;j++){
                printf("%d\t",c[i][j]);
            }printf("\n");
        }



    }

    

    return 0;
}