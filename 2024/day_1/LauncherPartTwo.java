package day_1;

import java.util.ArrayList;

public class LauncherPartTwo {

	public static void main(String[] args) {

		ListManager listManager = new ListManager();
		HandleFile handleFile = new HandleFile();
		handleFile.readTheFile();
		handleFile.readEveryLineAndUpdateList(listManager);

		ArrayList<Integer> leftList = (ArrayList<Integer>) listManager.getLeftList();
		ArrayList<Integer> rightList = (ArrayList<Integer>) listManager.getRightList();

		int similarityCount = 0;

		for (Integer eachLeft : leftList) {
			int similarity = 0;
			for (Integer eachRight : rightList) {
				if (eachRight.equals(eachLeft)) {
					similarity++;
				}
			}
			similarityCount += similarity * eachLeft;
		}

		System.out.print(similarityCount); // 21328497

	}

}
