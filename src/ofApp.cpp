#include "ofApp.h"
#include <cmath>
#include <fstream>

//Constants                                 

float dt = 0.01;// [sec]
float m = 0.5; // mass [kg]  
float L = 0.5; //нить [metres]
float k = 60; //коэф жесткости в [n/metres]  
ofPoint g(0.0, 9.8);
float k_pixel = 300; // k пикселей = 1 метр

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(100);  //100fps);
	ofSetCircleResolution(100);

	alphastart = ofRandom(-0.5, 0.5);

	R = 0.4*100; // radius telezhki [metres]
	r = 0.2*100; // radius sharika [metres]
	pos_t_centr = ofPoint(400, 400); // koordinata nachala niti

	pos_end = ofPoint(pos_t_centr.x - L*k_pixel * sin(alphastart), pos_t_centr.y - L*k_pixel * cos(alphastart)); //нач полож шарика
	V = ofPoint(0, 0);
	//database.open("DataBase.txt");

}

//--------------------------------------------------------------
void ofApp::update() {

	

		ofPoint delta = pos_end - pos_t_centr; //вектор разницы координат шарика и тележки в пикселях - длина нити в данный момент
		delta = delta / k_pixel; // длина нити в данный момент в метрах
		float len = delta.length(); //модуль вектора
		float Fh = -k * (len - L); //модуль сила гука   
		delta.normalize(); // теперь delta — единичный вектор с направлением
		ofPoint Fh_vector = delta * Fh;//vector Fhooke
		
		
		ofPoint F = Fh_vector + m*g; //результирующая сила
		ofPoint a = F / m; // accel
		V += a * dt; //speed



		pos_end += V * dt * k_pixel; // в пикселях
		// ----

		color = ofColor(50); //цвет шара

		//

		float dist = pos_end.distance(pos_t_centr);

		if (dist <= R + r) {
			ofPoint rasst = pos_end - pos_t_centr;
			float skalar = rasst.dot(V);
			float l1 = rasst.length();
			float l2 = V.length();

			float cosA = skalar / (l1 * l2); //угол между V и линией соединяющей центры шаров
			ofPoint p = cosA * l2 * (rasst / l1);
			if (cosA < 0) {
				ofPoint Votsk = V - 2 * p; //вектор отскока
				V = Votsk;
			}

			while (dist <= R + r) {
				dist = pos_end.distance(pos_t_centr);
				pos_end += V * dt;
			}
		}

	V = V * 0.995; //потеря скорости изза воздуха (чтобы огромные скорости не набирал)
	//database << pos_end.x << " " << pos_end.y << "\t" << pos_t_centr.x << " " << pos_t_centr.y << "\t" << V.x << " " << V.y << endl;



	

	
	
	/*float deltaX = pos_end.x - pos_t_centr.x;
	float deltaY = pos_end.y - pos_t_centr.y;
	float angleRadians = atan2(deltaX, deltaY);
	alpha = ofRadToDeg(angleRadians);
	// Переворот начала отсчета на 180 градусов
	alpha -= 180;
	// Приведение угла в диапазон [-180; 180]
	if (alpha < -180) {
		alpha += 360;
	}
	*/
}
//--------------------------------------------------------------




void ofApp::draw() {

	ofSetBackgroundColor(230, 230, 230);

	ofSetColor(100, 100, 100);
	ofCircle(pos_t_centr.x, pos_t_centr.y, R); // telezhka
	ofSetColor(230);
	ofCircle(pos_t_centr.x, pos_t_centr.y, R / 1.2);// mini шар
	ofSetColor(100, 100, 100);
	ofLine(pos_t_centr.x, pos_t_centr.y, pos_end.x, pos_end.y); // line

	ofSetColor(color);
	ofCircle(pos_end.x, pos_end.y, r); // ball
	ofCircle(pos_t_centr.x, pos_t_centr.y, R / 5);

	ofSetColor(200, 100, 100);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

	//targetCartX = x-w/2;
	if (mouse_pos > -500) {
		pos_t_centr.x = x + pos_t0 - mouse_pos;
	}

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	if (((pos_t_centr.x - x) * (pos_t_centr.x - x) + (pos_t_centr.y - y) * (pos_t_centr.y - y)) <= 40 * 40) {
		mouse_pos = x;
		pos_t0 = pos_t_centr.x;
	}
	else {
		mouse_pos = -1000;
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

//--------------------------------------------------------------
void ofApp::exit() {
	// Закрываем файл

	//database.close();

}