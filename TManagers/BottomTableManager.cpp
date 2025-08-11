//
// Created by Felipe on 1/8/2025.
//

#include "BottomTableManager.h"

#include "../Deck/BottomDeck.h"


void BottomTableManager::addLineStart(FILE* f) {
    fprintf(f, "|");
}

void BottomTableManager::addStart(FILE *f) {
   fprintf(f," {| class=\"wikitable\""
            "!Card\n"
            "! colspan=\"3\" |Item \n"
            "|-\n");
}

void BottomTableManager::addCardSeparator(FILE *f) {
    fprintf(f, "|-\n");
}


void BottomTableManager::addChampLine(FILE *file, string & champ) {
    addLineStart(file);
    fprintf(file, champ.c_str());
    fprintf(file, " (x2)\n|[[File:PoC Common Relic icon.png|25px|link=]] at unlocked<br />[[File:PoC Rare Relic icon.png|25px|link=]] at level 8\n"
                        "|[[File:PoC Common Relic icon.png|25px|link=]] at level 13<br />[[File:PoC Rare Relic icon.png|25px|link=]] at level 19\n"
                        "|[[File:PoC Common Relic icon.png|25px|link=]] at level 25<br />[[File:PoC Rare Relic icon.png|25px|link=]] at level 30\n"
                        "|-\n");
}

void BottomTableManager::addCardLine(FILE *file,  Card &card) {
    addLineStart(file);
    fprintf(file,card.getLoRCard().c_str());
    fprintf(file, " (x2)\n");
}

void BottomTableManager::addItem1Line(FILE *file, Card &card) {
    addLineStart(file);
    fprintf(file, card.getPoCItem(true).c_str());
    fprintf(file," ");

    fprintf(file, card.getBottomTextFromlevel(true).c_str() );
}

void BottomTableManager::addItem2Line(FILE *file, Card &card) {
    addLineStart(file);
    if (!card.has2Items()) {
        fprintf(file,"\n");
        return;
    }
    fprintf(file, card.getPoCItem(false).c_str());
    fprintf(file, card.getBottomTextFromlevel(false).c_str());
}

void BottomTableManager::writeFile(const BottomDeck &deck) {
    string champ=deck.getLoRChamp();
    string champFile=deck.getChampFile();
    FILE * f= fopen(champFile.c_str(), "w");
    if (!f) {
        perror("fopen failed");
        std::cerr << "Path: [" << champFile << "]\n";
    }
    addStart(f);
    addChampLine(f,champ);
    size_t i = 0;
    while (!feof(f) && i<MAXCARDS) {
        Card card = deck.getCard(i);
        addCardLine(f,card);
        addItem1Line(f,card);
        addItem2Line(f,card);
        fprintf(f, "|\n");
        if (i<MAXCARDS-1)
            addCardSeparator(f);
        i++;
    }
    fprintf(f,"|}\n");
    fclose(f);
}

BottomTableManager::BottomTableManager() {
    deck=BottomDeck();
};

void BottomTableManager::makeTable(int deckNumber) {
    auto deck= BottomDeck(deckNumber);
    string champ= deck.getChamp();
    writeFile(deck);
}

void BottomTableManager::makeTable(BottomDeck deck) {
    this->deck=deck;
    writeFile(deck);
}
