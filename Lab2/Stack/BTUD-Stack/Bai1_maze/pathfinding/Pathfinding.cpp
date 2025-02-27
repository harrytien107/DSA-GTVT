#include "Pathfinding.h"
#include <iostream>

// Hàm kiểm tra xem ô có hợp lệ không
bool isValid(int x, int y, int m, int n, const vector<vector<int>>& maze, vector<vector<bool>>& visited) {
    return (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 1 && !visited[x][y]);
}

// Hàm BFS để tìm đường từ (startX, startY) đến (destX, destY)
bool bfs(const vector<vector<int>>& maze, pair<int, int> start, pair<int, int> dest) {
    int m = maze.size();
    if(m == 0) return false;
    int n = maze[0].size();
    
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<int, int>> q;
    
    q.push(start);
    visited[start.first][start.second] = true;
    
    while(!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        
        // Kiểm tra nếu đã đến đích
        if(current == dest) {
            return true;
        }
        
        // Khám phá các ô lân cận
        for(auto dir : DIRECTIONS) {
            int newX = current.first + dir.first;
            int newY = current.second + dir.second;
            
            if(isValid(newX, newY, m, n, maze, visited)) {
                q.push({newX, newY});
                visited[newX][newY] = true;
            }
        }
    }
    
    return false;
}

// Hàm DFS để tìm đường từ (startX, startY) đến (destX, destY)
bool dfs(const vector<vector<int>>& maze, pair<int, int> start, pair<int, int> dest) {
    int m = maze.size();
    if(m == 0) return false;
    int n = maze[0].size();
    
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    stack<pair<int, int>> s;
    
    s.push(start);
    visited[start.first][start.second] = true;
    
    while(!s.empty()) {
        pair<int, int> current = s.top();
        s.pop();
        
        // Kiểm tra nếu đã đến đích
        if(current == dest) {
            return true;
        }
        
        // Khám phá các ô lân cận
        for(auto dir : DIRECTIONS) {
            int newX = current.first + dir.first;
            int newY = current.second + dir.second;
            
            if(isValid(newX, newY, m, n, maze, visited)) {
                s.push({newX, newY});
                visited[newX][newY] = true;
            }
        }
    }
    
    return false;
}