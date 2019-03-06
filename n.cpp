#include <iostream>
#include <string>
using namespace std;

int maxDep, quest;//for addDep->relations

int whereIsMyRoot(int* arr,int r)
{
    if(arr[r] == r)
        return r;
    else 
    {
        arr[r] = whereIsMyRoot(arr, arr[r]);
        return arr[r];
    }
}
void relations(int* arr, int min, int max)
{
    for(int i = 1; i <= maxDep; ++i)
        if(arr[i]==max)
            arr[max]=min;
}

void checkDep(int* arr,int a, int b)
{
    int ta = whereIsMyRoot(arr, a);
    int tb = whereIsMyRoot(arr, b);
    if(ta==tb)
        cout << "MUSIC\n";
    else 
        cout << "SHOW!\n";
}

void addDep(int* arr, int a, int b)
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
        int ta = whereIsMyRoot(arr, a);
        int tb = whereIsMyRoot(arr, b);
        if(ta==tb)
            oneParty=true;
        //else //?
        int min = (ta<tb?ta:tb);
        int max = (ta>tb?ta:tb);
        arr[a]=arr[b] = min;

        relations(arr, min, max);
    }

    if(oneParty)
        cout << "BORE\n";
    else 
        cout << "NEWS!\n";
}

int main(int argc, char const *argv[])
{
    //cerr << "Begin!\n";
    cin >> maxDep >> quest;
    //int *arr = new int[maxDep+1];
    int *arr = new int[1000001];
    for(int i = 0; i < 1000001; ++i)
        arr[i] = 0;

    //cerr << "Start for" << endl;
    for(int q = 0; q < quest; ++q)
    {
        char op;
        int a = 0; int b = 0;
        cin >> op >> a >> b;
        ////cerr << "a " << a << " b " << b << " op " << op << "\n";

        if(op=='?')
        {
            checkDep(arr,a, b);
        }
        else if(op=='U')
        {
            addDep(arr, a, b);
        }
        else { cerr << "WUT\n"; }
        //for(int i = 1; i < maxDep+1; ++i)
            //cerr << arr[i] << " ";
        //cerr <<endl;
    }

    delete [] arr;
    return 0;
}