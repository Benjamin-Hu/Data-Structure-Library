#include <iostream>
#include <queue>
#include "binary_search_tree.hpp"

using namespace std;

BinarySearchTree::Node::Node(int new_val) {
	val = new_val;
	left = NULL;
	right = NULL;
}

BinarySearchTree::BinarySearchTree() {
	root_ = NULL;
	size_ = 0;
}

BinarySearchTree::~BinarySearchTree() {
	int size = size_;
	for(int counter = 0; counter < size && root_ != NULL; counter++)
		remove(root_->val);
}


int BinarySearchTree::getNodeDepth(Node* n) const {
	return 0;
}

unsigned int BinarySearchTree::size() const {
	return size_;
}

int BinarySearchTree::max() const {
	Node* current = root_;
	while(current->right != NULL)
		current = current->right;
	return current->val;

}

int BinarySearchTree::min() const {
	Node* current = root_;
	while(current->left != NULL)
		current = current->left;
	return current->val;
}

unsigned int BinarySearchTree::depth() const {
	queue<Node> tree;	//level order transversal of tree
	int depth = 0;
	tree.push(*root_);
	Node* N;
	while(!tree.empty())
	{
		N = &tree.front();
		if(N->left != NULL)
			tree.push(*N->left);
		if(N->right != NULL)
			tree.push(*N->right);
		tree.pop();
	}
	Node* current = root_;
	while(current)	//finds depth of lowest node
	{
		if(N->val == current->val)
			return depth;
		else if(N->val < current->val)
		{
			current = current->left;
			++depth;
		}
		else
		{
			current = current->right;
			++depth;
		}
	}
}

void BinarySearchTree::print() const {
	queue<Node> tree;	//level order transversal of tree
	tree.push(*root_);
	Node* N;
	while(!tree.empty())
	{
		N = &tree.front();
		if(N->left != NULL)
			tree.push(*N->left);
		if(N->right != NULL)
			tree.push(*N->right);
		cout << " " << N->val << " ";
		tree.pop();
	}
}

bool BinarySearchTree::exists(int val) const {
	Node* current = root_;
	while(current)
	{
		if(val == current->val)
			return true;
		else if(val < current->val)
			current = current->left;
		else
			current = current->right;
	}
	return false;
}

BinarySearchTree::Node* BinarySearchTree::getRootNode() {
    return root_;
}

BinarySearchTree::Node** BinarySearchTree::getRootNodeAddress() {
    return &root_;
}

bool BinarySearchTree::insert(int val) {
    Node** current = &root_;
    while(*current)
    {
    	if(val == (*current)->val)
    		return false;
		else if(val < (*current)->val)
    		current = &(*current)->left;
    	else
    		current = &(*current)->right;
	}
    *current = new Node(val);
    ++size_;
    return true;
}

bool BinarySearchTree::remove(int val) {
    //finds if val exists and assigns current to point to node
	Node* parent = root_;
	Node* current = root_;
    bool foundNode = false;
	while(current && !foundNode)
	{
		if(val == current->val)
			foundNode = true;
		else if(val < current->val)
		{
			parent = current;
			current = current->left;
		}
		else
		{
			parent = current;
			current = current->right;
		}
	}
	if(!foundNode)	//no node found
		return false;
	if(!current->left && !current->right)	//case 1 - no child
	{
		if(current == root_)
			root_ = NULL;
		else if(current->val < parent->val)
			parent->left = NULL;
		else
			parent->right = NULL;
		--size_;			
		delete current;
	}
	else if(current->right == NULL)	//case 2.1 - left child
	{
		if(current == root_)
			root_ = current->left;
		else if(current->val < parent->val)
			parent->left = current->left;
		else
			parent->right = current->left;
		--size_;		
		delete current;
	}
	else if(current->left == NULL)	//case 2.2 - right child
	{
		if(current == root_)
			root_ = current->right;
		else if(current->val < parent->val)
			parent->left = current->right;
		else
			parent->right = current->right;
		--size_;
		delete current;
	}
	else	//case 3 - two children
	{
		Node* replace = current->left;
		while(replace->right != NULL)
			replace = replace->right;
		int predecessor = replace->val;
		remove(predecessor);
		current->val = predecessor;
	}
	return true;
}
