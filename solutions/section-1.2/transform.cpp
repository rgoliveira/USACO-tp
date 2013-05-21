/*
ID: ricardo39
PROG: transform
LANG: C++
*/
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void cswap(char *a, char *b)
{
    char c;
    c = *a;
    *a = *b;
    *b = c;
}

vector< vector<char> > transpose(vector< vector<char> > v, int n) // transpose square matrices
{
    int i, j;
    for (i=0; i<=n-2; i++)
    {
        for (j=i+1; j<=n-1; j++)
        {
            cswap( &v[i][j], &v[j][i] );
        }
    }
    return v;
}

vector< vector<char> > hflip(vector< vector<char> > v, int n) // hor. flip square matrices
{
    int i, j;
    for (i=0; i<n; i++)
    {
        for (j=0; j<(n/2); j++)
        {
            cswap( &v[i][j], &v[i][n-1-j] );
        }
    }
    return v;
}

vector< vector<char> > vflip(vector< vector<char> > v, int n) // vert. flip square matrices
{
    int i, j;
    for (j=0; j<n; j++)
    {
        for (i=0; i<(n/2); i++)
        {
            cswap( &v[i][j], &v[n-1-i][j] );
        }
    }
    return v;
}

int main()
{
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    
    int n;
    vector< vector<char> > sqbfr;
    vector< vector<char> > sqaft;
    
    string line;
    int i, j;
    
    fin >> n;
    for (i=0; i<n; i++)
    {
        sqbfr.push_back(vector<char>());
        fin >> line;
        for (j=0; j<n; j++)
        {
            sqbfr[i].push_back(line[j]);
        }
    }
    for (i=0; i<n; i++)
    {
        sqaft.push_back(vector<char>());
        fin >> line;
        for (j=0; j<n; j++)
        {
            sqaft[i].push_back(line[j]);
        }
    }

    if ( sqaft == hflip( transpose(sqbfr,n), n) )
        i = 1; // 90 degree rotation
    else if ( sqaft == hflip( vflip(sqbfr,n) , n) )
        i = 2; // 180 degree rotation
    else if ( sqaft == vflip( transpose(sqbfr,n), n) )
        i = 3; // 270 degree rotation
    else if ( sqaft == hflip(sqbfr,n) )
        i = 4; // horizontal reflection
    else
    {
        vector< vector<char> > aux = hflip(sqbfr,n); // aux <- horizontal flipped "before" matrix
        if ( sqaft == hflip( transpose(aux,n), n) )
            i = 5; // 90 degree rotation
        else if ( sqaft == hflip( vflip(aux,n) , n) )
            i = 5; // 180 degree rotation
        else if ( sqaft == vflip( transpose(aux,n), n) )
            i = 5; // 270 degree rotation
        else if ( sqbfr == sqaft )
            i = 6; // no change
        else
            i = 7;
    }
    
    //cout << i << endl;
    fout << i << endl;
    return 0;
}
