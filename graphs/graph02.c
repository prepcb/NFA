#include<stdio.h>
#define N 19


void q(int A[N],int M[N][N],int n){
    char k;
    printf(" %c",n+'a');
    //scanf("%c",&k);
    A[n]=1;
    int i, j;
    for(i=0;i<N;i++)
        if(A[i]==1)
            for(j=0;j<N;j++)
                if(M[i][j]==1)
                    if(A[j]==0)q(A,M,j);
        
}

int main(){

int M[N][N]={
0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,0,1,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,
0,1,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,
0,0,0,0,1,0,1,0,0,1,0,1,0,1,0,0,0,0,0,
0,0,0,0,1,1,0,0,1,0,1,0,0,1,1,0,0,0,0,
0,0,0,0,0,1,0,1,0,1,0,0,1,0,1,0,0,0,0,
0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,1,0,
0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,1,0,1,
0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,
0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0 };

    char r;
    int i=0,j;

    for (i=0;i<N;i++){
        printf("%c:", i+'a');
        for(j=0;j<N;j++){
            if(M[i][j]==1)printf("%c ",j+'a');
        }
        printf("\n");
    }
 /*   
    for(i=0;i<N;i++){
        printf("input for %c followed by 0\n",i+'a');
        scanf(" %c",&r);
        j = r -'a';
        while(j>=0){
            M[i][j]=1;
            scanf(" %c",&r);
            j = r -'a';
            printf("j=%d\n",j);
        }
    }
    */
    int A[N]={0};

    q(A,M,0);
    printf("\n");
  



}