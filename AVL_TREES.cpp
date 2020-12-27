
// C++ program to insert_pair a node in AVL tree 
#include<bits/stdc++.h> 
#include<string>
#include<cstring>
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std; 
// An AVL tree node 

string str_input()
{
    char ch;
    while (cin.readsome(&ch, 1) != 0)
         ;
    string myString;
    while((ch=getchar())!='\n')
    {
        myString.push_back(ch);
    }
    return myString;
}
class AVL_TREE{
public:
struct avl_Node 
{ 
	string address;
    string key; 
	avl_Node *left; 
	avl_Node *right; 
	int height; 
}*root; 

AVL_TREE(){
	root=NULL;
}

// A utility function to get the 
// height of the tree 
int height(avl_Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return N->height; 
} 

// A utility function to get maximum 
// of two integers 
int max(int a, int b) 
{ 
	return (a > b)? a : b; 
} 

/* Helper function that allocates a 
new node with the given key and 
NULL left and right pointers. */
avl_Node* newNode(string key,string address) 
{ 
	avl_Node* node = new avl_Node(); 
	node->key = key; 
	node->address=address;
	node->left = NULL; 
	node->right = NULL; 
	node->height = 1; // new node is initially 
					// added at leaf 
	return(node); 
} 

// A utility function to right 
// rotate subtree root_temped with y 
// See the diagram given above. 
avl_Node *rightRotate(avl_Node *y) 
{ 
	avl_Node *x = y->left; 
	avl_Node *T2 = x->right; 

	// Perform rotation 
	x->right = y; 
	y->left = T2; 

	// Update heights 
	y->height = max(height(y->left), 
					height(y->right)) + 1; 
	x->height = max(height(x->left), 
					height(x->right)) + 1; 

	// Return new root_temp 
	return x; 
} 

// A utility function to left 
// rotate subtree root_temped with x 
// See the diagram given above. 
avl_Node *leftRotate(avl_Node *x) 
{ 
	avl_Node *y = x->right; 
	avl_Node *T2 = y->left; 

	// Perform rotation 
	y->left = x; 
	x->right = T2; 

	// Update heights 
	x->height = max(height(x->left),	 
					height(x->right)) + 1; 
	y->height = max(height(y->left), 
					height(y->right)) + 1; 

	// Return new root_temp 
	return y; 
} 

// Get Balance factor of node N 
int getBalance(avl_Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return height(N->left) - height(N->right); 
} 

void insert(string key,string address)
{
	root=insert_pair(root,key,address);
}
// Recursive function to insert_pair a key 
// in the subtree root_temped with node and 
// returns the new root_temp of the subtree. 
avl_Node* insert_pair(avl_Node* node, string key,string address) 
{ 
	/* 1. Perform the normal BST insert_pairion */
	if (node == NULL) 
		return(newNode(key,address)); 

	if (key < node->key) 
		node->left = insert_pair(node->left, key,address); 
	else if (key > node->key) 
		node->right = insert_pair(node->right, key,address); 
	else // Equal keys are not allowed in BST 
		return node; 

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left), 
						height(node->right)); 

	/* 3. Get the balance factor of this ancestor 
		node to check whether this node became 
		unbalanced */
	int balance = getBalance(node); 

	// If this node becomes unbalanced, then 
	// there are 4 cases 

	// Left Left Case 
	if (balance > 1 && key < node->left->key) 
		return rightRotate(node); 

	// Right Right Case 
	if (balance < -1 && key > node->right->key) 
		return leftRotate(node); 

	// Left Right Case 
	if (balance > 1 && key > node->left->key) 
	{ 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 

	// Right Left Case 
	if (balance < -1 && key < node->right->key) 
	{ 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 

	/* return the (unchanged) node pointer */
	return node; 
} 

// A utility function to print preorder 
// traversal of the tree. 
// The function also prints height 
// of every node 
void preOrder(avl_Node *root_temp) 
{ 
	if(root_temp != NULL) 
	{ 
		cout <<"Key: "<< root_temp->key << endl <<"Address: "<<root_temp->address<<endl<<endl; 
		preOrder(root_temp->left); 
		preOrder(root_temp->right); 
	} 
} 
void Display()
{
	preOrder(root);
}


};
/*
// Driver Code 
int main() 
{ 
	AVL_TREE Tree; 
	
	Tree.insert("10","file1,line1"); 
	Tree.insert("20","file1,line2"); 
	Tree.insert("30","file1,line3"); 
	Tree.insert("40","file1,line4"); 
	Tree.insert("50","file1,line5"); 
	Tree.insert("25","file1,line6"); 
	

	cout << "Preorder traversal of the "
			"constructed AVL tree is \n"; 
	Tree.Display(); 
	
	return 0; 
} 
*/