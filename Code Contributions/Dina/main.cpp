#include <iostream>
#include "Cell.h"
#include "Puzzle.cpp"
#include "Algorithms.h"
#include "HelperFunctions.h"
#include "GameEngine.h"
#include "History.h"

int EvilPuzzle[] = {   0,0,4, 5,0,1, 9,0,0,
                       0,2,0, 0,8,0, 0,3,0,
                       6,0,0, 0,0,0, 0,0,5,
                       0,0,8, 7,0,6, 3,0,0,
                       0,5,0, 0,0,0, 0,9,0,
                       0,0,3, 4,0,8, 5,0,0,
                       3,0,0, 0,0,0, 0,0,9,
                       0,8,0, 0,7,0, 0,6,0,
                       0,0,2, 8,0,5, 1,0,0   };

int MediumPuzzle[] = { 0,7,9, 0,4,0, 5,0,0,
                       1,8,0, 3,5,0, 0,0,0,
                       0,0,0, 1,0,0, 0,6,0,
                       4,1,0, 2,0,9, 6,7,5,
                       0,0,0, 7,0,8, 0,3,0,
                       3,2,7, 5,0,4, 8,0,1,
                       0,3,1, 0,0,0, 0,4,6,
                       9,0,0, 0,7,0, 0,0,0,
                       0,0,0, 4,0,0, 1,0,9 };

int EasyPuzzle[] = {   0,7,9, 8,4,0, 5,1,3,
                       1,8,0, 3,5,0, 0,0,0,
                       0,0,0, 1,9,0, 0,6,0,
                       4,1,0, 2,0,9, 6,7,5,
                       0,0,0, 7,0,8, 0,3,0,
                       3,2,7, 5,0,4, 8,0,1,
                       0,3,1, 0,0,0, 7,4,6,
                       9,0,0, 0,7,0, 0,0,0,
                       0,0,0, 4,0,0, 1,0,9 };


void PrintGame(Puzzle * puzzle, int r, int c, bool * b)
{
    int v = puzzle->GetCell(r, c)->GetValue();
    if ((c == 0) || (c == 3) || (c == 6)) {
        std::cout << "||";
        if (v != 0) std::cout << ' ' << v << ' ';
        else std::cout << "   ";
    }
    else {
        std::cout << "|";
        if (v != 0) std::cout << ' ' << v << ' ';
        else std::cout << "   ";
    }
    if (c == 8) {
        std::cout << "||\n";
        if ((r == 2) || (r == 5)) std::cout << "||===|===|===||===|===|===||===|===|===||\n";
        else if (r != 8) std::cout << "||---|---|---||---|---|---||---|---|---||\n";
    }
    return;
}

void PrintSolution(Puzzle* puzzle, int r, int c, bool* b)
{
    int v = puzzle->GetCell(r, c)->GetSolution();
    if ((c == 0) || (c == 3) || (c == 6)) {
        std::cout << "||";
        if (v != 0) std::cout << ' ' << v << ' ';
        else std::cout << "   ";
    }
    else {
        std::cout << "|";
        if (v != 0) std::cout << ' ' << v << ' ';
        else std::cout << "   ";
    }
    if (c == 8) {
        std::cout << "||\n";
        if ((r == 2) || (r == 5)) std::cout << "||===|===|===||===|===|===||===|===|===||\n";
        else if (r != 8) std::cout << "||---|---|---||---|---|---||---|---|---||\n";
    }
    return;
}

void LoadGame(Puzzle * puzzle, int r, int c, bool *b)
{
    Cell cell;
    cell.SetRow(r);
    cell.SetCol(c);
    cell.SetValue(EvilPuzzle[r * 9 + c]);
    if (cell.GetValue() != 0) {
        cell.SetHardWired(true);
        cell.SetSolution(cell.GetValue());
    }
    else {
        cell.SetSolution(0);
        cell.SetHardWired(false);
    }
    for (int i = 0; i < 9; i++) {
        cell.GetNotes()[i] = 0;
    }
    puzzle->SetCell(cell);
    return;
}


int main()
{
    Puzzle puzzle;
    History history;
    GameEngine engine;

    engine.Setup(&puzzle, &history);

    // Load test game
    LoopOverPuzzle(&puzzle, &LoadGame);

    // Pretty print the puzzle
    std::cout << "\n";
    std::cout << "||===|===|===||===|===|===||===|===|===||\n";
    LoopOverPuzzle(&puzzle, &PrintGame);
    std::cout << "||===|===|===||===|===|===||===|===|===||\n";

    // Solve the puzzle
    //SolveBruteForce(&puzzle);
    bool mod = true;
    while (mod) {
        PopulatePossibilities(&puzzle);
        UseSingletons(&puzzle);
        mod = UseOnlyChoice(&puzzle);
        std::cout << "\n";
        std::cout << "||===|===|===||===|===|===||===|===|===||\n";
        LoopOverPuzzle(&puzzle, &PrintSolution);
        std::cout << "||===|===|===||===|===|===||===|===|===||\n";
    }

    // Pretty print the soluton
    std::cout << "\n";
    std::cout << "||===|===|===||===|===|===||===|===|===||\n";
    LoopOverPuzzle(&puzzle, &PrintSolution);
    std::cout << "||===|===|===||===|===|===||===|===|===||\n";

    // Set up GameEngine for testing


    // Get user/programmer input for testing
    bool done = false;
    char command;
    int row = 0, col = 0;
    while (!done) {
        std::cout << "Command: (u)ndo, (U)ndo until correct, Set current (v)alue, (s)et cell, (h)int specific, (H)int random, (n)ote mode toggle, (l)oad puzzle,(r)un test suite, (q)uit: ";
        std::cin >> command;
        switch (command) {
            case 'q':
                done = true;
                break;
            case 'u':
                engine.UndoLastMove();
                break;
            case 'U':
                engine.UndoUntilCorrect();
                break;
            case 'v':
                std::cout << "Enter value: ";
                int val;
                std::cin >> val;
                engine.SetCurrentValue(val);
                break;
            case 's':
                std::cout << "Enter row: ";
                std::cin >> row;
                std::cout << "Enter column: ";
                std::cin >> col;
                //if (!engine.GetNotesMode()) engine.SetCell(row, col);
                //else engine.SetNote(row, col);
                engine.SetCell(row, col);
                break;
            case 'h':
                std::cout << "Enter row: ";
                std::cin >> row;
                std::cout << "Enter column: ";
                std::cin >> col;
                engine.GetSpecificHint(row, col);
                break;
            case 'H':
                engine.GetRandomHint();
                break;
            case 'n':
                engine.ToggleNotesMode();
                break;
            case 'l':
                engine.LoadPuzzle();
                break;
            case 'r':
                RunTestSuite(&puzzle, &history, &engine);
                break;
            default:
                break;
        }
        if (!engine.GetNotesMode()) {
            // Pretty print the puzzle
            std::cout << "\n";
            std::cout << "||===|===|===||===|===|===||===|===|===||\n";
            LoopOverPuzzle(&puzzle, &PrintGame);
            std::cout << "||===|===|===||===|===|===||===|===|===||\n";
        }
        else {
            // Pretty print notes for last cell selected
            Cell* cell = puzzle.GetCell(row, col);
            for (int i = 0; i < 9; i++) {
                std::cout << cell->GetNotes()[i];
                if (i != 8) std::cout << ", ";
            }
            std::cout << "\n";
        }
    }
}
