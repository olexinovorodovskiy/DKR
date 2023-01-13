#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void martix_fill(int *arr, const int martix_size);
void martix_print_num(int *arr, const int martix_size);
int rnd_diapazon(const int low, const int high);
void sort(int *sortable_matrix, int *result_matrix, const int matrix_size);
void swap(int *a, int *b);
void swap_next_rows(int *arr, int row, const int matrix_size);
int once_sort_rows(int *sortable_matrix, const int matrix_size);

#define MATRIX_SIZE 5

int main()
{
    srand(time(NULL)); //"rnd" begin for func rand()

    int A[MATRIX_SIZE][MATRIX_SIZE];
    int B[MATRIX_SIZE][MATRIX_SIZE] = {0};

    martix_fill(&A[0][0], MATRIX_SIZE);

    sort(&A[0][0], &B[0][0], MATRIX_SIZE);
    martix_print_num(&A[0][0], MATRIX_SIZE);
    martix_print_num(&B[0][0], MATRIX_SIZE);
    getch();
    return 0;
}

void sort(int *sortable_matrix, int *result_matrix, const int matrix_size)
{
    for (int i = 0; i < matrix_size * matrix_size; i++)
        result_matrix[i] = sortable_matrix[i];
    while (once_sort_rows(&result_matrix[0], matrix_size))
        ;
}

int once_sort_rows(int *sortable_matrix, const int matrix_size)
{
    int sum1 = 0, sum2 = 0;
    for (int j = 0; j < matrix_size; j++)
        sum1 += sortable_matrix[j];
    for (int i = 1; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
            sum2 += sortable_matrix[i * matrix_size + j];
        if (sum2 < sum1)
        {
            swap_next_rows(&sortable_matrix[0], i, matrix_size);
            return 1; // if matrix sorted not fully, return "1"
        }
        sum1 = sum2;
        sum2 = 0;
    }
    return 0; // if sorted all matrix, return "0"
}

void swap_next_rows(int *arr, int row, const int matrix_size)
{
    for (int j = 0; j < matrix_size; j++)
        swap(&arr[(row - 1) * matrix_size + j], &arr[row * matrix_size + j]);
}

void martix_fill(int *arr, const int martix_size)
{
    for (int i = 0; i < martix_size; i++)
        for (int j = 0; j < martix_size; j++)
            arr[i * martix_size + j] = rnd_diapazon(3, 7); // fill arr by "rnd" numbers
}

void martix_print_num(int *arr, const int martix_size)
{
    printf("%2d  ", 0);
    for (int j = 1; j <= martix_size; j++)
        printf(" %5d", j);
    printf("\n");
    for (int i = 0; i < martix_size; i++)
    {
        printf("%2d||", i + 1);
        for (int j = 0; j < martix_size; j++)
            printf(" %5d", arr[i * martix_size + j]);
        printf(" ||\n");
    }
    printf("\n");
}

int rnd_diapazon(const int low, const int high)
{
    return rand() % (high - low + 1) + low;
}

void swap(int *a, int *b)
{
    int pp = *b;
    *b = *a;
    *a = pp;
}
