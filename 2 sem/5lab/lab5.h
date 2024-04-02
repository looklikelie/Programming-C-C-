#pragma once
#include <vector>
#include <iostream>
#include "lab5_exep.h"

template <class T>
T ArrayMax(std::vector <T> arr) {
        if (arr.empty())
            throw EmptyException();
        T max = arr[0];
        for (auto &i : arr)
            if (i > max)
                max = i;
        return max;
};

template <class T>
class Matrix {
public:
    Matrix(int n, int m) {
        this->data_.assign(n, std::vector <T>(m));
    };
    explicit Matrix(std::vector <std::vector <T>> v) {
        this->data_ = v;
    };
    T operator()(T i, T j) {
        if (i < 0 || i > this->data_.size())
            throw ExistExeption();
        if (j < 0 || j > this->data_[i].size())
            throw ExistExeption();
        return this->data_[i][j];
    };
    std::vector <T> operator()(T i) {
        if (i < 0 || i > this->data_.size())
            throw ExistExeption();
        return this->data_[i];
    };
private:
    std::vector <std::vector <T>> data_;
};