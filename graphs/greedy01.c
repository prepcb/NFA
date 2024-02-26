#include<stdio.h>
#include<stdlib.h>

#define N 100
#define Q 6
int B[N]={0},iB=19;//stores final order

void q(int A[N],int M[N][N],int i){
    char k;
    //printf(" %c",n+'a');
    //scanf("%c",&k);
    A[i]=1;
    int j;
    
    for(j=0;j<N;j++)  
        if(M[i][j]==1)      //A[i]-->A[j] since M[i][j]=1
            if(A[j]==0)     //1st occurrence of A[j]?
                q(A,M,j);   //Then find next in link:  A[j] --> ?
                    
    


                                    //on return (depth path exhausted) check next A[i]-->A[j]
                                    //if no more then return up tree
 // these lines are to reverse order
    B[iB] = i;
    iB--;
    //print as we find them
    printf("%c",i+'a');
}

int main(){

//contains all the transitions 
//row 0 for 'a'
//row 1 for 'b' etc
//row 4='d' has a transition to j and w (column 9 and 22 respectively)
int M[N][N]={0};
int V[] = {0,9,0,0,0,14,15,0,0,0,23,0,0,0,0,0,0,0,0,0,2,0,0,19,0,
0,6,0,0,0,0,6,0,0,0,11,0,0,0,16,0,0,18,0,30,0,5,0,0,0,0,0,20,0,0,44,0,0,0,0,0,0,0,0};


    char r;
    int i=0,j,w,n=8,k=0;

    printf("happy with default transitions ('y' or newline)?\n");
    while(r=getchar()){
        if(r=='y'){

            for(i=0;i<8;i++)
                for(j=0;j<8;j++)
                    {
                        M[i][j]=V[k];
                        k++;
                    }
        }    
        else

            {
                printf("Input number of nodes\n");
                scanf("%d",&n);
                for(i=0;i<n;i++){
                    printf("\ninput node and weight for node %d (EofS=-1)\n",i);
                    scanf("%d",&j);
                    while(j>=0){
                        scanf("%d",&w);
                        M[i][j] = w;
                        scanf("%d",&j);
                    }
                }  
            }
           break;
        }
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%d,",M[i][j]);
        printf("\n");
    }
    //now look at transitions
    int A[N][N]={0};
    A[0][0]=1; // start state
    int ii=0,min;
    for(k=0;k<Q;k++){
        min=2000;
    
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(A[j][k]>0)
                    A[i][k+1]+=M[j][i];
       
        for(i=0;i<n;i++)
            if(A[i][k+1]<min&&A[i][k+1]>0){
                min=A[i][k+1];
                ii=i;
            }
        for(i=0;i<n;i++)
            if(ii!=i)A[i][k+1]=0;
    }
    printf("\n");
    for(k=0;k<Q;k++){
        for(i=0;i<n;i++)
            printf("%7d,",A[i][k]);
        printf("\n");
    }


}