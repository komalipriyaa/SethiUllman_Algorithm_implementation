#include<iostream>
#include<cstdlib>
#include<queue>
#include<stack>
using namespace std;


struct Node {

	char data;
	int l;
	struct Node * left;
	struct Node * right;
};



struct Node * insert();

void postOrder ( struct Node * );

int isleaf(struct Node *);

int max(int, int);

void inOrder(struct Node *);

void inLabel (struct Node *);

struct Node * newNode(char);

struct Node * insertValue(struct Node * root, char value, queue<Node *>& q);

void levelOrder(struct Node *);

stack<int> swap(stack<int> reg);

void gen(int top, char op, int R);

void genT(int top, char op, int R);

void genR(int top, char op, int R);

void gencode(struct Node * root, stack<int> reg, stack<int> tstack);
