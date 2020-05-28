# SethiUllman_Algorithm_implementation

*Generates code for expression trees (not dags).\n
*Target machine model is simple. Has a load instruction, a store instruction, and binary operations involving either a register and a memory, or two registers.
*Does not use algebraic properties of operators. If a∗b has to be evaluated using r1 ← r1 ∗r2, then a and b have to be necessarily loaded in r1 and r2 respectively. 
*Extensions to take into account algebraic properties of operators. 
*Generates optimal code – i.e. code with least number of instructions. There may be other notions of optimality. 
*Complexity is linear in the size of the expression tree.

Labeling the Expression Tree
*Visit the tree in post-order.
*For every node visited do: 
1. Label each left leaf by 1 and each right leaf by 0. 
2. If the labels of the children of a node n are l1 and l2 respectively, then
    label(n) = max(l1,l2),if l1 != l2 
             = l1 + 1,otherwise
             
1. The code generation algorithm is represented as a function gencode(n), which produces code to evaluate the node labeled n.
2. Register allocation is done from a stack of register names rstack, initially containing r0,r1,...,rk (with r0 on top of the stack).
3. gencode(n) evaluates n in the register on the top of the stack.
4. Temporary allocation is done from a stack of temporary names tstack, initially containing t0,t1,...,tk (with t0 on top of the stack).
5. swap(rstack) swaps the top two registers on the stack.

ALGORITHM:

Case(1): Node n is a left leaf:
  gen(top(rstack) ← name) 
   n is named by a variable say name. Code is generated to load name into a register.
   
Case(2):  n’s right child is a leaf:
  gencode(n1)
  gen(top(rstack) ← top(rstack) op name)
   n1 is ﬁrst evaluated in the register on the top of the stack, followed by the operation op leaving the result in the same register.
   
Case(3):The left child of n requires lesser number of registers. This requirement is strictly less than the available number of registers.
  swap(rstack);                         Right child goes into next to top register 
  gencode(n2);                          Evaluate right child 
  R := pop(rstack); 
  gencode(n1);                          Evaluate left child 
  gen(top(rstack) ← top(rstack) op R);  Issue op 
  push(rstack,R); 
  swap(rstack)                          Restore register stack
  
Case(4):The right child of n requires lesser (or the same) number of registers than the left child, and this requirement is strictly less than the available number of registers
  gencode(n1); 
  R := pop(rstack); 
  gencode(n2); 
  gen(R ← R op top(rstack)); 
  push(rstack,R)

Case(5): Both the children of n require registers greater or equal to the available number of registers.
  gencode(n2); 
  T := pop(tstack); 
  gen(T ← top(rstack)); 
  gencode(n1); push(tstack,T); 
  gen(top(rstack) ← top(rstack) op T); 

 
Info about the files:
header.h    --------- the header file
insret.cpp   ----------- to create the input tree. The input to be given from right to left in levelOrder.
postOrder.cpp    ------------ labelling the Nodes
SethiUllman.cpp  ----------- contains code for Sethi-Ullman Algoritm
test.cpp  ---- the driver code
The screenshot attatched is an example.
