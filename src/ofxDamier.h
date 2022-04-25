#pragma once

/*    ·▄▄▄▐▄• ▄ ·▄▄▄▄   ▄▄▄· • ▌ ▄ ·. ▪  ▄▄▄ .▄▄▄    ░█░█░█░█░█
▪     ▐▄▄· █▌█▌▪██▪ ██ ▐█ ▀█ ·██ ▐███▪██ ▀▄.▀·▀▄ █·  █░█░█░█░█░
 ▄█▀▄ ██▪  ·██· ▐█· ▐█▌▄█▀▀█ ▐█ ▌▐▌▐█·▐█·▐▀▀▪▄▐▀▀▄   ░█░█░█░█░█
▐█▌.▐▌██▌.▪▐█·█▌██. ██ ▐█ ▪▐▌██ ██▌▐█▌▐█▌▐█▄▄▌▐█•█▌  █░█░█░█░█░
 ▀█▄▀▪▀▀▀ •▀▀ ▀▀▀▀▀▀▀•  ▀  ▀ ▀▀  █▪▀▀▀▀▀▀ ▀▀▀ .▀  ▀  */

#include "ofMain.h"
#include <string.h>

class ofxDamier {

	public:
		ofxDamier();

		int hauteur;
		int box_size;
		int box_hight;
		int box_nbr;

		ofColor color_1;
		ofColor color_2;

		ofTexture textu_1;
        ofTexture textu_2;

		vector <ofBoxPrimitive> boxes;
		vector <int> random_val1;
		vector <int> random_val2;
		vector <int> random_order;

		void creation(int haut, int box_nbr, int box_hight, ofColor color1, ofColor color2);
		void set_texture(string path_img1, string path_img2);
		
		void draw();
		void draw_texture();
		
		void SinWavefx();
		void freezfx();

};

