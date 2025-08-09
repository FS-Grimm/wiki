//
// Created by Felipe on 1/8/2025.
//

#ifndef TOPTABLEMAKER_H
#define TOPTABLEMAKER_H
#include "../Deck/TopDeck.h"
const std::vector level {
    U2N,U3N, U4N,U6N,U9N, U12N,U15N,U18N,U21N,U24N,U27N
};

inline const char* STARTSWITH= " starts with ";
class TopTableManager {

    static void addStart(FILE *f);
    static void addCardLine(FILE *file, Card &card);
public:
    static void addEmptyCardLine(FILE * file, size_t key);

    static void makeTable(int deckNumber);
};



#endif //TOPTABLEMAKER_H
