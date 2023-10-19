#pragma once

#include <juce_audio_processors/juce_audio_processors.h>
#include <utils/extras/AudioChannelUtilities.h>
#include <Flanger.h>

//==============================================================================
/**
*/
class FlangerPluginAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    FlangerPluginAudioProcessor();
    ~FlangerPluginAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    void updateParameters();

    juce::AudioProcessorValueTreeState apvts;
    juce::AudioProcessorValueTreeState::ParameterLayout createParameters();

private:
    //==============================================================================

    Flanger<float> flanger;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FlangerPluginAudioProcessor)
};