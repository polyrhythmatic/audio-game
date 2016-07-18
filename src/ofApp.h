#pragma once

#include "ofMain.h"
#include "ofxGPIO.h"
#include "GamePlayer.h"
#include "ofxJSON.h"

class ofApp : public ofBaseApp{

    public:
        void setup();
        void update();
        void draw();
        void exit();
        
        void keyPressed (int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y );
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
    
        void startGame();
        void setScore(string userID, float theScore, string fieldID, string assignmenttype);
        int score;
    
        void setupGPIO();
        void resetGame();
        GPIO gpio17;
        GPIO gpio18;
        GPIO gpio26;
        string state_button_17;
        string state_button_18;
        string state_button_26;
    
        string UID;
        string currentUID;
    
        ofSoundPlayer silence;
        ofSoundPlayer noise;
    
        GamePlayer gamePlayer1;
        GamePlayer gamePlayer2;
        GamePlayer gamePlayer3;
    
        GamePlayer *currentGamePlayer;
    
        int currentGame;
};

