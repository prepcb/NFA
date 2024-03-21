# include<stdio.h>
# include<stdlib.h>
#define n 4
void q0(int A[],int S[]);
void q1(int A[],int a,int S[],int s);
void q2(int A[],int a,int S[],int s);
void q3();

void q0(int A[],int S[]){
    printf("q0: string index (%d) value %2d; stack index %d\n",0,A[0],0);

    switch(A[0]){
        case -1:
            q3();
        default:
            S[0] = -1;
            q1(A,0,S,0);
    }
}

void q1(int A[],int a,int S[],int s){
    printf("q1: string index (%d) value %2d; stack index %d\n",a,A[a],s);
    switch(A[a]){
        case -1:
            return;
        default:
            S[s+1] = A[a];
            q2(A,a+1,S,s+1);//assume LHS of string is read (centre reached)
            q2(A,a+1,S,s);  //option for  central character (off length)
            q1(A,a+1,S,s+1);//keep reading LHS of string
    }
}

void q2(int A[],int a,int S[],int s){
    printf("q2: string index (%d) value %2d; stack index %d\n",a,A[a],s);
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
    int A[] = {6,8,12,3,10,10,3,12,8,6,-1};
    int S[99] = {-2};
    printf("for string \n{");
    int i;
    for(i=0;i<9;i++)
        printf("%2d, ",A[i]);
    printf("%2d}\n we test for palingdrome\n",A[9]);
    q0(A,S);
    printf("Fail: not a palindrome\n");
}