package day_2;

public class ParseLine {

	public void parseLine(String line) {
		
		StringBuilder numString = new StringBuilder();
		for (char eachChar : line.toCharArray()) {
			if(eachChar == ' ') {
				continue;
			}
			numString.append(eachChar);
		}
		
	}

}
