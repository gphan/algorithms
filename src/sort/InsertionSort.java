package sort;

public class InsertionSort extends Sort {

	/**
	 * Moves an index to the end position and shifts everything to the right.
	 * Assuming that the start index is to the right.
	 */
	private static void shiftRightAndInsert(int[] a, int start, int end) {
		int startVal = a[start];
		for (int i = start; i > end; i--) {
			a[i] = a[i - 1];
		}
		a[end] = startVal;
	}

	@Override
	public void sort(int[] a) {
		int curr = 0;

		while (curr < a.length) {
			int itr = 0;
			// Insert it into the right place on the left
			// Find the right place index
			while (a[itr] < a[curr])
				itr++;
			shiftRightAndInsert(a, curr, itr);
			curr++;
		}
	}
}
