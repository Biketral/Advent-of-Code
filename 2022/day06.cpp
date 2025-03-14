#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

int main()	{

	std::size_t index_counter {0};
	char current_char;
	std::string marker {""};
	bool found {false};
	std::fstream data_stream ("day_6_data.txt", std::fstream::in);
	while (data_stream >> current_char) {
		index_counter++;
		marker.push_back(current_char);

		if(marker.size() > 14) 
			marker.erase(marker.begin()); 

		if(marker.size() == 14) {
			std::unordered_set<char> set_current;
			for (char c : marker) {
				set_current.insert(c);
			}
			if(set_current.size() == 14) {
				found = true;
				break;
			}
		}
		if(found) break;
	}
	std::cout << "the marker starts at: " << index_counter << "\n";
	data_stream.close();

	return 0;
}