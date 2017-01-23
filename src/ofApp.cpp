#include "ofApp.h"


//--------------------------------------------------------------
// Grab shared pointes from main.cpp about our windows so we can query them.
//
// Creates a new empty `Mirror` for each of the given `mirrorWindow`s.
//
// Gets called just before `ofApp::setup`.
void ofApp::setWindows(shared_ptr<ofAppBaseWindow> _mainWindow,
                       shared_ptr<ofAppBaseWindow> _secondWindow)
{
    // The GUI window, used for testing.
    mainWindow = _mainWindow;
    mainWindow->setWindowTitle("Test GUI Window");
    
    // LED window - displays the aggregate visualisation.
    secondWindow = _secondWindow;
    secondWindow->setWindowTitle("Second Window");
}

//--------------------------------------------------------------
void ofApp::setup(){

    second_window_fbo.allocate(secondWindow->getWidth(), secondWindow->getHeight());
    second_window_fbo.begin();
    ofClear(0);
    second_window_fbo.end();
}

//--------------------------------------------------------------
void ofApp::update(){
    cout << "Main winodow width = " << mainWindow->getWidth() <<
    " -- Main window height = " << mainWindow->getHeight() <<
    " -- Second window widht = " << secondWindow->getWidth() <<
    " -- Second window height = " << secondWindow->getHeight() << endl;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
}

//--------------------------------------------------------------
void ofApp::drawLedWindow(ofEventArgs &args){
    int x = secondWindow->getWidth()/2;
    int y = secondWindow->getHeight()/2;
    
    ofPushMatrix();
    ofTranslate(x, y);
    second_window_fbo.begin();
    ofClear(0);
    ofSetColor(255,0,0);
    ofDrawEllipse(0, 0, 100,100);
    second_window_fbo.end();
    
    ofPopMatrix();

    second_window_fbo.draw(0,0,secondWindow->getWidth(),secondWindow->getHeight());
}