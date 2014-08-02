#include <fstream>

int main() {
	char* path1 = "edges.txt";
	char* path2 = "matrix.txt";
	FILE* input = fopen(path1, "r");
	FILE* output = fopen(path2, "w");

	int N = 0;			// количество вершин
	int a, b;			// номера вершин
	int** matrix;		// матрица

	while (!feof(input)) {
		fscanf(input, "%d %d", &a, &b);
		if (a > N)
			N = a;		// ищем максимальный номер вершины
		if (b > N)
			N = b;		// ищем максимальный номер вершины
	}

	fclose(input);

	matrix = new int* [N];
	for (int i = 0; i < N; i++) {
		matrix[i] = new int [N];

		for (int j = 0; j < N; j++)
			matrix[i][j] = 0;			// начальные значения в матрице
	}

	input = fopen(path1, "r");

	while (!feof(input)) {
		fscanf(input, "%d %d", &a, &b);
		matrix[a-1][b-1]++;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			fprintf(output, "%d ", matrix[i][j]);
		}
		fprintf(output, "\n");
	}

	fclose(output);

	return 0;
}
