//
// Created by Felipe on 9/8/2025.
//

#ifndef JSONPARSER_H
#define JSONPARSER_H
#include <string>
#include <bits/stdc++.h>
#include <nlohmann/json.hpp>
#include <fstream>

#include "../Card/ChampCard.h"


class Card;
extern ChampCard champ1;
extern ChampCard champ2;
extern ChampCard champ3;
extern ChampCard champ4;
extern std::vector<Card> cardsGlobal1;
extern std::vector<Card> cardsGlobal2;
extern std::vector<Card> cardsGlobal3;
extern std::vector<Card> cardsGlobal4;
extern std::vector<ChampCard*> champsGlobal;
extern std::vector<vector<Card>*> cardsGlobal;
class JsonParser {
    string patchVersion;
    string champType;

    static bool hasInvalidName(const string & itemName);

    static void setValidName(string * itemName);
public:
    static ifstream getVersionFile_impl(const string &filePath);

    ifstream getVersionFile();



    static void checkInvalidName(string *itemName);

    static void parseItem(nlohmann::json::const_reference json, string ref, string *itemName, int *itemLevel);


    void parseCards(nlohmann::json j, vector<Card> * cardsP);


    void parseNew(nlohmann::json::const_reference json,bool *isNew);
    void parseType(nlohmann::json::const_reference json);

    void parseRef(string ref, nlohmann::json::const_reference json, string *target);

    void parseRelic(nlohmann::json::const_reference json, string * relic);


    void parse();

    JsonParser();

    JsonParser(string patchVersion);
};



#endif //JSONPARSER_H
