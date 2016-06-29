#include "GamePlayer.h"

GamePlayer::GamePlayer(){
}

void GamePlayer::setup(string directory){
    sample.load("sounds/" + directory + "/sample.wav");
    sampleA.load("sounds/" + directory + "/sampleA.wav");
    sampleB.load("sounds/" + directory + "/sampleB.wav");
    sampleAA.load("sounds/" + directory + "/sampleAA.wav");
    sampleBB.load("sounds/" + directory + "/sampleBB.wav");
    sampleAB.load("sounds/" + directory + "/sampleAB.wav");
    sampleBA.load("sounds/" + directory + "/sampleBA.wav");
    
    currentSampleName = "sample";
    currentSample = &sample;
    gameOver = false;
}

void GamePlayer::start(){
    sample.play();
}

bool GamePlayer::isOver(){
    return gameOver;
}

void GamePlayer::update(){
    if((currentSampleName == "sampleAA" || currentSampleName == "sampleAB" || currentSampleName == "sampleBA" || currentSampleName == "sampleBB") && !(currentSample->isPlaying())){
        // last sample
        gameOver = true;
    }
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
    currentSample = &thePlayer;
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