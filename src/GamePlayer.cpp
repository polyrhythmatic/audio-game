#include "GamePlayer.h"

GamePlayer::GamePlayer(){
}

void GamePlayer::setup(string directory, int num){
    gameNum = num;
    
    intro.load("sounds/" + directory + "/intro.wav");
    choiceA.load("sounds/" + directory + "/choiceA.wav");
    choiceB.load("sounds/" + directory + "/choiceB.wav");
    
    currentSampleName = "intro";
    currentSample = &intro;
    gameOver = false;
}

void GamePlayer::start(){
    intro.play();
}

bool GamePlayer::isPlaying(){
    return currentSample->isPlaying();
}
bool GamePlayer::isOver(){
    return gameOver;
}

void GamePlayer::update(){
    if((currentSampleName == "choiceA" || currentSampleName == "choiceB") && !(currentSample->isPlaying())){
        // last sample
        gameOver = true;
    }
}

int GamePlayer::finalScore(){
    float score = 0.0;
    score = round(500.0 * ofRandom(1.0) + (-50.0 * ofRandom(2.0, 5.0)));
    return ofToInt(ofToString(floor(score)));
}

void GamePlayer::decisionTree(int button){
    //GPIO 18 is value 0 for button
    //GPIO 17 is value 1 for button
    //                  intro
    //          ------          ------
    //          |                     |
    //      choiceA                 choiceB
    if(currentSampleName == "intro"){
        cout << "in the decision tree" << endl;
        if(button == 1){
            playSound(choiceA, "choiceA");
        } else if (button == 0){
            playSound(choiceB, "choiceB");
        }
    }
}

void GamePlayer::resetPlayer(){
    currentSampleName = "intro";
    currentSample = &intro;
    gameOver = false;
    
}

void GamePlayer::playSound(ofSoundPlayer & thePlayer, string playerName){
    stopAll();
    thePlayer.play();
    currentSampleName = playerName;
    currentSample = &thePlayer;
}

void GamePlayer::stopAll(){
    intro.stop();
    choiceA.stop();
    choiceB.stop();
}