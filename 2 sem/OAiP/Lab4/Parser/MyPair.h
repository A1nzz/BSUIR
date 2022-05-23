#pragma once
template <typename T, typename U>

struct Pair {
	T first;
	U second;
	
	Pair(T first, U second) : first(first), second(second) {}

	Pair(Pair<T, U> first, Pair<T, U> second) : first(first.first), second(second.second) {}

	Pair& operator=(const Pair& other) {
		first = other.first;
		second = other.second;
		return *this;
	}
	bool operator<(const Pair& other) const {
		return first < other.first;
	}

	bool operator==(const Pair& other) const {
		return first == other.first && second == other.second;
	}

	bool operator!=(const Pair& other) const {
		return !(*this == other);
	}

	bool operator>(const Pair& other) const {
		return first > other.first;
	}
	
	bool operator<=(const Pair& other) const {
		return !(*this > other);
	}

	bool operator>=(const Pair& other) const {
		return !(*this < other);
	}
};