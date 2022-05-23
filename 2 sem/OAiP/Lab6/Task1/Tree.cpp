#include "Tree.h"

Node* Node::SearchNode(int key) {
	if (this->key == key)
		return this;

	if (this->key > key) {
		if (this->left) {
			return this->left->SearchNode(key);
		}
		else {
			return nullptr;
		}
	}
	else {
		if (this->right) {
			return this->right->SearchNode(key);
		}
		else {
			return nullptr;
		}
	}
}


void Node::TraversePreorder() {
	this->Print();

	if (this->left)
		this->left->TraversePreorder();

	if (this->right)
		this->right->TraversePreorder();
}

void Node::TraverseInorder() {
	if (this->left)
		this->left->TraverseInorder();

	this->Print();

	if (this->right)
		this->right->TraverseInorder();
}

void Node::TraversePostorder() {
	if (this->left)
		this->left->TraversePostorder();

	if (this->right)
		this->right->TraversePostorder();

	this->Print();
}

void Node::TraverseDepthFirst() {
	std::queue<Node*> children;
	children.push(this);

	while (!children.empty()) {
		Node* node = children.front();
		children.pop();

		node->Print();

		if (node->left)
			children.push(node->left);
		if (node->right)
			children.push(node->right);
	}
}