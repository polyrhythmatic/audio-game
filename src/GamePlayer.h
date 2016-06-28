#ifndef _GAMEPLAYER
#define _GAMEPLAYER

#include "ofMain.h"

class GamePlayer {
    
public:
    void setup();
    void start();
    void decisionTree();
    void dispose();
    void playSound(ofSoundPlayer & thePlayer, string playerName);
    void stopAll();
    
    ofSoundPlayer sample;
    ofSoundPlayer sampleA;
    ofSoundPlayer sampleB;
    ofSoundPlayer sampleAA;
    ofSoundPlayer sampleAB;
    ofSoundPlayer sampleBB;
    ofSoundPlayer sampleBA;
    
    string currentSampleName;
    
    int score;
    
    GamePlayer();
};

#endif