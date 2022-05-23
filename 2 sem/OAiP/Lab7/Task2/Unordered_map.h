#pragma once
#include <functional>
#include <vector>
#include <list>

template<typename KeyType, typename ValueType, typename Hash = std::hash<KeyType>, typename KeyEqual = std::equal_to<KeyType>>
class Unordered_map
{
public:
	const double LOAD_FACTOR = 0.75;
	using iterator = typename std::list<std::pair<KeyType, ValueType>>::iterator;
private:
	std::vector<std::list<std::pair<KeyType, ValueType>>> buckets;
	std::list<std::pair<KeyType, ValueType>> listOfAllElements;
	int size = 8;
	int count = 0;
	Hash hasher;

public:
	Unordered_map() : size(8), count(0), buckets(8), listOfAllElements()
	{
	}

	std::pair<iterator, bool> insert(std::pair<const KeyType, ValueType> pair) {
		KeyType key = pair.first;
		ValueType value = pair.second;
		int hash = hasher(key) % size;

		if (buckets[hash].empty())
		{
			buckets[hash].push_back(std::make_pair(key, value));
			listOfAllElements.push_back(std::make_pair(key, value));
			count++;
			if (count / size > LOAD_FACTOR)
			{
				rehash();
			}
			auto iter = listOfAllElements.end();
			iter--;
			return std::make_pair(iter, true);
		}
		else
		{
			for (auto it = buckets[hash].begin(); it != buckets[hash].end(); it++)
			{
				if (key == it->first)
				{
					it->second = value;
					return std::make_pair(it, false);
				}
			}
			buckets[hash].push_back(std::make_pair(key, value));
			listOfAllElements.push_back(std::make_pair(key, value));
			count++;
			if (count / size > LOAD_FACTOR)
			{
				rehash();
			}
			auto iter = listOfAllElements.end();
			iter--;
			return std::make_pair(iter, true);
		}
	}

	iterator find(const KeyType& key) {
		int hash = hasher(key) % size;

		for (auto it = buckets[hash].begin(); it != buckets[hash].end(); it++)
		{
			if (key == it->first)
			{
				return it;
			}
		}

		throw std::out_of_range("Key not found");
	}

	void erase(KeyType key) {
		int hash = hasher(key) % size;
		for (auto it = buckets[hash].begin(); it != buckets[hash].end(); it++)
		{
			if (key == it->first)
			{
				buckets[hash].erase(it);
				break;
			}
		}
		for (auto it = listOfAllElements.begin(); it != listOfAllElements.end(); it++)
		{
			if (key == it->first)
			{
				listOfAllElements.erase(it);
				break;
			}
		}
		count--;
	}

	void erase(iterator pos) {
		int hash = hasher(pos->first) % size;
		for (auto it = buckets[hash].begin(); it != buckets[hash].end(); it++)
		{
			if (pos->first == it->first)
			{
				buckets[hash].erase(it);
				break;
			}
		}
		for (auto it = listOfAllElements.begin(); it != listOfAllElements.end(); it++)
		{
			if (pos->first == it->first)
			{
				listOfAllElements.erase(it);
				break;
			}
		}
		count--;
	}

	void clear()
	{
		buckets.clear();
		listOfAllElements.clear();
		buckets.resize(8);
		size = 8;
		count = 0;
	}

	bool contains(KeyType key) {
		int hash = hasher(key) % size;
		for (auto it = buckets[hash].begin(); it != buckets[hash].end(); it++)
		{
			if (key == it->first)
			{
				return 1;
			}
		}
		return 0;
	}


	void rehash() {
		std::vector<std::list<std::pair<KeyType, ValueType>>> newBuckets(size * 2);
		for (auto it = listOfAllElements.begin(); it != listOfAllElements.end(); it++)
		{
			int hash = hasher(it->first) % (size * 2);
			newBuckets[hash].push_back(std::make_pair(it->first, it->second));
		}
		buckets = newBuckets;
		size *= 2;
	}

	ValueType& operator[](const KeyType& key)
	{
		if (contains(key)) {
			auto iter = find(key);
			return (*iter).second;
		}

		return insert(std::make_pair(key, (ValueType)key)).first->second;
	}

	int getCount()
	{
		return count;
	}

	bool isEmpty() {
		return count == 0;
	}

	iterator begin() { return listOfAllElements.begin(); }

	iterator end() { return listOfAllElements.end(); }
};


