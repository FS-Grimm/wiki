//
// Created by Felipe on 1/8/2025.
//

#ifndef BOTTOMTABLEMANAGER_H
#define BOTTOMTABLEMANAGER_H
#include "../Deck/BottomDeck.h"

#include <cwchar>
#include <cstdio>


class BottomTableManager {

private:
    static void addLineStart(FILE *f);
    static void addStart(FILE *f);
    static void addCardSeparator(FILE *f);
    BottomDeck deck;
    static void addChampLine(FILE * file,  string & champ);


    static void addCardLine(FILE *file, Card &card);

    static void addItem1Line(FILE * file, Card & card);

    static void addItem2Line(FILE * file, Card & card);


    static void writeFile(const BottomDeck & deck);


public:
    BottomTableManager();
    void makeTable(BottomDeck deck);

    static void makeTable(int deckNumber);


};



#endif //BOTTOMTABLEMANAGER_H
