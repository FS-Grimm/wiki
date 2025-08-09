//
// Created by Felipe on 1/8/2025.
//

#include "TopTableManager.h"



void TopTableManager::addStart(FILE *f) {
   fprintf(f," {{PoCChampionLevel\n");
}

void TopTableManager::makeTable(int deckNumber) {
    auto deck= TopDeck(deckNumber);
    string champ= deck.getChamp();
    string champFile = deck.getChampFile();

    FILE * f= fopen(champFile.c_str(), "w");
    if (!f) {
        perror("fopen failed");
        std::cerr << "Path: [" << deck.getChampFile() << "]\n";
    }
    addStart(f);
    Card card;
    long long i = 0;
    size_t key=level[i];
    while (i < MAXITEMS && key<=27) {
        if (!deck.hasKey(key)) {
            if (key!=U4N)
                addEmptyCardLine(f,key);
            i++;
            key= level[i];
            continue;
        }
        card = deck.getCard(key);

        addCardLine(f,card);
        if (card.has2Items() && card.getItemLevel(false)>card.getItemLevel(true)) {
            card.swapItems();
        }
        i++;
        key= level[i];
    }
    fprintf(f,"}}\n");
    fclose(f);
}


void TopTableManager::addCardLine(FILE *file,  Card & card) {
    fprintf(file,card.getTopTextFromlevel().c_str() );
    fprintf(file,card.getLoRCard().c_str());
    fprintf(file,STARTSWITH);
    fprintf(file,card.getPoCItem(true).c_str() );
    fprintf(file,".\n");
}

void TopTableManager::addEmptyCardLine(FILE *file, size_t key) {
    fprintf(file,Card::getTopTextFromlevel(key).c_str() );
    fprintf(file,"\n");

}



