/*
ID: ricardo39
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

string baseConv_reverse(int base10, int b)
{
    int i, r;
    char c;
    string fub;
    i = base10;
    while ( i >= b )
        {
            r = i%b;
            if (r < 10)
                c = r + '0';
            else
                c = r + 'A' - 10;
            fub.push_back(c);
            i = i/b;
        }
        if ( i > 0 )
        {
            if (i < 10)
                c = i + '0';
            else
                c = i + 'A' - 10;
            fub.push_back(c);
        }
    return fub;
}

string baseConv(int base10, int b)
{
    string buf;
    buf = baseConv_reverse(base10, b);
    std::reverse(buf.begin(), buf.end());
    return buf;
}

int main() {
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    int b, n;
    int square;
    string buf;
    string fub;
    
    fin >> b;
    for (n=1; n<=300; n++)
    {
        square = n*n;
        fub = baseConv_reverse(square, b);
        buf.resize(fub.length());
        reverse_copy(fub.begin(), fub.end(), buf.begin()); // lazy palindrome check
        if ( buf[0] == '0' || fub[0] == '0' )
            continue;
        if (buf == fub)
        {
            cout << n << " " << baseConv(n,b) << " " << buf << endl;
            fout << baseConv(n,b) << " " << buf << endl;
        }
    }
    
    return 0;
}
