//
// Created by Felipe on 10/8/2025.
//

#ifndef PRINTER_H
#define PRINTER_H
#include "Parser/jsonParser.h"
#include "TManagers/BottomTableManager.h"
#include "TManagers/TopTableManager.h"


class Printer {
    TopTableManager tManager;
    BottomTableManager bManager;
    JsonParser jParser;
    string patchVersion;
    FILE* patchFile;
    int newChamps;


    void openPatchFile();

    void printNewCards(size_t globalIdx);
    void printNewChamp();

    void printConsts();

    void printChamps();

    void printRelic();

    void printShop();



public:
    Printer(TopTableManager tManager, BottomTableManager bManager, JsonParser jParser, string patchVersion);
    void parseVersionAndSetDirectory();

    void printPatch();

    void printTables();
};



#endif //PRINTER_H
