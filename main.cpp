

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

#include "Printer.h"
#include "Parser/jsonParser.h"
#include "TManagers/BottomTableManager.h"
#include "TManagers/TopTableManager.h"
#define patchVersionConst "6.7"

int main() {
   Deck::patchVersion=patchVersionConst;

    auto printer= Printer(TopTableManager(), BottomTableManager(), JsonParser(patchVersionConst),patchVersionConst);
    printer.parseVersionAndSetDirectory();
    printer.printTables();

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.