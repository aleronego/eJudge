#include <iostream>
#include <string>
using namespace std;

class Graph
{
int size;
unsigned int *node;
public:
    //int count = 0;
    Graph(int);
    void addRel(int, int);
    void searchRel(int, int);
    int whereRoot(int);
    // void optimisation();
    ~Graph() { delete[] node; }
};

Graph::Graph(int s) : size(s+1)
{
    node = new unsigned int[size]{0};
}

void Graph::addRel(int a, int b)
{
    if(node[a] == 0 && node[b] == 0)
        node[a] = node[b] = (a<b?a:b);
    else if(node[a]==0)
        node[a] = whereRoot( node[b] );
    else
        node[b] = whereRoot( node[a] );
}

int Graph::whereRoot(int a)
{
    //++count;
    if(node[a] == a)
        return a;
    else
    {
        node[a] = whereRoot(node[a]);
        //return whereRoot( node[a] );
        return node[a];
    }
}

void Graph::searchRel(int a, int b)
{
    if(node[a] == 0 || node[b] == 0)
    {
        cout << ":(\n";
    }
    else
    {
        int tA = whereRoot(a);
        int tB = whereRoot(b);
        if(tA == tB)
            cout << ":)\n";
        else
            cout << ":(\n";
    }
}

// void Graph::optimisation()
// {
//     cerr << "OPT\n";
//     for(int i = 1; i < size; ++i)
//     {
//         if(node[i] != i)
//         {
//              node[i] = whereRoot(node[i]);
//         }
//     }
//     cerr << "END OPT\n";
// }

int main(int argc, char const *argv[])
{
    int programmers, relationships;  
    cin >> programmers >> relationships;

    Graph g(programmers);
    for(int i = 0; i < relationships; ++i)
    {
        int a,b;
        cin >> a >> b;
        g.addRel(a,b);
    }

    // g.optimisation();

    int requests;
    cin >> requests;

    for(int i = 0; i < requests; ++i)
    {
        int a,b;
        cin >> a >> b;
        g.searchRel(a,b);
    }
}