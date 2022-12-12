//using namespace std;
#include "History.h"
//#include "Entry.h"


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


// //Testing integration of History and Entry
// int main(){
//     cout << "Testing main function in History.cpp" << endl;
//     Cell origCell1;
//     Cell newCell1;
//     bool status1 = false;
    
//     Cell origCell2;
//     Cell newCell2;
//     bool status2 = false;
    
//     Cell origCell3;
//     Cell newCell3;
//     bool status3 = false;

//     History test;
//     cout << "Testing IsHistoryEmpty() before pushing to the stack" << endl;
//     cout << test.IsHistoryEmpty() << endl;
    
//     //Create 3 entries and push them to the stack
//     Entry testEntry1(&origCell1, &newCell1, status1);
//     Entry testEntry2(&origCell1, &newCell1, status2);
//     Entry testEntry3(&origCell1, &newCell1, status3);

//     cout << "Pushing 3 entries to the stack" << endl;
//     test.PushHistory(&testEntry1);
//     test.PushHistory(&testEntry2);
//     test.PushHistory(&testEntry3);
    
//     cout << "Testing IsHistoryEmpty() after pushing to the stack" << endl;
//     cout << test.IsHistoryEmpty() << endl;
    
//     //Pop all entries from the stack
//     cout << "Popping all entries from the stack" << endl;
//     Entry* popped = test.PopHistory();
//     cout << popped << endl;
//     popped = test.PopHistory();
//     cout << popped << endl;
//     popped = test.PopHistory();
//     cout << popped << endl;

//     cout << "Testing IsHistoryEmpty() after popping everything from the stack" << endl;
//     cout << test.IsHistoryEmpty() << endl;
// }