/*
ID: ricardo39
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream fdict ("dict.txt");
    int i, key;
    string number;
    string name;
    bool flag;
    
    /* "keypad"
    * 2 = ABC
    * 3 = DEF
    * 4 = GHI
    * 5 = JKL
    * 6 = MNO
    * 7 = PRS   * Q is missing.
    * 8 = TUV
    * 9 = WXY
    *           * Z is missing
    */
    
    // get input
    fin >> number;
    
    // load dict, filtering impossible matches
    flag = false;
    while (!(fdict.eof()))
    {
        fdict >> name;
        if ( name.length() == number.length() )
        {
            i = -1;
            while (i < (int)name.length())
            {
                i++;
                if (name[i] == 'Z')
                {
                    break;
                }
                key = ((name[i] - 'A' ) / 3)+2;
                if (name[i] == 'S' || name[i] == 'V' || name[i] == 'Y')
                {
                    key--;
                }
                if ( key <= 9 && key >= 2)
                {
                    if ( number[i] != (key + '0') )
                    {
                        break;
                    }
                }
            }
            if ( i == (int)name.length() ) // entire name is ok?
            {
                fout << name << endl;
                flag = true;
            }
        }
    }
    
    if (!flag)
    {
        fout << "NONE" << endl;
    }
    
    return 0;
}
