package sort;

public class QuickSort extends Sort {
	
	private static final int partition(int[] a, int left, int right, int pivotIndex) {
		int pivotValue = a[pivotIndex];
		Sort.swap(a, pivotIndex, right);
		
		int index = left;
		for (int i = left; i < right; i++) {
			if (a[i] < pivotValue) {
				Sort.swap(a, i, index);
				index++;
			}
		}
		
		Sort.swap(a, index, right);
		return index;
	}
	
	private static final void quicksort(int a[], int left, int right) {
		if (left < right) {
			int pivotIndex = (left + right) / 2;
			
			pivotIndex = partition(a, left, right, pivotIndex);
			quicksort(a, left, pivotIndex - 1);
			quicksort(a, pivotIndex + 1, right);
		}
	}
	
	@Override
	public void sort(int[] array) {
		Sort.shuffle(array);
		quicksort(array, 0, array.length - 1);
	}
}
