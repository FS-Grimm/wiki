//
// Created by Felipe on 1/8/2025.
//

#ifndef TOPTABLEMANAGER_H
#define TOPTABLEMANAGER_H
#include "../Deck/TopDeck.h"

const std::vector level {
    U2N,U3N, U4N,U6N,U9N, U12N,U15N,U18N,U21N,U24N,U27N, 3000000
};

inline const char* STARTSWITH= " starts with ";
class TopTableManager {

    static void addStart(FILE *f);
    static void addCardLine(FILE *file, Card &card);
public:
    static void addEmptyCardLine(FILE * file, size_t key);

    static void makeTable(int deckNumber);

    static void writeFile(const TopDeck & deck);

    void makeTable(const TopDeck & deck);
};



#endif //TOPTABLEMANAGER_H
