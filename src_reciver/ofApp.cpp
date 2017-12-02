#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetDataPathRoot("../Resources/data/"); 
    
    ofBackground(0, 0, 0);
    ofHideCursor();
    ofSetFrameRate(30);
    
    bPlaying = false;
    black = false;
    
    movie.load("test.mp4");
    
    
    movie.setLoopState(OF_LOOP_NONE);
    
    receiver.setup(PORT);
    
    
    // movie on off startのタイミングを手動でずらした
    movie_on = false;
    framecount = 0;
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    movie.update();
    movie.setLoopState(OF_LOOP_NONE);
    
    // osc setting
    while (receiver.hasWaitingMessages()) {
        ofxOscMessage m;
        receiver.getNextMessage(&m);
    
    
        if (m.getAddress() == "/qtmovie/play" ){
            count_start = true;
            play();
        }
    
        else if (m.getAddress() == "/qtmovie/pause"){
            count_start = false;
            pause();
        }
    }
    
    // start timing
    if(count_start){
        framecount ++;
        if(framecount == 2){
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
    if(black == false && movie_on == true){
        movie.draw(0, 0, ofGetScreenWidth(), ofGetScreenHeight());
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
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

//--------------------------------------------------------------
void ofApp::play(){
    movie.play();
    movie.setPaused(false);
    bPlaying = true;
}
//--------------------------------------------------------------
void ofApp::pause() {
    movie.setPosition(0.0);
    movie.setPaused(true);
    bPlaying = false;
    
}
