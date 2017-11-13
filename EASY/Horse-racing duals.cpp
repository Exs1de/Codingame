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
    int N;
    cin >> N; cin.ignore();
    
    int P[N];
    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        P[i] = Pi;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    
    int answer  = 999999; 
    sort(P, P + N);
    
    for(int i = 0; i < N; i++){
        if(abs(P[i] - P[i + 1]) < answer)answer = abs(P[i] - P[i + 1]);
    }
    
    cout << answer << endl;
}
