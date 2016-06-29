#include "GamePlayer.h"

GamePlayer::GamePlayer(){
}

void GamePlayer::setup(){
    sample.load("sounds/audio.wav");
    sampleA.load("sounds/audio.wav");
    sampleB.load("sounds/audio.wav");
    sampleAA.load("sounds/audio.wav");
    sampleBB.load("sounds/audio.wav");
    sampleAB.load("sounds/audio.wav");
    sampleBA.load("sounds/audio.wav");
    
    currentSampleName = "sample";
    
}

void GamePlayer::start(){
    sample.play();
}

void GamePlayer::decisionTree(int button){
    //GPIO 27 is value 0 for button
    //GPIO 17 is value 1 for button
    //                  sample
    //          ------          ------
    //          |                     |
    //      sampleA                 sampleB
    //    ------ ------         ------ ------
    //    |			|           |			|
    //    sampleAA	sampleAB	sampleBA 	sampleBB
    if(currentSampleName == "sample"){
        if(button == 1){
            cout<<"you chose button A"<<endl;
            playSound(sampleA, "sampleA");
        } else if (button == 0){
            playSound(sampleB, "sampleB");
        }
    } else if(currentSampleName == "sampleA") {
        if(button == 1){
            playSound(sampleAA, "sampleAA");
        } else if (button == 0){
            playSound(sampleAB, "sampleAB");
        }
    } else if(currentSampleName == "sampleB") {
        if(button == 1){
            playSound(sampleBA, "sampleBA");
        } else if (button == 0){
            playSound(sampleBB, "sampleBB");
        }
    }
}

void GamePlayer::dispose(){
    
}

void GamePlayer::playSound(ofSoundPlayer & thePlayer, string playerName){
    stopAll();
    thePlayer.play();
    currentSampleName = playerName;
}

void GamePlayer::stopAll(){
    sample.stop();
    sampleA.stop();
    sampleB.stop();
    sampleAA.stop();
    sampleAB.stop();
    sampleBA.stop();
    sampleBB.stop();
}