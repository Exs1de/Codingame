#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <sstream>  //stringstream

using namespace std;

void predictRoute(int i, int j, int type);

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
string dir = "down";

int main()
{
    int W; // number of columns.
    int H; // number of rows.
    cin >> W >> H; cin.ignore();
    
    int lvl[H][W];
    string temp;
    int j;
    
    for (int i = 0; i < H; i++) {
        string LINE; // represents a line in the grid and contains W integers. Each integer represents one room of a given type.
        getline(cin, LINE);
        
        stringstream ss(LINE);
        j = 0;
        while(getline(ss, temp, ' '))
        {
            lvl[i][j] = atoi(temp.c_str());
            j++;
        }
    }
    
    for(int i = 0; i < H; i++)
    {
        for(int w = 0; w < W; w++)
            cerr << lvl[i][w] << "\t";         
        cerr << endl;
    }
    
    int EX; // the coordinate along the X axis of the exit (not useful for this first mission, but must be read).
    cin >> EX; cin.ignore();

    // game loop
    while (1) {
        int XI;
        int YI;
        string POS;
        cin >> XI >> YI >> POS; cin.ignore();
        cerr << "XI : " << XI << endl;
        cerr << "YI : " << YI << endl;

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        // One line containing the X Y coordinates of the room in which you believe Indy will be on the next turn.
        // cout << "0 0" << endl;
        
        predictRoute(YI, XI, lvl[YI][XI]);
    }    
}

void predictRoute(int i, int j, int type)
{
    switch(type)
    {
        case 1:
        case 3:
        case 7:
        case 8:
        case 9:
        case 12:
        case 13:
            i++;
            dir = "down";
            break;
        case 2:
            if(dir == "left"){j--; dir = "left";}
            else{j++; dir = "right";} break;
        case 4:
            if(dir == "down"){j--; dir = "left";}
            else{i++; dir = "down";} break;
        case 5:
            if(dir == "down"){j++; dir = "right";}
            else{i++; dir = "down";} break;
        case 6:
            if(dir == "left"){j--; dir = "left";}
            else{j++; dir = "right";} break;
        case 10:
            j--;
            dir = "left";
            break;
        case 11:
            j++;
            dir = "right";
            break;
    }
    cout << j << " " << i << endl; 
}
