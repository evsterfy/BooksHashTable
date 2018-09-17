#include <string>
#include <iostream>
#include <fstream>
#include "HashMap.h"



int main() {
	std::string fileInput;
	std::string value;
	int stock;
	std::string entry;
	HashMap hashMap;
	std::fstream file;
	file.open("C:\\Users\\evang\\OneDrive\\Documents\\Visual Studio 2017\\Projects\\Personal\\Hash Table\\Books.txt");

	std::cout << "Current Stock" << std::endl;

	while (std::getline(file, fileInput)) {
		int space = fileInput.find(",./");
		value = fileInput.substr(0, space - 1);
		stock = stoi(fileInput.substr(space + 3));

		hashMap.Insert(value, stock);

		std::cout << value << " | Stock: " << stock << std::endl;
	}

	std::cout << std::endl;


	while (entry != "0") {
		std::cout << "Return book: 1 \nCheck for book: 2 \nCheck out: 3 \nSee stock: 4 \nEntry: ";

		std::getline(std::cin, entry);

		std::cout << std::endl;

		if (entry == "1") {
			std::cout << "Enter title to return: ";

			std::getline(std::cin, value);
			
			std::cout << std::endl;

			hashMap.Insert(value, 1);

			std::cout << "Returned: " << value << std::endl << std::endl;
		}
		else if (entry == "2") {
			std::cout << "Enter title to check for: ";

			std::getline(std::cin, value);

			std::cout << std::endl;

			if (hashMap.Search(value) != NULL && hashMap.Search(value)->value == value && hashMap.Search(value)->stock > 0) {
				std::cout << "We have title: " << value << std::endl;
				std::cout << "Stock: " << hashMap.Search(value)->stock << std::endl << std::endl;
			}
			else {
				std::cout << "Out of stock" << std::endl << std::endl;
			}
		}
		else if (entry == "3") {
			std::cout << "Enter title to check out: ";

			std::getline(std::cin, value);

			std::cout << std::endl;

			if (hashMap.Search(value) != NULL && hashMap.Search(value)->value == value && hashMap.Search(value)->stock > 0) {
				hashMap.Remove(value);

				std::cout << "Title checked out: " << value << std::endl << std::endl;
			}
			else {
				std::cout << "Out of stock" << std::endl << std::endl;
			}
		}
		else if (entry == "4") {
			for (int i = 0; i < hashMap.TABLE_SIZE; i++) {
				if (hashMap.table[i]->stock != 0) {
					std::cout << hashMap.table[i]->value << " | Stock: " << hashMap.table[i]->stock << std::endl;
				}
			}

			std::cout << std::endl;
		}
		else if (entry != "0") {
			continue;
		}
	}

	system("PAUSE");
}