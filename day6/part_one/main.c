#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

long apply_op(char **row, size_t len) {
    char op = row[len - 1][0];
    char *end;
    errno = 0;

    long result = strtol(row[0], &end, 10);
    if (*end != '\0' || errno) return 0;

    for (size_t i = 1; i < len - 1; i++) {
        errno = 0;
        long val = strtol(row[i], &end, 10);
        if (*end != '\0' || errno) return 0;

        switch (op) {
            case '+': result += val; break;
            case '-': result -= val; break;
            case '*': result *= val; break;
            case '/':
                if (val == 0) return 0;
                result /= val;
                break;
            default:
                return 0;
        }
    }

    return result;
}

int main() {
    FILE *file = fopen("../input.txt", "r");

    char ***grid = NULL;
    size_t rows = 0, cols = 0;

    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, file) != -1) {
        char **row = NULL;
        size_t col_count = 0;

        char *tok = strtok(line, " \n");
        while (tok) {
            row = realloc(row, (col_count + 1) * sizeof(char *));
            row[col_count++] = strdup(tok);
            tok = strtok(NULL, " \n");
        }

        if (rows == 0) cols = col_count;
        if (col_count != cols) return 1;

        grid = realloc(grid, (rows + 1) * sizeof(char **));
        grid[rows++] = row;
    }

    free(line);
    fclose(file);

    long sum = 0;
    for (size_t j = 0; j < cols; j++) {
        char **trow = malloc(rows * sizeof(char *));
        for (size_t i = 0; i < rows; i++)
            trow[i] = grid[i][j];

        long res = apply_op(trow, rows);
        sum += res;

        free(trow);
    }

    printf("%ld\n", sum);

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++)
            free(grid[i][j]);
        free(grid[i]);
    }

    free(grid);
    return 0;
}
