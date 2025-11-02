// Atulyas Matrix
#include <iostream>
using namespace std;

class Matrix {
private:
    int n;
    int mat[10][10];

public:
    Matrix(int size) {
        n = size;
    }

    void inputMatrix() {
        cout << "Enter elements of " << n << "x" << n << " matrix:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }
    }

    void displayMatrix() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix multiply(Matrix &m2) {
        Matrix result(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result.mat[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    result.mat[i][j] += mat[i][k] * m2.mat[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    int n;
    cout << "Enter order of square matrix (n): ";
    cin >> n;

    Matrix m1(n), m2(n), result(n);

    m1.inputMatrix();
    m2.inputMatrix();

    result = m1.multiply(m2);

    cout << "Resultant Matrix after multiplication:" << endl;
    result.displayMatrix();

    return 0;
}


