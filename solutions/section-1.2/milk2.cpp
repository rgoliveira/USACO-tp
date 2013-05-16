/*
ID: ricardo39
PROG: milk2
LANG: C++
*/
#include <map>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    
    int n;
    int milkingStart, milkingEnd;
    int noMilkingStart, noMilkingEnd;
    int maxMilking, maxNoMilking, total;
    int i;
    
    map<int,int> times; // guarantees sorting by key (in this case, starting times)
    
    fin >> n;
    for (i=0; i<n; i++)
    {
        fin >> milkingStart >> milkingEnd;
        times.insert(pair<int,int>(milkingStart,milkingEnd));
    }
    
    maxMilking = maxNoMilking = 0;
    total = 0;
    map<int,int>::iterator it = times.begin();
    milkingStart = it->first;
    milkingEnd = it->second;
    total = milkingEnd - milkingStart;
    for (it=times.begin(); it!=times.milkingEnd(); ++it)
    {
        if (it->first > milkingEnd)
        {
            total = milkingEnd - milkingStart;
            maxMilking = max(maxMilking, total);
            milkingStart = it->first;
            noMilkingStart = milkingEnd;
            milkingEnd = it->second;
            
            noMilkingEnd = it->first;
            total = noMilkingEnd - noMilkingStart;
            maxNoMilking = max(maxNoMilking, total);
            
        }
        else
        {
            if ( it->second > milkingEnd )
            {
                milkingEnd = it->second;
            }
        }
    }
    
    total = milkingEnd - milkingStart;
    maxMilking = max(maxMilking, total);
    
    fout << maxMilking << " " << maxNoMilking << endl;

    return 0;
}
