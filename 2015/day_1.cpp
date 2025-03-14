#include <iostream>
#include <fstream>

int main() {

	std::fstream data ("day_1_data.txt", std::fstream::in);
	int result {0}, counter {0}, first_basement {0};
	char current_char;
	while (data >> current_char) {
		//counter++;
		if(current_char == '(') result++;
		else result--;	

		//if(result == -1) { break;}
	}
	std::cout << "Santa is at: " << result << "floor\n";
	//std::cout << "santas first time on basement: " << counter << "\n";
	data.close();

	return 0;
}