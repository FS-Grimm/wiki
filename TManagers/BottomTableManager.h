//
// Created by Felipe on 1/8/2025.
//

#ifndef BOTTOMTABLEMAKER_H
#define BOTTOMTABLEMAKER_H
#include "../Deck/BottomDeck.h"
#include <cwchar>
#include <cstdio>


class BottomTableManager {

    static void addLineStart(FILE *f);
    static void addStart(FILE *f);
    static void addCardSeparator(FILE *f);
public:

    static void addChampLine(FILE * file,  string & champ);


    static void addCardLine(FILE *file, Card &card);

    static void addItem1Line(FILE * file, Card & card);

    static void addItem2Line(FILE * file, Card & card);


    static void writeFile(const BottomDeck & deck);

    static void makeTable(int deckNumber);

    static void makeTable(const string & champ, const vector<Card> & cardsV);
};



#endif //BOTTOMTABLEMAKER_H
