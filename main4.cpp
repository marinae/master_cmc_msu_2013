#include <fstream>

int countPlace(char c) {
	if (c >= '0' && c <= '9')
		return c - '0';

	if (c >= 'A' && c <= 'Z')
		return 10 + c - 'A';

	if (c >= 'a' && c <= 'z')
		return 36 + c - 'a';
	return -1;
}

int countChar(int i) {
	if (i >= 0 && i <= 9)
		return '0' + i;

	if (i >= 10 && i <= 35)
		return 'A' + i - 10;

	if (i >= 36 && i <= 61)
		return 'a' + i - 36;
}

int main() {
	char* path1 = "input.txt";
	char* path2 = "output.txt";
	FILE* input = fopen(path1, "r");
	FILE* output = fopen(path2, "w");

	char c1, c2;
	int count[62][62];
	int x, y;
	int max = 0;
	int prevMax = 0;
	bool first = true;

	for (int i = 0; i < 62; i++)
		for (int j = 0; j < 62; j++)
			count[i][j] = 0;

	fscanf(input, "%c", &c1);

	while (!feof(input)) {
		fscanf(input, "%c", &c2);		
		x = countPlace(c1);
		y = countPlace(c2);
		if (x != -1 && y != -1)
			count[x][y]++;
		c1 = c2;
	}

	while (prevMax > 1 || first) {	

		for (int i = 0; i < 62; i++) {
			for (int j = 0; j < 62; j++) {
				if (first) {
					if (count[i][j] > max)
						max = count[i][j];
				}
				else if (count[i][j] > max && count[i][j] < prevMax)
					max = count[i][j];
			}
		}

		if (max > 0) {
			for (int i = 0; i < 62; i++) {
				for (int j = 0; j < 62; j++) {
					if (count[i][j] == max) {
						c1 = countChar(i);
						c2 = countChar(j);
						fprintf(output, "%c%c %d\n", c1, c2, max);
					}
				}
			}
		}

		prevMax = max;
		max = 0;
		first = false;
	}

	fclose(input);
	fclose(output);
	return 0;
}
