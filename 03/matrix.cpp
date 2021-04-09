#include "matrix.hpp"

ProxyRow::ProxyRow() {}

ProxyRow::ProxyRow(ProxyRow &row)
{
    size = row.getSize();
    data = new int32_t[size];
    for (size_t i = 0; i < size; i++)
    {
        data[i] = row[i];
    }
}

ProxyRow::ProxyRow(size_t size, int32_t value)
{
    this->size = size;
    data = new int32_t[size];
    for (size_t i = 0; i < size; i++)
    {
        data[i] = value;
    }
}

size_t ProxyRow::getSize() const
{
    return size;
}

int32_t &ProxyRow::operator[](size_t i)
{
    if (i >= size)
    {
        throw std::out_of_range("");
    }
    return data[i];
}

int32_t &ProxyRow::operator[](size_t i) const
{
    if (i >= size)
    {
        throw std::out_of_range("");
    }
    return data[i];
}

ProxyRow ProxyRow::operator+(const ProxyRow &row) const
{
    if (size != row.getSize())
    {
        throw std::out_of_range("");
    }
    ProxyRow result(size, 0);
    for (size_t i = 0; i < size; i++)
    {
        result[i] = data[i] + row[i];
    }
    return result;
}

ProxyRow &ProxyRow::operator=(const ProxyRow &row)
{
    if (size != row.getSize())
    {
        throw std::out_of_range("");
    }
    for (size_t i = 0; i < size; i++)
    {
        data[i] = row[i];
    }
    return *this;
}

ProxyRow &ProxyRow::operator*=(int32_t value)
{
    for (size_t i = 0; i < size; i++)
    {
        data[i] *= value;
    }
    return *this;
}

ProxyRow &ProxyRow::operator+=(int32_t value)
{
    for (size_t i = 0; i < size; i++)
    {
        data[i] += value;
    }
    return *this;
}

bool ProxyRow::operator==(const ProxyRow &row) const
{
    if (size != row.getSize())
    {
        return false;
    }
    for (size_t i = 0; i < size; i++)
    {
        if (data[i] != row[i])
        {
            return false;
        }
    }
    return true;
}

bool ProxyRow::operator!=(const ProxyRow &row) const
{
    return !(*this == row);
}

std::ostream &operator<<(std::ostream &out, const ProxyRow &row)
{
    for (size_t i = 0; i < row.getSize(); i++)
    {
        out << row[i] << ' ';
    }
    out << '\n';
    return out;
}

ProxyRow::~ProxyRow()
{
    delete[] data;
}

Matrix::Matrix(size_t rows, size_t cols, int32_t value)
{
    this->rows = rows;
    this->cols = cols;
    data = static_cast<ProxyRow *>(operator new[](rows * sizeof(ProxyRow)));
    for (size_t i = 0; i < rows; i++)
    {
        new (data + i) ProxyRow(cols, value);
    }
}

Matrix::Matrix(Matrix &matrix)
{
    rows = matrix.getRows();
    cols = matrix.getCols();
    data = new ProxyRow[rows];
    for (size_t i = 0; i < rows; i++)
    {
        data[i] = matrix[i];
    }
}

size_t Matrix::getRows() const
{
    return rows;
}

size_t Matrix::getCols() const
{
    return cols;
}

ProxyRow &Matrix::operator[](size_t i)
{
    if (i >= rows)
    {
        throw std::out_of_range("");
    }
    return data[i];
}

ProxyRow &Matrix::operator[](size_t i) const
{
    if (i >= rows)
    {
        throw std::out_of_range("");
    }
    return data[i];
}

Matrix Matrix::operator+(const Matrix &matrix) const
{
    if (rows != matrix.getRows())
    {
        throw std::out_of_range("");
    }
    Matrix result(rows, cols, 0);
    for (size_t i = 0; i < rows; i++)
    {
        result[i] = data[i] + matrix[i];
    }
    return result;
}

Matrix &Matrix::operator=(const Matrix &matrix)
{
    if (rows != matrix.getRows())
    {
        throw std::out_of_range("");
    }
    for (size_t i = 0; i < rows; i++)
    {
        data[i] = matrix[i];
    }
    return *this;
}

Matrix &Matrix::operator*=(int32_t value)
{
    for (size_t i = 0; i < rows; i++)
    {
        data[i] *= value;
    }
    return *this;
}

Matrix &Matrix::operator+=(int32_t value)
{
    for (size_t i = 0; i < rows; i++)
    {
        data[i] += value;
    }
    return *this;
}

bool Matrix::operator==(const Matrix &matrix) const
{
    if (rows != matrix.getRows())
    {
        return false;
    }
    for (size_t i = 0; i < rows; i++)
    {
        if (data[i] == matrix[i])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix &matrix) const
{
    return !(*this == matrix);
}

std::ostream &operator<<(std::ostream &out, const Matrix &matrix)
{
    for (size_t i = 0; i < matrix.getRows(); i++)
    {
        out << matrix[i];
    }
    return out;
}

Matrix::~Matrix()
{
    for (size_t i = 0; i < rows; i++)
    {
        data[i].~ProxyRow();
    }
    operator delete[](data);
}