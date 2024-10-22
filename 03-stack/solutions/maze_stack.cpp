﻿#include <vector>
#include <stack>
#include <iostream>

using std::vector;
using std::stack;

struct Position {
    int x, y;
    Position(int x, int y) : x(x), y(y) {}
};

// Размери за лабиринта
const int width = 5;
const int height = 5;

// Посоките: нагоре, надолу, наляво, надясно
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool is_valid_move(int x, int y, vector<vector<int>>& maze, vector<vector<bool>>& visited) {
    return (x >= 0 && x < width && y >= 0 && y < height && !maze[x][y] && !visited[x][y]);
}

bool solve_maze(vector<vector<int>>& maze, Position start, Position end) {
    vector<vector<bool>> visited(width, vector<bool>(height, false));
    return solve_maze_rec(start, maze, visited, end);

    // TODO: solve with stack
}

int main() {
    // 0 = път, 1 = стена
    vector<vector<int>> maze = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0}
    };

    Position start(0, 0);
    Position end(4, 4);

    std::cout << std::boolalpha << solve_maze(maze, start, end);

    return 0;
}