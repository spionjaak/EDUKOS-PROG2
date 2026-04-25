#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX 10

typedef struct {
    int row;
    int col;
    float mat[MAX][MAX];
} matrix_t;

void fillRandom(matrix_t*, float , float);
void bestPositiveCol(const matrix_t *);
void freeMatrix(matrix_t*);

#endif //FUNCTIONS_H