#include <iostream>
#include <fstream>

char same_letter_func(std::string first_half, std::string second_half);
unsigned int get_value_char(char letter);

int main() {

	std::fstream data_list ("day_3_data.txt");
	std::string item {""};
	unsigned int sum {0};

	while(std::getline(data_list, item)) {
		std::string first_half {item.substr(0, item.size()/2)};
		std::string second_half {item.substr(item.size()/2, item.size())};
		char found_letter { same_letter_func(first_half, second_half) };
		unsigned int value_item {get_value_char(found_letter)};
	//  std::cout << item << "\n\t" << first_half << "\n\t" << second_half << "\n\t" << found_letter << "  " << value_item << "\n";
		sum += value_item;
	}
	
	data_list.close();
	std::cout << "the sum is: " << sum; 

	return 0; 
}


char same_letter_func(std::string first_half, std::string second_half) {
	for (std::size_t i {0}; i < first_half.size(); i++) {
		for (std::size_t j {0}; j < second_half.size(); j++) {
			if(first_half.at(i) == second_half.at(j)) {
				return first_half.at(i);
			}
		}
	}
	return '?';
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
