package day_2;

import java.util.ArrayList;
import java.util.List;

public class LineHandler {
	private List<Integer> listOfNumbers;
	
	public void createNewLine() {
		listOfNumbers = new ArrayList<>();	
	}
	
	public void addNumber(Integer number) {
		listOfNumbers.add(number);
	}
}



