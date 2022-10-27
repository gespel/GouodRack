//
// Created by sten on 27.10.22.
//

#include "Synths.h"

Synth::Synth(float freq, float sampleRate) {
    this->freq = freq;
    this->sampleRate = sampleRate;
}

SineSynth::SineSynth(float freq, float sampleRate) : Synth(freq, sampleRate) {
    this->freq = freq;
    this->sampleRate = sampleRate;
}
float SineSynth::getSample() {
    this->phase += (this->freq / this->sampleRate) * 2.0 * 3.14159265;
    return sin(this->phase);
}
void SineSynth::setFrequency(float freq) {
    this->freq = freq;
}
