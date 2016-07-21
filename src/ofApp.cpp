#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    setupGPIO();
    
    //this helps reduce noise for some reason
    silence.load("sounds/silence.wav");
    silence.setLoop(true);
    silence.play();
    
    noise.load("sounds/noise.wav");
    noise.setLoop(true);
    noise.play();
    
    score = 0;
    
    gamePlayer1.setup("first", 1);
    gamePlayer2.setup("second", 2);
//    gamePlayer3.setup("third", 3);
    
    currentGame = 0;
    currentGamePlayer = &gamePlayer1;
    
    UID = "";
    currentUID = "";
}

//--------------------------------------------------------------
void ofApp::update() {
    gpio17.getval_gpio(state_button_17);
    gpio18.getval_gpio(state_button_18);
    gpio26.getval_gpio(state_button_26);
    
    if(state_button_26 == "1"){
        ofLog() << "shutdown";
        ofSystem("sudo shutdown -h now");
    }
    //button checking
    int button = -1;
    if(state_button_17 == "1"){
        button = 1;
        cout<<"you chose button A"<<endl;
        ofLog() << currentGamePlayer->isPlaying();
    } else if(state_button_18 == "1") {
        button = 0;
        cout<<"you chose button B"<<endl;
    }
    if(button != -1 && !(currentGamePlayer->isPlaying())){
        if(currentGame == 1){
            gamePlayer1.decisionTree(button);
        } else if(currentGame == 2){
            gamePlayer2.decisionTree(button);
        }
    }
    
    gamePlayer1.update();
    gamePlayer2.update();
    
    if(gamePlayer1.isOver() && currentGame == 1){
        currentGame = 2;
        currentGamePlayer = &gamePlayer2;
        gamePlayer2.start();
        score += gamePlayer1.finalScore();
    } else if(gamePlayer2.isOver() && currentGame == 2){
        currentGame = 0;
        currentGamePlayer = &gamePlayer1;
        score += gamePlayer2.finalScore();
        
        setScore(currentUID, score, "81", "balance");
        setScore(currentUID, score, "77", "assign");
        setScore(currentUID, gamePlayer1.finalScore(), "83", "assign");
        setScore(currentUID, gamePlayer2.finalScore(), "85", "assign");
        ofLog() << gamePlayer2.finalScore();
        ofLog() << gamePlayer1.finalScore();
        score = 0;
        currentUID = "";
        gamePlayer1.resetPlayer();
        gamePlayer2.resetPlayer();
    }
    
    if(currentGamePlayer->isPlaying() && noise.isPlaying()){
        noise.setPaused(true);
    } else if(!currentGamePlayer->isPlaying() && !noise.isPlaying() && currentGame == 0){
        noise.setPaused(false);
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
}

//--------------------------------------------------------------
void ofApp::exit() {
    gpio17.unexport_gpio();
    gpio18.unexport_gpio();
    gpio26.unexport_gpio();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if(key == 10){
        ofLog() << "reset";
        //make the API calls here
        //add a splash screen to let users know its loading?
        startGame();
        currentUID = UID;
        UID = "";
    } else {
        UID += key;
    }
    ofLog() << UID;
}

void ofApp::startGame(){
    gamePlayer1.start();
    currentGame = 1;
}

void ofApp::setScore(string userID, float theScore, string fieldID, string assignmenttype){
    /**
    adds to the final score
    **/
    ofxJSONElement response;
    string scoreString = ofToString(floor(theScore));
    cout << scoreString << endl;
    string url = "http://10.102.10.202/api/mh1uo7i0zwnopqfr9awo7j1ihmukrzfrnuzop4ylpgvw8kt9fcikr1am3c45z5mie3o233zub22tvs4i/project/ftwd2016/setticketmiscfield?&uid=" + userID + "&miscfieldid=" + fieldID + "&value=" + scoreString + "&assignmenttype=" + assignmenttype;
    cout << url << endl;
    if (!response.open(url))
    {
        ofLogNotice("ofApp::keyPressed") << "Failed to parse JSON";
        // this is where we prompt the user to scan again?
    }
    ofLog() << "score submitted";
    ofLog() << response;
}

void ofApp::setupGPIO(){
    gpio17.setup("17");
    gpio17.export_gpio();
    gpio17.setdir_gpio("in");
    
    gpio18.setup("18");
    gpio18.export_gpio();
    gpio18.setdir_gpio("in");
    
    gpio26.setup("26");
    gpio26.export_gpio();
    gpio26.setdir_gpio("in");
}

void ofApp::resetGame(){
    score = 0;
    currentGame = 0;
    gamePlayer1.stopAll();
    gamePlayer2.stopAll();
    gamePlayer1.resetPlayer();
    gamePlayer2.resetPlayer();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    std::exit(1);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
