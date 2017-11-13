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
    int R;
    cin >> R; cin.ignore();
    int L;
    cin >> L; cin.ignore();
    cerr << "R: " << R << endl;
    cerr << "L: " << L << endl;

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    
    int count, x;
    vector<int> line, new_line;
    line.push_back(R);
    
    for(int i = 0; i < L - 1; ++i)
    {
        for(int j = 0; j < line.size(); ++j)
        {
            x = line[j];
            count = 0;
            while(x == line[j + count] && (j + count < line.size()))count++;
            if(count >= 2)j += (count - 1);
            new_line.push_back(count);
            new_line.push_back(x);         
        }
        line = new_line;
        new_line.clear();           
    }
    
    for(int i = 0; i < line.size(); ++i)
    {
        if(i != line.size() - 1)cout << line[i] << " ";
        else cout << line[i] << endl;
    }    
}
