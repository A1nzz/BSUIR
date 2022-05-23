#pragma once

#include <iostream>
#define BUFFER_SIZE 10
using namespace std;

template <typename T>
class DequeIterator {
public:
	typedef DequeIterator iterator;
	typedef const DequeIterator const_iterator;
	typedef random_access_iterator_tag iterator_category;
	// iterator tag.
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef T** map_pointer;
	typedef DequeIterator self;

	T* cur;    // pointer, pointing to the current element.
	T* first;  // pointer, pointing to the first element in current buffer.
	T* last;   // pointer, pointing to the last element in current buffer.
	map_pointer node;  // pointer, pointing to the buffer.

	static size_t buffer_size() { return BUFFER_SIZE; }

	DequeIterator(T* x, map_pointer y)
		: cur(x), first(*y), last(*y + buffer_size()), node(y) {}
	DequeIterator() : cur(0), first(0), last(0), node(0) {}
	DequeIterator(const iterator& x)
		: cur(x.cur), first(x.first), last(x.last), node(x.node) {}

	reference operator*() const { return *cur; }
	reference operator->() const { return cur; }
	bool operator==(const self& x) const { return cur == x.cur; }
	bool operator!=(const self& x) const { return !(*this == x); }
	bool operator<(const self& x) const {
		return (node == x.node) ? (cur < x.cur) : (node < x.node);
	}
	void set_node(map_pointer new_node) {
		node = new_node;
		first = *new_node;
		last = first + buffer_size();
	}

	difference_type operator-(const self& x) const {
		return difference_type(buffer_size()) * (node - x.node - 1) +
			(cur - first) + (x.last - x.cur);
	}
	

	self& operator++() {
		++cur;
		if (cur == last) {
			set_node(node + 1);
			cur = first;
		}
		return *this;
	}

	self operator++(int) {
		self temp = *this;
		++* this;
		return temp;
	}

	self& operator--() {
		if (cur == first) {
			set_node(node - 1);
			cur = last;
		}
		--cur;
		return *this;
	}
	
	self operator--(int) {
		self temp = *this;
		--* this;
		return temp;
	}

	self& operator+=(difference_type n) {
		difference_type offset = n + (cur - first);
		if (offset >= 0 && offset < difference_type(buffer_size())) {
			cur += n;		}
		else {
			difference_type node_offset =
				offset > 0 ? offset / difference_type(buffer_size())
				: -difference_type((-offset - 1) / buffer_size()) - 1;
			set_node(node + node_offset);
			cur = first + (offset - node_offset * difference_type(buffer_size()));
		}
		return *this;
	}
	self& operator-=(difference_type n) { return *this += -n; }

	self operator+(difference_type n) const {
		self tmp = *this;
		return tmp += n;
	}
	self operator-(difference_type n) const {
		self tmp = *this;
		return tmp -= n;
	}
	reference operator[](difference_type n) const { return *(*this + n); }
};
#include <new>
#define MAP_SIZE 20
template <typename T>
class deque {
public:
	typedef T value_type;
	typedef value_type* pointer;
	typedef value_type& reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef allocator<value_type> d_allocator;
	typedef allocator<pointer> m_allocator;
	typedef DequeIterator<T> iterator;
	typedef pointer* map_pointer;
	m_allocator map_allocator;
	d_allocator data_allocator;

protected:
	static size_type buffer_size() { return size_t(BUFFER_SIZE); }
	static size_type initial_map_size() { return 8; }
	size_type max_size() const { return size_type(-1); }

	pointer allocate_node() { return data_allocator.allocate(buffer_size()); }
	
	void deallocate_node(pointer n) {
		data_allocator.deallocate(n, buffer_size());
	}
	void create_map_and_nodes(size_type num_elements) {
		size_type num_nodes = num_elements / BUFFER_SIZE + 1;
		map_size = max(initial_map_size(), num_nodes + 2);

		map = map_allocator.allocate(map_size);
		
		map_pointer nstart = map + (map_size - num_nodes) / 2;
		map_pointer nfinish = nstart + num_nodes - 1;
		for (map_pointer cur = nstart; cur <= nfinish; cur++) {
			*cur = allocate_node();
		}
		start.set_node(nstart);
		finish.set_node(nfinish);
		start.cur = start.first;
		finish.cur = finish.first + num_elements % BUFFER_SIZE;
	}
	
	void reallocate_map(size_type nodes_to_add, bool add_at_front) {
		size_type old_num_nodes = finish.node - start.node + 1;
		size_type new_num_nodes = old_num_nodes + nodes_to_add;
		map_pointer new_nstart;
		if (map_size > 2 * new_num_nodes) {
			
			new_nstart = map + (map_size - new_num_nodes) / 2 +
				(add_at_front ? nodes_to_add : 0);
			if (new_nstart < start.node)
				copy(start.node, finish.node + 1, new_nstart);
			else
				copy_backward(start.node, finish.node + 1, new_nstart + old_num_nodes);
		}
		else {
			size_type new_map_size = map_size + max(map_size, nodes_to_add) + 2;
			
			map_pointer new_map = map_allocator.allocate(new_map_size);
			new_nstart = new_map + (new_map_size - new_num_nodes) / 2 +
				(add_at_front ? nodes_to_add : 0);
			
			copy(start.node, finish.node + 1, new_nstart);
			map_allocator.deallocate(map, map_size);
			map = new_map;
			map_size = new_map_size;
		}
		//  reset start and finish node.
		start.set_node(new_nstart);
		finish.set_node(new_nstart + old_num_nodes - 1);
	}

protected:
	iterator start;
	iterator finish;
	map_pointer map;
	size_type map_size;
public:

	deque() : start(), finish(), map(0) { create_map_and_nodes(0); }

	~deque() {
		for (map_pointer node = start.node; node <= finish.node; ++node) {
		
			delete* node;
		}
		destroy_map_and_nodes();
	}

	void destroy_map_and_nodes() { map_allocator.deallocate(map, map_size); }

	iterator begin() { return start; }
	iterator end() { return finish; }
	reference front() { return *start; }
	reference back() {
		iterator temp = finish;
		--temp;
		return *temp;
	}
	
	reference operator[](size_type n) { return start[difference_type(n)]; }
	size_type size() const { return finish - start; }
	bool empty() const { return finish == start; }
	
	void push_back(const value_type& t) {
		if (finish.cur != finish.last - 1) {
			data_allocator.construct(finish.cur, t);
			++finish.cur;
		}
		else {
			push_back_aux(t);
		}
	}
	
	void push_back_aux(const value_type& t) {
		value_type t_copy = t;
		reserve_map_at_back();
		*(finish.node + 1) = allocate_node();
		map_allocator.construct(finish.cur, t_copy);
		finish.set_node(finish.node + 1);
		finish.cur = finish.first;
	}
	
	void reserve_map_at_back(size_type nodes_to_add = 1) {
		if (nodes_to_add > map_size - (finish.node - map) - 1)
			
			reallocate_map(nodes_to_add, false);
	}
	
	void push_front(const value_type& t) {
		if (start.cur != start.first) {
			data_allocator.construct(start.cur - 1, t);
			--start.cur;
		}
		else
			
			push_front_aux(t);
	}
	
	void push_front_aux(const value_type& t) {
		value_type t_copy = t;
		reserve_map_at_front();
		*(start.node - 1) = allocate_node();
		start.set_node(start.node - 1);
		start.cur = start.last - 1;
		data_allocator.construct(start.cur, t_copy);
	}
	void reserve_map_at_front(size_type nodes_to_add = 1) {
		if (nodes_to_add > start.node - map) reallocate_map(nodes_to_add, true);
	}
	
	void pop_back() {
		if (!empty()) {
			if (finish.cur != finish.first) {
				data_allocator.destroy(finish.cur);
				--finish.cur;
			}
			else
				pop_back_aux();
		}
	}
	
	void pop_back_aux() {
		deallocate_node(finish.first);  
		finish.set_node(finish.node - 1);
		finish.cur = finish.last - 1;
		data_allocator.destroy(finish.cur);  
	}

	void pop_front() {
		if (!empty()) {
			if (start.cur != start.last - 1) {
				data_allocator.destroy(start.cur);
				++start.cur;
			}
			else

				pop_front_aux();
		}
	}
	void pop_front_aux() {
		data_allocator.destroy(start.cur);
		deallocate_node(start.first);  
		start.set_node(start.node + 1);
		start.cur = start.first;
	}
	void clear() {
		
		while (!empty()) {
			pop_back();
		}
	}
};

