package sort;

import java.util.Arrays;
import java.util.Random;

/**
 * Base class for all sorts to provide testing interface.
 * @author gphan
 *
 */
public abstract class Sort {
	private static final Random rand = new Random();
	private static final int[] array = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	
	public static int[] getShuffledArray() {
		int[] copy = Arrays.copyOf(array, array.length);
		shuffle(copy);
		return copy;
	}
	
	public static final void swap(int[] a, int i, int j) {
		int t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	
	public static final void shuffle(int[] a) {
		for (int i = 0; i < a.length; i++) {
			int r = rand.nextInt(a.length);
			swap(a, i, r); 
		}
	}
	
	public static final void printArray(int[] a) {
		System.out.println(Arrays.toString(a));
	}
	
	public abstract void sort(int[] array);
}
