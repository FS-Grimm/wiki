//
// Created by Felipe on 1/8/2025.
//
#pragma once

#ifndef DEFS_H
#include "defsItems.h"
#include "defsUpgradeLevels.h"
#include "defsCards.h"

#define DEFS_H
#define MAXCARDS 8
#define UTILITYSEPARATOR "|"

#define CHAMP1 "Mel"

inline const char *cardsChamp1[MAXCARDS] = {
    "Lest"  C1,
    "Academy Prodigy" C2,
    "Ballistic Bot" C2,
    "Elora" C3,
    "Howling Gale" C3,
    "Solar Snare" C3,
    "Funsmith" C4,
    "Rebuttal" C5

};
const int MAXITEMS= MAXCARDS+4;
inline const char *itemsChamp1[MAXITEMS] = {
    { "Bounty Board" BLEVELTEXT2   UTILITYSEPARATOR "Coralcrush Gauntlets" BLEVELTEXT24 },
    { "Entrancing Lure" BLEVELTEXT6 },
    { STUDDEDLEATHER BLEVELTEXT9       },
    { "Skirmisher's Sabre" BLEVELTEXT12 },
    { "Ardent Censer" BLEVELTEXT21 },
    { POROSNAXSS BLEVELTEXT15 },
    { "Savage Shield" BLEVELTEXT18 },
    { MANAPOTIONS BLEVELTEXT3} //Card 8 I 1/2
};


#define CHAMP2 "Spirit Blossom Ahri"
inline const char *cardsChamp2[MAXCARDS] = {
    "Orb of Deception" C2,
    "Spirit Rush" C3,
    "Essence Thief" C2,
    "Serene Spirit" C3,
    "Final Blessing" C5,
    "Sparring Student" C1,
    "Prancing Sea Spirits" C2,
    "Petals of Fate" C1,
};

inline const char *itemsChamp2[MAXCARDS] = {

};
#endif //DEFS_H
