#include<stdio.h>
//#define N 6
#define M 100
int main(){
    int m;
    printf("Input number of states\n");
    scanf("%d",&m);
    printf("Input connection pairs for 0 followed by negative number\n");
    int ipaircount,in;
    ipaircount = 0;

    int A[M][2]={0};
    int k=0;
    scanf("%d",&in);
    while(in >=0){
        A[ipaircount][k] = in;
        if(k==1){
            ipaircount++;
            k = 0;
        }
        else
            k = 1;
        scanf("%d",&in);
    }
    int Ak;
    Ak = ipaircount;
    printf("0 pairs %d\n",Ak);


    int B[M][2]={0};
    ipaircount = 0;
    in = 0;

    k=0;
    printf("Input connection pairs for 1 followed by negative number\n");

    scanf("%d",&in);
    while(k<2 && in >=0){
        B[ipaircount][k] = in;
        if(k==1){
            ipaircount++;
            k = 0;
        }
        else
            k = 1;
        scanf("%d",&in);
        }
    int Bk;
    Bk = ipaircount;
    printf("1 pairs %d\n",Bk);

    
    //int A[Ak][2] = {0,0, 1,2, 2,3}; //graph for 0
    //int B[Bk][2] = {0,0, 0,1};      //graph for 1
    int R[M]={0};
    int f;
    f = 0;
    while(f==0){

    
    printf("Input 0,1 input string followed by -1:\n");
    k=0;
    scanf("%d",&in);
    while(in>=0){
        R[k]=in;
        k++;
        scanf("%d",&in);
    }
    int N;
    N = k;


    int i,j;
    int x[M][M] = {0};
    

    for(i=0;i<Ak;i++){
        for(j=0;j<2;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");

    }
    
   // x[0][0] = 1; //initialise start state 
    int b;
    printf("Input start state:\n");
    scanf("%d",&b);
    x[0][b] = 1;


    for(j=0;j<m;j++){
        printf("%d ",x[0][j]);
    }
    printf("------------\n");


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
        for(j=0;j<m;j++){
            printf("%d ",x[i+1][j]);
        }
        printf("\n");

    }
    
    int n,a;
    printf("Input accept state(s) followed by -1\n");
    
    n = 0;
    scanf("%d",&a);
    while(a>=0){
        n = n | x[N][a];
        scanf("%d",&a);
    }

    switch(n){
        case 0:
            printf("Not accepted\n");
            break;
        default:
            printf("Accepted\n");
            break;

    }
    printf("Any more strings: 0 = yes?\n");
    scanf("%d",&f);
    }
    
}