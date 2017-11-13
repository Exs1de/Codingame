#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
int main()
{
    int N;
    cin >> N; cin.ignore();
    
    map<string, int> num_sort;
    for (int i = 0; i < N; i++) {
        string telephone;
        cin >> telephone; cin.ignore();
        num_sort.insert(pair<string, int>(telephone, i));
    }

    vector<string> num; //vector of sorted phone numbers (sort using map)
    for(auto it : num_sort)
        num.push_back(it.first);
          
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    
    int count = 0;
    int answer = num[0].size();
    if(num.front() != num.back()) //if all numbers are the same no need to loop over them
    {
        for(int i = 1; i < N; ++i)
        {
            for(int j = 0; j < num[i].size(); ++j)
            {
                if(num[i - 1][j] && num[i - 1][j] == num[i][j])count++;
                else break;
            }
            answer += num[i].size() - count;
            count = 0;
        }
    }

    // The number of elements (referencing a number) stored in the structure.
    cout << answer << endl;
}
