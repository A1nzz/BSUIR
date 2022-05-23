#include "Header.h"
void* my_memcpy(void* s1, const void* s2, size_t n) {
	char* p1 = static_cast<char*>(s1);
	const char* p2 = static_cast<const char*>(s2);
	for (size_t i = 0; i < n; i++) {
		p1[i] = p2[i];
	}
	return s1;
}

void* my_memmove(void* s1, const void* s2, size_t n) {
	char* p1 = static_cast<char*>(s1);
	const char* p2 = static_cast<const char*>(s2);
	if (p1 > p2) {
		for (size_t i = 0; i < n; i++) {
			p1[i] = p2[i];
		}
	}
	else {
		for (size_t i = n; i > 0; i--) {
			p1[i - 1] = p2[i - 1];
		}
	}
	return s1;
}

char* my_strcpy(char* s1, const char* s2) {
	char* p1 = s1;
	const char* p2 = s2;
	while (*p2 != '\0') {
		*p1 = *p2;
		p1++;
		p2++;
	}
	*p1 = '\0';
	return s1;
}

char* my_strncpy(char* s1, const char* s2, size_t n) {
	char* p1 = s1;
	const char* p2 = s2;
	for (size_t i = 0; i < n; i++) {
		*p1 = *p2;
		p1++;
		p2++;
	}
	*p1 = '\0';
	return s1;
}

char* my_strcat(char* s1, const char* s2) {
	char* p1 = s1;
	const char* p2 = s2;
	while (*p1 != '\0') {
		p1++;
	}
	while (*p2 != '\0') {
		*p1 = *p2;
		p1++;
		p2++;
	}
	*p1 = '\0';
	return s1;
}

char* my_strncat(char* s1, const char* s2, size_t n) {
	char* p1 = s1;
	const char* p2 = s2;
	while (*p1 != '\0') {
		p1++;
	}
	for (size_t i = 0; i < n; i++) {
		*p1 = *p2;
		p1++;
		p2++;
	}
	*p1 = '\0';
	return s1;
}

int my_memcmp(const void* s1, const void* s2, size_t n) {
	const char* p1 = static_cast<const char*>(s1);
	const char* p2 = static_cast<const char*>(s2);
	for (size_t i = 0; i < n; i++) {
		if (p1[i] < p2[i]) {
			return -1;
		}
		else if (p1[i] > p2[i]) {
			return 1;
		}
	}
	return 0;
}

int my_strcmp(const char* s1, const char* s2) {
	const char* p1 = s1;
	const char* p2 = s2;
	while (*p1 != '\0' && *p2 != '\0') {
		if (*p1 < *p2) {
			return -1;
		}
		else if (*p1 > *p2) {
			return 1;
		}
		p1++;
		p2++;
	}
	if (*p1 == '\0' && *p2 == '\0') {
		return 0;
	}
	else if (*p1 == '\0') {
		return -1;
	}
	else {
		return 1;
	}
}

int my_strcoll(const char* s1, const char* s2) {
	return my_strcmp(s1, s2);
}

int my_strncmp(const char* s1, const char* s2, size_t n) {
	const char* p1 = s1;
	const char* p2 = s2;
	for (size_t i = 0; i < n; i++) {
		if (p1[i] < p2[i]) {
			return -1;
		}
		else if (p1[i] > p2[i]) {
			return 1;
		}
	}
	if (n == 0) {
		return 0;
	}
	else if (p1[n - 1] < p2[n - 1]) {
		return -1;
	}
	else if (p1[n - 1] > p2[n - 1]) {
		return 1;
	}
	return 0;
}

size_t my_strxfrm(char* s1, const char* s2, size_t n) {
	char* p1 = s1;
	const char* p2 = s2;
	for (size_t i = 0; i < n; i++) {
		*p1 = *p2;
		p1++;
		p2++;
	}
	*p1 = '\0';
	return n;
}

char* my_strchr(const char* s, int c) {
	const char* p = s;
	while (*p != '\0') {
		if (*p == c) {
			return (char*)p;
		}
		p++;
	}
	if (c == '\0') {
		return (char*)p;
	}
	return nullptr;
}

char* my_strtok(char* s1, const char* s2) {
	static char* p1 = nullptr;
	if (s1 != nullptr) {
		p1 = s1;
	}
	else {
		if (p1 == nullptr) {
			return nullptr;
		}
	}
	char* p2 = p1;
	while (*p2 != '\0') {
		if (my_strchr(s2, *p2) != nullptr) {
			*p2 = '\0';
			p1 = p2 + 1;
			return p2;
		}
		p2++;
	}
	p1 = nullptr;
	return nullptr;
}

void* my_memset(void* s, int c, size_t n) {
	char* p = static_cast<char*>(s);
	for (size_t i = 0; i < n; i++) {
		p[i] = c;
	}
	return s;
}

size_t my_strlen(const char* s) {
	const char* p = s;
	size_t n = 0;
	while (*p != '\0') {
		n++;
		p++;
	}
	return n;
}
