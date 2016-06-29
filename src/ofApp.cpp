#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    gpio17.setup("17");
    gpio17.export_gpio();
    gpio17.setdir_gpio("in");

    gpio27.setup("27");
    gpio27.export_gpio();
    gpio27.setdir_gpio("in");
    
    silence.load("sounds/silence.wav");
    silence.setLoop(true);
    silence.play();
    
    
    clickTime = 0;

    gamePlayer.setup();
    gamePlayer.start();
    
    UID = "";
}

//--------------------------------------------------------------
void ofApp::update() {
    gpio17.getval_gpio(state_button_17);
    gpio27.getval_gpio(state_button_27);


    if((state_button_17 == "1" || state_button_27 == "1") && (ofGetElapsedTimef() - clickTime > 5.0)){
        clickTime = ofGetElapsedTimef();
        gamePlayer.decisionTree(0);
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
}

//--------------------------------------------------------------
void ofApp::exit() {
    gpio17.unexport_gpio();
    gpio27.unexport_gpio();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if(key == 10){
        ofLog() << "reset";
        //make the API calls here
        UID = "";
    } else {
        UID += key;
    }
    ofLog() << UID;
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
