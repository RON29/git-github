#include <stdio.h>
#include <limits.h>

int cost = 0;

int find_next_city( int n, int G[][n], int cities_completed[], int source) {
	int i, min = INT_MAX, min_cost, dist, city = INT_MAX;
	for( i = 0; i < n; i++)
		if(G[source][i] != INT_MAX && cities_completed[i] == 0) {
			dist = G[source][i] + G[i][0];
			if(dist < min) {
				min = dist;
				min_cost = G[source][i];
				city = i;
			}
		}

	if(min != INT_MAX)
		cost += min_cost;
	return city;
}

void tsp( int n, int G[][n], int cities_completed[], int source) {
	cities_completed[source] = 1;
	printf("%d -> ", source);
	int next_city = find_next_city( n, G, cities_completed, source);
	if(next_city == INT_MAX) {
		printf("%d\n", 0);
		cost += G[source][0];
		printf("Cost: %d\n", cost);
		return;
	}
	tsp( n, G, cities_completed, next_city);
}

int main() {
	int no_of_cities;
	printf("Enter the number of cities: ");
	scanf("%d", &no_of_cities);
	int adj_matrix[no_of_cities][no_of_cities], cities_completed[no_of_cities];
	int i, j;
	for( i = 0; i < no_of_cities; i++) {
		for( j = 0; j < no_of_cities; j++)
			if(i != j) {
				printf("Enter the distance between city %d and %d: ", i, j);
				scanf("%d", &adj_matrix[i][j]);
			} else
				adj_matrix[i][j] = INT_MAX;
		cities_completed[i] = 0;
	}

	tsp( no_of_cities, adj_matrix, cities_completed, 0);
	return 0;
}
