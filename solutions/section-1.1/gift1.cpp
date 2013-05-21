/*
ID: ricardo39
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int i, j;
    string s;
    char c [500];
    int NP;
    int val;
    int gifts;
    string pnames [10];
    std::map<string,int> m;
    
    fin >> NP; // numero de pessoas
    for ( i=0; i<NP; i++ ) { // carrega nomes e popula map
        fin >> pnames[i];
        m.insert(std::pair<string,int>(pnames[i],0));
    }
    for ( i=0; i<NP; i++ ) {
        fin >> s; // nome do presenteador
        fin >> val >> gifts; // valor inicial, presenteados
        //sscanf(c, "%d %d\n", &val, &gifts);
        m[s] -= val; // valor inicial
        //cout << s << " | " << val << " | " << gifts << endl;
        if ( gifts>0 ) {
            m[s] = m[s] + (val % gifts);
            for ( j=0; j<gifts; j++ ) {
                fin >> s; // nome do presenteado
                m[s] += (val / gifts);
            }
        } else {
            m[s] += val;
        }
    }
    for ( i=0; i<NP; i++ ) {
        fout << pnames[i] << " " << m[pnames[i]] << endl;
    }
    return 0;
}
