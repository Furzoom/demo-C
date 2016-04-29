#include <iostream>

using namespace std;

class Matrix {
  public:
    Matrix(int row, int col) : _row(row), _col(col)
    {
        _pmat = new double[row * col];
        cout << "Matrix(" << row << ", " << col << ")" << endl;
    }
    Matrix(const Matrix &rhs) : _row(rhs._row), _col(rhs._col)
    {
        int elem_cnt = _row * _col;
        _pmat = new double[elem_cnt];
        for (int i = 0; i < elem_cnt; ++i)
        {
            _pmat[i] = rhs._pmat[i];
        }
    }
    ~Matrix()
    {
        delete [] _pmat;
        cout << "~Matrix()" << endl;
    }
//  private:
    int _row, _col;
    double *_pmat;
};

void test()
{
    Matrix mat(4, 4);
    cout << "(" << mat._row << ", " << mat._col << ")" << endl;
    cout << "ADDR: " << mat._pmat << endl;

    {
        Matrix mat2 = mat;
        cout << "(" << mat2._row << ", " << mat2._col << ")" << endl;
        cout << "ADDR: " << mat2._pmat << endl;
    }

    cout << "(" << mat._row << ", " << mat._col << ")" << endl;
    cout << "ADDR: " << mat._pmat << endl;
}

int main()
{
    test();
    return 0;
}
