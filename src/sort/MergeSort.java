package sort;

import java.util.Arrays;

public class MergeSort extends Sort {

	private static int[] merge(int[] left, int[] right) {
		int[] merged = new int[left.length + right.length];
		int[] aux = new int[merged.length];
		int leftIdx = 0;
		int rightIdx = merged.length - 1;

		// Copy left into aux
		for (int i = 0; i < left.length; i++) {
			aux[i] = left[i];
		}

		// Copy right into aux reversed
		for (int i = 0; i < right.length; i++) {
			aux[rightIdx - i] = right[i];
		}

		int index = 0;
		while (leftIdx <= rightIdx) {
			if (aux[leftIdx] < aux[rightIdx])
				merged[index++] = aux[leftIdx++];
			else
				merged[index++] = aux[rightIdx--];
		}

		return merged;
	}

	private static int[] mergeSort(int[] array, int left, int right) {
		// Divide the array into two unless left >= right, in which case return
		// the single item
		// as an array
		if (left >= right) {
			return Arrays.copyOfRange(array, left, left + 1);
		} else {
			int mid = (left + right) / 2;
			int[] leftArray = mergeSort(array, left, mid);
			int[] rightArray = mergeSort(array, mid + 1, right);

			// Return the joined arrays using the merge function
			return merge(leftArray, rightArray);
		}
	}

	@Override
	public void sort(int[] array) {
		int[] sorted = mergeSort(array, 0, array.length - 1);

		System.arraycopy(sorted, 0, array, 0, sorted.length);
	}
}
