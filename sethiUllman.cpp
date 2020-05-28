#include"header.h"

stack<int> swap(stack<int> reg) {
	int x = reg.top();
	reg.pop();
	int y = reg.top();
	reg.pop();
	reg.push(x);
	reg.push(y);
	return reg;
}

void gen(int top, char op, int R) {
	cout<<"r"<<top<<" <-- r"<<top<<op<<"r"<<R<<endl;
}
void genT(int top, char op, int T) {
	cout<<"r"<<top<<" <-- r"<<top<<op<<"t"<<T<<endl;
}

void genR(int top, char op, char name) {
	cout<<"r"<<top<<" <-- r"<<top<<op<<name<<endl;
}

void gencode(struct Node * root, stack<int> reg, stack<int> tstack) {
	//cout<<"gencode\n";
	if(!root) {
		cout<<"no root\n";
		return;
	}

	//int r[2] = {0, 0}
	//int reg[2];
	//stack<int> reg;
	//stack<int> tstack;
	//tstack.push(1);
	//reg.push(0);
	//reg.push(1);
	int R;

	int avlRegisters = 2;
	//cout<<"hey\n";
	if(isleaf(root)==0 && root->l == 1) {
		cout<<"MOVE "<<root->data<<", r"<<reg.top()<<endl;
		return;
	}
	if(isleaf(root->right)==0) {
		//cout<<"leafins\n";
		gencode(root->left, reg, tstack);
		genR(reg.top(), root->data, root->right->data);
		//return;
	}
	
	else if((root->left->l)<(root->right->l) && (root->right->l)<avlRegisters) {
		reg = swap(reg);//swap(rstack)

		gencode(root->right, reg, tstack);

		R = reg.top();
		reg.pop();//pop(rstack)

		gencode(root->left, reg, tstack);
		
		gen(reg.top(), root->data, R);

		reg.push(R);//push(rstack, R)

		reg = swap(reg);//restore the stack
		//return;
	}

	else if((root->left->l)>=(root->right->l) && (root->left->l)<avlRegisters) {
		gencode(root->left, reg, tstack);
		R = reg.top();
		reg.pop();//pop(rstack)
		
		gencode(root->right, reg, tstack);

		//cout<<reg.top()<<"top"<<endl;

		gen(R, root->data, reg.top());//R <-- R op top(rstack)
		
		reg.push(R);

	}

	else {
		gencode(root->right, reg, tstack);
		
		int T = tstack.top();
		tstack.pop();
		cout<<"MOVE r"<<reg.top()<<", t"<<T<<endl;

		gencode(root->left, reg, tstack);

		tstack.push(T);

		genT(reg.top(), root->data, T);	
	}
}
