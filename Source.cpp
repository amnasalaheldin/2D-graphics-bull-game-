#include<Windows.h>    
#include<gl/GL.h>    
#include<gl/GLU.h>    
#include<gl/glut.h>
#include<math.h>
#include<iostream>
using namespace std;
int xpos = 0;
int ypos = 0;
int angle;
float sc_x = 1;
float sc_y = 1;
float x_axis;
float y_axis;
float b_speed;
float block_speed = -0.002;
float b = -0.001;
int a = 0;


void spec_key(int key, int x, int y) {
	if (key == GLUT_KEY_UP) {
		ypos += 1;
		if (ypos >= 11)ypos = 10.5;
	}
	if (key == GLUT_KEY_DOWN) {
		ypos -= 1;
		if (ypos <= 0)ypos = 0.5;
	}
	glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y) {
	if (key == 'z' || key == 'Z') {
		sc_x = 0.5;
		sc_y = 0.5;
	}
	if (key == 'x' || key == 'X') {
		sc_x = 1;
		sc_y = 1;
	}
	if (key == 'c' || key == 'C') {
		angle = -90;
	}
	if (key == 'v' || key == 'V') {
		angle = 0;
	}

	glutPostRedisplay();

}
void background() {
	glClearColor(0.2, 0.8, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);//ground
	glColor3ub(50, 205, 50);
	glVertex2f(0, 0);
	glVertex2f(0, 2);
	glVertex2f(16, 2);
	glVertex2f(16, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(139, 69, 16);//139,90,43
	glVertex2f(0, 0);
	glVertex2f(0, 0.75);
	glVertex2f(16, 0.75);
	glVertex2f(16, 0);
	glEnd();
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3ub(139, 69, 16);//139,90,43
	glVertex2f(14, 2);
	glVertex2f(14, 12);
	glVertex2f(15.5, 12);
	glVertex2f(15.5, 2);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(10, 2);
	glVertex2f(10, 12);
	glVertex2f(11.5, 12);
	glVertex2f(11.5, 2);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(6, 2);
	glVertex2f(6, 12);
	glVertex2f(7.5, 12);
	glVertex2f(7.5, 2);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(2, 2);
	glVertex2f(2, 12);
	glVertex2f(3.5, 12);
	glVertex2f(3.5, 2);
	glEnd();
	glPopMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	for (float theta = 0; theta < 360; theta += 1) {
		float deginrad = theta * 3.14 / 180;
		glVertex2f(2.8 + 2 * cos(deginrad), 13 + 3 * sin(deginrad));
	}
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	for (float theta = 0; theta < 360; theta += 1) {
		float deginrad = theta * 3.14 / 180;
		glVertex2f(6.8 + 2 * cos(deginrad), 13 + 3 * sin(deginrad));
	}
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	for (float theta = 0; theta < 360; theta += 1) {
		float deginrad = theta * 3.14 / 180;
		glVertex2f(10.8 + 2 * cos(deginrad), 13 + 3 * sin(deginrad));
	}
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	for (float theta = 0; theta < 360; theta += 1) {
		float deginrad = theta * 3.14 / 180;
		glVertex2f(14.8 + 2 * cos(deginrad), 13 + 3 * sin(deginrad));
	}
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	for (float theta = 0; theta < 360; theta += 1) {
		float deginrad = theta * 3.14 / 180;
		glVertex2f(14 + 0.27 * cos(deginrad), 12 + 0.45 * sin(deginrad));
	}
	glEnd();
	glPushMatrix();
	glTranslatef(1, 2, 0);
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	for (float theta = 0; theta < 360; theta += 1) {
		float deginrad = theta * 3.14 / 180;
		glVertex2f(14 + 0.27 * cos(deginrad), 12 + 0.45 * sin(deginrad));
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.5, 0, 0);
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	for (float theta = 0; theta < 360; theta += 1) {
		float deginrad = theta * 3.14 / 180;
		glVertex2f(14 + 0.27 * cos(deginrad), 12 + 0.45 * sin(deginrad));
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 2, 0);
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	for (float theta = 0; theta < 360; theta += 1) {
		float deginrad = theta * 3.14 / 180;
		glVertex2f(14 + 0.27 * cos(deginrad), 12 + 0.45 * sin(deginrad));
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-2, 2, 0);
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	for (float theta = 0; theta < 360; theta += 1) {
		float deginrad = theta * 3.14 / 180;
		glVertex2f(14 + 0.27 * cos(deginrad), 12 + 0.45 * sin(deginrad));
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-4, 2.5, 0);
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	for (float theta = 0; theta < 360; theta += 1) {
		float deginrad = theta * 3.14 / 180;
		glVertex2f(14 + 0.27 * cos(deginrad), 12 + 0.45 * sin(deginrad));
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-3, 1, 0);
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	for (float theta = 0; theta < 360; theta += 1) {
		float deginrad = theta * 3.14 / 180;
		glVertex2f(14 + 0.27 * cos(deginrad), 12 + 0.45 * sin(deginrad));
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-4.5, 0.5, 0);
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	for (float theta = 0; theta < 360; theta += 1) {
		float deginrad = theta * 3.14 / 180;
		glVertex2f(14 + 0.27 * cos(deginrad), 12 + 0.45 * sin(deginrad));
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-3.5, 0.2, 0);
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	for (float theta = 0; theta < 360; theta += 1) {
		float deginrad = theta * 3.14 / 180;
		glVertex2f(14 + 0.27 * cos(deginrad), 12 + 0.45 * sin(deginrad));
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-6, 2.5, 0);
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	for (float theta = 0; theta < 360; theta += 1) {
		float deginrad = theta * 3.14 / 180;
		glVertex2f(14 + 0.27 * cos(deginrad), 12 + 0.45 * sin(deginrad));
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-7, 0.5, 0);
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	for (float theta = 0; theta < 360; theta += 1) {
		float deginrad = theta * 3.14 / 180;
		glVertex2f(14 + 0.27 * cos(deginrad), 12 + 0.45 * sin(deginrad));
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-7.5, 3, 0);
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	for (float theta = 0; theta < 360; theta += 1) {
		float deginrad = theta * 3.14 / 180;
		glVertex2f(14 + 0.27 * cos(deginrad), 12 + 0.45 * sin(deginrad));
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-8.8, 0.8, 0);
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	for (float theta = 0; theta < 360; theta += 1) {
		float deginrad = theta * 3.14 / 180;
		glVertex2f(14 + 0.27 * cos(deginrad), 12 + 0.45 * sin(deginrad));
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-12, 2.5, 0);
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	for (float theta = 0; theta < 360; theta += 1) {
		float deginrad = theta * 3.14 / 180;
		glVertex2f(14 + 0.27 * cos(deginrad), 12 + 0.45 * sin(deginrad));
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-10.5, 0.5, 0);
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	for (float theta = 0; theta < 360; theta += 1) {
		float deginrad = theta * 3.14 / 180;
		glVertex2f(14 + 0.27 * cos(deginrad), 12 + 0.45 * sin(deginrad));
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-10.5, 2.5, 0);
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	for (float theta = 0; theta < 360; theta += 1) {
		float deginrad = theta * 3.14 / 180;
		glVertex2f(14 + 0.27 * cos(deginrad), 12 + 0.45 * sin(deginrad));
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-12.5, 0, 0);
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	for (float theta = 0; theta < 360; theta += 1) {
		float deginrad = theta * 3.14 / 180;
		glVertex2f(14 + 0.27 * cos(deginrad), 12 + 0.45 * sin(deginrad));
	}
	glEnd();
	glPopMatrix();

}
void bull() {


	glLineWidth(6);
	//body
	glEnable(GL_POINT_SMOOTH);

	glBegin(GL_POLYGON);
	glColor3f(0.52, 0.37, 0.26);
	glVertex2f(0.77363, 6.01083);
	glVertex2f(3, 6);
	glVertex2f(3, 2);
	glVertex2f(0.77363, 2);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.35, 0.16, 0.14);
	glVertex2f(0.77363, 6.01083);
	glVertex2f(3, 6);
	glVertex2f(3, 2);
	glVertex2f(0.77363, 2);

	glEnd();
	/////////////////////////////////////////////
	//horns
	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.8, 0.8);
	glVertex2f(0.77363, 5.60785);
	glVertex2f(0.22307, 5.60785);
	glVertex2f(0.22307, 6.29448);
	glVertex2f(0.43403, 6.00021);
	glVertex2f(0.77363, 6.01083);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.8, 0.8);
	glVertex2f(3, 5.60785);
	glVertex2f(3.57986, 5.60785);
	glVertex2f(3.57986, 6.29448);
	glVertex2f(3.32936, 5.99953);
	glVertex2f(3, 6);

	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0.35, 0.16, 0.14);
	glVertex2f(0.77363, 5.60785);
	glVertex2f(0.22307, 5.60785);
	glVertex2f(0.22307, 6.29448);
	glVertex2f(0.43403, 6.00021);
	glVertex2f(0.77363, 6.01083);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glLineWidth(4);
	glColor3f(0.35, 0.16, 0.14);
	glVertex2f(3, 5.60785);
	glVertex2f(3.57986, 5.60785);
	glVertex2f(3.57986, 6.29448);
	glVertex2f(3.32936, 5.99953);
	glVertex2f(3, 6);
	glEnd();
	//////////////////////////////////////////////////////////
		//legs
	glBegin(GL_POLYGON);
	glColor3f(0.25, 0.16, 0.10);
	glVertex2f(1.1027, 2.24381);
	glVertex2f(1.1027, 2);
	glVertex2f(1.58818, 2);
	glVertex2f(1.58818, 2.24218);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.35, 0.16, 0.14);
	glVertex2f(1.09174, 2.80407);
	glVertex2f(1.09174, 2);
	glVertex2f(1.59432, 2);
	glVertex2f(1.59432, 2.7959);
	glVertex2f(1.1027, 2.24381);
	glVertex2f(1.58818, 2.24218);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.25, 0.16, 0.10);
	glVertex2f(2.20239, 2.24381);
	glVertex2f(2.20239, 2);
	glVertex2f(2.69257, 2);
	glVertex2f(2.69257, 2.24218);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.35, 0.16, 0.14);
	glVertex2f(2.20239, 2.80407);
	glVertex2f(2.20239, 2);
	glVertex2f(2.69257, 2);
	glVertex2f(2.69257, 2.80407);
	glVertex2f(2.20239, 2.24218);
	glVertex2f(2.69257, 2.24218);
	glEnd();
	/////////////////////////////////////////
	//nose
	glBegin(GL_LINE_LOOP);
	glColor3f(0.35, 0.16, 0.14);//color red 0.35 green 0.16 blue 0.14
	glVertex2f(1.22332, 4.31078);
	glVertex2f(1.22332, 3.5035);
	glVertex2f(2.5, 3.5);
	glVertex2f(2.49549, 4.31078);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.91, 0.76, 0.65); //color red 0.91 green 0.76 blue 0.65
	glVertex2f(1.22332, 4.31078);
	glVertex2f(1.22332, 3.5035);
	glVertex2f(2.5, 3.5);
	glVertex2f(2.49549, 4.31078);
	glEnd();
	///////////////////////////////////////
	//nose circle
	glBegin(GL_POLYGON);
	glColor3f(0.858824, 0.576471, 0.439216);// color red 0.858824 green 0.576471 blue 0.439216

	for (float theta = 0; theta < 360; theta += 1) {
		float deginrad = theta * 3.14 / 180;
		glVertex2f(1.5 + 0.12 * cos(deginrad), 4 + 0.12 * sin(deginrad));
	}

	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.858824, 0.576471, 0.439216);// color red 0.858824 green 0.576471 blue 0.439216

	for (float theta = 0; theta < 360; theta += 1) {
		float deginrad = theta * 3.14 / 180;
		glVertex2f(2.21575 + 0.12 * cos(deginrad), 4.00366 + 0.12 * sin(deginrad));
	}
	glEnd();
	////////////////////////////////////////////////
	//right eye
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (float theta = 0; theta < 360; theta += 1) {
		float deginrad = theta * 3.14 / 180;
		glVertex2f(2.47551 + 0.44 * cos(deginrad), 5.07418 + 0.44 * sin(deginrad));//2.47551, 3.07418)
	}
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(71, 46, 0);
	for (float theta = 0; theta < 360; theta += 1) {
		float deginrad = theta * 3.14 / 180;
		glVertex2f(2.47551 + 0.22 * cos(deginrad), 5.07418 + 0.22 * sin(deginrad));
	}
	glEnd();
	//left eye
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (float theta = 0; theta < 360; theta += 1) {
		float deginrad = theta * 3.14 / 180;
		glVertex2f(1.33655 + 0.44 * cos(deginrad), 5.07418 + 0.44 * sin(deginrad));
	}
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(71, 46, 0);
	for (float theta = 0; theta < 360; theta += 1) {
		float deginrad = theta * 3.14 / 180;
		glVertex2f(1.33655 + 0.22 * cos(deginrad), 5.07418 + 0.22 * sin(deginrad));
	}
	glEnd();




}

void block() {
	glPushMatrix();
	glTranslatef(x_axis, y_axis, 0);
	x_axis += block_speed;
	if (x_axis <= -43)x_axis = 8;
	glBegin(GL_POLYGON);
	glColor3ub(204, 0, 0);
	glVertex2f(8, 7);
	glVertex2f(9, 7);
	glVertex2f(9, 16);
	glVertex2f(8, 16);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3ub(153, 0, 0);
	glVertex2f(8, 7);
	glVertex2f(9, 7);
	glVertex2f(9, 16);
	glVertex2f(8, 16);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(204, 0, 0);
	glVertex2f(15, 0);
	glVertex2f(15.5, 0);
	glVertex2f(15.5, 5);
	glVertex2f(15, 5);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3ub(153, 0, 0);
	glVertex2f(15, 0);
	glVertex2f(15.5, 0);
	glVertex2f(15.5, 5);
	glVertex2f(15, 5);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(204, 0, 0);
	glVertex2f(15, 11);
	glVertex2f(15.5, 11);
	glVertex2f(15.5, 16);
	glVertex2f(15, 16);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3ub(153, 0, 0);
	glVertex2f(15, 11);
	glVertex2f(15.5, 11);
	glVertex2f(15.5, 16);
	glVertex2f(15, 16);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(204, 0, 0);
	glVertex2f(23, 4);
	glVertex2f(24, 4);
	glVertex2f(24, 16);
	glVertex2f(23, 16);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3ub(153, 0, 0);
	glVertex2f(23, 4);
	glVertex2f(24, 4);
	glVertex2f(24, 16);
	glVertex2f(23, 16);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(204, 0, 0);
	glVertex2f(31, 0);
	glVertex2f(32, 0);
	glVertex2f(32, 10);
	glVertex2f(31, 10);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3ub(153, 0, 0);
	glVertex2f(31, 0);
	glVertex2f(32, 0);
	glVertex2f(32, 10);
	glVertex2f(31, 10);
	glEnd();
	glPopMatrix();
	glutPostRedisplay();
}
void moving_block() {
	glPushMatrix();
	glTranslatef(x_axis, b_speed, 0);
	b_speed += b;
	x_axis += block_speed;
	if (x_axis <= -43)x_axis = 8;
	if (b_speed <= -2.5) b += 0.02;
	else if (b_speed >= 2.5) b += -0.02;
	glBegin(GL_POLYGON);
	glColor3ub(204, 0, 0);
	glVertex2f(40, 7);
	glVertex2f(41, 7);
	glVertex2f(41, 12);
	glVertex2f(40, 12);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3ub(153, 0, 0);
	glVertex2f(40, 7);
	glVertex2f(41, 7);
	glVertex2f(41, 12);
	glVertex2f(40, 12);
	glEnd();
	glPopMatrix();
	glutPostRedisplay();
}

void Game_Over() {
	if (x_axis >= xpos - 8.5 && x_axis <= xpos - 4.5 && ypos >= y_axis + 5 && ypos <= y_axis + 10 || x_axis >= xpos - 8.5 && x_axis <= xpos - 4.5 && ypos >= y_axis + 1) {
		block_speed = 0;
	}
	else if (x_axis >= xpos - 14.8 && x_axis <= xpos - 12 && ypos >= y_axis - 1.3 && ypos <= y_axis + 2.3 || ypos <= y_axis + 3 && x_axis >= xpos - 14.8 && x_axis <= xpos - 12) {//
		block_speed = 0;
	}
	else if (x_axis <= xpos - 11.5 && x_axis >= xpos - 14.8 && ypos >= y_axis + 9 && ypos <= y_axis + 10 || ypos >= y_axis + 5 && x_axis >= xpos - 14.8 && x_axis <= xpos - 11.5) {
		block_speed = 0;
	}
	else if (x_axis <= xpos - 19.5 && x_axis >= xpos - 22.8 && ypos >= y_axis && ypos <= y_axis + 10) {
		block_speed = 0;
	}
	else if (x_axis <= xpos - 27.4 && x_axis >= xpos - 30.8 && ypos >= y_axis && ypos <= y_axis + 4 || ypos <= y_axis + 8 && x_axis <= xpos - 27.4 && x_axis >= xpos - 31) {
		block_speed = 0;
	}
	else if (x_axis <= xpos - 37 && x_axis >= xpos - 39.8 && ypos >= b_speed && ypos <= b_speed || ypos >= b_speed + 1 && x_axis <= xpos - 37 && x_axis >= xpos - 39.8) {
		b = 0;
		block_speed = 0;
	}
}
///////////////////////////////////////////////////////////////
void Game_Over2() {
	if (x_axis >= xpos - 9 && x_axis <= xpos - 6.2 && ypos >= y_axis + 4 && ypos <= y_axis + 10 || x_axis >= xpos - 9 && x_axis <= xpos - 6.2 && ypos >= y_axis + 4) {
		block_speed = 0;
	}
	if (x_axis >= xpos - 15 && x_axis <= xpos - 13.2 && ypos >= y_axis - 1.3 && ypos <= y_axis + 4 || ypos <= y_axis + 3 && x_axis >= xpos - 15 && x_axis <= xpos - 13.2) {//
		block_speed = 0;
	}
	if (x_axis <= xpos - 13.2 && x_axis >= xpos - 15.2 && ypos >= y_axis + 8 && ypos <= y_axis + 10 || ypos >= y_axis + 8 && x_axis >= xpos - 15.2 && x_axis <= xpos - 13.2) {
		block_speed = 0;
	}
	if (x_axis <= xpos - 21.2 && x_axis >= xpos - 22.8 && ypos >= y_axis + 1 && ypos <= y_axis + 10 || ypos >= y_axis + 1 && x_axis <= xpos - 21.2 && x_axis >= xpos - 22.8) {
		block_speed = 0;
	}
	if (x_axis <= xpos - 29.2 && x_axis >= xpos - 31.5 && ypos >= y_axis - 1.3 && ypos <= y_axis + 4 || ypos <= y_axis + 9 && x_axis <= xpos - 29.2 && x_axis >= xpos - 31.5) {
		block_speed = 0;
	}
	if (x_axis <= xpos - 38.4 && x_axis >= xpos - 40 && ypos >= b_speed && ypos <= b_speed || ypos >= b_speed + 3.5 && x_axis <= xpos - 38.4 && x_axis >= xpos - 40) {
		b = 0;
		block_speed = 0;

	}
	glutPostRedisplay();
}
////////////////////////////////
void Game_Over3() {
	if (x_axis >= xpos - 7 && x_axis <= xpos - 1.8 && ypos >= y_axis + 2 && ypos <= y_axis + 10 || x_axis >= xpos - 7 && x_axis <= xpos - 1.8 && ypos >= y_axis + 2) {
		block_speed = 0;
	}
	if (x_axis >= xpos - 13.5 && x_axis <= xpos - 8.8 && ypos >= y_axis - 1.3 && ypos <= y_axis + 2.5 || ypos <= y_axis + 2.5 && x_axis >= xpos - 13.5 && x_axis <= xpos - 8.8) {//
		block_speed = 0;
	}
	if (x_axis <= xpos - 8.8 && x_axis >= xpos - 13.5 && ypos >= y_axis + 8 && ypos <= y_axis + 10 || ypos >= y_axis + 6 && x_axis >= xpos - 13.5 && x_axis <= xpos - 8.8) {
		block_speed = 0;
	}
	if (x_axis <= xpos - 16.8 && x_axis >= xpos - 21.8 && ypos >= y_axis && ypos <= y_axis + 10) {
		block_speed = 0;
	}
	if (x_axis <= xpos - 25 && x_axis >= xpos - 31.5 && ypos >= y_axis - 1.3 && ypos <= y_axis + 4 || ypos <= y_axis + 9 && x_axis <= xpos - 25 && x_axis >= xpos - 31.5) {
		block_speed = 0;
	}
	if (x_axis <= xpos - 34 && x_axis >= xpos - 40 && ypos >= b_speed && ypos <= b_speed || ypos >= b_speed + 1 && x_axis <= xpos - 34 && x_axis >= xpos - 40) {
		b = 0;
		block_speed = 0;

	}
	glutPostRedisplay();
}
void display() {
	background();

	if (sc_x == 1 && sc_y == 1 && angle == 0) {
		glPushMatrix();
		glTranslatef(xpos, ypos, 0);
		glScalef(sc_x, sc_y, 0);
		glTranslatef(0.5, 2.8, 0);
		glRotatef(angle, 0, 0, 1);
		glTranslatef(-0.5, -2.8, 0);
		bull();
		glPopMatrix();
		Game_Over();

	}
	else if (sc_x == 0.5 && sc_y == 0.5) {
		glPushMatrix();
		glTranslatef(xpos, ypos, 0);
		glScalef(sc_x, sc_y, 0);
		bull();
		glPopMatrix();
		Game_Over2();
	}
	else if (angle == -90) {
		glPushMatrix();
		glTranslatef(xpos, ypos, 0);
		glTranslatef(2.8, 2.8, 0);
		glRotatef(angle, 0, 0, 1);
		glTranslatef(-2.8, -2.8, 0);
		bull();
		glPopMatrix();
		Game_Over3();

	}
	block();
	moving_block();
	glFlush();
	glutPostRedisplay();

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(1100, 600);

	glutInitWindowPosition(200, 200);
	glutCreateWindow("Cartoon");
	gluOrtho2D(0, 16, 0, 16);
	glutSpecialFunc(spec_key);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}