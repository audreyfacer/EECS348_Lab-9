#include <iostream>
#include <fstream>
#include <string>
#include "matrix.hpp"
std::pair<Matrix<int>, Matrix<int>> read_int_matrices_from_file(const std::string &filename) {
    std::ifstream file(filename);
    size_t N;
    int type_flag;
    file >> N >> type_flag;

    Matrix<int> matrix1(N), matrix2(N);
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j) {
            int val;
            file >> val;
            matrix1.set_value(i, j, val);
        }

    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j) {
            int val;
            file >> val;
            matrix2.set_value(i, j, val);
        }

    return {matrix1, matrix2};
}

std::pair<Matrix<double>, Matrix<double>> read_double_matrices_from_file(const std::string &filename) {
    std::ifstream file(filename);
    size_t N;
    int type_flag;
    file >> N >> type_flag;

    Matrix<double> matrix1(N), matrix2(N);
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j) {
            double val;
            file >> val;
            matrix1.set_value(i, j, val);
        }

    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j) {
            double val;
            file >> val;
            matrix2.set_value(i, j, val);
        }

    return {matrix1, matrix2};
}
int main(int argc, char *argv[]) {
    std::string filename;
    std::cout << "Enter a file name: ";
    std::getline(std::cin, filename);
    std::ifstream temp(filename);
    if (!temp) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }
    size_t N;
    int type_flag;
    temp >> N >> type_flag;
    temp.close();
    if(type_flag == 0){
        auto [matrix1, matrix2] = read_int_matrices_from_file(filename);
        matrix1.print_matrix();
        matrix2.print_matrix();
        Matrix added_matrix = matrix1 + matrix2;
        added_matrix.print_matrix();
        Matrix multiplied_matrix = matrix1 * matrix2;
        multiplied_matrix.print_matrix();
        int sum_major = matrix1.sum_diagonal_major();
        int sum_minor = matrix1.sum_diagonal_minor();
        std::cout << "Sum of the main diagonal elements of the first matrix is: " << sum_major << std::endl;
        std::cout << "Sum of the secondary diagonal elements of the first matrix is: " << sum_minor << std::endl;
        int sum_major2 = matrix2.sum_diagonal_major();
        int sum_minor2 = matrix2.sum_diagonal_minor();
        std::cout << "Sum of the main diagonal elements of the second matrix is: " << sum_major2 << std::endl;
        std::cout << "Sum of the secondary diagonal elements of the second matrix is: " << sum_minor2 << std::endl;
        int matrix_choice;
        std::cout << "Enter the matrix you would like to swap rows with(1 for the first, or 2 for the second): ";
        std::cin >> matrix_choice;
        int row1, row2;
        std::cout << "Enter the rows you would like to swap(in the format: row1 row2): ";
        std::cin >> row1 >> row2;
        if(matrix_choice == 1){
            matrix1.swap_rows(row1, row2);
        }else{
            matrix2.swap_rows(row1, row2);
        }
        int matrix_choice_col;
        std::cout << "Enter the matrix you would like to swap columns with(1 for the first, or 2 for the second): ";
        std::cin >> matrix_choice_col;
        int col1, col2;
        std::cout << "Enter the columns you would like to swap(in the format: col1 col2): ";
        std::cin >> col1 >> col2;
        if(matrix_choice_col == 1){
            matrix1.swap_cols(col1, col2);
        }else{
            matrix2.swap_cols(col1, col2);
        }
        int matrix_num, row, col, value;
        std::cout << "Enter the matrix you would like to change, the row and column of value you would like to change, and new value(in the format: matrix# row col value): ";
        std::cin >> matrix_num >> row >> col >> value;
        if(matrix_num == 1){
            matrix1.set_value(row, col, value);
            matrix1.print_matrix();
        }else{
            matrix2.set_value(row, col, value);
            matrix2.print_matrix();
        }
    }else{
        auto [matrix1, matrix2] = read_double_matrices_from_file(filename);
        matrix1.print_matrix();
        matrix2.print_matrix();
        Matrix added_matrix = matrix1 + matrix2;
        added_matrix.print_matrix();
        Matrix multiplied_matrix = matrix1 * matrix2;
        multiplied_matrix.print_matrix();
        double sum_major = matrix1.sum_diagonal_major();
        double sum_minor = matrix1.sum_diagonal_minor();
        std::cout << "Sum of the main diagonal elements of the first matrix is: " << sum_major << std::endl;
        std::cout << "Sum of the secondary diagonal elements of the first matrix is: " << sum_minor << std::endl;
        double sum_major2 = matrix2.sum_diagonal_major();
        double sum_minor2 = matrix2.sum_diagonal_minor();
        std::cout << "Sum of the main diagonal elements of the second matrix is: " << sum_major2 << std::endl;
        std::cout << "Sum of the secondary diagonal elements of the second matrix is: " << sum_minor2 << std::endl;
        int matrix_choice;
        std::cout << "Enter the matrix you would like to swap rows with(1 for the first, or 2 for the second): ";
        std::cin >> matrix_choice;
        int row1, row2;
        std::cout << "Enter the rows you would like to swap(in the format: row1 row2): ";
        std::cin >> row1 >> row2;
        if(matrix_choice == 1){
            matrix1.swap_rows(row1, row2);
        }else{
            matrix2.swap_rows(row1, row2);
        }
        int matrix_choice_col;
        std::cout << "Enter the matrix you would like to swap columns with(1 for the first, or 2 for the second): ";
        std::cin >> matrix_choice_col;
        int col1, col2;
        std::cout << "Enter the columns you would like to swap(in the format: col1 col2): ";
        std::cin >> col1 >> col2;
        if(matrix_choice_col == 1){
            matrix1.swap_cols(col1, col2);
        }else{
            matrix2.swap_cols(col1, col2);
        }
        int matrix_num, row, col, value;
        std::cout << "Enter the matrix you would like to change, the row and column of value you would like to change, and new value(in the format: matrix# row col value): ";
        std::cin >> matrix_num >> row >> col >> value;
        if(matrix_num == 1){
            matrix1.set_value(row, col, value);
            matrix1.print_matrix();
        }else{
            matrix2.set_value(row, col, value);
            matrix2.print_matrix();
        }
    }
    
    return 0;
}
