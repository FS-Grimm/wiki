//
// Created by Felipe on 1/8/2025.
//

#ifndef DECK_H
#define DECK_H
#include "../Card/ChampCard.h"

using namespace std;


 class Deck {

protected:

  ChampCard * champ;

  void setChamp(const string & champ);

  string getChamp(int deckNumber);

  const char **getCards(int deckNumber);

  const char **getItems(int deckNumber);

public:
    static string patchVersion;
    void setChamp(ChampCard *champ);

  virtual ~Deck() ;

  string getPatchDirectory();
  [[nodiscard]] const virtual string getChampFile() const;
  virtual size_t getSize() const;
  virtual void add(Card card);
  virtual Card getCard(size_t pos) const;
  [[nodiscard]] string getChamp() const;


  [[nodiscard]] string getPoCChampName() const;

  [[nodiscard]] string getLoRChampName() const;
 };



#endif //DECK_H
