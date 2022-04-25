/*    ·▄▄▄▐▄• ▄ ·▄▄▄▄   ▄▄▄· • ▌ ▄ ·. ▪  ▄▄▄ .▄▄▄    ░█░█░█░█░█
▪     ▐▄▄· █▌█▌▪██▪ ██ ▐█ ▀█ ·██ ▐███▪██ ▀▄.▀·▀▄ █·  █░█░█░█░█░
 ▄█▀▄ ██▪  ·██· ▐█· ▐█▌▄█▀▀█ ▐█ ▌▐▌▐█·▐█·▐▀▀▪▄▐▀▀▄   ░█░█░█░█░█
▐█▌.▐▌██▌.▪▐█·█▌██. ██ ▐█ ▪▐▌██ ██▌▐█▌▐█▌▐█▄▄▌▐█•█▌  █░█░█░█░█░
 ▀█▄▀▪▀▀▀ •▀▀ ▀▀▀▀▀▀▀•  ▀  ▀ ▀▀  █▪▀▀▀▀▀▀ ▀▀▀ .▀  ▀  */

#include "ofxDamier.h"

#include <vector>
#include <string>
#include <iostream>


//----------------------------------------
ofxDamier::ofxDamier(){}

//----------------------------------------
void ofxDamier::creation(int haut, int box_hight, int box_tick, ofColor color1, ofColor color2){
	hauteur = haut;
	box_size = box_hight;
	box_hight = box_tick;
	color_1 = color1;
	color_2 = color2;
	// Création de chaques pièces du damier
	// et insertion dans le vector boxes
	int box_start_point = -((box_size*hauteur)/2);;
	for (int i=0; i<hauteur; i++){
		for (int j=0; j<hauteur; j++){
			ofBoxPrimitive box;
			box.set(box_size,box_hight,box_size);
			box.setPosition(box_start_point+(i*box_size),0,box_start_point+(j*box_size));
			boxes.push_back(box);
		}

	}
	for (int i=0; i<boxes.size(); i++) {
		random_order.push_back(i);
		random_val1.push_back(ofRandom(-3,3));
		random_val2.push_back(ofRandom(-5,5));
	}
	random_shuffle(random_order.begin(), random_order.end());

	box_nbr = ofRandom(0, boxes.size());

}


void ofxDamier::set_texture(string path_img1, string path_img2) {
	ofLoadImage(textu_1,path_img1);
	ofLoadImage(textu_2,path_img2);
}


//----------------------------------------
void ofxDamier::draw(){
	// À éxécuter dans la section draw() pour 
	// afficher chacune des tuiles
	for (int i=0; i<boxes.size(); i++) {
		if (i % 2 == 0){
			ofSetColor(color_1,ofMap(boxes[i].getY(),-150,0,0,255));
		} else {
			ofSetColor(color_2,ofMap(boxes[i].getY(),-150,0,0,255));
		}
	boxes[i].draw();
	}

}

//----------------------------------------
void ofxDamier::draw_texture(){
	// À éxécuter dans la section draw() pour 
	// afficher chacune des tuiles
	for (int i=0; i<boxes.size(); i++) {
		if (i % 2 == 0){
			textu_1.bind();
			boxes[i].draw();
			textu_1.unbind();
		} else {
			textu_2.bind();
			boxes[i].draw();
			textu_2.unbind();
		}
	}

}

//----------------------------------------
void ofxDamier::SinWavefx(){
	for (int i=0; i<boxes.size(); i++) {
		float vague_mini = ofMap(sin(random_val1[i]*ofGetElapsedTimef()),-1,1,-random_val1[i],random_val1[i]);
		float eclatement = ofMap(sin(0.5*ofGetElapsedTimef()),-1,1,-random_val2[i],random_val2[i]);
		float y_val = vague_mini + eclatement;
		boxes[random_order[i]].setPosition(boxes[random_order[i]].getX(),y_val,boxes[random_order[i]].getZ());
	}
}


//----------------------------------------
void ofxDamier::freezfx(){
	int time = floor(ofGetElapsedTimef());
	if (time % 2 == 0){
		if (box_nbr == 0) {
			boxes[box_nbr].setPosition(boxes[box_nbr].getX(),0,boxes[box_nbr].getZ());
			box_nbr = ofRandom(0, boxes.size());
		} else {
			boxes[box_nbr].setPosition(boxes[box_nbr].getX(),ofRandom(10,15),boxes[box_nbr].getZ());
		}
		
	} else {
		box_nbr = 0;
	
	}
}