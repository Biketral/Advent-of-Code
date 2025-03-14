package day_1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class HandleFile {
	private File inputFile = new File("day_1_input.txt");
	 private Scanner scanner;
	
	public void readTheFile() {
		try {
			scanner = new Scanner(inputFile);
		} catch(FileNotFoundException e) {
			e.printStackTrace();
			throw new IllegalStateException("File couldnt be read");
		}
	}
	
	public void readEveryLineAndUpdateList(ListManager listManager) {
		ParseLine parseLine = new ParseLine();
		while(scanner.hasNextLine()) {
			String line = scanner.nextLine();
			parseLine.parseLineAndUpdateList(line, listManager);
		}  
	}
}
