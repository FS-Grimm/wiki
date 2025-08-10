

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

#include "TManagers/BottomTableManager.h"
#include "TManagers/TopTableManager.h"

void createMissingDirectory() {
    string champFile="../champs/v"  patchVersion "/"+ champ1 + "B.txt";
    FILE* f=fopen(champFile.c_str(),"w");
    if (!f)
        std::filesystem::create_directories("../champs/v"  patchVersion);

    fclose(f);
}


int main() {


    jsonParser::parseDefinedVersion();
    createMissingDirectory();

    vector champs = { &champ1, &champ2, &champ3, &champ4 };
    vector  cardsGlobal ={ &cardsGlobal1,& cardsGlobal2,& cardsGlobal3, &cardsGlobal4};
    size_t i=0;
    while (!champs[i]->empty() && i<champs.size()) {
        BottomTableManager::makeTable(*champs[i],*cardsGlobal[i]);
        TopTableManager::makeTable(*champs[i],*cardsGlobal[i]);
        i++;
    }

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.