package rotate;

import sort.Sort;

/**
 * Rotates an int array using reversing sub-arrays and then reversing the entire
 * array.
 * 
 * @author gphan
 * 
 */
public class ReverseRotate {
	static void reverseSub(int[] a, int start, int end) {
		int s = start, e = end;
		while (s < e) {
			int t = a[s];
			a[s] = a[e];
			a[e] = t;
			s++;
			e--;
		}
	}

	static void rotate(int[] a, int dist) {
		// Reverse sublists
		reverseSub(a, 0, dist - 1);
		reverseSub(a, dist, a.length - 1);

		// Reverse entire thing
		reverseSub(a, 0, a.length - 1);
	}

	public static final void main(String[] args) {
		int[] array = Sort.getShuffledArray();

		Sort.printArray(array);
		rotate(array, 2);
		Sort.printArray(array);
	}
}
