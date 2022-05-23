#pragma once

#define STRING_API __declspec(dllexport)
#include <fstream>
class STRING_API MyString
{
private:
	size_t size;
	char* str;
	
public:
	MyString() {
		size = 0;
		str = new char[1];
		str[0] = '\0';
	}
	MyString(const char* str) {
		size = strlen(str);
		this->str = new char[size + 1];
		strcpy_s(this->str, size + 1, str);
	}
	MyString(const MyString& str) {
		size = str.size;
		this->str = new char[size + 1];
		strcpy_s(this->str, size + 1, str.str);
	}
	~MyString() {
		delete[] str;
	}

	MyString& operator=(const MyString& str) {
		if (this != &str) {
			delete[] this->str;
			size = str.size;
			this->str = new char[size + 1];
			strcpy_s(this->str, size + 1, str.str);
		}
		return *this;
	}
	MyString& operator=(const char* str) {
		delete[] this->str;
		size = strlen(str);
		this->str = new char[size + 1];
		strcpy_s(this->str, size + 1, str);
		return *this;
	}
	MyString& operator+=(const MyString& str) {
		size_t newSize = size + str.size;
		char* newStr = new char[newSize + 1];
		strcpy_s(newStr, newSize + 1, this->str);
		strcat_s(newStr, newSize + 1, str.str);
		delete[] this->str;
		this->str = newStr;
		this->size = newSize;
		return *this;
	}
	MyString& operator+=(const char* str) {
		size_t newSize = size + strlen(str);
		char* newStr = new char[newSize + 1];
		strcpy_s(newStr, newSize + 1, this->str);
		strcat_s(newStr, newSize + 1, str);
		delete[] this->str;
		this->str = newStr;
		this->size = newSize;
		return *this;
	}
	MyString& operator+=(const char ch) {
		size_t newSize = size + 1;
		char* newStr = new char[newSize + 1];
		strcpy_s(newStr, newSize + 1, this->str);
		newStr[newSize - 1] = ch;
		newStr[newSize] = '\0';
		delete[] this->str;
		this->str = newStr;
		this->size = newSize;
		return *this;
	}
	
	char& operator[](size_t index) {
		return str[index];
	}
	const char& operator[](size_t index) const {
		return str[index];
	}
	
	bool isEmpty() const {
		return size == 0;
	}
	
	size_t getSize() const {
		return size;
	}
	const char* getStr() const {
		return str;
	}
	
	void setStr(const char* str) {
		delete[] this->str;
		size = strlen(str);
		this->str = new char[size + 1];
		strcpy_s(this->str, size + 1, str);
	}

	void setStr(const MyString& str) {
		delete[] this->str;
		size = str.size;
		this->str = new char[size + 1];
		strcpy_s(this->str, size + 1, str.str);
	}
	
	void setSize(size_t size) {
		delete[] this->str;
		this->size = size;
		this->str = new char[size + 1];
		this->str[size] = '\0';
	}
	//bool operator==(const MyString& str1, const MyString& str2) {
	//	return strcmp(str1.getStr(), str2.getStr()) == 0;
	//}


	//bool operator==(const MyString& str, const char* str2) {
	//	return strcmp(str.getStr(), str2) == 0;
	//}

	//bool operator==(const char* str1, const MyString& str2) {
	//	return strcmp(str1, str2.getStr()) == 0;
	//}

	//MyString operator+(const MyString& str1, const MyString& str2) {
	//	MyString str = str1;
	//	str += str2;
	//	return str;
	//}

	//bool operator!=(const MyString& str1, const MyString& str2) {
	//	return strcmp(str1.getStr(), str2.getStr()) != 0;
	//}

	//bool operator!=(const MyString& str, const char* str2) {
	//	return strcmp(str.getStr(), str2) != 0;
	//}

	//bool operator!=(const char* str1, const MyString& str2) {
	//	return strcmp(str1, str2.getStr()) != 0;
	//}

	//bool operator<(const MyString& str1, const MyString& str2) {
	//	return strcmp(str1.getStr(), str2.getStr()) < 0;
	//}

	//bool operator<(const MyString& str, const char* str2) {
	//	return strcmp(str.getStr(), str2) < 0;
	//}

	//bool operator<(const char* str1, const MyString& str2) {
	//	return strcmp(str1, str2.getStr()) < 0;
	//}

	//bool operator>(const MyString& str1, const MyString& str2) {
	//	return strcmp(str1.getStr(), str2.getStr()) > 0;
	//}

	//bool operator>(const MyString& str, const char* str2) {
	//	return strcmp(str.getStr(), str2) > 0;
	//}

	//bool operator>(const char* str1, const MyString& str2) {
	//	return strcmp(str1, str2.getStr()) > 0;
	//}

	//std::ostream& operator<<(std::ostream& os, const MyString& str) {
	//	os << str.getStr();
	//	return os;
	//}

	//std::istream& operator>>(std::istream& is, MyString& str) {
	//	char* newStr = new char[str.getSize() + 1];
	//	is >> newStr;
	//	str.setStr(newStr);
	//	delete[] newStr;
	//	return is;
	//}


};

