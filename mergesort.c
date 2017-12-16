#include <stdio.h>

void merge( int a[], int p, int r, int q) {
	int i, j, k;

	int leftLen = r - p + 1;
	int rightLen = q - r;

	int L[leftLen], R[rightLen];

	for( i = 0; i < leftLen; i++)
		L[i] = a[p + i];

	for( j = 0; j < rightLen; j++)
		R[j] = a[r + 1 + j];

	for( i = 0, j = 0, k = p; i < leftLen && j < rightLen; k++)
		if(L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		} else {
			a[k] = R[j];
			j++;
		}

	while( i < leftLen) {
		a[k] = L[i];
		k++;
		i++;
	}

	while( j < rightLen) {
		a[k] = R[j];
		k++;
		j++;
	}
}

void mergeSort( int a[], int p, int q) {
	if(p < q) {
		int r = (p + q) / 2;
		mergeSort( a, p, r);
		mergeSort( a, r + 1, q);
		merge(a, p, r, q);
	}
}

int main() {
	int len, i;
	printf("Enter the length of the array: ");
	scanf("%d", &len);

	int a[len];
	for( i = 0; i < len; i++) {
		printf("Entry number %d: ", i + 1);
		scanf("%d", &a[i]);
	}

	mergeSort( a, 0, len - 1);

	printf("The sorted array:\n");
	for( i = 0; i < len; i++)
		printf("%d\t", a[i]);

	printf("\n");
	return 0;
}
