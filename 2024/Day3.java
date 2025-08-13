package day_3;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Day3 {
	public static List<String> matches = new ArrayList<>();
	public static List<Integer> tempResults = new ArrayList<>();
	public static Pattern pattern = Pattern.compile("mul\\((\\d+),(\\d+)\\)");
	public static int result = 0;
	public static void main(String[] args) {
		try {
			
			File myObj = new File("C:\\Users\\Görkem\\git/Advent-of-Code/2024/day_3/day3_input");
			Scanner myReader = new Scanner(myObj);
			
			while (myReader.hasNextLine()) {			
				String data = myReader.nextLine();
				findMatches(data);
			}
			printMatches();
			calculateResult();
			System.out.println(result);
			myReader.close();
		} catch (FileNotFoundException e) {
			System.out.println("An error occurred.");
			e.printStackTrace();
		}
		
	}

	
	private static void findMatches(String data) {
		Matcher matcher = pattern.matcher(data);
		while(matcher.find()) {
			matches.add(matcher.group());
	        int first = Integer.parseInt(matcher.group(1));
	        int second = Integer.parseInt(matcher.group(2));
            int temp = first * second;
            tempResults.add(temp);
		}
	}


	private static void calculateResult() {
		for (Integer integer : tempResults) {
			result += integer;
		}
	}

	private static void printMatches() {
		for (String string : matches) {
			System.out.println(string);
		}
	}
	

}
