#include<bits/stdc++.h>
using namespace std;
#define n 3

double A[n][n],L[n][n],U[n][n],mul_matrix[n][n];

void printMatrix(double arr[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           printf("%7.3f",arr[i][j]);
        }printf("\n");
    }
}
bool successful_decompose(){
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                double sum=0;
                for(int k=0;k<n;k++){//n->the common order
                    sum=sum+L[i][k]*U[k][j];
                }mul_matrix[i][j]=sum;
            }
        }

        return (A==mul_matrix);
}

int main(){
    double pivot,m;
    int p;
    
    // freopen("lu_decompose.txt","r",stdin);

    cout<<"Enter A matrix:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>A[i][j];
        }
    }
    cout<<endl;
    //initialize L matrix

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                L[i][j]=1;
            }
            else{
                L[i][j]=0;
            }
        }
    }
    //copy A matrix to U matrix and then perform gauss elimination on U
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            U[i][j]=A[i][j];
        }
    }
    //gauss elimination on U and creating L
     for(int i=0;i<n-1;i++){
        pivot=U[i][i];
        if(pivot==0){
            for(p=i+1;p<n;p++){
                if(U[p][i]!=0.0) break;
            }
            for(int a=0;a<n;a++){//swap
                int temp=U[i][a];
                U[i][a]=U[p][a];
                U[p][a]=temp;
            }
        }
        for(int j=i+1;j<n;j++){
            pivot=U[i][i];
            m=U[j][i]/pivot;
            L[j][i]=m;
            for(int k=0;k<n;k++){
                U[j][k]-=m*U[i][k];
            }
        }
    }

    cout<<"After decomposition,L:\n";
    printMatrix(L);
    cout<<"\nAfter decomposition,U:"<<endl;
    printMatrix(U);

    /*bool b=successful_decompose();
    if(b){
        cout<<"Successful decomposition\n";
    }
    else{
        cout<<"Nott successful\n";
    }*/

    cout<<"After multiplication of L and U\n";

    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                double sum=0;
                for(int k=0;k<n;k++){//n->the common order
                    sum=sum+L[i][k]*U[k][j];
                }mul_matrix[i][j]=sum;
            }
        }

        printMatrix(mul_matrix);

}