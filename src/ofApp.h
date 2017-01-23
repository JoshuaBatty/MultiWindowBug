#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void drawLedWindow(ofEventArgs& args);

        // Grab shared pointes from main.cpp about our windows so we can query them.
        //
        // Creates a new empty `Mirror` for each of the given `mirrorWindow`s.
        //
        // This method is called just before `setup()`.
        void setWindows(shared_ptr<ofAppBaseWindow> _mainWindow,
                        shared_ptr<ofAppBaseWindow> _secondWindow);
    
        // A handle to each window.
        shared_ptr<ofAppBaseWindow> mainWindow;
        shared_ptr<ofAppBaseWindow> secondWindow;
		
        ofFbo second_window_fbo;
};
