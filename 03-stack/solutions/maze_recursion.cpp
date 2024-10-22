#include <vector>
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

bool solve_maze_rec(Position curr, vector<vector<int>>& maze, vector<vector<bool>>& visited, Position end) {
    if (curr.x == end.x && curr.y == end.y) {
        return true;
    }

    // Ако текущия ход е валиден
    if (is_valid_move(curr.x, curr.y, maze, visited)) {
        visited[curr.x][curr.y] = true;

        // Разглеждаме позициите във всяка посока
        for (int i = 0; i < 4; i++) {
            int newX = curr.x + dx[i];
            int newY = curr.y + dy[i];

            // Търсим решение за новата позиция
            if (solve_maze_rec(Position(newX, newY), maze, visited, end)) {
                return true;
            }
        }
        // Ако никоя позиция не е била валидна, бектракваме
    }

    // Ако нито една позиция не е била валидна или довела до края, значи няма решение
    return false;
}

bool solve_maze_rec(vector<vector<int>>& maze, Position start, Position end) {
    vector<vector<bool>> visited(width, vector<bool>(height, false));
    return solve_maze_rec(start, maze, visited, end);
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

    std::cout << std::boolalpha << solve_maze_rec(maze, start, end);

    return 0;
}