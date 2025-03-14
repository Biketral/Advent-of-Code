package day_1;

import java.util.ArrayList;
import java.util.List;

public class ListManager {

	private List<Integer> leftList = new ArrayList<>();
	private List<Integer> rightList = new ArrayList<>();

	public void addleftList(Integer leftValue) {
		leftList.add(leftValue);
	}

	public void addRightList(Integer rightValue) {
		rightList.add(rightValue);
	}

	public Integer getSmallestNumber(ArrayList<Integer> list) {
		Integer smallestNumber = Integer.MAX_VALUE;
		for (Integer eachNum : list) {
			if (eachNum < smallestNumber) {
				smallestNumber = eachNum;
			}
		}
		return smallestNumber;
	}

	public void deleteNumber(ArrayList<Integer> list, Integer numToDelete) {
		int i = 0;
		for (; i < list.size(); ++i) {
			if (list.get(i).equals(numToDelete)) {
				break;
			}
		}

		list.remove(i);
	}

	public List<Integer> getLeftList() {
		return leftList;
	}

	public List<Integer> getRightList() {
		return rightList;
	}

}
