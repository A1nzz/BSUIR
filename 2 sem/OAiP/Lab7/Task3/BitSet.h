#pragma once

#include <bitset>
#include <iostream>

template<size_t N>
class BitSet {
private:
	using ty = unsigned long long;
	static const size_t Bitsperword = 8 * sizeof(ty);
	static const size_t size = (N + 63) / 64 + 1;
	ty array[size];
public:
	BitSet() : array{} {}

	BitSet(unsigned long long value) : array{ value } {}


	class Reference {
		friend BitSet<N>;
	public:
		Reference& operator=(bool _Val) {
			bitset->set_unchecked(pos, _Val);
			return *this;
		}

		Reference& operator=(const Reference& _Bitref) {
			bitset->set_unchecked(pos, static_cast<bool>(_Bitref));
			return *this;
		}

		Reference& flip() {
			bitset->flip_unchecked(pos);
			return *this;
		}

		bool operator~() const {
			return !bitset->subscript(pos);
		}

		operator bool() const {
			return bitset->subscript(pos);
		}

	private:
		BitSet<N>* bitset;
		size_t pos;

		Reference() : bitset(nullptr), pos(0) {}
		Reference(BitSet<N>& bs, size_t p) : bitset(bs), pos(p) {}
	};

	Reference operator[](size_t pos) {
		if (pos >= N) {
			throw std::out_of_range("bitset index outside range");
		}
		return Reference(*this, pos);
	}


	bool operator[] (size_t pos) const{
		if (pos >= N) {
			throw std::out_of_range("bitset index outside range");
		}
		return subscript(pos);
	}

	BitSet<N>& set() {
		std::memset(&array, 0xFF, sizeof(array));
		trim();
		return *this;
	}

	BitSet<N>& set(size_t pos, bool val = true) {
		/*if (size <= pos) {
			throw new std::exception(std::out_of_range("bitset out of range"));
		}*/
		return set_unchecked(pos, val);

	}

	BitSet& reset() noexcept { // set all bits false
		std::memset(array, 0, sizeof(array));
		return *this;
	}

	BitSet& reset(size_t pos) { // set bit at pos to false
		return set(pos, false);
	}

	BitSet& flip() noexcept { // flip all bits
		for (size_t _Wpos = 0; _Wpos < size; ++_Wpos) {
			array[_Wpos] = ~array[_Wpos];
		}
		trim();
		return *this;
	}

	BitSet& flip(size_t pos) { // flip bit at _Pos
		/*if (size <= pos) {
			throw new std::exception(std::out_of_range("bitset out of range"));
		}*/
		return flip_unchecked(pos);
	}

	bool any() const noexcept {
		for (size_t _Wpos = 0; _Wpos < size; ++_Wpos) {
			if (array[_Wpos] != 0) {
				return true;
			}
		}

		return false;
	}

	bool none() const noexcept {
		return !any();
	}

	bool all() const noexcept {
		bool _Zero_length = N == 0;
		if (_Zero_length) { // must test for this, otherwise would count one full word
			return true;
		}
		bool _No_padding = N % Bitsperword == 0;
		for (size_t _Wpos = 0; _Wpos < size - 1 + _No_padding; ++_Wpos) {
			if (array[_Wpos] != ~static_cast<ty>(0)) {
				return false;
			}
		}
		return _No_padding || array[size - 1] == (static_cast<ty>(1) << (N % Bitsperword)) - 1;
	}

	size_t count() const noexcept { // count number of set bits
		return std::_Select_popcount_impl<ty>([this](auto _Popcount_impl) {
			size_t _Val = 0;
			for (size_t _Wpos = 0; _Wpos < size; ++_Wpos) {
				_Val += _Popcount_impl(array[_Wpos]);
			}
			return _Val;
			});
	}

	size_t Size() const noexcept {
		return N;
	}

	bool test(size_t pos) const {
		/*if (pos >= N) {
			throw new std::exception(std::out_of_range("bitset out of range"));
		}*/

		return subscript(pos);
	}


	bool subscript(size_t pos) const {
		return (array[pos / Bitsperword] & (ty{ 1 } << pos % Bitsperword)) != 0;
	}


	void trim() noexcept { // clear any trailing bits in last word
		bool Work_to_do = N == 0 || N % Bitsperword != 0;
		if (Work_to_do) {
			array[size - 1] &= (ty{ 1 } << N % Bitsperword) - 1;
		}
	}

	std::string to_string() {// convert bitset to string
		std::string str;
		for (auto pos = N; 0 < pos;) {
			str.push_back(subscript(--pos) ? '1' : '0');
		}

		return str;
	}

	unsigned long long to_ullong() const {
		bool _Bits_zero = N == 0;
		bool _Bits_large = N > 64;
		if (_Bits_zero) {
			return 0;
		}
		else {
			if (_Bits_large) {
				for (size_t _Idx = 1; _Idx < size; ++_Idx) {
					if (array[_Idx] != 0) {
						throw new std::exception(std::out_of_range("overflow error"));
					}
				}
			}

			return array[0];
		}
	}

	unsigned long to_ulong() const {
		bool _Bits_zero = N == 0;
		bool _Bits_small = N <= 32;
		bool _Bits_large = N > 64;
		if (_Bits_zero) {
			return 0;
		}
		else if (_Bits_small) {
			return static_cast<unsigned long>(array[0]);
		}
		else {
			if (_Bits_large) {
				for (size_t _Idx = 1; _Idx < size; ++_Idx) {
					if (array[_Idx] != 0) {
						throw new std::exception(std::out_of_range("overflow error"));
					}
				}
			}

			if (array[0] > ULONG_MAX) {
				throw new std::exception(std::out_of_range("overflow error"));
			}

			return static_cast<unsigned long>(array[0]);
		}
	}

	BitSet& operator&=(const BitSet& right) noexcept {
		for (size_t _Wpos = 0; _Wpos <= size; ++_Wpos) {
			array[_Wpos] &= right.array[_Wpos];
		}

		return *this;
	}
	BitSet& operator|=(const BitSet& right) noexcept {
		for (size_t _Wpos = 0; _Wpos <= size; ++_Wpos) {
			array[_Wpos] |= right.array[_Wpos];
		}

		return *this;
	}
	BitSet& operator^=(const BitSet& right) noexcept {
		for (size_t _Wpos = 0; _Wpos <= size; ++_Wpos) {
			array[_Wpos] ^= right.array[_Wpos];
		}

		return *this;
	}

	BitSet operator<<(size_t pos) const noexcept {
		BitSet tmp = *this;
		tmp <<= pos;
		return tmp;
	}
	BitSet operator>>(size_t pos) const noexcept {
		BitSet tmp = *this;
		tmp >>= pos;
		return tmp;
	}

	BitSet& operator<<=(size_t pos) noexcept { // shift left by _Pos, first by words then by bits
		const auto _Wordshift = static_cast<ptrdiff_t>(pos / Bitsperword);
		if (_Wordshift != 0) {
			for (ptrdiff_t _Wpos = size; 0 <= _Wpos; --_Wpos) {
				array[_Wpos] = _Wordshift <= _Wpos ? array[_Wpos - _Wordshift] : 0;
			}
		}

		if ((pos %= Bitsperword) != 0) { // 0 < _Pos < _Bitsperword, shift by bits
			for (ptrdiff_t _Wpos = size; 0 < _Wpos; --_Wpos) {
				array[_Wpos] = (array[_Wpos] << pos) | (array[_Wpos - 1] >> (Bitsperword - pos));
			}

			array[0] <<= pos;
		}
		trim();
		return *this;
	}
	BitSet& operator>>=(size_t pos) noexcept { // shift right by _Pos, first by words then by bits
		const auto _Wordshift = static_cast<ptrdiff_t>(pos / Bitsperword);
		if (_Wordshift != 0) {
			for (ptrdiff_t _Wpos = 0; _Wpos <= size; ++_Wpos) {
				array[_Wpos] = _Wordshift <= size - _Wpos ? array[_Wpos + _Wordshift] : 0;
			}
		}

		if ((pos %= Bitsperword) != 0) { // 0 < _Pos < _Bitsperword, shift by bits
			for (ptrdiff_t _Wpos = 0; _Wpos < size; ++_Wpos) {
				array[_Wpos] = (array[_Wpos] >> pos) | (array[_Wpos + 1] << (Bitsperword - pos));
			}

			array[size] >>= pos;
		}
		return *this;
	}

private:
	BitSet& set_unchecked(size_t pos, bool val) { // set bit at Pos to Val, no checking
		auto& Selected_word = array[pos / Bitsperword];
		const auto Bit = ty{ 1 } << pos % Bitsperword;
		if (val) {
			Selected_word |= Bit;
		}
		else {
			Selected_word &= ~Bit;
		}
		return *this;
	}

	BitSet& flip_unchecked(size_t pos) { // flip bit at _Pos, no checking
		array[pos / Bitsperword] ^= ty{ 1 } << pos % Bitsperword;
		return *this;
	}
};



