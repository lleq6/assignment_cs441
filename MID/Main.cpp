#include <iostream>

using namespace std;

void DisplayMatrix(int, float**);
float** MatrixMultiply(int, float**, float**);
float** GetCofactor(float**, int, int, int);
int FindDeterminant(int, float**);
float** Adjoint(int, float**);
float** FindInverse(int, float**);

int main()
{
    int N;
    cout << "Enter a number of N : ";
    cin >> N;
    if (cin.fail())
    {
        cout << "Please enter only numbers." << endl;
        return EXIT_FAILURE;
    }
    float** MatrixA = new float* [N];
    float** MatrixB = new float* [N];
    for (int i = 0; i < N; ++i)
    {
        MatrixA[i] = new float[N];
    }
    for (int i = 0; i < N; ++i)
    {
        MatrixB[i] = new float[N];
    }
    cout << "Enter a value of Matrix A (" << N << "x" << N << ") : ";
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> MatrixA[i][j];
            if (cin.fail())
            {
                cout << "Please enter only numbers." << endl;
                return EXIT_FAILURE;
            }
        }
    }
    cout << "Enter a value of Matrix B (" << N << "x" << N << ") : ";
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> MatrixB[i][j];
            if (cin.fail())
            {
                cout << "Please enter only numbers." << endl;
                return EXIT_FAILURE;
            }
        }
    }
    cout << "----------------------------" << endl;
    cout << "          Matrix A          " << endl;
    cout << "----------------------------" << endl;
    DisplayMatrix(N, MatrixA);
    cout << "----------------------------" << endl;
    cout << "          Matrix B          " << endl;
    cout << "----------------------------" << endl;
    DisplayMatrix(N, MatrixB);
    float** newMatrix = MatrixMultiply(N, MatrixA, MatrixB);
    cout << "----------------------------" << endl;
    cout << "Multiply of Matrix AxB = " << N << "x" << N << endl;
    cout << "----------------------------" << endl;
    DisplayMatrix(N, newMatrix);
    float** Inverse = FindInverse(N, newMatrix);
    if (Inverse != NULL)
    {
        cout << "----------------------------" << endl;
        cout << " Invese of Matrix AB (AB-1) " << endl;
        cout << "----------------------------" << endl;
        DisplayMatrix(N, Inverse);
    }
    for (int i = 0; i < N; ++i)
    {
        delete[] MatrixA[i];
    }
    delete[] MatrixA;
    for (int i = 0; i < N; ++i)
    {
        delete[] MatrixB[i];
    }
    delete[] MatrixB;
    return EXIT_SUCCESS;
}

void DisplayMatrix(int N, float** Matrix)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << Matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

float** MatrixMultiply(int N, float** MatrixA, float** MatrixB)
{
    float** newMatrix = new float* [N];
    for (int i = 0; i < N; ++i)
    {
        newMatrix[i] = new float[N];
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            newMatrix[i][j] = 0;
            for (int k = 0; k < N; ++k)
            {
                newMatrix[i][j] += MatrixA[i][k] * MatrixB[k][j];
            }
        }
    }
    return newMatrix;
}

float** GetCofactor(float** Matrix, int P, int Q, int N)
{
    float** Temp = new float* [N];
    for (int i = 0; i < N; ++i)
    {
        Temp[i] = new float[N];
    }
    int i = 0, j = 0;
    for (int Row = 0; Row < N; Row++)
    {
        for (int Column = 0; Column < N; Column++)
        {
            if (Row != P && Column != Q)
            {
                Temp[i][j++] = Matrix[Row][Column];
                if (j == N - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
    return Temp;
}

int FindDeterminant(int N, float** Matrix)
{
    int Determinant = 0;
    if (N == 1) return Matrix[0][0];
    int Mask = 1;
    for (int i = 0; i < N; i++)
    {
        float** Temp = GetCofactor(Matrix, 0, i, N);
        Determinant += Mask * Matrix[0][i] * FindDeterminant(N - 1, Temp);
        Mask = -Mask;
    }
    return Determinant;
}

float** Adjoint(int N, float** Matrix)
{
    float** Adj = new float* [N];
    for (int i = 0; i < N; ++i)
    {
        Adj[i] = new float[N];
    }
    if (N == 1)
    {
        Adj[0][0] = 1;
        return Adj;
    }
    int Mask = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            float** Temp = GetCofactor(Matrix, i, j, N);
            Mask = ((i + j) % 2 == 0) ? 1 : -1;
            Adj[j][i] = Mask * FindDeterminant(N - 1, Temp);
        }
    }
    return Adj;
}

float** FindInverse(int N, float** Matrix)
{
    int Determinant = FindDeterminant(N, Matrix);
    if (Determinant == 0)
    {
        cout << "Can't find its inverse." << endl;
        cout << "Determinant = " << Determinant << endl;
        return NULL;
    }
    cout << "Determinant = " << Determinant << endl;
    float** Adj = Adjoint(N, Matrix);
    float** Inverse = new float* [N];
    for (int i = 0; i < N; ++i)
    {
        Inverse[i] = new float[N];
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            Inverse[i][j] = Adj[i][j] / float(Determinant);
        }
    }
    return Inverse;
}