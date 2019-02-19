#include <iostream>
#include <string>
using namespace std;

class Graph
{
int size;
unsigned int *node;
public:
    Graph(int);
    void addRel(int, int);
    void searchRel(int, int);
    int whereRoot(int);
    ~Graph() { delete[] node; }
};

Graph::Graph(int s) : size(++s)
{
    node = new unsigned int[size]{0};
}

void Graph::addRel(int a, int b)
{
    if(node[a] == 0 && node[b] == 0)
        node[a] = node[b] = (a<b?a:b);
    else if(node[a]==0)
        node[a] = whereRoot( node[b] );
    else if(node[b]==0)
        node[b] = whereRoot( node[a] );
    else
    {
        cerr << "else"<< a << " " << b <<"\n";
        int tA = whereRoot( node[a] );
        int tB = whereRoot( node[b] );
        int min = (tA<tB?tA:tB);
        int max = (tA>tB?tA:tB);
        node[max] = min;
    }
}

int Graph::whereRoot(int a)
{
    if(node[a] == a)
        return a;
    else
    {
        node[a] = whereRoot(node[a]);
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

    int requests;
    cin >> requests;
    int **req = new int*[requests+1];
    for(int i = 0; i < requests; ++i)
        req[i]=new int[2];
    
    for(int i = 0; i < requests; ++i)
    {
        cin >> req[i][0] >> req[i][1];
        
    }

    for(int i = 0; i < requests; ++i)
    {
        g.searchRel(req[i][0],req[i][1]);
    }

    for(int i = 0; i < requests; ++i)
        delete req[i];
    delete[] req;

    //slow variant
    // for(int i = 0; i < requests; ++i)
    // {
    //     int a,b;
    //     cin >> a >> b;
    //     g.searchRel(a,b);
    // }
}