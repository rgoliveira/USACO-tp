/*
ID: ricardo39
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string comet, group;
    int i, cometi, groupi;
    fin >> comet >> group;

    cometi = 1;
    for (i=0; i<comet.length(); i++) {
        cometi *= (comet[i] - 64);
    }

    groupi = 1;
    for (i=0; i<group.length(); i++) {
        groupi *= (group[i] - 64);
    }

    if (cometi % 47 == groupi % 47)
        fout << "GO";
    else
        fout << "STAY";
    fout << endl;
    return 0;
}
