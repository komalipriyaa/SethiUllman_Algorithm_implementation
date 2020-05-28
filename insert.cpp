#include"header.h"

struct Node * newNode(char value) {
	Node * n = new Node;
	n->data = value;
	n->left = NULL;
	n->right = NULL;
	n->l = 0;
}

struct Node * insertValue(struct Node * root, char value, queue<Node *>& q) {
	Node * node = newNode(value);
	if(!root)
		root = node;

	else if(q.front()->right == NULL)
		q.front()->right = node;

	else {
		q.front()->left = node;
		q.pop();
	}
	
	q.push(node);
	return root;
}

void levelOrder(struct Node * root) {
	if(root == NULL)
		return;

	queue<Node *> n;
	n.push(root);

	while(!n.empty()) {
		if(n.front()->left != NULL)
			n.push(n.front()->left);
		if(n.front()->right != NULL)
			n.push(n.front()->right);
		n.pop();
	}
}


struct Node * insert () {
	char data;
	Node * root = NULL;

	queue<Node *> q;
	for(int i=0; i<9; i++) {
		cout<<"enter data\n";
		cin>>data;
		root = insertValue(root, data, q);
	}

	
	levelOrder(root);
	cout<<"InOrder traversal of Tree:\n";

	inOrder(root);

	postOrder(root);
	cout<<"\nLabels for the inOrder traversal:"<<endl;
	inLabel(root);
	cout<<"\n";

	return root;
}
