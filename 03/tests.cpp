#include "matrix.hpp"
void CreatingMatrixTest()
{
    bool success;
    try
    {
        Matrix matrix = Matrix(4, 5, 1);
        success = true;
    }
    catch (...)
    {
        success = false;
    }
    assert(success);
}

void GettingSizesTest()
{
    bool success;
    size_t rows, cols;
    try
    {
        Matrix matrix = Matrix(4, 5, 1);
        rows = matrix.getRows();
        cols = matrix.getCols();
        success = true;
    }
    catch (...)
    {
        success = false;
    }
    assert(success);
    assert(rows == 4);
    assert(cols == 5);
}

void GettingElementTest()
{
    bool success;
    int32_t value_1, value_2;
    try
    {
        Matrix matrix = Matrix(5, 5, 1);
        value_1 = matrix[0][0];
        value_2 = matrix[4][4];
        success = true;
    }
    catch (...)
    {
        success = false;
    }
    assert(success);
    assert(value_1 == 1);
    assert(value_2 == 1);
}

void RowIndexOutOfRangeTest()
{
    bool success;
    try
    {
        int32_t value;
        Matrix matrix = Matrix(3, 3, 1);
        value = matrix[3][0];
        success = false;
    }
    catch (...)
    {
        success = true;
    }
    assert(success);
}

void ColumnIndexOutOfRangeTest()
{
    bool success;
    try
    {
        int32_t value;
        Matrix matrix = Matrix(3, 3, 1);
        value = matrix[0][3];
        success = false;
    }
    catch (...)
    {
        success = true;
    }
    assert(success);
}

void ValueMatrixTest()
{
    bool success;
    int32_t value_1, value_2, value_3, value_4;
    try
    {
        Matrix matrix = Matrix(2, 2, 1);
        value_1 = matrix[0][0];
        value_2 = matrix[0][1];
        value_3 = matrix[1][0];
        value_4 = matrix[1][1];
        success = true;
    }
    catch (...)
    {
        success = false;
    }
    assert(success);
    assert(value_1 == 1);
    assert(value_2 == 1);
    assert(value_3 == 1);
    assert(value_4 == 1);
}

void ChangeElementTest()
{
    bool success;
    int32_t value_1, value_2;
    try
    {
        Matrix matrix = Matrix(2, 2, 1);
        matrix[0][0] = 2;
        value_1 = matrix[0][0];
        value_2 = matrix[0][1];
        success = true;
    }
    catch (...)
    {
        success = false;
    }
    assert(success);
    assert(value_1 == 2);
    assert(value_2 == 1);
}

void AssignmentTest()
{
    bool success;
    int32_t value_1, value_2, value_3, value_4;
    try
    {
        Matrix first_matrix = Matrix(2, 2, 1);
        Matrix second_matrix = Matrix(2, 2, 2);
        second_matrix = first_matrix;
        value_1 = second_matrix[0][0];
        value_2 = second_matrix[0][1];
        value_3 = second_matrix[1][0];
        value_4 = second_matrix[1][1];
        success = true;
    }
    catch (...)
    {
        success = false;
    }
    assert(success);
    assert(value_1 == 1);
    assert(value_2 == 1);
    assert(value_3 == 1);
    assert(value_4 == 1);
}

void EqualityTest()
{
    bool success;
    bool equal;
    try
    {
        Matrix first_matrix = Matrix(10, 10, 15);
        Matrix second_matrix = Matrix(10, 10, 15);
        equal = (second_matrix == first_matrix);
        success = true;
    }
    catch (...)
    {
        success = false;
    }
    assert(success);
    assert(equal);
}

void UnequalityTest()
{
    bool success;
    bool equal;
    try
    {
        Matrix first_matrix = Matrix(10, 10, 20);
        Matrix second_matrix = Matrix(10, 10, 15);
        equal = !(second_matrix == first_matrix);
        success = true;
    }
    catch (...)
    {
        success = false;
    }
    assert(success);
    assert(equal);
}

void MultiplicationTest()
{
    bool success;
    bool equal;
    try
    {
        Matrix first_matrix = Matrix(10, 10, 15);
        Matrix second_matrix = Matrix(10, 10, 30);
        first_matrix *= 2;
        equal = (second_matrix == first_matrix);
        success = true;
    }
    catch (...)
    {
        success = false;
    }
    assert(success);
    assert(equal);
}

void SumNumberTest()
{
    bool success;
    bool equal;
    try
    {
        Matrix first_matrix = Matrix(10, 10, 5);
        Matrix second_matrix = Matrix(10, 10, 10);
        first_matrix += 5;
        equal = (second_matrix == first_matrix);
        success = true;
    }
    catch (...)
    {
        success = false;
    }
    assert(success);
    assert(equal);
}

void SumMatrixTest()
{
    bool success;
    bool equal;
    try
    {
        Matrix first_matrix = Matrix(10, 10, 5);
        Matrix second_matrix = Matrix(10, 10, 10);
        Matrix sum_matrix = Matrix(10, 10, 15);
        equal = (sum_matrix == first_matrix + second_matrix);
        success = true;
    }
    catch (...)
    {
        success = false;
    }
    assert(success);
    assert(equal);
}

void PrintTest()
{
    bool success;
    try
    {
        Matrix matrix = Matrix(5, 5, 5);
        std::cout << "----------TEST PRINT----------\n";
        std::cout << matrix;
        std::cout << "----------TEST PRINT----------\n";
        success = true;
    }
    catch (...)
    {
        success = false;
    }
    assert(success);
}

int main()
{
    CreatingMatrixTest();
    GettingSizesTest();
    GettingElementTest();
    RowIndexOutOfRangeTest();
    ColumnIndexOutOfRangeTest();
    ValueMatrixTest();
    ChangeElementTest();
    AssignmentTest();
    EqualityTest();
    UnequalityTest();
    MultiplicationTest();
    SumNumberTest();
    SumMatrixTest();
    PrintTest();
    std::cout << "Success!\n";
    return 0;
}