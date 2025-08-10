

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

#include "parser/jsonParser.h"
#include "TManagers/BottomTableManager.h"
#include "TManagers/TopTableManager.h"



int main() {
    jsonParser::parseDefinedVersion();

    BottomTableManager::makeTable(champ1,cardsGlobal1);
    TopTableManager::makeTable(champ1,cardsGlobal1);

    BottomTableManager::makeTable(champ2,cardsGlobal2);
    TopTableManager::makeTable(champ2,cardsGlobal2);

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.