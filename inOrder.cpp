#include"header.h"


void inOrder ( struct Node * root ) {

	if ( root ) {
	
		inOrder ( root->left );
		cout<<root->data<<" ";
		inOrder ( root->right );
	}
	//printf("\n");

}

void inLabel(struct Node * root) {
	
	if(root) {
		inLabel(root->left);
		cout<<root->l<<" ";
		inLabel(root->right);
	}
}
