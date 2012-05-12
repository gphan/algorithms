package sort;

public class SelectionSort extends Sort {
	@Override
	public void sort(int[] a) {
		for (int i = 0; i < a.length; i++) {
			int lowIdx = i;
			int lowest = a[i];
			// Look for lowest number
			for (int j = i+1; j < a.length; j++) {
				if (a[j] < lowest) {
					lowest = a[j];
					lowIdx = j;
				}
			}
			Sort.swap(a, lowIdx, i);
		}
	}
}
