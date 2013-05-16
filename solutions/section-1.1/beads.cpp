/*
ID: ricardo39
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ofstream fout ( "beads.out" );
    ifstream fin ( "beads.in" );
    int n;
    fin >> n;
    
    string beads;
    fin >> beads;
    
    int i, j;
    int p, q;
    int count;
    count = 0;
    int caux;
    caux = 1;
    int ctl;
    char cur; // current color
    
    for ( j=0; j<n; j++ ) {
        if ( caux > count ) { // atualiza solução atual
            count = caux;
        }
        caux = 0;
        ctl = 0;

        if ( beads[j] == 'w' ) {
            cur = ' ';
        } else {
            cur = beads[j];
        }
        //cout << " i=" << j << "; i<" << (n+j) << "; i++" << endl;
        for ( i=j; i<(n+j); i++ ) {
            p = i % n;
            if ( beads[ p ] != 'w' ) {
                if ( cur == ' ' ) {
                    cur = beads[ p ];
                } else {
                    if ( cur != beads[ p ] ) {
                        ctl++;
                        cur = beads[ p ];
                    }
                }
            }
            
            if ( ctl > 1 ) { // trocou de cores mais de uma vez
                ctl = 0;
                break;
            } else {
                caux++;
            }
            //cout << "pos: " << p << " | caux: " << caux << endl;
        }
        //cout << endl << endl;
    }
    //cout << "count: " << count << endl;
    fout << count << endl;
    return 0;
}
