//
// Created by sten on 27.10.22.
//

#include "Synths.h"

Synth::Synth(double freq, double sampleRate) {
    this->freq = freq;
    this->sampleRate = sampleRate;
}

SineSynth::SineSynth(double freq, double sampleRate) : Synth(freq, sampleRate) {
    this->freq = freq;
    this->sampleRate = sampleRate;
}
double SineSynth::getSample() {
    this->phase += (this->freq / this->sampleRate) * 2.0 * 3.14159265;
    return sin(this->phase);
}
void SineSynth::setFrequency(double freq) {
    this->freq = freq;
}


SquareSynth::SquareSynth(double freq, double sampleRate) : Synth(freq, sampleRate) {
    this->freq = freq;
    this->sampleRate = sampleRate;
}
double SquareSynth::getSample() {
    this->phase += (this->freq / this->sampleRate) * 2.0 * 3.14159265;
    if(sin(this->phase) > 0) {
        return 0.5;
    }
    else if (sin(this->phase) < 0) {
        return -0.5;
    }
    return 0;
}
void SquareSynth::setFrequency(double freq) {
    this->freq = freq;
}
