#include <iostream>
#include <fstream>
//Advent of Code 2022 - Day 2

int main() {

	std::ifstream data_list ("B_Z.md");
	std::string data {""};
	std::size_t total_score {0};
	std::size_t ultra_decrypting_strategy {0};

	const std::size_t draw {3}, win {6}, lose {0};
	const std::size_t rock {1}, paper {2}, scissors {3};


	while(std::getline(data_list, data)) {
		char opponent_turn {data[0]}, your_turn {data[2]};
		
		if (opponent_turn == 'A') { 
			if(your_turn == 'X') { 
				total_score += rock + draw; 
			}
			else if(your_turn == 'Y') {
				total_score += paper + win; 
			}
			else if(your_turn == 'Z') {
				total_score += scissors + lose; 
			}
		}

		else if (opponent_turn == 'B') { 
			if(your_turn == 'X') {
				total_score += rock + lose; 
			}
			else if(your_turn == 'Y') {
				total_score += paper + draw; 
			}
			else if(your_turn == 'Z') {
				total_score += scissors + win; 
			}
		}

		else if (opponent_turn == 'C') { 
			if(your_turn == 'X') {
				total_score += rock + win;
			}
			else if(your_turn == 'Y') {
				total_score += paper + lose; 
			}
			else if(your_turn == 'Z') {
				total_score += scissors + draw;
			}
		}

	}

	data_list.close();
	std::cout << "the total score is: " << total_score;

	return 0;
}

