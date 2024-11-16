#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();



	float pos_t; //х тележки
	float pos_t_prev; //прошлый x
	float r;
	float R;
	float targetCartX;
	ofPoint V; //  скорость маятника
	float Um; //скорость маятника но в других координатах 
	float Un; //скорость маятника но в других координатах 
	float accel; // угловое ускорение маятника
	ofPoint pos_end; // координаты центра маятника
	ofPoint pos_t_centr; //координата центра тележки
	float pos_t0; //начальное положение тележки(для управления мышкой)
	float mouse_pos; //часть за которую взяла мышь
	float alpha; //угол между oy и центрами шаров
	float alphastart;
	ofColor color;
	ofstream database;

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	void exit();
};
