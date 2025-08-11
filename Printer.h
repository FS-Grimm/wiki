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


    void printPatch(const string &champ, const vector<Card> &cards);

public:
    Printer(TopTableManager tManager, BottomTableManager bManager, JsonParser jParser, string patchVersion);
    void parseVersionAndSetDirectory();


    void printTables();
};



#endif //PRINTER_H
