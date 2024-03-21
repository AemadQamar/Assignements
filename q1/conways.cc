#include <iostream>
using namespace std;

void makeBigger(int **board, int *cap) {
    int newCapacity = (*cap)*2;
    int *newArray = new int[newCapacity];
    for (int i = 0; i < *cap; ++i){
        newArray[i] = board[0][i];
    }
    delete[] *board;
    *cap = newCapacity;
    *board = newArray;
}
void printBoard(int **board, int r, int c){
    for (int i = 0; i < c; ++i){
        cout << "|";
    }
    cout << endl;
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            if (board[0][(c*i)+j]) {
                cout << "O";
            }
            else {
                cout << ".";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < c; ++i){
        cout << "|";
    }
    cout << endl;
}
void updateBoard(int **board, int r, int c){

    int *newBoard = new int[r*c];
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            int alive = (j != 0 ? board[0][c*i+(j-1)] : 0) + (j != c-1 ? board[0][c*i+(j+1)] : 0)\
            + (i != 0 ? board[0][c*(i-1)+j] : 0) + (i != r-1 ? board[0][c*(i+1)+j] : 0)\
            + ((i != 0) && (j != 0) ? board[0][c*(i-1)+(j-1)] : 0) + ((i != r-1) && (j != 0) ? board[0][c*(i+1)+(j-1)] : 0)\
            + ((i != 0) && (j != c-1) ? board[0][c*(i-1)+(j+1)] : 0) + ((i != r-1) && (j != c-1) ? board[0][c*(i+1)+(j+1)] : 0);

            if (board[0][c*i+j]) {
                if ((alive < 2) || (alive > 3)){
                    newBoard[(c*i)+j] = 0;
                } else {
                    newBoard[(c*i)+j] = 1;
                }
            } else {
                if (alive == 3){
                    newBoard[(c*i)+j] = 1;
                } else {
                    newBoard[(c*i)+j] = 0;
                }
            }
        }
    }
    delete[] *board;
    *board = newBoard;
}
int main() {
    int r = 1;
    int c = 0;
    char newChar;
    int i = 0;
    int capacity = 4;
    int *board = new int[4];

    cin >> noskipws;
    cin >> newChar;
    while(newChar != '\n') {
        if (i == capacity) {
            makeBigger(&board, &capacity);
        }
        if (newChar == '.') {
            board[i] = 0;
        } else {
            board[i] = 1;
        }
        i += 1;
        c += 1;
        cin >> newChar;
    }
    cin >> skipws;
    cin >> newChar;
    while(newChar != 'x'){
        if (i == capacity) {
            makeBigger(&board, &capacity);
        }
        if (newChar == '.') {
            board[i] = 0;
        } else {
            board[i] = 1;
        }
        i += 1;
        cin >> newChar;
    }
    r = i / c;
    while (cin >> newChar){
        if (newChar == 's'){
            updateBoard(&board, r, c);
        } else {
            printBoard(&board,r,c);
        }
    }
    delete[] board;
    return 0;
}
