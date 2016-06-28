#pragma once

#include "ofMain.h"
#include "ofAppNoWindow.h"
#include "ofxGPIO.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void exit();
    void begin();
    void decisionTree();
    void stopAll();
    
    void playSound(ofSoundPlayer & thePlayer, string playerName);
    
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
    
    
    GPIO gpio17;
    GPIO gpio27;
    string state_button_17;
    string state_button_27;
    
    ofSoundPlayer silence;
    
    ofSoundPlayer sample;
    ofSoundPlayer sampleA;
    ofSoundPlayer sampleB;
    ofSoundPlayer sampleAA;
    ofSoundPlayer sampleAB;
    ofSoundPlayer sampleBB;
    ofSoundPlayer sampleBA;
    
    ofSoundPlayer* currentSample;
    string currentSampleName;
    
    float clickTime;
};

