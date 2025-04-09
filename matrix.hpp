#ifndef __Matrix<T>_HPP__
#define __Matrix<T>_HPP__

#include <cstdint>
#include <vector>

// all of your function definitions should be in this file now
template <typename T>
class Matrix {
private:
    size_t size;
    std::vector<std::vector<T>> data;
public:
    Matrix(std::size_t N): size(N), data(N, std::vector<T>(N, 0)) {}
    Matrix<T>(std::vector<std::vector<T>> nums) : size(nums.size()) {}

    Matrix<T> operator+(const Matrix<T> &rhs) const{
        
        Matrix<T> result(size); 
        for (std::size_t i = 0; i < size; ++i) {
            for (std::size_t j = 0; j < size; ++j) {
                result.data[i][j] = this->data[i][j] + rhs.data[i][j];
            }
        }
    
        return result;
    }
    Matrix<T> operator*(const Matrix<T> &rhs) const {
        Matrix result(size);

        for (std::size_t i = 0; i < size; ++i) {
            for (std::size_t j = 0; j < size; ++j) {
                for (std::size_t k = 0; k < size; ++k){
                    result.data[i][j] += this->data[i][k] * rhs.data[k][j];
                } 
            } 
        }

        return result;
    }
    void set_value(std::size_t i, std::size_t j, int n) {

    }
    T get_value(std::size_t i, std::size_t j) const {

    }
    int get_size() const{
        return size;
    }
    T sum_diagonal_major() const {
        T sum = 0;
        for (std::size_t i = 0; i < size; ++i) {
            sum += data[i][i]; 
        }
        return sum;

    }
    T sum_diagonal_minor() const {
        T sum = 0;
        for (std::size_t i = 0; i < size; ++i) {
            sum += data[i][size-i-1]; 
        }
        return sum;

    }
    void swap_rows(std::size_t r1, std::size_t r2) {
        if(r1 < size && r2 < size){
            std::swap(data[r1], data[r2]);
        }else{
            throw std::out_of_range("Error: Matrix index out of bounds");
        }
        print_matrix();
    }
    void swap_cols(std::size_t c1, std::size_t c2) {
        if(c1 < size && c2 < size){
            for(size_t i = 0; i < size; ++i){
                std::swap(data[i][c1], data[i][c2]);
            }
        }else{
            throw std::out_of_range("Error: Matrix index out of bounds");
        }
        print_matrix();
    }
    void print_matrix() const {
        for(size_t i = 0; i < size; ++i) {
            for(size_t j = 0; j < size; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

#endif // __Matrix<T>_HPP__
