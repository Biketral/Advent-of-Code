#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

char same_letter_func_2(std::vector<std::string> group_item);
unsigned int get_value_char(char letter);

int main() {

	std::fstream data_list ("day_3_data.txt");
	std::vector<std::string> group_item {"", "", ""};
	unsigned int sum {0};


	while(std::getline(data_list, group_item[0]) && std::getline(data_list, group_item[1]) && std::getline(data_list, group_item[2]) ) {

		char found_letter { same_letter_func_2(group_item) };
		unsigned int value_item {get_value_char(found_letter)};
		sum += value_item;
		
		for (std::size_t i {0}; i < 3; i++ ) group_item[i] = "";
	}
	
	data_list.close();
	std::cout << "the sum is: " << sum; 

	return 0; 
}

char same_letter_func_2(std::vector<std::string> group_item) {
	if(group_item.size() !=3) throw std::runtime_error("Error: vector isn't 3 sizes long");
	for (char current_char : group_item[0]) {
		if(group_item[1].find(current_char) != std::string::npos && group_item[2].find(current_char) != std::string::npos) {
			return current_char;
		}
	}
	return '\0';
}

unsigned int get_value_char(char letter) {
	unsigned int ascii_value {static_cast<unsigned int>(letter)};
	if(ascii_value > 64 && ascii_value < 91) {
		ascii_value -= 64;
		ascii_value += 26;
	}
	else if (ascii_value > 96 && ascii_value < 123) {
		ascii_value -= 96;
	}
	return ascii_value;
}
