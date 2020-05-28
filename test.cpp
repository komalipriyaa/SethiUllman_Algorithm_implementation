#include "header.h"

int main() {

	struct Node *root = ( struct Node * ) malloc ( sizeof( struct Node ));
	stack<int> reg;
	reg.push(1);
	reg.push(0);

	stack<int> tstack;
	tstack.push(1);
	

	root = insert();

	cout<<"\nGENERATED CODE:\n";

	gencode(root, reg, tstack);
	cout<<"gen";

	return 0;
}
