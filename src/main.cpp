#include "ofMain.h"
#include "ofApp.h"

//--------------------------------------------------------------
int main(){
    ofAppNoWindow window;
    ofSetupOpenGL(&window, 0,0, OF_WINDOW);
    ofRunApp(new ofApp()); // start the app
}