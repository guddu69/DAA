// graph colouring using backtracking
#include <iostream>
#define V 4
using namespace std;
void print(int color[]);
bool issafe(int graph[V][V], int v, int color[], int c)
{
    for (int i = 0; i < V; i++)
    {
        if (graph[v][i] && c == color[i])
            return false;
    }
    return true;
}
bool graphuntil(int graph[V][V], int m, int color[], int v)
{
    // if assignment sucesssfull return true
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++)
    {
        if (issafe(graph, v, color, c))
        {
            color[v] = c;
            if (graphuntil(graph, m, color, v + 1) == true)
                return true;
            color[v] = 0;
        }
    }
    return false;
}
bool graphcolor(int graph[V][V], int m)
{
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;
    
    // calling function for vertex 0
    if (graphuntil(graph, m, color, 0) == false)
    {
        cout << "Sol does not exit" << endl;
        return false;
    }
    print(color);
    return true;
}
void print(int color[])
{
    cout << "Assigned colours are: ";
    for (int i = 0; i < V; i++)
        cout << color[i] << " ";
}
int main()
{
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    int m = 3;
    graphcolor(graph, m);
    return 0;
}