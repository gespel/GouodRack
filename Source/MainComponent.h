#pragma once

#include <JuceHeader.h>
#include "Synths.h"
#include "Randoneur.h"
#include "EnvelopeGenerator.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::AudioAppComponent
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...
    Synth *xL = new SawtoothSynth(110, 48000);
    Synth *xR = new SawtoothSynth(110, 48000);
    Synth *x3 = new SquareSynth(110, 48000);
    Synth *x2 = new SquareSynth(220.0, 48000);
    Synth *y = new SineSynth(1, 1);
    Synth *z = new SineSynth(0.3, 48000);
    Synth *a = new SineSynth(0.3, 48000);
    Randoneur *r = new Randoneur(64);
    WavetableSynth *wtL = new WavetableSynth(35, 48000, 32);
    WavetableSynth *wtR = new WavetableSynth(35, 48000, 32);
    EnvelopeGenerator *st = new SawtoothEnvelopeIncreasing(48000, 1);
    EnvelopeGenerator *st2 = new SawtoothEnvelopeIncreasing(48000, 1);
    EnvelopeGenerator *st3 = new SawtoothEnvelopeIncreasing(48000, 1);
    //Synth *b = new SquareSynth(3, 48000);
    int wyld = 0;
    int envelope = 0;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
