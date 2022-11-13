#include <iostream>
#include <chrono>
#include <mpi.h>
#include <stdio.h>
#include <string>
#include <windows.h>
#include <vector>
#include <fstream>

void print(std::vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << std::endl;
    }
}

int main(int argc, char* argv[])
{
    /*int cr = 900;
    std::vector<int> matrix1(cr*cr);
    std::vector<int> matrix2(cr * cr);
    for (int i = 0; i < cr * cr; i++) {
        matrix1[i] = (rand() % 3 +1 );
        matrix2[i] = (rand() % 3 +1);
    }
    std::ofstream data("Data.txt");
    for (int i = 0; i < cr * cr; i++) {
        data << matrix1[i] << " " << matrix2[i] << " ";
    }
    data.close(); */
    int SIZE = 900;
    setlocale(LC_ALL, "ru");
    MPI_Init(&argc, &argv);
    int my_rank, proc_num;
    MPI_Comm_size(MPI_COMM_WORLD, &proc_num);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    int dimension = 0;
    std::vector<int> matrix_1(SIZE* SIZE);
    std::vector<int> matrix_2_transponse(SIZE* SIZE);
    std::vector<int> matrix_4(SIZE* SIZE);
    if (my_rank == 0)
    {
        std::vector<int> matrix_2(SIZE* SIZE);
        std::ifstream data("Data.txt");
        int temp;
        bool changer = true;
        int i1 = 0;
        int i2 = 0;
        while (data >> temp) {
            if (changer) {
                matrix_1[i1] = temp;
                i1++;
            }
            else {
                matrix_2[i2] = temp;
                i2++;
            }
            changer = !changer;
        }
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                matrix_2_transponse[i * SIZE + j] = matrix_2[j * SIZE + i];
            }
        }
        dimension = SIZE;
    }
    MPI_Bcast(&dimension, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if (my_rank)
    {
        std::vector<int> matrix_2_transponse(SIZE* SIZE);
    }
    int local_size = dimension / proc_num;
    std::vector<int> local_a_part(local_size * dimension);  // 8*8, 4 процесса, т.е. 2x8 
    std::vector<int> local_result(local_size * dimension);
    int* matrix_1_pointer = &matrix_1[0];
    int* local_a_part_pointer = &local_a_part[0];
    int* local_result_pointer = &local_result[0];
    int* matrix_4_pointer = &matrix_4[0];
    int* matrix_2_transponse_pointer = &matrix_2_transponse[0];
    MPI_Scatter(matrix_1_pointer + my_rank * dimension * local_size, dimension * local_size, MPI_INT, local_a_part_pointer, dimension * local_size, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(matrix_2_transponse_pointer, dimension * dimension, MPI_INT, 0, MPI_COMM_WORLD);
    for (int i = 0; i < local_size; ++i)
    {
        for (int j = 0; j < dimension; ++j)
        {
            local_result[i * dimension + j] = 0;
            for (int k = 0; k < dimension; ++k)
            {
                local_result[i * dimension + j] += local_a_part[i * dimension + k] * matrix_2_transponse[j * dimension + k];
            }
        }
    }
    MPI_Gather(local_result_pointer, local_size * dimension, MPI_INT, matrix_4_pointer, dimension * local_size, MPI_INT, 0, MPI_COMM_WORLD);
    if (my_rank == 0) {
        std::ofstream matrix("Result.txt");
        for (long int i = 0; i < SIZE * SIZE; ++i) {
            matrix << matrix_4[i] << " ";
        }
        matrix.close();
        std::cout << "Operation successfully completed" << std::endl;
    }
    MPI_Finalize();
    return 0;
}