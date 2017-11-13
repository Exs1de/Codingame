#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
int main()
{
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    string T;
    getline(cin, T);
    
    cerr << "L: " << L << endl;
    cerr << "H: " << H << endl;
    cerr << "T: " << T << endl;
    
    string alphabet[H];
    
    for (int i = 0; i < H; i++) {
        string ROW;
        getline(cin, ROW);  
        alphabet[i] = ROW;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    
    int c;
    string answer[H];
    string temp;
    for(int i = 0; i < T.length(); i++)
    {
        c = int(T[i]);
        
        if(c >= 97 && c <= 122)c -= 32; //convert lowcase letters to uppercase
        
        if(c >= 65 && c <= 90){
            for(int h = 0; h < H; h++){
                temp = alphabet[h];
                for(int l = 0; l < L; l++)
                    answer[h] += temp[(c - 65) * L + l];
            }
        }
        else{
            for(int h = 0; h < H; h++){
                temp = alphabet[h];
                for(int l = 0; l < L; l++)
                    answer[h] += temp[26 * L + l];
            }
        }
    } 
    for(int q = 0; q < H; q++)cout << answer[q] << endl;
}
