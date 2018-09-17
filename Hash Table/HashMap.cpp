#include "HashMap.h"



HashMap::HashMap()
{
	table = new HashEntry*[TABLE_SIZE];

	for (int i = 0; i < TABLE_SIZE; i++) {
		table[i] = new HashEntry("", 0);
	}
}


HashMap::~HashMap()
{
}

int HashMap::HashFunc(std::string value)
{
	int hash = 0;

	for (int i = 0; i < value.length(); i++) {
		if (alpha.find(value[i])) {
			hash += (alpha.find(value[i]) + 1) * (i + 1);
		}
		else if (digit.find(value[i])) {
			hash += (digit.find(value[i]) + 27) * (i + 1);
		}
		else if (value[i] == quotes) {
			hash += 37 * (i + 1);
		}
		else if (symbol.find(value[i])) {
			hash += (symbol.find(value[i]) + 38) * (i + 1);
		}
	}

	return (hash %= TABLE_SIZE);
}

void HashMap::Insert(std::string value, int stock)
{
	table[HashFunc(value)]->value = value;
	table[HashFunc(value)]->stock += stock;
}

HashEntry* HashMap::Search(std::string value)
{
	return table[HashFunc(value)];
}

void HashMap::Remove(std::string value)
{
	if (table[HashFunc(value)]->stock > 0) {
		table[HashFunc(value)]->stock--;
	}
}
