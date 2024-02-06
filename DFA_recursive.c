#include<stdio.h>
#include<stdlib.h>
// T is transition matrix; A is input string: scanned in.
int T[100][2],A[100];

//returns new state N given state N-1 and string character A[N-1] 
int R(int n){
    if(n==0)
        return(0);
    else
        return(  T[R(n-1)] [A[n-1]]  );
}
int main(){
    //Uses the formula R(n) = delta(R(n-1),A[n-1])
    // with R(0) the starting state

    // Input DFA and string
    printf("Input number of states\n");
    int n;
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
    int d;
    d = 0;
    scanf("%d",&A[d]);
    while(A[d]>=0){
        d++;
        scanf("%d",&A[d]);
    }
    ///// end of input //////


    printf("Final state is %d\n",R(d));
    }

}