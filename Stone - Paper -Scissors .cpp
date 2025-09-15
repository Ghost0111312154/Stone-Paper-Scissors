#include <iostream>
#include <cstdlib>
using namespace std;
enum enGamechoice {
    Stone = 1,
    Paper = 2,
    Scissors = 3
};
enum enWinner { Player = 1, Computer = 2, Draw = 3 };
int RandomNumber(int From, int To) {
    int Random = rand() % (To - From + 1) + From;
    return Random;
}
int NumberOfRounds() {
    int Rounds;
    do {
        cout << "How many Rounds 1 To 10?\n";
        cin >> Rounds;
    } while (Rounds < 1 || Rounds>10);
    return Rounds;
}
enGamechoice ReadPlayerChoice() {
    int choice;
    do {
        cout << "Your Choice: [1]:Stone ,[2]:Paper ,[3]:Scissors ?\n";
        cin >> choice;
    } while (choice < 1 || choice>3);
    return (enGamechoice)choice;
}
enGamechoice GetComputerChoice() {
    return (enGamechoice)RandomNumber(1, 3);
}
string ChoiceToString(enGamechoice choice) {
    switch (choice) {
    case Stone:return"Stone";
    case Paper:return"Paper";
    case Scissors:return"Scissors";
    default: return "Unknown";
    }
}
enWinner WhoWin(enGamechoice Player, enGamechoice Computer) {
    if (Player == Computer)
        return enWinner::Draw;
    if ((Player == Stone && Computer == Scissors) ||
        (Player == Paper && Computer == Stone) ||
        (Player == Scissors && Computer == Paper))
        return enWinner::Player;
    return enWinner::Computer;
}
string WinnerToString(enWinner W) {
    switch (W) {
    case Player:return"Player";
    case Computer:return"Computer";
    case Draw: return "Draw";
    default: return "Unknown";
    }
}
void SetColor(enWinner W) {
    if (W == Player) system("color 2F");
    else if (W == Computer) system("color 4F");
    else system("color 6F");
}

void ResetColor() {
    system("color 07");
}
void ShowFinalStatistics(int PlayerWins, int ComputerWins, int Draws, int Rounds) {
    cout << "\n=== Final Statistics ===\n";
    cout << "Total Rounds   : " << Rounds << endl;
    cout << "Player Wins    : " << PlayerWins << endl;
    cout << "Computer Wins  : " << ComputerWins << endl;
    cout << "Draws          : " << Draws << endl;

    if (PlayerWins > ComputerWins)
        cout << "\nOverall Winner : Player \n";
    else if (ComputerWins > PlayerWins)
        cout << "\nOverall Winner : Computer \n";
    else
        cout << "\nOverall Result : Draw \n";
}

void PlayGame() {
    int PlayerWins = 0, ComputerWins = 0, Draws = 0;
    int Rounds = NumberOfRounds();
    for (int i = 1; i < Rounds; i++) {
        cout << "\nRound [" << i << "] begins:";
        enGamechoice PlayerChoice = ReadPlayerChoice();
        enGamechoice ComputerChoice = GetComputerChoice();
        cout << "Player Choice:" << PlayerChoice << endl;
        cout << "Computer Choice:" << ComputerChoice << endl;
        enWinner Result = WhoWin(PlayerChoice, ComputerChoice);
        SetColor(Result);
        cout << "Round Winner: " << WinnerToString(Result);
        if (Result == Player) PlayerWins++;
        else if (Result == Computer) ComputerWins++;
        else Draws++;
    }
    ShowFinalStatistics(PlayerWins, ComputerWins, Draws, Rounds);
}
void StartGame() {
    bool PlayAgain = true;
    int Choice;

    while (PlayAgain) {
        PlayGame();
        cout << "\nDo you want to play again? [1]Yes, [0]No: ";
        cin >> Choice;
        PlayAgain = (Choice == 1);
        ResetColor();
    }
}
int main() {
    srand((unsigned)time(NULL));

    StartGame();
    return 0;
}
