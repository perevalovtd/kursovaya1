#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();



	float pos_t; //� �������
	float pos_t_prev; //������� x
	float r;
	float R;
	float targetCartX;
	ofPoint V; //  �������� ��������
	float Um; //�������� �������� �� � ������ ����������� 
	float Un; //�������� �������� �� � ������ ����������� 
	float accel; // ������� ��������� ��������
	ofPoint pos_end; // ���������� ������ ��������
	ofPoint pos_t_centr; //���������� ������ �������
	float pos_t0; //��������� ��������� �������(��� ���������� ������)
	float mouse_pos; //����� �� ������� ����� ����
	float alpha; //���� ����� oy � �������� �����
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
