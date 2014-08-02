#include <fstream>

int main() {
	char* path1 = "polynomial.txt";
	char* path2 = "parameters.txt";
	char* path3 = "result.txt";
	FILE* input1 = fopen(path1, "r");
	FILE* input2 = fopen(path2, "r");
	FILE* output = fopen(path3, "w");

	float coef[100];
	float x;
	double integral = 0;
	float a, b;
	int d;

	int N = 0;			// количество коэффициентов

	while (!feof(input1)) {
		fscanf(input1, "%f", &x);
		coef[N] = x;
		N++;
	}

	fscanf(input2, "%f %f %d", &a, &b, &d);

	for (int i = N - 1; i >= 0; i--) {
		coef[i] = coef[i] / (N - i);
		integral = integral + coef[i]*(pow(b, N - i) - pow(a, N - i));
	}

	fprintf(output, "%.4f", integral);

	fclose(input1);
	fclose(input2);
	fclose(output);

	return 0;
}
