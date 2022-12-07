#include <iostream>
#include "Puzzle.h"
#include "History.h"
using namespace std;


class GameEngine {
    public:
        void Undo();
        void UndoUntilCorrect();

    private:
        int currentValue;
        Puzzle puzzle;
        History history;
}