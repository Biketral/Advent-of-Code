#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


std::vector<std::string> extract_data(std::vector<std::string>);
std::vector<int> extract_numbers(std::string);
std::string reverser(std::string);


int main() {

//	std::ofstream myfile;
//	myfile.open("example.txt", std::ios::app);

	std::fstream data_list ("day_5_data.txt");
	std::string line {""};
	std::vector<std::string> raw_data;

	while(std::getline(data_list, line)) {
		if(line == "") break;
		else raw_data.push_back(line);
	}
	std::vector<std::string> extracted_data { extract_data(raw_data) };


	while(std::getline(data_list, line)) {
		// extract numbers
		std::vector<int> number_list {extract_numbers(line)};
		
		// extract values from numbers
		int count {0}, from {0}, to {0};
		if(number_list.size() > 3) {
			int tmp {number_list[0]};
			tmp *= 10;
			tmp += number_list[1];
			count = tmp;
			from = number_list[2];
			to = number_list[3];
		}
		else {
			count = number_list[0]; 
			from = number_list[1];
			to = number_list[2];
		}
		from--;
		to--;

//		myfile << "line: " << line << "\n";
//		myfile << " count: " << count << "from: " << from << " to " << to  << "\n";
//		myfile << "extracted_data[to]: " << extracted_data[to] << "\n";
//		myfile<< "extracted_data[from]: " << extracted_data[from] << "\n";

		// execute movement
		for (; count > 0; count--) {
			char last_char {extracted_data[from].back()};
			if(last_char != ' ') {
				extracted_data[to]  += extracted_data[from].back(); 
				extracted_data[from].pop_back();
			}
			
//			myfile << "count: " << count << " character: " << extracted_data[from].back() << "\n";

			//for (auto c : extracted_data[to]) {(int(c) == 32) extracted_data[to].remove(c);}
		}

		// this line to erase spaces in the string
//		extracted_data[to].erase(remove_if(extracted_data[to].begin(), extracted_data[to].end(), isspace), extracted_data[to].end());
//		extracted_data[to].shrink_to_fit();

//		myfile << "new extracted_data[to]: " << extracted_data[to] << "\n";
//		myfile<< "new extracted_data[from]: " << extracted_data[from] << "\n\n";

		number_list.clear();
	}
	std::string end_result {""};
	for (auto c : extracted_data) {
		std::cout << c << "\n";
		end_result += c.back();
	}
	std::cout << "\n"  << end_result;
//	myfile.close();

	data_list.close();
	return 0;
}


std::vector<std::string> extract_data(std::vector<std::string> raw_data) {
	raw_data.pop_back();
	std::vector<std::string> result;
	
	for (std::size_t i {1}; i < raw_data[0].size(); i+=4) {
		std::string column {""};
		std::string tmp {""};
		for(std::string c : raw_data) {
			char value {c[i]};
			if (value != '\0') 
				tmp.push_back(value);
		}

		column += reverser(tmp);
		result.push_back(column);
	}
	//for(auto c : result )std::cout << c << "\n";
	return result;
}

std::vector<int> extract_numbers(std::string line) {
	std::vector<int> number_list;
	for (char current_char : line) {
		int ascii_val {(int)current_char};
		if (ascii_val >= '0' && ascii_val <= '9') {
			int right_value {current_char - '0'};
			number_list.push_back(right_value);
		}
	}
	return number_list;
}

std::string reverser(std::string text) {
	std::string reverse {text};
	std::reverse(reverse.begin(), reverse.end());
	return reverse;
}

