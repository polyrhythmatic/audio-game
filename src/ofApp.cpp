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

    gamePlayer1.setup("first");
    gamePlayer2.setup("second");
    gamePlayer3.setup("third");

    gamePlayer1.start();
    
    currentGame = 1;
    
    UID = "";
}

//--------------------------------------------------------------
void ofApp::update() {
    gpio17.getval_gpio(state_button_17);
    gpio27.getval_gpio(state_button_27);

    int button = -1;
    if(state_button_17 == "1"){
        button = 1;
        cout<<"you chose button A"<<endl;
    } else if(state_button_27 == "1") {
        button = 0;
        cout<<"you chose button B"<<endl;
    }
    if(button != -1 && (ofGetElapsedTimef() - clickTime > 5.0)){
        clickTime = ofGetElapsedTimef();

        if(currentGame == 1){
            gamePlayer1.decisionTree(button);
        } else if(currentGame == 2){
            gamePlayer2.decisionTree(button);
        } else if(currentGame == 3){
            gamePlayer3.decisionTree(button);
        }
    }
    
    gamePlayer1.update();
    gamePlayer2.update();
    gamePlayer3.update();
    
    if(gamePlayer1.isOver()){
        currentGame = 2;
        gamePlayer2.start();
    }
    if(gamePlayer2.isOver()){
        currentGame = 3;
        gamePlayer3.start();
    }
    if(gamePlayer3.isOver()){
        //do something with the end here
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
        //add a splash screen to let users know its loading?
        
        string url = "https://query.yahooapis.com/v1/public/yql?q=select%20*%20from%20weather.forecast%20where%20woeid%20in%20(select%20woeid%20from%20geo.places(1)%20where%20text%3D%22nome%2C%20ak%22)&format=json&env=store%3A%2F%2Fdatatables.org%2Falltableswithkeys";
        if (!response.open(url))
        {
            ofLogNotice("ofApp::keyPressed") << "Failed to parse JSON";
        }
        cout << response["query"]["count"].asInt() << endl;

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
