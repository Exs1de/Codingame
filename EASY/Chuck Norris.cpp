#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
int main()
{
    string MESSAGE;
    getline(cin, MESSAGE);

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    
    string input, output;
    int i = 0;
    
    for (char c : MESSAGE)input += bitset< 7 >( c ).to_string();   
     
    while (i < input.size()){
        if (input[i] == '0'){
            output += "00 ";
            for (; i < input.size() && input[i] == '0'; i++)output += "0";          
            if (i < input.size()) output += " ";
        }
        else{
            output += "0 ";
            for (; i < input.size() && input[i] == '1'; i++)output += "0";  
            if (i < input.size())output += " ";
        }
    }
    
    cout << output << endl;
}
