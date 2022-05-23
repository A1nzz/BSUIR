#pragma once
#include <string>
#include <list>
#include <utility>
#include <iostream>

#include <queue>

template <typename KeyType, typename ValueType>
class Map
{
	class Node {
	public:
		Node* right;
		Node* left;
		Node* parent;
		std::pair<const KeyType, ValueType> data;
		unsigned char height;

		Node(std::pair<const KeyType, ValueType> k)
			: data(k),parent(nullptr), left(nullptr), right(nullptr), height(1)
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
			q->parent = p;
			p->left = q->right;
			q->right = p;
			p->parent = q;
			if (p->right != nullptr) p->right->parent = p;
			if (p->left != nullptr) p->left->parent = p;
			fixheight(p);
			fixheight(q);
			return q;
		}
		Node* rotateleft(Node* q) // левый поворот вокруг q
		{
			Node* p = q->right;
			p->parent = q;
			q->right = p->left;
			p->left = q;
			q->parent = p;

			if (q->right != nullptr) q->right->parent = q;
			if (q->left != nullptr) q->left->parent = q;
			fixheight(q);
			fixheight(p);
			return p;
		}

		Node* balance(Node* p) // балансировка узла p
		{
			fixheight(p);
			if (p->right != nullptr) p->right->parent = p;
			if (p->left != nullptr) p->left->parent = p;
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

		void insertToList(std::list<Node*>& list, Node* node) {
			if (list.empty()) list.push_back(node);
			else {
				auto it = list.begin();
				while (it != list.end() && *(it).key < node.key) ++it;
				list.insert(it, node);
			}
		}

		void removeFromList(std::list<Node*>& list, Node* node) {
			for (auto it = list.begin(); it != list.end(); ++it) {
				if (*it == node) {
					list.erase(it);
					return;
				}
			}
		}

		Node* insert(Node* p, std::pair<const KeyType, ValueType> k) // вставка пары k в дерево с корнем p
		{
			if (!p) return new Node(k);
			if (p->left != nullptr) p->left->parent = p;
			if (p->right != nullptr) p->right->parent = p;

			if (k.first < p->data.first) {
				p->left = insert(p->left, k);
			}
			else {

				p->right = insert(p->right, k);
			}

			//insertToList(list, p);
			return balance(p);
		}

		Node* findmin(Node* p) // поиск узла с минимальным ключом в дереве p 
		{
			return p->left ? findmin(p->left) : p;
		}
		Node* findmax(Node* node) {
			Node* curr = node;
			while (curr && curr->right) {
				curr = curr->right;
			}
			return curr;
		}

		Node* removemin(Node* p) // удаление узла с минимальным ключом из дерева p
		{
			if (p->left == 0)
				return p->right;
			p->left = removemin(p->left);
			return balance(p);
		}

		Node* remove(Node* p, KeyType k) // удаление ключа k из дерева p
		{
			if (!p) return 0;
			if (k < p->data.first)
				p->left = remove(p->left, k);
			else if (k > p->data.first)
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
			std::cout << (data.second) + (with_new_line ? "\n" : "");
		};

		Node* SearchNode(KeyType key) {
			if (this->data.first == key)
				return this;

			if (this->data.first > key) {
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


		void TraversePreorder() {
			this->Print();

			if (this->left)
				this->left->TraversePreorder();

			if (this->right)
				this->right->TraversePreorder();
		}

		void TraverseInorder() {
			if (this->left)
				this->left->TraverseInorder();

			this->Print();

			if (this->right)
				this->right->TraverseInorder();
		}

		void TraversePostorder() {
			if (this->left)
				this->left->TraversePostorder();

			if (this->right)
				this->right->TraversePostorder();

			this->Print();
		}

		void TraverseDepthFirst() {
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
	};



	class Iterator;
	class Const_Iterator;
	class Reverse_Iterator;
public:
	Map()
		: root(nullptr)
	{
	}

	~Map()
	{
		DestroyNode(root);
	}
	void insert(std::pair<const KeyType, ValueType> k) {
		root = root->insert(root, k);
		if (root != nullptr) root->parent = nullptr;
	}
	void remove(KeyType key) {
		root = root->remove(root, key);
		if (root != nullptr) root->parent = nullptr;
	}

	void clear() {
		DestroyNode(root);
		root = nullptr;
	}

	Node* search(KeyType key) {
		return root->SearchNode(key);
	}

	Iterator begin() {
		return Iterator(root->findmin(root));
	}
	Iterator end() {
		return Iterator(nullptr);
	}

	Const_Iterator cbegin() {
		return Const_Iterator(root->findmin(root));
	}

	Const_Iterator cend() {
		return Const_Iterator(nullptr);
	}

	Reverse_Iterator rbegin() {
		return Reverse_Iterator(root->findmax(root));
	}

	Reverse_Iterator rend() {
		return Reverse_Iterator(nullptr);
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
	std::list<Node*> list;

public:
	class Iterator {
	private:
		Node* current;
	public:
		Iterator(Node* c) : current(c) {}
		Iterator(const Iterator& it) : current(it.current) {}
		Iterator& operator=(const Iterator& it) {
			current = it.current;
			return *this;
		}
		Node& operator*() const { return *(current); }
		Node* operator->() const { return current; }

		bool operator==(const Iterator& it) const { return current == it.current; }
		bool operator!=(const Iterator& it) const { return current != it.current; }

		Iterator& operator++() {
			if (current->right != nullptr) {
				current = current->findmin(current->right);
			}
			else {
				KeyType key = current->data.first;
				current = current->parent;
				while (current != nullptr && current->data.first < key) {
					current = current->parent;
				}
			}
			return *this;
		}

		Iterator operator++(int) {
			Iterator it = *this;
			++(*this);
			return it;
		}

		Iterator& operator--() {
			if (current->left != nullptr) {
				current = current->findmax(current->left);
			}
			else {
				KeyType key = current->data.first;
				current = current->parent;
				while (current != nullptr && current->data.first > key) {
					current = current->parent;
				}
			}

			return *this;
		}

		Iterator operator--(int) {
			Iterator it = *this;
			--(*this);
			return it;
		}
	};


	class Const_Iterator {
	private:
		Node* current;
	public:
		Const_Iterator(Node* c) : current(c) {}
		Const_Iterator(const Const_Iterator& it) : current(it.current) {}
		Const_Iterator& operator=(const Const_Iterator& it) {
			current = it.current;
			return *this;
		}
		const Node& operator*() const { return *(current); }
		const Node* operator->() const { return current; }

		bool operator==(const Const_Iterator& it) const { return current == it.current; }
		bool operator!=(const Const_Iterator& it) const { return current != it.current; }

		Const_Iterator& operator++() {
			if (current->right != nullptr) {
				current = current->findmin(current->right);
			}
			else {
				KeyType key = current->data.first;
				current = current->parent;
				while (current != nullptr && current->data.first < key) {
					current = current->parent;
				}
			}

			return *this;
		}

		Const_Iterator operator++(int) {
			Const_Iterator it = *this;
			++(*this);
			return it;
		}

		Const_Iterator& operator--() {
			if (current->left != nullptr) {
				current = current->findmax(current->left);
			}
			else {
				KeyType key = current->data.first;
				current = current->parent;
				while (current != nullptr && current->data.first > key) {
					current = current->parent;
				}
			}

			return *this;
		}

		Const_Iterator operator--(int) {
			Const_Iterator it = *this;
			--(*this);
			return it;
		}
	};

	class Reverse_Iterator {
	private:
		Node* current;
	public:
		Reverse_Iterator(Node* c) : current(c) {}
		Reverse_Iterator(const Reverse_Iterator& it) : current(it.current) {}
		Reverse_Iterator& operator=(const Reverse_Iterator& it) {
			current = it.current;
			return *this;
		}
		Node& operator*() const { return *(current); }
		Node* operator->() const { return current; }

		bool operator==(const Reverse_Iterator& it) const { return current == it.current; }
		bool operator!=(const Reverse_Iterator& it) const { return current != it.current; }

		Reverse_Iterator& operator++()
		{
			if (current == nullptr) {
				current = current->findmax(current);
			}
			else if (current->left != nullptr) {
				current = current->findmax(current->left);
			}
			else {
				KeyType key = current->data.first;
				current = current->parent;
				while (current != nullptr && current->data.first > key) {
					current = current->parent;
				}
			}

			return *this;
		}

		Reverse_Iterator operator++(int) {
			Reverse_Iterator it = *this;
			++(*this);
			return it;
		}

		Reverse_Iterator& operator--() {
			if (current->right != nullptr) {
				current = current->findmin(current->right);
			}
			else {
				KeyType key = current->data.first;
				current = current->parent;
				while (current != nullptr && current->data.first < key) {
					current = current->parent;
				}
			}

			return *this;
		}

		Reverse_Iterator operator--(int) {
			Reverse_Iterator it = *this;
			--(*this);
			return it;
		}

	};

};

