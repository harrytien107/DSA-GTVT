#ifndef PATHFINDING_H
#define PATHFINDING_H

#include <vector>
#include <queue>
#include <stack>
#include <utility>
using namespace std;

// Hướng di chuyển: lên, xuống, trái, phải
const vector<pair<int, int>> DIRECTIONS = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

// Hàm kiểm tra xem ô có hợp lệ không
bool isValid(int x, int y, int m, int n, const vector<vector<int>>& maze, vector<vector<bool>>& visited);

// Hàm BFS để tìm đường từ (startX, startY) đến (destX, destY)
bool bfs(const vector<vector<int>>& maze, pair<int, int> start, pair<int, int> dest);

// Hàm DFS để tìm đường từ (startX, startY) đến (destX, destY)
bool dfs(const vector<vector<int>>& maze, pair<int, int> start, pair<int, int> dest);

#endif // PATHFINDING_H