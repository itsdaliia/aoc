#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *file = fopen("../input.txt", "r");
    char **grid = NULL;
    size_t rows = 0;

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file)) != -1) {
        grid = realloc(grid, (rows + 1) * sizeof(char *));
        grid[rows] = strdup(line);
        rows++;
    }

    free(line);
    fclose(file);
    
    int dx[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
    int dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

    int accessible = 0;
    for (size_t i = 0; i < rows; i++) {
        size_t cols = strlen(grid[i]);

        for (size_t j = 0; j < cols; j++) {
            if (grid[i][j] == '@') {
                int count = 0;

                for (int k = 0; k < 8; k++) {
                    int ni = (int)i + dx[k];
                    int nj = (int)j + dy[k];

                    if (ni >= 0 && ni < (int)rows) {
                        if (nj >= 0 && nj < (int)strlen(grid[ni])) {
                            if (grid[ni][nj] == '@') {
                                count++;
                            }
                        }
                    }
                }

                if (count < 4) {
                    accessible++;
                }
            }
        }
    }

    printf("%d\n", accessible);

    for (size_t i = 0; i < rows; i++) {
        free(grid[i]);
    }

    free(grid);
    return 0;
}
