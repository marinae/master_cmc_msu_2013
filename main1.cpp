#include <fstream>

int main() {
	char* path1 = "numbers.txt";
	char* path2 = "max.txt";
	FILE* input = fopen(path1, "r");
	FILE* output = fopen(path2, "w");

	int num[100];		// массив чисел
	int N = 0;			// количество чисел в файле
	int x;				// вспомогательная переменная
	int count[20001];	// счетчики
	int max = 0;		// макс кол-во раз

	for (int i = 0; i < 20001; i++) {
		count[i] = 0;
	}

	while(!feof(input)) {
		fscanf(input, "%d", &x);
		num[N] = x;
		N++;
	}	

	for (int i = 0; i < N; i++) {
		count[num[i] + 10000]++;
	}

	for (int i = 0; i < 20001; i++) {
		if (count[i] > max)
			max = count[i];
	}

	for (int i = 20000; i >= 0; i--) {
		if (count[i] == max)
			fprintf(output, "%d %d\n", i - 10000, max);
	}	

	fclose(input);
	fclose(output);

	return 0;
}
