#include "HashEntry.h"
#include <string>


class HashMap
{
public:
	HashMap();
	~HashMap();
	int HashFunc(std::string value);
	void Insert(std::string value, int stock);
	HashEntry* Search(std::string value);
	void Remove(std::string value);
	const int TABLE_SIZE = 127;
	HashEntry** table;

private:
	HashEntry* valueObj;
	std::string alpha = "abcdefghijklmnopqrstuvwxyz";
	std::string digit = "0123456789";
	std::string symbol = "`~!@#$%^&*()-_=+[{]};:',<.>/?";
	char quotes = '"';
};

