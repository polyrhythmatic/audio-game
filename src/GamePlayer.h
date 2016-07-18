#ifndef _GAMEPLAYER
    #define _GAMEPLAYER

#include "ofMain.h"

class GamePlayer {
    
    public:
        void setup(string directory, int num);
        void start();
        void update();
        void decisionTree(int button);
        void dispose();
        void playSound(ofSoundPlayer & thePlayer, string playerName);
        void stopAll();
        void resetPlayer();
    
        bool isOver();
        bool gameOver;
        bool isPlaying();
    
        int finalScore();
    
        float choiceWeights[2];

        int gameNum;
    
        ofSoundPlayer intro;
        ofSoundPlayer choiceA;
        ofSoundPlayer choiceB;
        
        string currentSampleName;
        ofSoundPlayer * currentSample;
        int choice;
    
        float choice1a[2];
        float choice1b[2];
        float choice2a[2];
        float choice2b[2];
        
        GamePlayer();
};

#endif