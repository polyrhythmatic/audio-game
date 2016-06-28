#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gpio17.setup("17");
    gpio17.export_gpio();
    gpio17.setdir_gpio("in");

    gpio27.setup("27");
    gpio27.export_gpio();
    gpio27.setdir_gpio("in");
    
    sample.load("sounds/audio.wav");
    sampleA.load("sounds/audio.wav");
    sampleB.load("sounds/audio.wav");
    sampleAA.load("sounds/audio.wav");
    sampleBB.load("sounds/audio.wav");
    sampleAB.load("sounds/audio.wav");
    sampleBA.load("sounds/audio.wav");
    
    currentSampleName = "sample";

    silence.load("sounds/silence.wav");
    silence.setLoop(true);
    silence.play();
    
    currentSample = &sample;
    
    clickTime = 0;

    begin();
}

//--------------------------------------------------------------
void ofApp::update() {
    gpio17.getval_gpio(state_button_17);
    gpio27.getval_gpio(state_button_27);


    if((state_button_17 == "1" || state_button_27 == "1") && (ofGetElapsedTimef() - clickTime > 5.0)){
        clickTime = ofGetElapsedTimef();
//        ofLog()<<state_button_27;
        decisionTree();
    }
//    usleep(50000);
}

void ofApp::begin(){
//    currentSample = sample;
//    currentSample.play();
    sample.play();
}

void ofApp::decisionTree(){
//                  sample
//          ------          ------
//          |                     |
//      sampleA                 sampleB
//    ------ ------         ------ ------
//    |			|           |			|
//    sampleAA	sampleAB	sampleBA 	sampleBB
    if(currentSampleName == "sample"){
        if(state_button_17 == "1"){
            cout<<"you chose button A"<<endl;
            playSound(sampleA, "sampleA");
        } else if (state_button_27 == "1"){
            playSound(sampleB, "sampleB");
        }
    } else if(currentSampleName == "sampleA") {
        if(state_button_17 == "1"){
            playSound(sampleAA, "sampleAA");
        } else if (state_button_27 == "1"){
            playSound(sampleAB, "sampleAB");
        }
    } else if(currentSampleName == "sampleB") {
        if(state_button_17 == "1"){
            playSound(sampleBA, "sampleBA");
        } else if (state_button_27 == "1"){
            playSound(sampleBB, "sampleBB");
        }
    }
}

void ofApp::playSound(ofSoundPlayer & thePlayer, string playerName){
    stopAll();
    thePlayer.play();
    currentSampleName = playerName;
}

void ofApp::stopAll(){
    sample.stop();
    sampleA.stop();
    sampleB.stop();
    sampleAA.stop();
    sampleAB.stop();
    sampleBA.stop();
    sampleBB.stop();
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
