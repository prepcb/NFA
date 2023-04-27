#include <stdio.h>
#include <stdlib.h>
int q_delta_a(int q, int a, int qn, int delta[100][2]);
int QorEps(int q, int qn, int epsilon[]);
int Input_A(int A[100]);
int Input_epsilon(int epsilon[]);
void Input_delta(int delta[100][2], int qn);
/*
NFA accepts{0}[1]* U {0}*{1}

corrsponds to the 5 state transition table
   | 0     | 1     |  e
----|-------|-------|-----
q0  |  {}   |  {}   | {q1,q3}
q1  |  {q2} |  {}   | {}
q2  |  {}   | {q2}  | {}
q3  | {q3}  | {q4}  | {}
q4  |  {}   |  {}   | {}

int delta[100][2] = {
        0, 0,
        4, 0,
        0, 4,
        8, 16,
        0, 0};

int epsilon[5]={10,0,0,0,0};


e.g.
0 1 1 1 yes
0 0 0 1 yes
1 0 0 1 no
0 0 0 0 no
0 0 1 1 no

*/

int main()
{
    printf("You can use the following 5 state epsilon\n");
    printf("epsilon= [10 0 0 0 0]\n");
    printf("and transition function\n");
    printf("delta = \n 1  0\n 4  16\n 0  2\n 16 8\n 0  0\n");
    printf("\nwhich accepts {0}*{01}*{1} union 0{1}*{0}\n");
    int A[100], i, n, q = 1, j, a, qn, epsilon[100], delta[100][2];

    qn = Input_epsilon(epsilon);
    while (q != QorEps(q, qn, epsilon)) // Epsilon closure from start state
        q = QorEps(q, qn, epsilon);
    printf("start state = %d\n", q);

    Input_delta(delta, qn);
    int f;
    printf("What are the accepting states {a,b,..}=2^a+2^b+...?\n");
    scanf("%d", &f);
    n = Input_A(A);
    while (n > 0)
    {

        for (j = 0; j < n; j++)
        {
            a = A[j];
            q = q_delta_a(q, a, qn, delta);
            while (q != QorEps(q, qn, epsilon))
                q = QorEps(q, qn, epsilon); // Epsilon closure from intermediate state (though not necessary in this example)
            printf("A[%d]=%d,q=%d\n", j, A[j], q);
        }

        printf("Final q=%d\n", q);

        if ((int)(q & f) != 0) // End state 2^4 or 2^2, i.e. 2 or 4
            printf("\n accepted\n");
        else
            printf("\n not accepted\n");
        n = Input_A(A);
        q = 1;                              // restart start state
        while (q != QorEps(q, qn, epsilon)) // Epsilon closure from start state
            q = QorEps(q, qn, epsilon);
    }
    return (0);
}

// Given input a, calulates the delta transition
int q_delta_a(int q, int a, int qn, int delta[100][2])
{

    int i, ii = 1, p;

    p = delta[0][a];
    for (i = 0; i < qn; i++)
    {
        if ((int)(q & ii) > 0)
            p = p | delta[i][a];
        ii = ii * 2;
    }
    return (p);
}

// Calculates one epsilon transition
// Array epsilon[] is the epsilon column normally in transtiion table delta
//  10 =2 + 8 =2^1 + 2^3 equivalent to {1 or 3}={1,3}
int QorEps(int q, int qn, int epsilon[])
{
    int i, ii = 1, p;
    // int epsilon[5] = {10, 0, 0, 0, 0};
    p = q;

    for (i = 0; i < qn; i++)
    {
        if ((int)(q & ii) > 0)
            p = p | epsilon[i];
        ii = ii * 2; // Creates ii = 2^i as we loop on i
    }
    q = p;
    return (q);
}
int Input_A(int A[100])
{
    int i, n;
    printf("How many 0s and 1s in your input?\n");

    scanf("%d", &n);
    if (n < 1)
        exit(0);
    printf(" Enter %d 0s and 1s each separated by a space\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    return (n);
}
int Input_epsilon(int epsilon[])
{
    int n, i, j;
    printf("How many states?\n");
    scanf("%d", &n);
    if (n < 1)
        exit(0);
    printf("In the form {a,b,c,..} = 2^a+2^b+2^c +..\n");
    j = 1;
    for (i = 0; i < n; i++)
        j = j * 2;
    printf("\nMake sure all states are < %d\n", j);
    for (i = 0; i < n; i++)
    {
        printf("Input epsilon states for state %d\n", i);

        scanf("%d", &epsilon[i]);
    }
    return (n);
}
void Input_delta(int delta[100][2], int qn)
{
    int i;
    printf("In the form {a,b,c,..} = 2^a+2^b+2^c +..\n");
    for (i = 0; i < qn; i++)
    {
        printf("Input 2 transition states for state %d for input 0,1\n", i);

        scanf("%d%d", &delta[i][0], &delta[i][1]);
    }
}