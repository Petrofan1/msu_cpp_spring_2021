#ifndef HEADER
#define HEADER

#include <iostream>
#include <cassert>
#include <sstream>
#include <cstring>

class ProxyRow
{
private:
    size_t size;
    int32_t *data;

public:
    ProxyRow();
    ProxyRow(ProxyRow &row);
    ProxyRow(size_t size, int32_t value);
    size_t getSize() const;
    int32_t &operator[](size_t i);
    int32_t &operator[](size_t i) const;
    ProxyRow operator+(const ProxyRow &row) const;
    ProxyRow &operator=(const ProxyRow &row);
    ProxyRow &operator+=(int32_t value);
    ProxyRow &operator*=(int32_t value);
    bool operator==(const ProxyRow &row) const;
    bool operator!=(const ProxyRow &row) const;

    friend std::ostream &operator<<(std::ostream &out, const ProxyRow &row);

    ~ProxyRow();
};

class Matrix
{
private:
    size_t rows;
    size_t cols;
    ProxyRow *data;

public:
    Matrix(Matrix &matrix);
    Matrix(size_t rows, size_t cols, int32_t value);
    size_t getRows() const;
    size_t getCols() const;
    ProxyRow &operator[](size_t i);
    ProxyRow &operator[](size_t i) const;
    Matrix operator+(const Matrix &matrix) const;
    Matrix &operator=(const Matrix &matrix);
    Matrix &operator+=(int32_t value);
    Matrix &operator*=(int32_t value);
    bool operator==(const Matrix &matrix) const;
    bool operator!=(const Matrix &matrix) const;

    friend std::ostream &operator<<(std::ostream &out, const Matrix &matrix);

    ~Matrix();
};
#endif