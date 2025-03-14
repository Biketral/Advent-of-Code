package day_1;

public class ParseLine {


	public void parseLineAndUpdateList(String line, ListManager listManager) {
		StringBuilder firstNumber = new StringBuilder();
		StringBuilder secondNumber = new StringBuilder();
		boolean isFirstNumFinished = false;
		for (char eachChar : line.toCharArray()) {
			if (eachChar == ' ') {
				isFirstNumFinished = true;
				continue;
			}
			if (!isFirstNumFinished) {
				firstNumber.append(eachChar);
			} else {
				secondNumber.append(eachChar);
			}
		}
		Integer firstNumberInt = Integer.parseInt(firstNumber.toString());
		Integer secondNumberInt = Integer.parseInt(secondNumber.toString());
		listManager.addleftList(firstNumberInt);
		listManager.addRightList(secondNumberInt);
	}

}
