#include <iostream>
#include <fstream>
//Advent of Code 2022 - Day 1

int main() {

	std::ifstream data_list("2000.pl");
	std::string data {""};
	int max_calories {0}, current_calories {0}, max_2 {0}, max_3 {0};

	while(std::getline(data_list, data)) {
		
		if(data == "") {
			if (current_calories > max_calories) {
				max_3 = max_2;
				max_2 = max_calories;
				max_calories = current_calories;
			}
			else if(current_calories > max_2 && current_calories != max_calories) {
				max_3 = max_2;
				max_2 = current_calories;
			}
			else if(current_calories > max_3 && current_calories != max_calories && current_calories != max_2) {
				max_3 = current_calories;
			}
			current_calories = 0;
		}
		else {
			try{
				current_calories += std::stoi(data);
			} catch (std::exception e) {}
		}
	}
	data_list.close();
	std::cout << "the max calories are: " << max_calories << "\n";
	std::cout << "the 2nd highest calories are: " << max_2 << "\n";
	std::cout << "the 3th calories are: " << max_3 << "\n";
	std::cout << "the sum up of the top 3: " << max_calories+max_2+max_3 << "\n";
	return 0;
}