/*
ID: ricardo39
PROG: milk
LANG: C++
*/
#include <map>
#include <iostream>
#include <fstream>
#include <algorithm>

int main()
{
    std::ofstream fout ("milk.out");
    std::ifstream fin ("milk.in");
    
    int n, m;
    std::map<int,int> info;
    std::map<int,int>::iterator it;
    int i, p, a, totalV, totalM;
    
    fin >> n >> m;
    for ( i=0; i<m; i++ )
    {
        fin >> p >> a;
        if (info.count(p)>0)
            info[p] += a;
        else
            info[p] = a;
    }
    
    totalV = totalM = 0;
    it = info.begin();
    while ( (it != info.end()) && (totalM < n) )
    {
        p = it->first;
        a = std::min(n-totalM, it->second);
        totalM += a;
        totalV += p*a;
        it++;
    }
    
    fout << totalV << std::endl;
    
    return 0;
}
