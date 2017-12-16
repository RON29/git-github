#include <stdio.h>

int cmm(int i, int j, int k_min[][j + 1], int r[]) {
	if(i == j)
		return 0;

	int k, min_sum, current_sum;
	for( k = i; k < j; k++) {
		current_sum = cmm( i, k, k_min, r) + cmm( k + 1, j, k_min, r) + (r[i - 1] * r[k] * r[j]);
		if(i == k) {
			min_sum = current_sum;
			k_min[i][j] = k;
		}
		if(current_sum < min_sum) {
			min_sum = current_sum;
			k_min[i][j] = k;
		}
	}

	if(i != k_min[i][j])
		printf("Group %d and %d.\n", i, k_min[i][j]);

	return min_sum;
}

int main() {
	int n;
	printf("Enter number of matrices: ");
	scanf("%d", &n);

	int r[n + 1], k_min[n + 1][n + 1], i;

	printf("Enter the dimensions:\n");
	for( i = 0; i < n + 1; i++)
		scanf("%d", &r[i]);

	int opt = cmm( 1, n, k_min, r);

	printf("Minimum number of multiplications: %d\n", opt);
	return 0;
}
