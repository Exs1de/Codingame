#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/
 
int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    
    cerr << "width : " << width << endl;
    cerr << "height : " << height << endl;
    
    string scheme[height];
    for (int i = 0; i < height; i++) {
        string line; // width characters, each either 0 or .
        getline(cin, line);
        cerr << line << endl;
        scheme[i] = line;
    }
    
    //create a grid of level
    int grid[height][width];
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(scheme[i].at(j) == '0')grid[i][j] = 1;
            else grid[i][j] = 0;
        }
    }

    string answer;
    int a, b;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            a = i + 1; b = j + 1;
            if(grid[i][j] == 1){  
                
                answer = to_string(j) + " " + to_string(i) + " ";
                while(b < width && grid[i][b] != 1)b++;
                if(grid[i][b] == 1 && b != width)answer += to_string(b) + " " + to_string(i) + " ";
                else answer += "-1 -1 ";
                
                while(a < height && grid[a][j] != 1)a++;
                if(grid[a][j] == 1 && a != height)answer += to_string(j) + " " + to_string(a) + " ";
                else answer += "-1 -1 ";
                cout << answer << endl;
            }
        }
    }
}
