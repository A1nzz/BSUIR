#include <queue>
#pragma once

class Node {
public:
	Node* right;
	Node* left;
	int key;
	unsigned char height;

	Node(int k)
		: key(k), left(nullptr), right(nullptr), height(1)
	{
	}

	unsigned char Height(Node* p)
	{
		return p ? p->height : 0;
	}

	int bfactor(Node* p)
	{
		return Height(p->right) - Height(p->left);
	}
	//функция восстанавливает корректное значение поля height заданного узла
	void fixheight(Node* p)
	{
		unsigned char hl = Height(p->left);
		unsigned char hr = Height(p->right);
		p->height = (hl > hr ? hl : hr) + 1;
	}

	Node* rotateright(Node* p) // правый поворот вокруг p
	{
		Node* q = p->left;
		p->left = q->right;
		q->right = p;
		fixheight(p);
		fixheight(q);
		return q;
	}
	Node* rotateleft(Node* q) // левый поворот вокруг q
	{
		Node* p = q->right;
		q->right = p->left;
		p->left = q;
		fixheight(q);
		fixheight(p);
		return p;
	}

	Node* balance(Node* p) // балансировка узла p
	{
		fixheight(p);
		if (bfactor(p) == 2)
		{
			if (bfactor(p->right) < 0)
				p->right = rotateright(p->right);
			return rotateleft(p);
		}
		if (bfactor(p) == -2)
		{
			if (bfactor(p->left) > 0)
				p->left = rotateleft(p->left);
			return rotateright(p);
		}
		return p; // балансировка не нужна
	}

	Node* insert(Node* p, int k) // вставка ключа k в дерево с корнем p
	{
		if (!p) return new Node(k);
		if (k < p->key)
			p->left = insert(p->left, k);
		else
			p->right = insert(p->right, k);
		return balance(p);
	}

	Node* findmin(Node* p) // поиск узла с минимальным ключом в дереве p 
	{
		return p->left ? findmin(p->left) : p;
	}

	Node* removemin(Node* p) // удаление узла с минимальным ключом из дерева p
	{
		if (p->left == 0)
			return p->right;
		p->left = removemin(p->left);
		return balance(p);
	}

	Node* remove(Node* p, int k) // удаление ключа k из дерева p
	{
		if (!p) return 0;
		if (k < p->key)
			p->left = remove(p->left, k);
		else if (k > p->key)
			p->right = remove(p->right, k);
		else //  k == p->key 
		{
			Node* q = p->left;
			Node* r = p->right;
			delete p;
			if (!r) return q;
			Node* min = findmin(r);
			min->right = removemin(r);
			min->left = q;
			return balance(min);
		}
		return balance(p);
	}

	void Print(bool with_new_line = false) {
		//std::cout << std::to_string(key) + (with_new_line ? "\n" : "");
	};

	void TraverseInorder();
	void TraversePreorder();
	void TraversePostorder();
	void TraverseDepthFirst();
	Node* SearchNode(int key);
};



class Tree
{
public:
	Tree()
		: root(nullptr)
	{
	}
	~Tree()
	{
		DestroyNode(root);
	}
private:
	static void DestroyNode(Node* node) {
		if (node) {
			DestroyNode(node->left);
			DestroyNode(node->right);
			delete node;
		}
	}
public:
	Node* root;
};

