#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <cmath>

using namespace std;

class ChessBoard {
public:
    enum class Color { WHITE,
        BLACK };

    class Piece {
    public:
        Piece(Color color) : color(color) {}
        virtual ~Piece() {}

        Color color;
        std::string color_string() const {
            if (color == Color::WHITE)
                return "white";
            else
                return "black";
        }

        /// Return color and type of the chess piece
        virtual std::string type() const = 0;

        /// Return short string representation of the chess piece
        virtual std::string short_type() const = 0;

        /// Returns true if the given chess piece move is valid
        virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;
    };

    class King : public Piece {
        // Task 1
    public:
        // Constructor
        King(Color color) : Piece(color) {}

        // Return color and type of the chess piece
        std::string type() const override {
            return color_string() + " king";
        }

        // Return short string representation of the chess piece
        std::string short_type() const override {
            return color == Color::WHITE ? "K" : "k";
        }

        // Returns true if the given chess piece move is valid
        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            return abs(from_x - to_x) <= 1 && abs(from_y - to_y) <= 1;
        }
    };

    class Knight : public Piece {
        // Task 1
    public:
        // Constructor
        Knight(Color color) : Piece(color) {}

        // Return color and type of the chess piece
        std::string type() const override {
            return color_string() + " knight";
        }

        // Return short string representation of the chess piece
        std::string short_type() const override {
            return color == Color::WHITE ? "N" : "n";
        }

        // Returns true if the given chess piece move is valid
        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            return (abs(from_x - to_x) == 2 && abs(from_y - to_y) == 1) ||
                   (abs(from_x - to_x) == 1 && abs(from_y - to_y) == 2);
        }
    };

    ChessBoard() {
        // Initialize the squares stored in 8 columns and 8 rows:
        squares.resize(8);
        for (auto &square_column : squares)
            square_column.resize(8);
    }

    // Function object executed after each move
    function<void()> after_piece_move;

    /// 8x8 squares occupied by 1 or 0 chess pieces
    vector<vector<unique_ptr<Piece>>> squares;

    /// Move a chess piece if it is a valid move.
    /// Does not test for check or checkmate.
    bool move_piece(const std::string &from, const std::string &to) {
        int from_x = from[0] - 'a';
        int from_y = stoi(string() + from[1]) - 1;
        int to_x = to[0] - 'a';
        int to_y = stoi(string() + to[1]) - 1;

        auto &piece_from = squares[from_x][from_y];
        if (piece_from) {
            if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
                cout << piece_from->type() << " is moving from " << from << " to " << to << endl;
                auto &piece_to = squares[to_x][to_y];
                if (piece_to) {
                    if (piece_from->color != piece_to->color) {
                        cout << piece_to->type() << " is being removed from " << to << endl;
                        if (auto king = dynamic_cast<King *>(piece_to.get()))
                            cout << king->color_string() << " lost the game" << endl;
                    } else {
                        // piece in the from square has the same color as the piece in the to square
                        cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
                        return false;
                    }
                }
                piece_to = move(piece_from);
                if (after_piece_move) {
                    after_piece_move();
                }
                return true;
            } else {
                cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
                return false;
            }
        } else {
            cout << "no piece at " << from << endl;
            return false;
        }
    }
};

// Class to print the chess board
class ChessBoardPrint {
public:
    ChessBoardPrint(ChessBoard &board) : board(board) {
        board.after_piece_move = [this]() { print_board(); };
    }

    // print the chess-board
    void print_board() const {
        for (int y = 7; y >= 0; --y) {
            cout << y + 1 << " ";
            for (int x = 0; x < 8; ++x) {
                if (board.squares[x][y]) {
                    cout << board.squares[x][y]->short_type() << " ";
                } else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
        cout << "  a b c d e f g h" << endl;
    }
private:
    ChessBoard &board;
};

int main() {
    ChessBoard board;
    ChessBoardPrint board_print(board);

    board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
    board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
    board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

    board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
    board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
    board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

    cout << "Invalid moves:" << endl;
    board.move_piece("e3", "e2");
    board.move_piece("e1", "e3");
    board.move_piece("b1", "b2");
    cout << endl;

    cout << "A simulated game:" << endl;
    board.move_piece("e1", "e2");
    board.move_piece("g8", "h6");
    board.move_piece("b1", "c3");
    board.move_piece("h6", "g8");
    board.move_piece("c3", "d5");
    board.move_piece("g8", "h6");
    board.move_piece("d5", "f6");
    board.move_piece("h6", "g8");
    board.move_piece("f6", "e8");
}
