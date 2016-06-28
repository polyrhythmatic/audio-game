#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gpio17.setup("17");
    gpio17.export_gpio();
    gpio17.setdir_gpio("in");
    
    sample.load("sounds/beat.wav");
    sample.setVolume(0.75f);
}

//--------------------------------------------------------------
void ofApp::update() {
    gpio17.getval_gpio(state_button);
//    ofLog()<<state_button;
    if(state_button == "1" && sample.isPlaying() == false){
        sample.play();
    }
//    usleep(50000);
}

//--------------------------------------------------------------
void ofApp::draw() {
}

//--------------------------------------------------------------
void ofApp::exit() {
    gpio17.unexport_gpio();
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
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
