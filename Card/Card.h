//
// Created by Felipe on 3/8/2025.
//

#ifndef CARD_H
#define CARD_H
#include <string>
#include <bits/stdc++.h>

// ReSharper disable once CppUnusedIncludeDirective
#include "../defs/defsDeck.h"


using namespace std;
static const std::unordered_map<std::string, int> levelMap = {
    { BLEVELTEXT2,  U2N },
    { BLEVELTEXT3,  U3N },
    { BLEVELTEXT4,  U4N },
    { BLEVELTEXT6,  U6N },
    { BLEVELTEXT9,  U9N },
    { BLEVELTEXT12, U12N },
    { BLEVELTEXT15, U15N },
    { BLEVELTEXT18, U18N },
    { BLEVELTEXT21, U21N },
    { BLEVELTEXT24, U24N },
    { BLEVELTEXT27, U27N }
};



class Card {
    string name;
    string item1;
    int item1Level=0;
    string item2;
    int item2Level=0;

    int cost=0;

    void setItem2Text(string & item2Text);
    void setItemText(string & itemText);
    string getItem1Text();
    string getItem2Text();
   public:
    Card(const string & cardName, string itemText);
    Card();

    Card(const string &  name,int cost, const std::string & item1, int item1Level, const std::string & item2Name, int item2Level);

    void setCost(const string & substr);

    void swapItems();

    [[nodiscard]] bool has2Items() const;




    int getLevelFromText(const string &itemLevelText);


    [[nodiscard]] int getItemLevel(bool first) const;

    [[nodiscard]] string getItemName(bool first) const;

    [[nodiscard]] string getLoRCard();

    [[nodiscard]] string getPoCItem(bool first) const;

    [[nodiscard]] string getTopTextFromlevel() const;
    [[nodiscard]] static string  getTopTextFromlevel(int itemLevel) ;

    [[nodiscard]] string getBottomTextFromlevel(bool first) const;

   static  bool cmpByCost(const Card &c1,const Card &c2);

   static bool cmpByLevel(const Card &c1,const Card &c2) ;

   static bool cmpAlphabetically(const Card &c1,const Card &c2);

};



#endif //CARD_H
