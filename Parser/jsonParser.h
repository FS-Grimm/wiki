//
// Created by Felipe on 9/8/2025.
//

#ifndef JSONPARSER_H
#define JSONPARSER_H
#include <string>
#include <bits/stdc++.h>
#include <nlohmann/json.hpp>
#include <fstream>

#include "../Card/Card.h"
#define patchVersion "6.8"


class Card;
extern std::string champ1;
extern std::string champ2;
extern std::string champ3;
extern std::string champ4;
extern std::vector<Card> cardsGlobal1;
extern std::vector<Card> cardsGlobal2;
extern std::vector<Card> cardsGlobal3;
extern std::vector<Card> cardsGlobal4;


class jsonParser {
  public:
    static ifstream getVersionFile_impl(string filePath);

    static ifstream getVersionFile();

    static bool hasInvalidName(const string & itemName);

    static void setValidName(string * itemName);


    static void parseCards(nlohmann::json j, vector<Card> * cardsP);
    static void parseDefinedVersion();
};



#endif //JSONPARSER_H
