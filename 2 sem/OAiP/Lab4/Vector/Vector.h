#pragma once
template<typename T>
class OwnIterator;
template<typename T>
class OwnReverseIterator;

template <typename T>
class Vector {
	typedef OwnIterator<T> iterator;
	typedef OwnIterator<const T> const_iterator;
	typedef OwnReverseIterator<T> reverse_iterator;
	typedef OwnReverseIterator<const T> const_reverse_iterator;
private:
	T* m_data;
	size_t m_size;
	size_t m_capacity;
public:
	Vector() {
		m_data = nullptr;
		m_size = 0;
		m_capacity = 0;
	}
	Vector(size_t size) {
		m_data = new T[size];
		m_size = size;
		m_capacity = size;
	}
	Vector(const Vector& other) {
		m_data = new T[other.m_size];
		m_size = other.m_size;
		m_capacity = other.m_capacity;
		for (size_t i = 0; i < m_size; i++) {
			m_data[i] = other.m_data[i];
		}
	}
	Vector(Vector&& other) {
		m_data = other.m_data;
		m_size = other.m_size;
		m_capacity = other.m_capacity;
		other.m_data = nullptr;
		other.m_size = 0;
		other.m_capacity = 0;
	}
	Vector& operator=(const Vector& other) {
		if (this != &other) {
			delete[] m_data;
			m_data = new T[other.m_size];
			m_size = other.m_size;
			m_capacity = other.m_capacity;
			for (size_t i = 0; i < m_size; i++) {
				m_data[i] = other.m_data[i];
			}
		}
		return *this;
	}
	Vector& operator=(Vector&& other) {
		if (this != &other) {
			delete[] m_data;
			m_data = other.m_data;
			m_size = other.m_size;
			m_capacity = other.m_capacity;
			other.m_data = nullptr;
			other.m_size = 0;
			other.m_capacity = 0;
		}
		return *this;
	}
	~Vector() {
		delete[] m_data;
	}
	T& operator[](size_t index) {
		return m_data[index];
	}
	const T& operator[](size_t index) const {
		return m_data[index];
	}
	size_t size() const {
		return m_size;
	}
	void resize(size_t newSize) {
		if (newSize > m_capacity) {
			T* newData = new T[newSize];
			for (size_t i = 0; i < m_size; i++) {
				newData[i] = m_data[i];
			}
			delete[] m_data;
			m_data = newData;
			m_capacity = newSize;
		}
		m_size = newSize;
	}

	void resize(size_t newSize, const T& value) {
		if (newSize > m_capacity) {
			T* newData = new T[newSize];
			for (size_t i = 0; i < m_size; i++) {
				newData[i] = m_data[i];
			}
			delete[] m_data;
			m_data = newData;
			m_capacity = newSize;
		}
		for (size_t i = m_size; i < newSize; i++) {
			m_data[i] = value;
		}
		m_size = newSize;
	}
	
	size_t capacity() const {
		return m_capacity;
	}
	void push_back(const T& value) {
		if (m_capacity == 0) {
			reserve(1);
		}	
		else if (m_size == m_capacity) {
			reserve(m_capacity * 2);
		}
		m_data[m_size] = value;
		m_size++;
	}
	
	void push_back(T&& value) {
		if (m_capacity == 0) {
			reserve(1);
		}
		else if (m_size == m_capacity) {
			reserve(m_capacity * 2);
		}
		m_data[m_size] = value;
		m_size++;
	}
	void pop_back() {
		m_size--;
	}
	void reserve(size_t newCapacity) {
		T* newData = new T[newCapacity];
		for (size_t i = 0; i < m_size; i++) {
			newData[i] = m_data[i];
		}
		delete[] m_data;
		m_data = newData;
		m_capacity = newCapacity;
	}
	void clear() {
		m_size = 0;
	}
	void insert(size_t index, const T& value) {
		if (m_capacity == 0) {
			reserve(1);
		}
		else if (m_size == m_capacity) {
			reserve(m_capacity * 2);
		}
		for (size_t i = m_size; i > index; i--) {
			m_data[i] = m_data[i - 1];
		}
		m_data[index] = value;
		m_size++;
	}
	void insert(size_t index, T&& value) {
		if (m_capacity == 0) {
			reserve(1);
		}
		else if (m_size == m_capacity) {
			reserve(m_capacity * 2);
		}
		for (size_t i = m_size; i > index; i--) {
			m_data[i] = m_data[i - 1];
		}
		m_data[index] = value;
		m_size++;
	}
	void emplace_back(const T& value) {
		if (m_capacity == 0) {
			reserve(1);
		}
		else if (m_size == m_capacity) {
			reserve(m_capacity * 2);
		}
		m_data[m_size] = value;
		m_size++;
	}

	void emplace(size_t index, const T& value) {
		if (m_capacity == 0) {
			reserve(1);
		}
		else if (m_size == m_capacity) {
			reserve(m_capacity * 2);
		}
		for (size_t i = m_size; i > index; i--) {
			m_data[i] = m_data[i - 1];
		}
		m_data[index] = value;
		m_size++;
	}
	T* data() { return m_data; }
	void erase(size_t index) {
		for (size_t i = index; i < m_size - 1; i++) {
			m_data[i] = m_data[i + 1];
		}
		m_size--;
	}
	void erase(size_t index, size_t count) {
		for (size_t i = index; i < m_size - count; i++) {
			m_data[i] = m_data[i + count];
		}
		m_size -= count;
	}
	void swap(size_t index1, size_t index2) {
		T temp = m_data[index1];
		m_data[index1] = m_data[index2];
		m_data[index2] = temp;
	}

	T& front() {
		return m_data[0];
	}

	const T& front() const {
		return m_data[0];
	}
	
	T* at(size_t index) {
		return &m_data[index];
	}

	const T* at(size_t index) const {
		return &m_data[index];
	}

	size_t max_size() const {
		return size_t(-1);
	}
	
	bool empty() const {
		return m_size == 0;
	}
	
	void swap(Vector<T>& other) {
		std::swap(m_data, other.m_data);
		std::swap(m_size, other.m_size);
		std::swap(m_capacity, other.m_capacity);
	}
	
	iterator begin();
	iterator end();
	const_iterator cbegin() const;
	const_iterator cend() const;

	reverse_iterator rbegin();
	reverse_iterator rend();
	const_reverse_iterator crbegin() const;
	const_reverse_iterator crend() const;
};

template<typename T>
class OwnIterator : public std::iterator<std::input_iterator_tag, T>
{
	template<typename U>
	friend class Vector;
private:
	OwnIterator(T* p);
public:
	OwnIterator(const OwnIterator& it);

	bool operator!=(OwnIterator const& other) const;
	bool operator==(OwnIterator const& other) const;
	
	T& operator*() const;
	OwnIterator& operator++();
	OwnIterator& operator--();
	friend OwnIterator operator - (OwnIterator& i1, OwnIterator& i2);

private:
	T* p;
};

template<typename T>
class OwnReverseIterator
{
	template<typename U>
	friend class Vector;
private:
	OwnReverseIterator(T* p);
public:
	OwnReverseIterator(const OwnReverseIterator& it);

	bool operator!=(OwnReverseIterator const& other) const;
	bool operator==(OwnReverseIterator const& other) const;

	T& operator*() const;
	OwnReverseIterator& operator++();
private:
	T* p;
};

template<typename T>
OwnIterator<T>::OwnIterator(T* p) : p(p)
{

}
template<typename T>
OwnIterator<T>::OwnIterator(const OwnIterator& it) : p(it.p)
{

}
template<typename T>
bool OwnIterator<T>::operator!=(OwnIterator const& other) const
{
	return p != other.p;
}
template<typename T>
bool OwnIterator<T>::operator==(OwnIterator const& other) const
{
	return p == other.p;
}
template<typename T>
T& OwnIterator<T>::operator*() const
{
	return *p;
}
template<typename T>
OwnIterator<T>& OwnIterator<T>::operator++()
{
	++p;
	return *this;
}
template<typename T>
OwnIterator<T>& OwnIterator<T>::operator--()
{
	--p;
	return *this;
}
template<typename T>
OwnIterator<T> operator - (OwnIterator<T>& i1, OwnIterator<T>& i2)
{
	return OwnIterator<T>(i1.p - i2.p);
}

template<typename T>
OwnReverseIterator<T>::OwnReverseIterator(T* p) : p(p)
{

}
template<typename T>
OwnReverseIterator<T>::OwnReverseIterator(const OwnReverseIterator& it) : p(it.p)
{

}
template<typename T>
bool OwnReverseIterator<T>::operator!=(OwnReverseIterator const& other) const
{
	return p != other.p;
}
template<typename T>
bool OwnReverseIterator<T>::operator==(OwnReverseIterator const& other) const
{
	return p == other.p;
}
template<typename T>
T& OwnReverseIterator<T>::operator*() const
{
	return *p;
}
template<typename T>
OwnReverseIterator<T>& OwnReverseIterator<T>::operator++()
{
	--p;
	return *this;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::begin()
{
	return iterator(m_data);
}
template <typename T>
typename Vector<T>::iterator Vector<T>::end()
{
	return iterator(m_data + m_size);
}
template <typename T>
typename Vector<T>::const_iterator Vector<T>::cbegin() const
{
	return const_iterator(m_data);
}
template <typename T>
typename Vector<T>::const_iterator Vector<T>::cend() const
{
	return const_iterator(m_data + m_size);
}


template <typename T>
typename Vector<T>::reverse_iterator Vector<T>::rbegin()
{
	return reverse_iterator(m_data + m_size - 1);
}
template <typename T>
typename Vector<T>::reverse_iterator Vector<T>::rend()
{
	return reverse_iterator(m_data - 1);
}
template <typename T>
typename Vector<T>::const_reverse_iterator Vector<T>::crbegin() const
{
	return const_reverse_iterator(m_data + m_size - 1);
}
template <typename T>
typename Vector<T>::const_reverse_iterator Vector<T>::crend() const
{
	return const_reverse_iterator(m_data - 1);
}