#include<stdio.h>
#include<stdlib.h>
int R(int T[][2],int A[],int d){
    if(d==0)
        return(0);
    else
        return(  T[R(T,A,d-1)] [A[d-1]]  );
}

int main(){
    //Uses the formula R(n) = delta(R(n-1),A[n-1])
    // with R(0) the starting state

    // Input DFA and string
    printf("Input number of states\n");
    int n,T[100][2];
    scanf("%d",&n);
    if(n<0)exit(0);
    printf("The states are numbered 0 to %d\n Starting state is assumed '0'\n",n-1);
    printf("Input string is made up of 0s and 1s\n");
    printf("Input %d x 2 transition table in pairs\n ",n);
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&T[i][0]);
        scanf("%d",&T[i][1]);
    }
    int k =0;
    while(k==0){
    printf("Input string of 0s and 1s followed by -1\n");
    int d,A[100];
    d = 0;
    scanf("%d",&A[d]);
    while(A[d]>=0){
        d++;
        scanf("%d",&A[d]);
    }
    ///// end of input //////


    printf("Final state is %d\n",R(T,A,d));
    }

}