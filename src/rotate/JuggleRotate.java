package rotate;

import sort.Sort;

/**
 * Rotates an int array using juggling.
 * 
 * @author gphan
 * 
 */
public class JuggleRotate {
	static int gcd(int a, int b) {
		int x = a, y = b;
		while (y != 0) {
			int z = x;
			x = y;
			y = z % y;
		}
		return x;
	}

	static void rotate(int[] a, int dist) {
		int g = gcd(dist, a.length);
		for (int i = 0; i < g; i++) {
			int t = a[i];
			int j = i;
			while (true) {
				int k = (j + dist) % a.length;
				if (k == i)
					break;
				a[j] = a[k];
				j = k;
			}
			a[j] = t;
		}
	}

	public static final void main(String[] args) {
		int[] array = Sort.getShuffledArray();
		Sort.printArray(array);
		rotate(array, array.length / 2);
		Sort.printArray(array);
	}
}
