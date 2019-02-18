#include <iostream>
#include <string>
using namespace std;

class Graph
{
int size;
int *node;
public:
    Graph(int);
    void addRel(int, int);
    void searchRel(int, int);
    int whereRoot(int);

    void printNode()
    {
        //cerr << "\nNODES\n";
        //for(int i = 0; i < size; ++i)
            //cerr << node[i] << " ";
        //cerr << "\n";
    }
};

Graph::Graph(int s) : size(s+1)
{
    node = new int[size]{0};
    printNode();
}

void Graph::addRel(int a, int b)
{
    if(node[a] == 0 && node[b] == 0)
        node[a] = node[b] = a;
    else if(node[a]==0)
        node[a] = node[b];
    else
        node[b] = node[a];
}

int Graph::whereRoot(int a)
{
    //cerr << "whereRoot " << a << endl;
    if(node[a] == a)
        return a;
    else
        return whereRoot(node[a]);
}

void Graph::searchRel(int a, int b)
{
    //cerr << "\nStart search " << a << " " << b << endl;
    //cerr << "node a " << node[a] << "\tnode b "<< node[b]<< endl;
    if(node[a] == 0 || node[b] == 0)
    {
        //cerr << "if\n";
        cout << ":(\n";
    }
    else
    {
        //cerr << "else\n";
        int tA = whereRoot(a);
        int tB = whereRoot(b);
        ////cerr << tA << " " << tB << endl;
        //f(node[a] ==  node[b])
        if(tA == tB)
            cout << ":)\n";
        else
            cout << ":(\n";
    }

    //cerr << "\nEnd search " << a << " " << b << endl;
}


int main(int argc, char const *argv[])
{
    int programmers, relationships; // M relationships
    cin >> programmers >> relationships;

    //cerr << "\nprogrammers " << programmers;
    //cerr << "\nrelationships " << relationships << "\n";

    Graph g(programmers);
    for(int i = 0; i < relationships; ++i)
    {
        int a,b;
        cin >> a >> b;
        g.addRel(a,b);
    }

    g.printNode();

    //cerr << "\nrequests\n";
    int requests;
    cin >> requests;

    //cerr << requests << "\n";

    for(int i = 0; i < requests; ++i)
    {
        int a,b;
        cin >> a >> b;
        //cerr << "\nReq: " << i << " " << a << " " << b << " ";
        g.searchRel(a,b);



        //cerr << "\nEnd req " << i <<"\n";
    }
    //cerr << "aaaaaaaaaaaa";
    return 0;
}