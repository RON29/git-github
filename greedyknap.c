#include <stdio.h>

void sort( int n, float a[], float b[], float c[]) {
	int i, j;
	float tmp;
	for( i = 0; i < n - 1; i++)
		for( j = 0; j < n - 1 - i; j++)
			if(a[j] <= a[j+1]) {
				tmp = a[j+1];
				a[j+1] = a[j];
				a[j] = tmp;

				tmp = b[j+1];
				b[j+1] = b[j];
				b[j] = tmp;

				tmp = c[j+1];
				c[j+1] = c[j];
				c[j] = tmp;
			}
}

float greedyKnapsack( int n, float c, float d[], float w[], float p[]) {
	int i;
       	float profit = 0;
	for( i = 0; i < n; i++)
		if(c > 0 && w[i] <= c) {
			c -= w[i];
			profit += p[i];
		} else
			break;
	if(c > 0)
		profit += c * d[i];
	return profit;
}

int main() {
	int nItems;
       	float capacity;
	printf("Enter the max capacity and the number of items: ");
	scanf("%f %d", &capacity, &nItems);

	float itemWeigths[nItems], itemProfits[nItems], profitDensity[nItems];
	int i;
	for( i = 0; i < nItems; i++) {
		printf("Enter the weight and profit of item %d: ", i + 1);
		scanf("%f %f", &itemWeigths[i], &itemProfits[i]);
		profitDensity[i] = itemProfits[i] / itemWeigths[i];
	}

	sort( nItems, profitDensity, itemWeigths, itemProfits);
	printf("Maximum profit: %.2f\n", greedyKnapsack( nItems, capacity, profitDensity, itemWeigths, itemProfits));
	return 0;
}
