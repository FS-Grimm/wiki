//
// Created by Felipe on 9/8/2025.
//

#ifndef TOPMAKER_H
#define TOPMAKER_H

#include "Deck.h"

class TopDeck:public Deck{
    std::map<int,Card> cards;

public:
    explicit TopDeck(int deckNumber);

    explicit TopDeck(const vector<Card> & cardsV);

    [[nodiscard]] const string getChampFile() const override;
    size_t getSize() const override;

    bool hasKey(size_t key) const;

    Card getCard(size_t level) const override;

    void add(Card card) override;
    ~TopDeck() override;
};



#endif //TOPMAKER_H
