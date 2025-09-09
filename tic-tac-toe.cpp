#include <iostream>
#include <cstdlib>
using namespace std;
#define RED     "\033[1;31m"
#define BLUE    "\033[1;34m"
#define YELLOW  "\033[1;33m"
#define GREEN   "\033[1;32m"
#define CYAN    "\033[1;36m"
#define MAGENTA "\033[1;35m"
#define WHITE   "\033[1;37m"
#define RESET   "\033[0m"
class Game {
    char playerBoard[10];
    string player1Name;
    string player2Name;
public:
    string color(char x) {
        if (x == 'X') return string(RED) + x + RESET;
        if (x == 'O') return string(GREEN) + x + RESET;
        return string(WHITE) + x + RESET;
    }
    void resetBoard () {
        for (int i = 0; i < 9; i++) {
            playerBoard[i] = '1' + i; 
        }
    }
    void resetName () {
        player1Name = "Player 1";
        player2Name = "Player 2";
    }
    Game () {
        resetBoard();
        resetName();
    }
    void printGame () {
        system("cls");
        cout << CYAN << "=========================================" << RESET << endl;
        cout << "\t\t" << CYAN << "TIC-TAC-TOE" << RESET << endl;
        cout << CYAN << "=========================================" << RESET << endl << endl;
        
        cout<<"\t\t|\t|\t"<<endl;
        cout<<"\t   "<<color(playerBoard[0])<<"    |   "<<color(playerBoard[1])<<"   |    "<<color(playerBoard[2])<<"   "<<endl;
        cout<<"\t\t|\t|\t"<<endl;
        cout<<"\t---------------------------"<<endl;
        cout<<"\t\t|\t|\t"<<endl;
        cout<<"\t   "<<color(playerBoard[3])<<"    |   "<<color(playerBoard[4])<<"   |    "<<color(playerBoard[5])<<"   "<<endl;
        cout<<"\t\t|\t|\t"<<endl;
        cout<<"\t---------------------------"<<endl;
        cout<<"\t\t|\t|\t"<<endl;
        cout<<"\t   "<<color(playerBoard[6])<<"    |   "<<color(playerBoard[7])<<"   |    "<<color(playerBoard[8])<<"   "<<endl;
        cout<<"\t\t|\t|\t"<<endl<<endl;

        cout << CYAN << "=========================================" << RESET << endl << endl;
    }
    void printMenu () {
       system("cls");
        cout << CYAN << "=========================================" << RESET << endl;
        cout << CYAN << "\t   TIC-TAC-TOE MENU\n" << RESET;
        cout << CYAN << "=========================================" << RESET << endl << endl;

        cout << MAGENTA << "1. Start Game\n" << RESET;
        cout << MAGENTA << "2. Play Again\n" << RESET;
        cout << MAGENTA << "3. Set Player Names\n" << RESET;
        cout << MAGENTA << "4. Show Rules\n" << RESET;
        cout << MAGENTA << "5. Exit\n\n" << RESET;

        cout << CYAN << "=========================================" << RESET << endl << endl;
        cout << YELLOW << "Enter your choice: " << RESET; 
    }
    void printEnd () {  
        cout<<endl;
        cout << GREEN << "=========================================\n";

        cout << "   T H A N K S   F O R   P L A Y I N G\n";
        cout << WHITE << "\n     Goodbye " << player1Name  << " and " << player2Name << "! \n" << RESET;

        cout << GREEN << "=========================================\n" << RESET;
    }
    void showRules() {
        system("cls");
        cout << CYAN << "=================================================" << RESET << endl;
        cout << "\t\t" << GREEN << "TIC-TAC-TOE RULES" << RESET << endl;
        cout << CYAN << "=================================================" << RESET << endl << endl;

        cout << YELLOW << "1. Two players: " << RED << player1Name << " (X) " << RESET << "and " << GREEN << player2Name << " (O)\n" << RESET;
        cout << YELLOW << "2. " << RESET << "Players take turns entering a number " << CYAN << "1-9" << RESET << " to \n   place their symbol.\n";
        cout << YELLOW << "3. " << RESET << "First player to align three symbols " << MAGENTA << "\n   horizontally, vertically, or diagonally" << RESET << " wins.\n";
        cout << YELLOW << "4. " << RESET << "If all cells are filled with no winner, the \n   game ends in a " << BLUE << "draw" << RESET << ".\n";
        cout << YELLOW << "5. " << RESET << "Cannot place a symbol in an " << RED << "already occupied" << RESET << " \n   cell.\n\n";
        
        cout << CYAN << "=========================================" << RESET << endl << endl;
        cout << YELLOW << "Press Enter to return to menu: "<< RESET;
        cin.get();
    }
    void setName () {
        string temp;
        cout<<endl;
        cout << YELLOW << "Enter Player 1 Name: "<<RESET;
        getline(cin, temp);
        if (!temp.empty()) player1Name = temp;

        cout << YELLOW << "Enter Player 2 Name: "<<RESET;
        getline(cin, temp);
        if (!temp.empty()) player2Name = temp;

        cout<<endl;
        cout<< WHITE << "Player names successfully set"<<endl<<endl;
        cout << CYAN << "=========================================" << RESET << endl << endl;
        cout << YELLOW << "Press Enter to return to menu: "<< RESET;
        cin.get();
        return;
    }
    
    void replay () {
        char again;
        cout << YELLOW << "Do you want to play again? (y/n): " << RESET;
        cin >> again;
        cin.ignore();
        if (again == 'y' || again == 'Y') {
            resetBoard();
            setValue();  
        }
    }
    int checkAndSymbol(int x, char y) {
        if (x < 1 || x > 9) {
            cout << "\a"; // terminal beep
            cout << RED << "Invalid Value! Choose between 1-9.\n"<<RESET;
            cout << YELLOW <<"Press Enter to try again..." << RESET;
            cin.get();
            printGame(); 
            return -1;
        }
        if (playerBoard[x-1] == 'X' || playerBoard[x-1] == 'O') {
            cout << "\a"; // terminal beep
            cout << RED << "Cell already taken!\n"<<RESET;
            cout << YELLOW <<"Press Enter to try again..." << RESET;
            cin.get();
            printGame();
            return -1;
        }
        playerBoard[x - 1] = y;
        return 0;
    }
    bool checkWinner(char y) {
        int wins[8][3] = {
            {0,1,2}, {3,4,5}, {6,7,8},
            {0,3,6}, {1,4,7}, {2,5,8},
            {0,4,8}, {2,4,6}
        };
        for (int i = 0; i < 8 ; i++) {
            if (playerBoard[wins[i][0]] == y && playerBoard[wins[i][1]] == y && playerBoard[wins[i][2]] == y) {
                return true;
            }
        }
        return false;
    }
    void setValue() {
        int x;
        string input;
        for (int i = 0; i<9 ;i++) {
            printGame();
            char turn = (i % 2 == 0) ? 'X' : 'O';
            do {
                cout << YELLOW << (turn == 'X' ? player1Name : player2Name )<< " (" << color(turn) <<YELLOW<< ")" << " enter your next move : "<<RESET;
                getline(cin, input);
                try {
                    x = stoi(input);
                } catch (...) {
                    x = -1; 
                }
                int result = checkAndSymbol(x, turn);
                if (result == 0) break;
            } while (true);

            if (checkWinner(turn)) {
                printGame();
                cout << WHITE << "!! Winner: " << (turn == 'X' ? player1Name : player2Name) << " (" << color(turn) <<YELLOW<< ")" <<RESET<< endl;
                replay();
                return;
            }
            if (i == 8) {
                printGame();
                cout << WHITE << "!! Match Drawn! " << player1Name << " (X) and " << player2Name << " (O) tied!" <<RESET<< endl;
                replay();
                return;
            }
        }
    }
};
int main() {
    Game g;
    int choice;
    string input;
    do {
        g.printMenu();
        getline(cin, input);
        if (input.empty()) {
            choice = 0; // if user just pressed Enter
        } else {
            try {
                choice = stoi(input); // convert string -> int
            } catch (...) { //all execptions 
                choice = 0; // invalid input
            }
        }
        switch (choice) {
            case 1:
                g.resetBoard();
                g.setValue();
                break;
            case 2:
                g.resetBoard();
                g.resetName();
                g.setValue();
                break;
            case 3:
                g.setName();
                break;
            case 4:
                g.showRules();
                break;
            case 5:
                g.printEnd();
                return 0;
            default:
                cout << RED << "Invalid choice! Please select 1-5.\n" << RESET;
                cout << YELLOW << "Press Enter to return to menu: "<< RESET;
                cin.get();
                break;
        }

    } while (true);
}