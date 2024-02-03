#include<stdio.h>
#define N 19


void q(int A[N],int M[N][N],int n){
    char k;
    printf(" %c",n+'a');
    //scanf("%c",&k);
    A[n]=1;
    int i, j;
    
    i = n;
//    for(i=0;i<N;i++)                //change these two lines for "i = n" for BFS
//        if(A[i]==1)                 //for "i = n" for BFS. Check all A[i] on this level
            for(j=0;j<N;j++)    
                if(M[i][j]==1)      //A[i]-->A[j] since M[i][j]=1
                    if(A[j]==0)     //1st occurrence of A[j]?
                        q(A,M,j);   //Then find next in link:  A[j] --> ?
                                    //on return (depth path exhausted) check next A[i]-->A[j]
                                    //if no more then return up tree
        
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
    

    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
            printf("%d,",M[i][j]);
        printf("\n");
    }
    */
    int A[N]={0};
    printf("\n");
    q(A,M,0);
    printf("\n");
  



}