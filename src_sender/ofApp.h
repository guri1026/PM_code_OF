#pragma once

#include "ofMain.h"
#include "ofxOsc.h"


#define HOST_01 "192.168.11.2" // B1  IP Address
#define HOST_02 "192.168.11.3" // B2
#define HOST_03 "192.168.11.4" // C
#define HOST_04 "192.168.11.5" // floor1
#define HOST_05 "192.168.11.6" // floor2
#define HOST_06 "192.168.11.7" // PA

//#define HOST_03 ......


#define PORT 8000

//#define MOVIE_FILE "/Users/Shared/C.mp4"

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
    
    void allPlay();
    void allPause();
    
    ofVideoPlayer movie;
    ofxOscSender sender_01, sender_02, sender_03,sender_04,sender_05,sender_06,sender_07;
    
    bool bPlaying;
    bool black;
    bool movie_on;
    bool count_start;
    
    int framecount;
    
};
