package day_1;

import java.util.ArrayList;

public class Launcher {

	public static void main(String[] args) {

		ListManager listManager = new ListManager();
		HandleFile handleFile = new HandleFile();
		handleFile.readTheFile();
		handleFile.readEveryLineAndUpdateList(listManager);

		ArrayList<Integer> leftList = (ArrayList<Integer>) listManager.getLeftList();
		ArrayList<Integer> rightList = (ArrayList<Integer>) listManager.getRightList();

		
		
		
		int sumDistances = 0;

		while (!leftList.isEmpty()) {
			int left = listManager.getSmallestNumber(leftList);
			int right = listManager.getSmallestNumber(rightList);
			listManager.deleteNumber(leftList, left);
			listManager.deleteNumber(rightList, right);
			int distance = Math.abs(left - right);
			sumDistances += distance;
		}
		System.out.print(sumDistances); // 2742123

	}

}
