#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetDataPathRoot("../Resources/data/");
    
    ofBackground(0, 0, 0);
    ofHideCursor();
    ofSetFrameRate(30);
    
    bPlaying = false;
    black = false;
    
    // start timing
    movie_on = false;
    count_start = false;
    framecount = 0;
    
    movie.load("test.mp4");
    
    movie.setLoopState(OF_LOOP_NONE);
    
    // osc setting
    sender_01.setup(HOST_01, PORT);
    sender_02.setup(HOST_02, PORT);
    sender_03.setup(HOST_03, PORT);
    sender_04.setup(HOST_04, PORT);
    sender_05.setup(HOST_05, PORT);
    sender_06.setup(HOST_06, PORT);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    movie.update();
    movie.setLoopState(OF_LOOP_NONE);
    
    // start timing
    if(count_start){
        framecount++;
        if(framecount == 12){
            movie_on = true;
        }
    }
    
    if(count_start == false){
        framecount = 0;
        movie_on = false;
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(movie_on){
        if(black == false){
            movie.draw(0,0,ofGetScreenWidth(), ofGetScreenHeight());
        }
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case ' ':
            count_start = !count_start;
            bPlaying = !bPlaying;
            if (bPlaying) {
                movie.play();
                allPlay();
            }
            
            else {
                movie.stop();
                movie.firstFrame();
                allPause();
            }
            break;
    }
    
    if(key == 'q'){
        black = !black;
    }
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
void ofApp::allPlay(){
    // osc message
    ofxOscMessage m;
    m.setAddress("/qtmovie/play");
    
    sender_01.sendMessage(m);
    sender_02.sendMessage(m);
    sender_03.sendMessage(m);
    sender_04.sendMessage(m);
    sender_05.sendMessage(m);
    sender_06.sendMessage(m);
    
}

//--------------------------------------------------------------
void ofApp::allPause(){
    // osc message
    ofxOscMessage m;
    m.setAddress("/qtmovie/pause");
    
    sender_01.sendMessage(m);
    
   
    sender_02.sendMessage(m);
    sender_03.sendMessage(m);
    sender_04.sendMessage(m);
    sender_05.sendMessage(m);
    sender_06.sendMessage(m);
    
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
