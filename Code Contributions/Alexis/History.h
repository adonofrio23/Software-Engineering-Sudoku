#pragma once
#include "cell.h"
#include <stack>
#include "Entry.h"


class History{
    public:
    void PushHistory(Entry* entry);
    Entry* PopHistory();
    bool IsHistoryEmpty();

    private:
    stack<Entry *> history;

};