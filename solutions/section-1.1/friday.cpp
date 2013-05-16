/*
ID: ricardo39
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>

#define SAT 0x00
#define SUN 0x01
#define MON 0x02
#define TUE 0x03
#define WED 0x04
#define THU 0x05
#define FRI 0x06

#define JAN 0x11
#define FEB 0x12
#define MAR 0x13
#define APR 0x14
#define MAY 0x15
#define JUN 0x16
#define JUL 0x17
#define AUG 0x18
#define SEP 0x19
#define OUT 0x1a
#define NOV 0x1b
#define DEZ 0x1c

using namespace std;

int main() {
    ofstream fout ( "friday.out" );
    ifstream fin ( "friday.in" );
    int yearstocalc;
    fin >> yearstocalc;
    int endyear = yearstocalc + 1900;
    
    int y = 1900;
    int m = JAN;
    int d = 1;
    int dayoftheweek = MON;
    int count13s [ 7 ] = { 0, 0, 0, 0, 0, 0, 0 };
    bool isLeap = false;
    
    while ( y < endyear ) {
        //cout << "n: " << yearstocalc << " | y: " << y << " | m: " << (m&0x0F) << " | d: " << d << endl;
        if ( d == 13 ) {
            count13s[ ( dayoftheweek ) % 7 ]++;
        }
        dayoftheweek = ( dayoftheweek + 1 ) % 7;
        d++;
        if ( d > 31 ) {
            if ( m == DEZ ) {
                y++;
                m = JAN;
                
                isLeap = ( y % 4 == 0 && y % 100 != 0 ) || ( y % 100 == 0 && y % 400 == 0 );
            } else {
                m++;
            }
            d = 1;
        } else if ( d > 30 ) { // virada de mês em dia 30
            if ( ( m == SEP ) || ( m == APR ) || ( m == JUN ) || ( m == NOV ) ) {
                m++;
                d = 1;
            }
        } else if ( ( d > 28 ) && ( m == FEB ) ) { // fevereiro
            if ( ( d > 28 ) && ( !isLeap ) || ( d > 29 ) && ( isLeap ) ) {
                m++;
                d = 1;
            }
        }
    }
    
    fout << count13s[0] << " " << count13s[1] << " " << count13s[2] << " " << count13s[3] << " " << count13s[4] << " " << count13s[5] << " " << count13s[6] << endl;
    
    return 0;
}