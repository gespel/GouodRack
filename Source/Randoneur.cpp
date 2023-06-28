/*
  ==============================================================================

    Randoneur.cpp
    Created: 28 Jun 2023 8:44:35pm
    Author:  Sten

  ==============================================================================
*/

#include "Randoneur.h"


Randoneur::Randoneur(int synthcount) {
    for(int i = 0; i < synthcount; i++) {
        random_rack.push_back(new SineSynth(440.f, 48000));
    }
}
