#include <iostream>
#include <vector>
#include <conio.h> // For _kbhit() and _getch()
#include <windows.h> // For Sleep()

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20

class Tetromino {
    std::vector<std::vector<int>> shape;
    int x, y; // Position on the board

public:
    Tetromino(std::vector<std::vector<int>> s, int startX) : shape(s), x(startX), y(0) {}

    void rotate() {
        // Rotates the shape 90 degrees clockwise
        std::vector<std::vector<int>> rotatedShape(shape[0].size(), std::vector<int>(shape.size()));
        for (size_t i = 0; i < shape.size(); i++) {
            for (size_t j = 0; j < shape[i].size(); j++) {
                rotatedShape[j][shape.size() - i - 1] = shape[i][j];
            }
        }
        shape = rotatedShape;
    }

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    const std::vector<std::vector<int>>& getShape() const { return shape; }
    int getX() const { return x; }
    int getY() const { return y; }
};

class Board {
    std::vector<std::vector<int>> grid;

public:
    Board() : grid(BOARD_HEIGHT, std::vector<int>(BOARD_WIDTH, 0)) {}

    bool checkCollision(const Tetromino& t) {
        // Checks for collision
        const auto& shape = t.getShape();
        for (size_t i = 0; i < shape.size(); i++) {
            for (size_t j = 0; j < shape[i].size(); j++) {
                if (shape[i][j] != 0) {
                    int boardX = t.getX() + j;
                    int boardY = t.getY() + i;
                    if (boardX < 0 || boardX >= BOARD_WIDTH || boardY < 0 || boardY >= BOARD_HEIGHT || grid[boardY][boardX] != 0) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    void unite(const Tetromino& t) {
        // Unites the tetromino with the board
        const auto& shape = t.getShape();
        for (size_t i = 0; i < shape.size(); i++) {
            for (size_t j = 0; j < shape[i].size(); j++) {
                if (shape[i][j] != 0) {
                    grid[t.getY() + i][t.getX() + j] = 1; // Assuming 1 represents filled
                }
            }
        }
    }

    void clearLines() {
        // Clears completed lines
        for (int i = 0; i < BOARD_HEIGHT; i++) {
            bool lineComplete = true;
            for (int j = 0; j < BOARD_WIDTH; j++) {
                if (grid[i][j] == 0) {
                    lineComplete = false;
                    break;
                }
            }
            if (lineComplete) {
                for (int k = i; k > 0; k--) {
                    grid[k] = grid[k - 1];
                }
                grid[0] = std::vector<int>(BOARD_WIDTH, 0);
            }
        }
    }

    void draw() const {
        system("cls");
        for (const auto& row : grid) {
            for (int cell : row) {
                std::cout << (cell ? "[]" : "  ");
            }
            std::cout << '\n';
        }
    }
};

class Game {
    Board board;
    Tetromino* currentTetromino;
    bool gameOver;

public:
    Game() : gameOver(false), currentTetromino(new Tetromino({ {1, 1, 1, 1} }, BOARD_WIDTH / 2 - 2)) {} // Example tetromino

    ~Game() {
        delete currentTetromino;
    }

    void run() {
        while (!gameOver) {
            if (_kbhit()) {
                char key = _getch();
                switch (key) {
                case 'a': // Move left
                    currentTetromino->move(-1, 0);
                    if (board.checkCollision(*currentTetromino)) {
                        currentTetromino->move(1, 0); // Move back
                    }
                    break;
                case 'd': // Move right
                    currentTetromino->move(1, 0);
                    if (board.checkCollision(*currentTetromino)) {
                        currentTetromino->move(-1, 0); // Move back
                    }
                    break;
                case 's': // Move down
                    currentTetromino->move(0, 1);
                    if (board.checkCollision(*currentTetromino)) {
                        currentTetromino->move(0, -1); // Move back
                        board.unite(*currentTetromino);
                        currentTetromino = new Tetromino({ {1, 1, 1, 1} }, BOARD_WIDTH / 2 - 2); // New tetromino
                        if (board.checkCollision(*currentTetromino)) {
                            gameOver = true; // End game if new tetromino collides on spawn
                        }
                    }
                    break;
                case 'w': // Rotate
                    currentTetromino->rotate();
                    if (board.checkCollision(*currentTetromino)) {
                        currentTetromino->rotate();
                        currentTetromino->rotate();
                        currentTetromino->rotate(); // Rotate back
                    }
                    break;
                }
            }
            board.draw();
            Sleep(1000); // Game tick
        }
        std::cout << "Game Over!" << std::endl;
    }
};

int main() {
    Game game;
    game.run();
    return 0;
}
