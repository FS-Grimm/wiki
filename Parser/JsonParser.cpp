//
// Created by Felipe on 9/8/2025.
//

#include <utility>

#include "jsonParser.h"
#include "../Card/ChampCard.h"
using namespace std;
ChampCard champ1;
ChampCard champ2;
ChampCard champ3;
ChampCard champ4;

vector<Card> cardsGlobal1;
vector<Card> cardsGlobal2;
vector<Card> cardsGlobal3;
vector<Card> cardsGlobal4;

ifstream JsonParser::getVersionFile_impl(const string &filePath) {
    ifstream file(filePath);
    if (!file) {
        throw runtime_error(filePath +" does not exist, please try a different version or define it");
    }
    return move(file);

}

ifstream JsonParser::getVersionFile() {
    string filePath = "../Parser/"  + patchVersion + ".json";
    return getVersionFile_impl(filePath);
}

bool JsonParser::hasInvalidName(const string &itemName) {
 return   find(invalidItemNames.begin(), invalidItemNames.end(), itemName) != invalidItemNames.end();
}

void JsonParser::setValidName( string * itemName) {
    cerr<<"The name "<<*itemName<<" is invalid, please add it's type to get a valid name"<<endl;
    if (*itemName==POROSNAXS) {
        *itemName = POROSNAXSV;
    } else if (*itemName==WANDERERBLESSING) {
        *itemName=WANDERERBLESSINGV;
    } else if (*itemName==ELIXIROFSKILLS) {
        *itemName=ELIXIROFSKILLSV;
    } else  { //if (*itemName==STOPWATCH)
        *itemName=STOPWATCHV;
    }
}

void JsonParser::checkInvalidName(string *itemName) {
    if (hasInvalidName(*itemName)) {
        setValidName(itemName);
    }
}

void JsonParser::parseItem(nlohmann::json::const_reference json, string ref,  string *itemName,
                           int * itemLevel) {
    *itemName=json.at(ref).get<string>();
    checkInvalidName(itemName);
    *itemLevel=json.at(ref + "Level").get<int>();
}

void JsonParser::parseName(nlohmann::json::const_reference json, string *cardname) {
    *cardname= json.at("name").get<string>();
}
void JsonParser::parseNew(nlohmann::json::const_reference json, bool *isNew) {
    if (json.contains("new")) {
        string state=json.at("new").get<string>();
        if (state=="true" || state=="True" || state=="TRUE") {
            *isNew=true;
            return;
        }
    }
    *isNew=false;

}

void JsonParser::parseCards(nlohmann::json j, vector<Card>* cardsP) {
    size_t i=0;
    string s="1";
    string cardname;
    string item1Name;
    int item1Level;
    string item2Name;
    int item2Level;
    int cost;
    bool isNew;
    nlohmann::json cardJ;
    while (j.contains(s) && i<MAXCARDSS) {
        item1Name="";
        item1Level=0;
        item2Name="";
        item2Level=0;
        cardJ=j[s];
        parseName(cardJ,&cardname);
        cost = cardJ.at("cost").get<int>();
        if (cardJ.contains("item1")) {
            parseItem(cardJ,"item1",&item1Name,&item1Level);
            }
        if (cardJ.contains("item2")) {
            parseItem(cardJ,"item2",&item2Name,&item2Level);
            }
        if (champIsNew) {
            parseNew(cardJ,&isNew);
        }
        cardsP->emplace_back(cardname,cost,item1Name,item1Level,item2Name,item2Level,isNew);
        i++;
        s=to_string(i+1);
    }
}



void JsonParser::parse() {
    ifstream f=getVersionFile();
    nlohmann::json json;
    f >> json;
    string  champName;
    vector cards_p = {  &cardsGlobal1,&cardsGlobal2,&cardsGlobal3, &cardsGlobal4};
    vector champs = { &champ1, &champ2, &champ3, &champ4 };
    size_t i=0;
    string s="1";
    nlohmann::json champJ;
    while (json.contains(s) && i < champs.size()) {
        champIsNew=false;
        champJ=json[s];
        parseName(champJ,&champName);
        parseNew(champJ,&champIsNew);
        auto champ = ChampCard(champName,champIsNew);
        *champs[i]=champ;
        parseCards(champJ,cards_p[i]);
        i++;
        s=to_string(i+1);
    }
}

JsonParser::JsonParser() {
    champIsNew=false;
    patchVersion="";
}

JsonParser::JsonParser(string patchVersion) {
    this->patchVersion=std::move(patchVersion);
}


