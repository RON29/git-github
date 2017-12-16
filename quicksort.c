#include <stdio.h>

void quickSort( int a[], int m, int n) {
	if(m < n) {
		int i = m + 1;
		int j = n;
		int key = a[m];
		int temp;

		while(1) {
			while(i < n && a[i] < key)
				i++;
			while(j > m && a[j] > key)
				j--;
			if(i < j) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			} else
				break;
		}

		a[m] = a[j];
		a[j] = key;
		quickSort( a, m, j - 1);
		quickSort( a, j + 1, n);
	}
}

int main() {
	int len, i;

	printf("Enter the length of the array: ");
	scanf("%d", &len);

	int a[len];
	for( i = 0; i < len; i++) {
		printf("Entry of element number %d: ", i + 1);
		scanf("%d", &a[i]);
	}

	quickSort( a, 0, len - 1);

	printf("The sorted array: ");
	for( i = 0; i < len; i++)
		printf("%d\t", a[i]);

	printf("\n");
	return 0;
}
