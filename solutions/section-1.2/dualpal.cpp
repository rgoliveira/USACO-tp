/*
ID: ricardo39
PROG: dualpal
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

bool isPalindromeInBaseB(int base10, int b)
{
    string fub, buf;
    fub = baseConv_reverse(base10, b);
    buf.resize(fub.length());
    std::reverse_copy(fub.begin(), fub.end(), buf.begin());
    if (buf[0] == '0' || fub[0] == '0')
        return false;
    else
        return (buf==fub);
}

int main() {
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    int i, b, n, s;
    int control;
    
    fin >> n >> s;
    i = s;
    while (n > 0)
    {
        i++;
        control = 0;
        for (b=2; b<=10; b++)
        {
            if (isPalindromeInBaseB(i,b)) { control++; }
            if (control > 1) { break; }
        }
        if (control > 1)
        {
            n--;
            fout << i << endl;
        }
    }
    
    return 0;
}
