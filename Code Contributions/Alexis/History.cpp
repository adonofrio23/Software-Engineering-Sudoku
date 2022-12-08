using namespace std;
#include "History.h"


void History::PushHistory(Entry* entry)
{
    history.push(entry);
}

Entry* History::PopHistory()
{
    Entry* topEntry = history.top();
    history.pop();
    return topEntry;
}

bool History::IsHistoryEmpty()
{
    return history.empty();
}