#include<stdio.h>
#define Bk  2
#define Ak  3
#define N 6
int main(){

    int R[]={1,1,0,1,0,0};
    int A[Ak][2] = {0,0, 1,2, 2,3}; //graph for 0
    int B[Bk][2] = {0,0, 0,1};      //graph for 1


    int i,k,j;
    int x[N+1][4] = {0};
    

    for(i=0;i<Ak;i++){
        for(j=0;j<2;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");

    }
    
    x[0][0] = 1; //initialise start state 
    for(j=0;j<4;j++){
        printf("%d ",x[0][j]);
    }
    printf("\n");


    // transitions are "OR" matrix operations: x[k][i] -> x[k][i] *A[i][j] = x[k+1][j]
    // where A[i][j] is 1 or 0 and stored as sparse matrix. Similarly B. 
    for(i=0;i<N;i++){
        switch(R[i]){
            case 0:
                for(k=0;k<Ak;k++){
                    x[i+1][A[k][1]] = x[i+1][A[k][1]] | x[i][A[k][0]];
                }
                break;
            case 1:
                for(k=0;k<Bk;k++){
                    x[i+1][B[k][1]] = x[i+1][B[k][1]] | x[i][B[k][0]];
                }
                break;
        }
        for(j=0;j<4;j++){
            printf("%d ",x[i+1][j]);
        }
        printf("\n");

    }
    
    int n;
    n = 1 & x[N][3];
    switch(n){
        case 0:
            printf("Not accepted\n");
            break;
        default:
            printf("Accepted\n");
            break;

    }

    
}