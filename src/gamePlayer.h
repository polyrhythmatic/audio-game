#ifndef _GAMEPLAYER
    #define _GAMEPLAYER

#include "ofMain.h"

class GamePlayer {
    
    public:
        void setup(string directory);
        void start();
        void update();
        void decisionTree(int button);
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
    ofSoundPlayer * currentSample;
    
        int score;
        
        GamePlayer();
};

#endif