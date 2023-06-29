#pragma once

#include <JuceHeader.h>
#include "Synths.h"
#include "Randoneur.h"

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
    Synth *x = new SawtoothSynth(0.5, 48000);
    Synth *x2 = new SquareSynth(220.0, 48000);
    Synth *y = new SineSynth(1, 1);
    Synth *z = new SineSynth(0.3, 48000);
    Synth *a = new SineSynth(0.3, 48000);
    Randoneur *r = new Randoneur(32);
    WavetableSynth *wtL = new WavetableSynth(55.0, 48000, 32);
    WavetableSynth *wtR = new WavetableSynth(55.0, 48000, 32);
    //Synth *b = new SquareSynth(3, 48000);
    int wyld = 0;
    int envelope = 0;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
