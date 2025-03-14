#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::string> slice_data(std::string);
std::vector<int> extract_numbers(std::string);
int main() {

	std::fstream data_list ("day_4_data.txt");
	std::string data {""};
	std::size_t complete_overlap_count {0}, overlap_count {0}; 
	//8-41,8-79
	while(std::getline(data_list, data)) {
		std::vector<std::string> sliced_data {slice_data(data)};
		
		std::vector<int> extracted_numbers_left {extract_numbers(sliced_data[0])};
		std::size_t left_begin = extracted_numbers_left[0];
		std::size_t left_end = extracted_numbers_left[1];

		std::vector<int> extracted_numbers_right {extract_numbers(sliced_data[1])};
		std::size_t right_begin = extracted_numbers_right[0];
		std::size_t right_end = extracted_numbers_right[1];


		if((right_begin >= left_begin && right_end <= left_end) || (left_begin >= right_begin && left_end <= right_end)) {
			complete_overlap_count++;
		}
		
		if(left_begin <= right_end && left_end >= right_begin) {
			overlap_count++;
		}
	}

	std::cout << "the completely overlap: " << complete_overlap_count << "\n";
	std::cout << "more than one overlap: " << overlap_count << "\n";
	data_list.close();

	return 0;
}


std::vector<std::string> slice_data(std::string data) {
		std::size_t comma_pos {data.find(',')};
		std::string first_range {data.substr(0, comma_pos)};
		std::string second_range {data.substr(comma_pos + 1)};
/*
		bool is_second_half {false};
		for (char c : data) {
			if(c == ',' || is_second_half) {
				is_second_half = true;
				second_range.push_back(c);
			}
			else 
				first_range.push_back(c);
		}
*/	
	return {first_range, second_range};
}

std::vector<int> extract_numbers(std::string data) {
	std::size_t dash_pos {data.find('-')};
	std::string first_range {data.substr(0, dash_pos)};
	std::string second_range {data.substr(dash_pos + 1)};	
	return {stoi(first_range),stoi(second_range)};
}