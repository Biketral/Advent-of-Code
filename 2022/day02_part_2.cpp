#include <iostream>
#include <fstream>
//Advent of Code 2022 - Day 2

int main() {

	std::ifstream data_list ("B_Z.md");
	std::string data {""};
	std::size_t total_score {0};

	const std::size_t draw {3}, win {6};
	const std::size_t rock {1}, paper {2}, scissors {3};


	while(std::getline(data_list, data)) {
		
		char opponent_turn {data[0]}, your_turn {data[2]};
		bool is_paper {false}, is_rock {false}, is_scissors {false};
		bool need_to_lose {false}, need_to_draw {false}, need_to_win {false};
		
		if(opponent_turn == 'A') {is_paper = true;}
		else if(opponent_turn == 'B') {is_rock = true;}
		else if(opponent_turn == 'C') {is_scissors = true;}
		
		if(your_turn == 'X') { need_to_lose = true; }
		if(your_turn == 'Y') { need_to_draw = true; }
		if(your_turn == 'Z') { need_to_win = true; }

		if(need_to_lose) { 
			if (is_paper) { total_score += scissors; } 
			else if (is_rock) { total_score += rock; }
			else if (is_scissors) { total_score += paper; }	
		}
		else if(need_to_draw) { 
			if (is_paper) { total_score += rock; }
			else if (is_rock) { total_score += paper; }
			else if (is_scissors) { total_score += scissors; }
			total_score += draw;				
		}
		else if(need_to_win) {
			if (is_paper) { total_score += paper; }
			else if (is_rock) { total_score += scissors; }
			else if (is_scissors) { total_score += rock; }	
			total_score += win;
		}
		is_paper = false;
		is_rock = false;
		is_scissors = false;
		need_to_draw = false;
		need_to_lose = false;
		need_to_win = false;

	}

	data_list.close();
	std::cout << "the ultra decrypting strategy score is: " << total_score;

	return 0;
}


