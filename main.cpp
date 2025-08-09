

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

#include "parser/jsonParser.h"
#include "TManagers/BottomTableManager.h"
#include "TManagers/TopTableManager.h"



int main() {

    TopTableManager::makeTable(1);
    BottomTableManager::makeTable(1);
    BottomTableManager::makeTable(2);

    TopTableManager::makeTable(2);

    jsonParser::parseDefinedVersion();
    vector<Card>::iterator it;

    for (it = cardsGlobal1.begin(); it != cardsGlobal1.end(); ++it) {
        it->print();
        cout<< "------------ \n";
    }
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.