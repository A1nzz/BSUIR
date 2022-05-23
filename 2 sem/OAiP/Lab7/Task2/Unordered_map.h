#pragma once
#include <functional>
#include <vector>
#include <list>
//#include <memory>
template<class KeyType, class ValueType, class Hash = std::hash<KeyType>, class KeyEqual = std::equal_to<KeyType>>
class Unordered_map
{
private:
	std::vector<std::list<std::pair<KeyType, ValueType>>> buckets;
	std::list listOfAllBuckets;
	int size = 10;
	int countOfBuckets = 0;
	Hash hasher;
};


