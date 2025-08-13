import java.util.Arrays;
import java.io.File;  
import java.io.FileNotFoundException; 
import java.util.Scanner; 

public class Day2 {
	public static void main(String[] args) {
    
    try {
        File myObj = new File("input.txt");
        Scanner myReader = new Scanner(myObj);
        int countSafeLines = 0;
        while (myReader.hasNextLine()) {
            String line = myReader.nextLine();
            int[] numbers = parseLineToNumbers(line);
            if (isSequenceSafe(numbers) ) {
                countSafeLines++;
            } 
        }
        System.out.println(countSafeLines);
        myReader.close();
    } catch (FileNotFoundException e) {
        System.out.println("Input File for Day 2 couldn't be found.");
        e.printStackTrace();
    }
	    
	    

	}
	
	private static int[] parseLineToNumbers(final String line) {
	    return Arrays.stream(line.trim().split("\\s+"))
                     .mapToInt(Integer::parseInt)
                     .toArray();
	}
	
	
	private static boolean isSequenceSafe(final int[] numbers) {
        boolean isIncreasing = numbers[0] < numbers[1];
	    for (int i = 0; i < numbers.length-1; i++) {
            int firstNumber = numbers[i];
            int secondNumber = numbers[i+1];
            
            
            if (areEqual(firstNumber, secondNumber)) { return false; }
            if (isDifferenceInvalid(firstNumber, secondNumber) ) { return false; }
            if (isIncreasing && firstNumber > secondNumber) return false;
            if (!isIncreasing && firstNumber < secondNumber) return false;
	    }

	    return true;
	}
	private static boolean areEqual(final int firstNumber, final int secondNumber) {
        if(firstNumber == secondNumber) {
            return true;
        }
        return false;
	}
	private static boolean isDifferenceInvalid(final int firstNumber, final int secondNumber) {
        int difference = Math.abs(firstNumber - secondNumber);
        if (difference >= 1 && difference <= 3) {
            return false;
        }
        return true;
	}
	
}
