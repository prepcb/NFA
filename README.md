# NFA
This code allows the user to input a Non Deterministic Finite Automata (NFA)

It is restricted to inputs 0s or 1s

An example NFA to accept either an even number of 0s or multiple of 3 1s is:

0   1   epsilon 

{  } {  }   {1,3} -> 0 0  10

{2 } {  }   {   } -> 4 0  0

{1 } {  }   {4  } -> 2 0  16

{  } {4 }   {   } -> 0 16 0

{  } {32}   {   } -> 0 32 0

{  } {8 }   {   } -> 0 8  0
