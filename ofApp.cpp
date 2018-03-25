#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	ofEnableDepthTest();
	ofSetColor(39, 239);
	ofFill();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	ofRotateX(45);

	float max_height = 300;
	for (int r = 1; r < 10; r += 1) {

		float radius = r * 30.f;
		float x, y, z, noise_value;
		float tmp_max_height = max_height * r / 10;

		for (int deg = 0; deg < 360; deg += 1) {

			vector<ofPoint> vertices;

			x = radius * cos(deg * DEG_TO_RAD);
			y = radius * sin(deg * DEG_TO_RAD);
			noise_value = ofNoise(x * 0.005, y * 0.005, ofGetFrameNum() * 0.008);
			noise_value = noise_value < 0.5 ? 0.5 : noise_value;
			z = ofMap(noise_value, 0.5, 1, 0, tmp_max_height);
			vertices.push_back(ofPoint(x, y, 0));
			vertices.push_back(ofPoint(x, y, z));

			x = radius * cos((deg + 1)* DEG_TO_RAD);
			y = radius * sin((deg + 1) * DEG_TO_RAD);
			noise_value = ofNoise(x * 0.005, y * 0.005, ofGetFrameNum() * 0.008);
			noise_value = noise_value < 0.5 ? 0.5 : noise_value;
			z = ofMap(noise_value, 0.5, 1, 0, tmp_max_height);
			vertices.push_back(ofPoint(x, y, z));
			vertices.push_back(ofPoint(x, y, 0));

			ofBeginShape();
			ofVertices(vertices);
			ofEndShape(true);
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}