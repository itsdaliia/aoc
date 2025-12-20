#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

long apply_op(long *nums, size_t count, char op) {
    if (count == 0) return 0;

    long result = nums[0];
    for (size_t i = 1; i < count; i++) {
        switch (op) {
            case '+': result += nums[i]; break;
            case '-': result -= nums[i]; break;
            case '*': result *= nums[i]; break;
            case '/':
                if (nums[i] == 0) return 0;
                result /= nums[i];
                break;
            default:
                return 0;
        }
    }
    return result;
}

int main() {
    FILE *file = fopen("../input.txt", "r");

    char **lines = NULL;
    size_t line_count = 0;

    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, file) != -1) {
        size_t line_len = strlen(line);
        if (line_len > 0 && line[line_len - 1] == '\n') {
            line[line_len - 1] = '\0';
        }
        lines = realloc(lines, (line_count + 1) * sizeof(char *));
        lines[line_count++] = strdup(line);
    }

    free(line);
    fclose(file);

    char *operators = lines[line_count - 1];
    line_count--;

    size_t op_len = strlen(operators);
    long sum = 0;

    for (size_t col = 0; col < op_len; col++) {
        char op = operators[col];
        if (isspace(op)) continue;

        size_t max_digit_count = 0;
        for (size_t i = 0; i < line_count; i++) {
            size_t count = 0;
            for (size_t k = col; k < strlen(lines[i]) && isdigit(lines[i][k]); k++) {
                count++;
            }
            if (count > max_digit_count) max_digit_count = count;
        }

        long *numbers = malloc(max_digit_count * sizeof(long));
        size_t num_count = 0;

        for (int offset = (int)max_digit_count - 1; offset >= 0; offset--) {
            char *num_str = malloc(line_count + 1);
            size_t num_idx = 0;

            for (size_t i = 0; i < line_count; i++) {
                size_t pos = col + offset;
                if (pos < strlen(lines[i]) && isdigit(lines[i][pos])) {
                    num_str[num_idx++] = lines[i][pos];
                }
            }
            num_str[num_idx] = '\0';

            if (num_idx > 0) {
                numbers[num_count++] = strtol(num_str, NULL, 10);
            }

            free(num_str);
        }

        long result = apply_op(numbers, num_count, op);
        sum += result;

        free(numbers);
    }

    printf("%ld\n", sum);

    for (size_t i = 0; i <= line_count; i++) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}