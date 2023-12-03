#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Get first and last number of a given string and concat them
// e. g. "xx3x5xx7x" => 37
int getNumFromStr(char *line) {
	char first, last;

	for (int i = 0; i < strlen(line); ++i) {
		if (isdigit(line[i])) {
			first = line[i];
			break;
		}
	}

	for (int j = strlen(line); j >= 0; --j) {
		if (isdigit(line[j])) {
			last = line[j];
			break;
		}
	}

	char number[2] = { first, last };
	return atoi(number);
}

// Insert replacement into given substring to work-around overlapping issue
// e. g. "one" => "o1n"; "twone" => "t2o1e"
char* insertReplacement(char *original, const char *substring, const char *replacement) {
	char buffer[100];
    char *insertPoint = &buffer[0];
    const char *temp = original;
    size_t substringLen = strlen(substring);
    size_t replacementLen = strlen(replacement);

    while (1) {
        const char *p = strstr(temp, substring);

        if (p == NULL) {
            strcpy(insertPoint, temp);
            break;
        }

        // Copy everything before the substring
        memcpy(insertPoint, temp, p - temp);
        insertPoint += p - temp;

        // Calculate the middle point of the substring
        size_t middle = (substringLen + 1) / 2;

        // Copy the first half of the substring
        memcpy(insertPoint, p, middle);
        insertPoint += middle;

        // Copy the replacement
        memcpy(insertPoint, replacement, replacementLen);
        insertPoint += replacementLen;

        // Copy the second half of the substring
        memcpy(insertPoint, p + middle, substringLen - middle);
        insertPoint += substringLen - middle;

        // Move past the substring
        temp = p + substringLen;
    }

    // Copy the modified string back to the original
    strcpy(original, buffer);

	return original;
}

int solve1(char *filepath) {
	FILE *file_ptr = fopen(filepath, "r");
	int k = 0;
	char *line = NULL; ssize_t read; size_t len = 0;

	while ((read = getline(&line, &len, file_ptr)) != -1) {
		k = k + getNumFromStr(line);
	}
	fclose(file_ptr);

	return k;
}

int solve2(char *filepath) {
	FILE *file_ptr = fopen(filepath, "r");
	int k = 0;
	char *line = NULL; ssize_t read; size_t len = 0;

	while ((read = getline(&line, &len, file_ptr)) != -1) {
		line = insertReplacement(line, "one",   "1");
		line = insertReplacement(line, "two",   "2");
		line = insertReplacement(line, "three", "3");
		line = insertReplacement(line, "four",  "4");
		line = insertReplacement(line, "five",  "5");
		line = insertReplacement(line, "six",   "6");
		line = insertReplacement(line, "seven", "7");
		line = insertReplacement(line, "eight", "8");
		line = insertReplacement(line, "nine",  "9");

		k = k + getNumFromStr(line);
	}
	fclose(file_ptr);

	return k;
}

int main(void) {
	char *filepath = "./input.txt";

	printf("%d\n", solve1(filepath));
	printf("%d\n", solve2(filepath));

	return 0;
}
