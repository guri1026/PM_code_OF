#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define PORT 8000

//#define MOVIE_FILE "/Users/Shared/test.mp4"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
 
//    void dumpOSC(ofxOscMessage m);
    
    void play();
    void pause();
    
    bool bPlaying;
    bool black;
    
    ofxOscReceiver receiver;
    ofVideoPlayer movie;
    
    int framecount;
    bool count_start;
    bool movie_on;
    
};
