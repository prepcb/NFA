#include<stdio.h>
#include<stdlib.h>

#define N 26

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
int M[N][N]={
0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,
0,0,0,1,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,
0,0,0,1,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,1,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    char r;
    int i=0,j;

    printf("happy with default transitions ('y' or newline)?\n");
    while(r=getchar()){
        if(r=='y')
            break;
        else
            for(i=0;i<N;i++){
                printf("\ninput for %c followed by newline\n",i+'a');

                while(r = getchar()){
                    if(r=='\n')
                        break;
                    else{
                        j = r - 'a';
                        M[i][j] = 1;
                    }
                }
            }
    }
    
    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
            printf("%d,",M[i][j]);
        printf("\n");
    }


    //compute dead letters to exclude them
    //these letters are not in the graph but useful
    // to have for conversion to numbers a=0,b=1,c=2 etc
    int A[N]={0};
    int sum;
    for(j=0;j<N;j++)
    {
        sum = 0;
        for(i=0;i<N;i++)
            sum=sum|(M[i][j])|(M[j][i]);
        if(sum==0)
            A[j]=1;
    }
    printf("\n");
    for(j=0;j<N;j++)
        if(A[j]==1)printf("dead letter %c\n",j+'a');
    printf("\n");

    printf("\n");
    //top call to topological search
    for(i=0;i<N;i++)
        if(A[i]==0)q(A,M,i);
    printf("\n\n");

    for(i=0;i<20;i++)
        printf("%c",B[i]+'a');
    printf("\n");
   
  



}