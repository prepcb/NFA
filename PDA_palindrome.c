# include<stdio.h>
# include<stdlib.h>
#define n 4
void q0(int A[],int S[]);
void q1(int A[],int a,int S[],int s);
void q2(int A[],int a,int S[],int s);
void q3();

void q0(int A[],int S[]){
    printf("q0:\n");

    switch(A[0]){
        case -1:
            q3();
        default:
            S[0] = -1;
            q1(A,0,S,0);
    }
}

void q1(int A[],int a,int S[],int s){
    printf("q1:\n");
    switch(A[a]){
        case -1:
            return;
        default:
            S[s+1] = A[a];
            q2(A,a+1,S,s+1);
            q2(A,a+1,S,s);
            q1(A,a+1,S,s+1);
    }
}

void q2(int A[],int a,int S[],int s){
    printf("q2:\n");
    int d;
    d = S[s] - A[a];
    switch(d){
        case 0:
            if(A[a+1]==-1)
                q3();
            else
                q2(A,a+1,S,s-1);
            break;
        default:
            break;
    }
}

void q3(){
        printf("Success: a palindrome\n");
        exit(0);
}

int main(){
    int A[] = {5,8,12,3,10,12,10,3,12,8,5,-1};
    int S[99] = {-2};
    q0(A,S);
    printf("Fail: not a palindrome\n");
}