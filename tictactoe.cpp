#include <iostream>
#include <string>
using namespace std;

class Tic_tac_toe {
    public:
    char field[5][5] = {
        {' ', 'x', '1', '2', '3'},
        {'y', ' ', ' ', ' ', ' '},
        {'1', ' ', '.', '.', '.'},
        {'2', ' ', '.', '.', '.'},
        {'3', ' ', '.', '.', '.'}
    };
    string x;
    string y;
    int step = 0;

    bool game_is_on = false;

    void start() {
        
        game_is_on = true;
        show();
        while (game_is_on == true) {
            do {
                x_enter('X');
                y_enter('X');
            }
            while (field[(y[0] - '0') + 1][(x[0] - '0') + 1] != '.');
            field[(y[0] - '0') + 1][(x[0] - '0') + 1] = 'X';
            step++;
            show();
            game_is_on = win_check('X');
            if (game_is_on == false)
                break;
            do {
                x_enter('O');
                y_enter('O');
            }
            while (field[(y[0] - '0') + 1][(x[0] - '0') + 1] != '.');
            field[(y[0] - '0') + 1][(x[0] - '0') + 1] = 'O';
            step++;
            show();
            game_is_on = win_check('O');
        }
    };

    void x_enter(char X_or_O) {
        
        do {
            if(X_or_O == 'X') {
                cout<<"First Player`s move\n Enter x coordinate between 1 and 3"<<endl;
            } else {
                cout<<"Second Player`s move\n Enter x coordinate between 1 and 3"<<endl;
            }
            cin>>x;
        }
        while (x[0] <= '0' || x[0] >= '4' || x.length() > 1);
    }

    void y_enter(char X_or_O) {
        do {
            if(X_or_O == 'X') {
                cout<<"First Player`s move\n Enter y coordinate between 1 and 3"<<endl;
            } else {
                cout<<"Second Player`s move\n Enter y coordinate between 1 and 3"<<endl;
            }
            cin>>y;
        }
        while (y[0] <= '0' || y[0] >= '4' || y.length() > 1);
    };

    bool win_check(char X_or_O) {
        
        for (int i = 2; i < 5; i++) {
            if(field[i][2] == X_or_O && field[i][3] == X_or_O && field[i][4] == X_or_O) {
                return win(X_or_O);
            }
        }
        for (int j = 2; j < 5; j++) {
            if(field[2][j] == X_or_O && field[3][j] == X_or_O && field[4][j] == X_or_O) {
                return win(X_or_O);
            }
        }
        if(field[2][2] == X_or_O && field[3][3] == X_or_O && field[4][4] == X_or_O) {
            return win(X_or_O);
        }
        if(field[2][4] == X_or_O && field[3][3] == X_or_O && field[4][2] == X_or_O) {
            return win(X_or_O);
        }
        if (step == 9) {
            cout<<"Draw!"<<endl;
            return false;
        }
        return true;
    };

    bool win(char X_or_O) {
        if(X_or_O == 'X') {
            cout<<"First player wins"<<endl;
        } else {
            cout<<"Second player wins"<<endl;
        }
        return false;
    };

    void show() {
        for(int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout<<field[i][j]<<' ';
            }
            cout<<endl;
        }
    };

};

main() {
    Tic_tac_toe a;
    a.start();
}