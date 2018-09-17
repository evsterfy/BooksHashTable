#include <string>


class HashEntry
{
public:
	HashEntry();
	~HashEntry();
	HashEntry(std::string value, int stock);
	std::string value;
	int stock = 0;
};

