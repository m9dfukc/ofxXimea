// ofxXimea Example, Nathan Wade

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){


	//configure
	xiCam.openDialog(); //interactive CLI selection
	//xiCam.openDevice(2); //or set with known index
	xiCam.config(XI_MONO8); //XI_MONO8 or XI_RGB32 are implemented
	xiCam.setExposure(3000);
	xiCam.setTriggerMode(0,0);

	//set binning (downsampling)
	binning = 1;
	xiCam.setBinning(binning, binning);
	ini = false;

	//set AWB region
	roi = ofRectangle(0,0,xiCam.sensorWidth, xiCam.sensorHeight);
	xiCam.setAWBROI(roi);
	xiCam.setFrameRate(30);

}


//--------------------------------------------------------------
void ofApp::update(){
	xiCam.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);

	xiCam.draw(0,0); //draw without scaling
	//xiCam.draw(0,0, ofGetWidth(), ofGetHeight()); //draw with scaling

	//draw ROI
	ofSetLineWidth(2);
	ofSetColor(0,0,255);
	ofNoFill();
	ofRect(roi);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key)
    {
		case '=':	//increase binning
		{
			switch (binning)
			{
			case 1:
				binning = 2;
				break;
			case 2: binning = 4;
				break;
			}

			xiCam.setBinning(binning, binning);
			break;
		}

		case '-':	//decrease binning
		{
			switch (binning)
			{
			case 2:
				binning = 1;
				break;
			case 4: binning = 2;
				break;
			}

			xiCam.setBinning(binning, binning);
			break;
		}
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
	roi.setWidth(ofGetMouseX() - mX);
	roi.setHeight(ofGetMouseY() - mY);

	xiCam.setAWBROI(roi);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if(!ini){
		xiCam.setAWB(1);
		roi.setWidth(1);
		roi.setHeight(1);
		mX = ofGetMouseX();
		mY = ofGetMouseY();
		roi.setPosition(mX,mY);
		ini = true;
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	ini = false;
	xiCam.setAWB(0);
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
void ofApp::exit(){
	xiCam.close();
}
