#include <iostream>
#include <string>
using namespace std;

class TVshow
{
int maxDep, quest; 
int* arr;
public:
    TVshow(int,int);
    ~TVshow();
    void mainLoop();
    int whereIsMyRoot(int r);
    void relations(int min, int max);
    void checkDep(int a, int b);
    void addDep( int a, int b);

};

TVshow::TVshow(int dep, int que) : maxDep(dep), quest(que)
{
    arr = new int[1000001];
    for(int i = 0; i < 1000001; ++i)
        arr[i] = 0;
    
    mainLoop();
}
TVshow::~TVshow()
{
    delete [] arr;
}

void TVshow::mainLoop()
{
    for(int q = 0; q < quest; ++q)
    {
        char op;
        int a = 0; int b = 0;
        cin >> op >> a >> b;
        if(op=='?') { checkDep(a, b); }
        else if(op=='U') { addDep(a, b); }
        else {  cerr << "WUT\n"; return; }//WRONG WAY
    }
}


int TVshow::whereIsMyRoot(int r)
{
    if(arr[r] == r)
        return r;
    else 
        return whereIsMyRoot(arr[r]);
}

void TVshow::relations(int min, int max)
{
    for(int i = 1; i <= maxDep; ++i)
        if(arr[i]==max)
            arr[max]=min;
}

void TVshow::checkDep(int a, int b)
{
    if(arr[a] == 0 || arr[b] == 0)
        cout << "SHOW!\n";
    else
    {
        int ta = whereIsMyRoot(a);
        int tb = whereIsMyRoot(b);
        if(ta==tb)
            cout << "MUSIC\n";
        else 
            cout << "SHOW!\n";
    }
}

void TVshow::addDep(int a, int b)
{
    bool oneParty=false;
    if(arr[a] == 0 && arr[b] == 0)
    {
        arr[a] = arr[b] = a;
    }
    else if(arr[a] == 0)
    {
        arr[a] = b;
    }
    else if(arr[b] == 0)
    {
        arr[b] = a;
    }
    else
    {
        int ta = whereIsMyRoot(a);
        int tb = whereIsMyRoot(b);
        if(ta==tb)
            oneParty=true;
        else
        {
            int min = (ta<tb?ta:tb);
            int max = (ta>tb?ta:tb);
            arr[max]=min;
        }
    }

    if(oneParty)
        cout << "BORE\n";
    else 
        cout << "NEWS!\n";
}

int main(int argc, char const *argv[])
{
    int dep, que;
    cin >> dep >> que;
    TVshow show(dep+1, que);
    return 0;
}