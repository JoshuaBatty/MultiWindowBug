#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"


//========================================================================
int main(){
    
    //---- GUI WINDOW
    ofGLFWWindowSettings settings;
    settings.setGLVersion(4,1);
    settings.width = 920;
    settings.height = 480;
    settings.setPosition(ofVec2f(510,700));
    settings.resizable = true;
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
    mainWindow->setVerticalSync(true);
    
    //---- MAIN LED WALL WINDOW
    settings.width = 480;
    settings.height = 640;
    settings.setPosition(ofVec2f(50,0));
    settings.resizable = true;
    settings.shareContextWith = mainWindow;
    shared_ptr<ofAppBaseWindow> secondWindow = ofCreateWindow(settings);
    secondWindow->setVerticalSync(true);
    
    
    // Create the main `ofApp` and set the windows.
    shared_ptr<ofApp> mainApp(new ofApp);
    mainApp->setWindows(mainWindow, secondWindow);
    
    // Set callback for drawing to the LED window via the `ofApp::drawLedWindow` method.
    ofAddListener(secondWindow->events().draw, mainApp.get(), &ofApp::drawLedWindow);


    
    ofRunApp(mainWindow, mainApp);
    ofRunMainLoop();
}
