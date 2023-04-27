# NFA
This code allows the user to input a Non Deterministic Finite Automata (NFA)

It is restricted to inputs 0s or 1s

An example NFA to accept either an even number of 0s or multiple of 3 1s is:

0   1   epsilon (is entered as->)

{  } {  }   {1,3} -> 0 0  (10 = 2^1+2^3)

{2 } {  }   {   } -> (4=2^2) 0  0

{1 } {  }   {4  } -> (2=2^1) 0  (16 = 2^4)

{  } {4 }   {   } -> 0 (16=2^4) 0

{  } {5}   {   } -> 0 (32=2^5) 0

{  } {3 }   {   } -> 0 (8=2^3)  0

This code uses powers of 2 to represent the choice, e.g. 5 = 1 + 4 = 2^0 + 2^2 so = {0,2}

Null = {} becomes 0
