#include <iostream>
#include <vector>

using namespace std;

struct Edge
{
    int From, To;
};

class Graph
{
public:
    vector<vector<int>> AdjList;
    vector<int> Indegree;

    Graph(vector<Edge> const &Edges, int Nodes)
    {
        AdjList.resize(Nodes);
        Indegree.assign(Nodes, 0);
        for (auto &Edge : Edges)
        {
            AdjList[Edge.From].push_back(Edge.To);
            Indegree[Edge.To]++;
        }
    }
};

bool TopologicalSort(Graph const &Graph, vector<int> &Sorted, int Nodes)
{
    vector<int> Indegree = Graph.Indegree;
    vector<int> zeroIndegreeNodes;

    for (int i = 0; i < Nodes; i++)
    {
        if (Indegree[i] == 0)
        {
            zeroIndegreeNodes.push_back(i);
        }
    }
    while (!zeroIndegreeNodes.empty())
    {
        int fromNode = zeroIndegreeNodes.back();
        zeroIndegreeNodes.pop_back();
        Sorted.push_back(fromNode);
        for (int toNode : Graph.AdjList[fromNode])
        {
            Indegree[toNode] -= 1;
            if (Indegree[toNode] == 0)
            {
                zeroIndegreeNodes.push_back(toNode);
            }
        }
    }
    if ((int)Sorted.size() != Nodes)
    {
        return false;
    }
    return true;
}

int main()
{
    int Nodes = 9;
    vector<Edge> Edges =
    {
        { 0, 1 }, // A, B
        { 0, 2 }, // A, C
        { 1, 3 }, // B, D
        { 1, 4 }, // B, E
        { 2, 4 }, // C, E
        { 3, 5 }, // D, I
        { 5, 4 }, // I, E
        { 6, 7 }, // F, G
        { 7, 8 }, // G, K
        { 8, 2 }, // K, C
    };
    vector<int> Sorted;
    Graph Graph(Edges, Nodes);
    if (TopologicalSort(Graph, Sorted, Nodes))
    {
        for (int i = 0; i < (int)Sorted.size(); i++)
        {
            cout << Sorted[i] << " ";
        }
    }
    else
    {
        cout << "Topological sorting is not possible as the graph isn't acyclic";
    }
    return 0;
}