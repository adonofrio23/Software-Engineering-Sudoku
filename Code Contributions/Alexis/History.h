#pragma once
//#include "Cell.h"
#include <stack>
#include "Entry.h"
//#include "../Anthony/Cell.h"

class History{
    public:
    void PushHistory(Entry* entry);
    Entry* PopHistory();
    bool IsHistoryEmpty();

    private:
    stack<Entry *> history;

};