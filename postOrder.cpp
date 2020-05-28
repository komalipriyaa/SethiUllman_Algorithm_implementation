

#include"header.h"


void postOrder ( struct Node * root ) {

	if ( isleaf(root) == 1 ) {
		postOrder ( root->left );
		//postOrder ( root->right );
		//printf ( "%d ", root->data );
		if(isleaf(root->left) == 0)
			(root->left)->l = 1;

		postOrder(root->right);

		if(isleaf(root->right) == 0)
			(root->right)->l = 0;

		if((root->left)->l != (root->right)->l)
			root->l = max((root->left)->l, (root->right)->l);
		
		else
			root->l = (root->left)->l +1;
		//cout<<root->l<<endl;
	}
}

int isleaf(struct Node * root) {
	if(!(root->left) && !(root->right))
		return 0;
	else 
		return 1;
}

int max(int a, int b) {
	//cout<<"\n"<<a<<endl;
	//cout<<"\n"<<b<<endl;
	if(a>b)
		return a;
	else
		return b;
}
