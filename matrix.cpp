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

// FUNCTION inputMatrix()
//     PRINT "Enter elements of n x n matrix:"
//     FOR i = 0 to n - 1  
//         FOR j = 0 to n - 1  
//             INPUT mat[i][j]  
//         END FOR  
//     END FOR  
// END FUNCTION  

// FUNCTION displayMatrix()
//     FOR i = 0 to n - 1  
//         FOR j = 0 to n - 1  
//             PRINT mat[i][j]  
//         END FOR  
//         PRINT newline  
//     END FOR  
// END FUNCTION  

// FUNCTION multiply(Matrix m2) RETURNS Matrix  
//     CREATE Matrix result of size n  
//     FOR i = 0 to n - 1  
//         FOR j = 0 to n - 1  
//             result.mat[i][j] = 0  
//             FOR k = 0 to n - 1  
//                 result.mat[i][j] = result.mat[i][j] + (mat[i][k] * m2.mat[k][j])  
//             END FOR  
//         END FOR  
//     END FOR  
//     RETURN result  
// END FUNCTION  

// BEGIN  
//     PRINT "Enter order of square matrix (n):"
//     INPUT n  

//     CREATE Matrix m1 of size n  
//     CREATE Matrix m2 of size n  
//     CREATE Matrix result of size n  

//     PRINT "Enter elements of first matrix:"
//     CALL m1.inputMatrix()  

//     PRINT "Enter elements of second matrix:"
//     CALL m2.inputMatrix()  

//     result = CALL m1.multiply(m2)  

//     PRINT "Resultant Matrix after multiplication:"
//     CALL result.displayMatrix()  

// END  
