#include <iostream>
#include <vector>
#include "pathfinding/Pathfinding.h"
#include "pathfinding/Pathfinding.cpp"
using namespace std;

int main() {
    // Ví dụ về mê cung
    vector<vector<int>> maze = {
        {1, 1, 0, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 1, 0, 1}
    };
    
    pair<int, int> start = {0, 0}; // Ô bắt đầu (x1, y1)
    pair<int, int> dest = {4, 4};  // Ô đích (x2, y2)
    
    // Kiểm tra bằng BFS
    if(bfs(maze, start, dest)) {
        cout << "Duong di ton tai tu (" << start.first << ", " << start.second << ") den (" 
                  << dest.first << ", " << dest.second << ") bang BFS." << endl;
    } else {
        cout << "Khong co duong di tu (" << start.first << ", " << start.second << ") den (" 
                  << dest.first << ", " << dest.second << ") bang BFS." << endl;
    }
    
    // Kiểm tra bằng DFS
    if(dfs(maze, start, dest)) {
        cout << "Duong di ton tai tu (" << start.first << ", " << start.second << ") den (" 
                  << dest.first << ", " << dest.second << ") bang DFS." << endl;
    } else {
        cout << "Khong co duong di tu (" << start.first << ", " << start.second << ") den (" 
                  << dest.first << ", " << dest.second << ") bang DFS." << endl;
    }
    
    return 0;
}