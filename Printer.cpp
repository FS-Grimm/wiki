//
// Created by Felipe on 10/8/2025.
//

#include "Printer.h"


void Printer::printPatch(const ChampCard &champ, const vector<Card> &cards) {
    if (!champ.isNew())
        return;
    fprintf(patchFile, "* ");
    fprintf (patchFile, champ.getLoRname().c_str());
    fprintf (patchFile, "\n");
    for (auto card:cards) {
        if (!card.isNew())
            continue;
        fprintf(patchFile, "* ");
        fprintf (patchFile,card.getLoRCard().c_str());
        fprintf (patchFile, "\n");
    }
    fprintf (patchFile, "\n");
}



Printer::Printer(TopTableManager tManager, BottomTableManager bManager, JsonParser jParser, string patchVersion): patchFile(
    nullptr) {
    this->tManager = tManager;
    this->bManager = bManager;
    this->jParser = jParser;
    this->patchVersion = patchVersion;
}

void Printer::parseVersionAndSetDirectory() {
    jParser.parse();
    string vFile="../champs/v" + patchVersion + "/" + patchVersion + ".txt";
    if (!std::filesystem::exists(vFile)) {
        std::filesystem::create_directories("../champs/v" + patchVersion);
    }
}

void Printer::printTables() {
    vector champs = { &champ1, &champ2, &champ3, &champ4 };
    vector  cardsGlobal ={ &cardsGlobal1,& cardsGlobal2,& cardsGlobal3, &cardsGlobal4};
    size_t i=0;

    string vFile="../champs/v" + patchVersion + "/"+ patchVersion+ ".txt";
     patchFile=fopen(vFile.c_str(),"w");
    while (champs[i]->hasName() && i<champs.size()) {
        auto bDeck=BottomDeck(champs[i],*cardsGlobal[i]);
        auto tDeck=TopDeck(champs[i],*cardsGlobal[i]);
        bManager.makeTable(bDeck);
        tManager.makeTable(tDeck);
        printPatch(*champs[i],*cardsGlobal[i]);
        i++;
    }

    fclose(patchFile);

}

