#include "ofMain.h"
#include "ofApp.h"

//--------------------------------------------------------------
int main(){
//    ofAppNoWindow window;
    ofSetupOpenGL(100,100, OF_WINDOW);
    ofRunApp(new ofApp()); // start the app
}