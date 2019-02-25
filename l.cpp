#include <iostream>
//#include <vector>
using namespace std;

void print(int arr[100][100], int n)
{
    cout << endl;
    for(int i = 1; i < n; ++i)
    {
        for(int j = 1; j < n; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    const int MAX = 101;
    int dev,pro,pairs;
    cin >> dev >> pro >> pairs;
    int n = (dev>pro?dev:pro)+1;
    int arr[MAX][MAX];
    //vector<pair<int,int> >res;
    int res[MAX][2];
    int resCurr=0;
    //int visited[100];
    //string res;
    for(int i = 0; i < pairs; ++i)
    {
        int a,b;
        cin >> a >> b;
        arr[a][b] = 1;
    }
    //cout << "\nBefore";
    //print(arr, n);

    for(int i = 1; i <= dev; ++i)
    {
        int max = 0;
        int single = 0;
        for(int j = 1; j <= pro; ++j)
        {
            if(arr[i][j])
            {
                if(j>max) max=j;
                
                int count = 0;
                for(int k = 1; k <= dev; ++k)
                {
                    if(arr[k][j])
                        ++count;
                }
                if(count == 1)
                    single = j;
                
            }
        }
        int choice = (single?single:max);
        if(choice!=0)
        {
            //res.push_back(make_pair(i, choice));
            ++resCurr;  
            res[resCurr][0] = i; 
            res[resCurr][1] = choice;

            for(int k = 1; k <= dev; ++k)
            {
                if(arr[k][choice])
                    arr[k][choice]=0;
            }
            for(int k = 1; k <= pro; ++k)
            {
                if(arr[i][k])
                    arr[i][k]=0;
            }
        }
    }
    //cout << "\nAfter";
    //print(arr, n);

    // cout << res.size() << endl;
    // for(vector<pair<int,int> >::iterator it = res.begin(); it != res.end(); ++it)
    //     cout << it->first << " " << it->second << endl;

    cout << resCurr << endl;
    if(resCurr)
        for(int i = 1; i <= resCurr; ++i)
            cout << res[i][0] << " " << res[i][1] << endl;
    return 0;
}