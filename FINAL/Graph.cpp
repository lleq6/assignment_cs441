#include <iostream>

using namespace std;

int ConvertCharToIndex(char Char)
{
    char chars[] = {
        'A', 'B', 'C', 'D', 'E',
        'F', 'G', 'H', 'I', 'J',
        'K', 'L', 'M', 'O', 'P',
    };
    for (int i = 0; i < sizeof(chars); ++i)
    {
        if (chars[i] == Char)
        {
            return i;
        }
    }
    return -1;
}

class Graph
{
private:
    int N;
    int Edges[10][10];
public:
    Graph(int N)
    {
        this->N = N;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                Edges[i][j] = 0;
            }
        }
    }

    void AddEdge(char U, char V)
    {
        int i = ConvertCharToIndex(U);
        int j = ConvertCharToIndex(V);
        if (i != -1 && j != -1)
        {
            Edges[i][j] = 1;
        }
    }

    void DisplayAdjacencyMatrix()
    {
        cout << "Adjacency Matrix :\n";
        for (int i = 0; i < N; ++i)
        {
            cout << "\n";
            for (int j = 0; j < N; ++j)
            {
                cout << " " << Edges[i][j];
            }
        }
        cout << endl;
    }
};

int main()
{
    const int N = 8;
    Graph graph = Graph(N);
    graph.AddEdge('D', 'E');
    graph.AddEdge('D', 'B');
    graph.AddEdge('E', 'B');
    graph.AddEdge('E', 'F');
    graph.AddEdge('B', 'A');
    graph.AddEdge('B', 'F');
    graph.AddEdge('A', 'C');
    graph.AddEdge('G', 'H');
    graph.AddEdge('H', 'F');
    graph.DisplayAdjacencyMatrix();
    return EXIT_SUCCESS;
}