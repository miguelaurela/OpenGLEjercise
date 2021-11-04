#include<stdio.h>
#include<stdlib.h>
#include <GL/glut.h>
#include<math.h>
#include<time.h>
#include<windows.h>


int w = 800, h = 800;

double rx = 0, ry = 0, rz = 0, px = 0, py = 0, pz = 0;
#define PI 3.1416

float anglMercurio = 0.0;

GLfloat sx = 0.2, sy = 0.2, sz = 0.2;

int planeta1;

GLfloat negro[] = { 0.0f,0.0f,0.0f,1.0f };
GLfloat amarillo[] = { 0.7f,0.2f,0.0f,1.0f };
GLfloat Ambiente[] = { 0.1,0.1,0.1,1.0 };
GLfloat Difusa[] = { 1.0,1.0,1.0,1.0 };
GLfloat Especular[] = { .50,.50,.50,.10 };
GLfloat Posicion[] = { 0,0,0,0.1 };

GLfloat General[1] = { 10 };
GLfloat sc[1] = { 2 + General[1] };
GLfloat scVenus[1] = {20 + General[1] };
GLfloat scTierra[1] = { 35+ General[1] };
GLfloat scMartes[1] = { 55+ General[1] };
GLfloat scJupiter[1] = { 80 + General[1] };
GLfloat scSaturno[1] = { 100+ General[1] };
GLfloat scUrano[1] = { 120+ General[1] };
GLfloat scNeptuno[1] = { 140+ General[1] };
GLfloat scPluto[1] = { 160+ General[1] };

double ang = 2 * PI / 300;
double angular = 2 * PI / 50;
//PARCIAL2  MIGUEL AURELA Y ANDREA MIRANDA
void reshape(int w, int h) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)h / (GLfloat)w, 1, 300);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void orbitaMercurio()
{
	//Linea de orbita
	glColor3f(1, 1, 1);

	int i = 0;
	for (i = 0; i < 1; i++) {
		glPushMatrix();
		if (i == 5)
		{
			glRotatef(45, 1.0, 0.0, 0.0);
		}
		else
		{
			glRotatef(63, 2.0, 0.0, 0.0);
		}
		glScalef(sc[i], sc[i], sc[i]);
		glBegin(GL_POINTS);
		double ang1 = 0.0;
		int i = 0;
		for (i = 0; i < 300; i++)
		{
			glVertex2d(cos(ang1), sin(ang1));
			ang1 += ang;
		}
		glEnd();
		glPopMatrix();
	}
}
void orbitaVenus()
{
	//Linea de orbita
	glColor3f(1, 1, 1);

	int i = 0;
	for (i = 0; i < 1; i++) {
		glPushMatrix();
		if (i == 5)
		{
			glRotatef(45, 1.0, 0.0, 0.0);
		}
		else
		{
			glRotatef(63, 2.0, 0.0, 0.0);
		}
		glScalef(scVenus[i], scVenus[i], scVenus[i]);
		glBegin(GL_POINTS);
		double ang1 = 0.0;
		int i = 0;
		for (i = 0; i < 300; i++)
		{
			glVertex2d(cos(ang1), sin(ang1));
			ang1 += ang;
		}
		glEnd();
		glPopMatrix();
	}
}
void orbitaTierra()
{
	//Linea de orbita
	glColor3f(1, 1, 1);

	int i = 0;
	for (i = 0; i < 1; i++) {
		glPushMatrix();
		if (i == 5)
		{
			glRotatef(45, 1.0, 0.0, 0.0);
		}
		else
		{
			glRotatef(63, 2.0, 0.0, 0.0);
		}
		glScalef(scTierra[i], scTierra[i], scTierra[i]);
		glBegin(GL_POINTS);
		double ang1 = 0.0;
		int i = 0;
		for (i = 0; i < 300; i++)
		{
			glVertex2d(cos(ang1), sin(ang1));
			ang1 += ang;
		}
		glEnd();
		glPopMatrix();
	}
}
void orbitaMarte()
{
	//Linea de orbita
	glColor3f(1, 1, 1);

	int i = 0;
	for (i = 0; i < 1; i++) {
		glPushMatrix();
		if (i == 5)
		{
			glRotatef(45, 1.0, 0.0, 0.0);
		}
		else
		{
			glRotatef(63, 2.0, 0.0, 0.0);
		}
		glScalef(scMartes[i], scMartes[i], scMartes[i]);
		glBegin(GL_POINTS);
		double ang1 = 0.0;
		int i = 0;
		for (i = 0; i < 300; i++)
		{
			glVertex2d(cos(ang1), sin(ang1));
			ang1 += ang;
		}
		glEnd();
		glPopMatrix();
	}
}
void orbitaJupiter()
{
	//Linea de orbita
	glColor3f(1, 1, 1);

	int i = 0;
	for (i = 0; i < 1; i++) {
		glPushMatrix();
		if (i == 5)
		{
			glRotatef(45, 1.0, 0.0, 0.0);
		}
		else
		{
			glRotatef(63, 2.0, 0.0, 0.0);
		}
		glScalef(scJupiter[i], scJupiter[i], scJupiter[i]);
		glBegin(GL_POINTS);
		double ang1 = 0.0;
		int i = 0;
		for (i = 0; i < 300; i++)
		{
			glVertex2d(cos(ang1), sin(ang1));
			ang1 += ang;
		}
		glEnd();
		glPopMatrix();
	}
}
void orbitaSaturno()
{
	//Linea de orbita
	glColor3f(1, 1, 1);

	int i = 0;
	for (i = 0; i < 1; i++) {
		glPushMatrix();
		if (i == 5)
		{
			glRotatef(45, 1.0, 0.0, 0.0);
		}
		else
		{
			glRotatef(63, 2.0, 0.0, 0.0);
		}
		glScalef(scSaturno[i], scSaturno[i], scSaturno[i]);
		glBegin(GL_POINTS);
		double ang1 = 0.0;
		int i = 0;
		for (i = 0; i < 300; i++)
		{
			glVertex2d(cos(ang1), sin(ang1));
			ang1 += ang;
		}
		glEnd();
		glPopMatrix();
	}
}
void orbitaUrano()
{
	//Linea de orbita
	glColor3f(1, 1, 1);

	int i = 0;
	for (i = 0; i < 1; i++) {
		glPushMatrix();
		if (i == 5)
		{
			glRotatef(45, 1.0, 0.0, 0.0);
		}
		else
		{
			glRotatef(63, 2.0, 0.0, 0.0);
		}
		glScalef(scUrano[i], scUrano[i], scUrano[i]);
		glBegin(GL_POINTS);
		double ang1 = 0.0;
		int i = 0;
		for (i = 0; i < 300; i++)
		{
			glVertex2d(cos(ang1), sin(ang1));
			ang1 += ang;
		}
		glEnd();
		glPopMatrix();
	}
}
void orbitaNeptuno()
{
	//Linea de orbita
	glColor3f(1, 1, 1);

	int i = 0;
	for (i = 0; i < 1; i++) {
		glPushMatrix();
		if (i == 5)
		{
			glRotatef(45, 1.0, 0.0, 0.0);
		}
		else
		{
			glRotatef(63, 2.0, 0.0, 0.0);
		}
		glScalef(scNeptuno[i], scNeptuno[i], scNeptuno[i]);
		glBegin(GL_POINTS);
		double ang1 = 0.0;
		int i = 0;
		for (i = 0; i < 300; i++)
		{
			glVertex2d(cos(ang1), sin(ang1));
			ang1 += ang;
		}
		glEnd();
		glPopMatrix();
	}
}
void orbitaPluto()
{
	//Linea de orbita
	glColor3f(1, 1, 1);

	int i = 0;
	for (i = 0; i < 1; i++) {
		glPushMatrix();
		if (i == 5)
		{
			glRotatef(45, 1.0, 0.0, 0.0);
		}
		else
		{
			glRotatef(63, 2.0, 0.0, 0.0);
		}
		glScalef(scPluto[i], scPluto[i], scPluto[i]);
		glBegin(GL_POINTS);
		double ang1 = 0.0;
		int i = 0;
		for (i = 0; i < 300; i++)
		{
			glVertex2d(cos(ang1), sin(ang1));
			ang1 += ang;
		}
		glEnd();
		glPopMatrix();
	}
}
void esfera(double radio, int longitud, int latitud)
{
	GLUquadricObj* q = gluNewQuadric();
	gluQuadricDrawStyle(q, GLU_FILL);
	gluQuadricNormals(q, GLU_SMOOTH);
	gluQuadricTexture(q, GL_TRUE);
	gluSphere(q, radio, longitud, latitud);
	gluDeleteQuadric(q);
}
void init()
{
	glClearColor(0, 0, 0, 0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(-10 + rx, 9 + ry, -10 + rz, px, py, pz, 0.0, 1.0, 0.0);
	glPushMatrix();


	for (float i = -100; i < 100; i += 1.1) {
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_LINE_STRIP);
		glVertex3f(i, 0, -100);
		glVertex3f(i, 0, 100);
		glEnd();
	}

	for (float i = -100; i < 100; i += 1.1) {
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_LINE_STRIP);
		glVertex3f(-100, 0, i);
		glVertex3f(100, 0, i);
		glEnd();
	}

	//Ejes
	//y
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_LINE_STRIP);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 100, 0);
	glEnd();
	//x
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_LINE_STRIP);
	glVertex3f(0, 0, 0);
	glVertex3f(100, 0, 0);
	glEnd();

	//z
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_LINE_STRIP);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 100);
	glEnd();

	//Objetos
	//glColor3f(0.0f, 1.0f, 0.0f);
	//glutSolidTeapot(1);
	/*glTranslatef(7, 1, 0);
	glutSolidCube(1);
	glTranslatef(15, 0, 9);
	glutSolidSphere(1, 30, 30);
	glTranslatef(-10, 0, 5);
	glutSolidTetrahedron();*/
	//glPopMatrix();
	//glutSwapBuffers();
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//glTranslatef(20, 0.0, 0.0);
	orbitaMercurio();
	
	
	
	//glPopMatrix();
	//glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	//glPushMatrix();
	glColor3f(1, 1, 0.3);

	//>>>>>>>> > SOL
	glScalef(sx, sy, sz);
	glLightfv(GL_LIGHT7, GL_POSITION, Posicion);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, amarillo);
	esfera(15, 50, 50);//------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>SOL
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, negro);
	glPopMatrix();

	glScalef(0.2, 0.2, 0.2);
	glPushMatrix();
	glRotatef(anglMercurio, 0.0, 1.0, -0.5);
	glTranslatef(25, 0.0, 0.0);
	glColor3f(1.0, 0.9, 0.0);

	glScalef(0.4, 0.4, 0.4);
	esfera(5, 50, 50);//------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>MERCURIO (1)
	//glPopMatrix();

	glPushMatrix();
	//orbitaVenus();

	glPopMatrix();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glPushMatrix();


	//orbitaVenus();
	glTranslatef(30, 0.0, 0.0);
	glColor3f(1, 0.5, 0.0);

	glScalef(0.4, 0.4, 0.4);
	
	esfera(15, 100, 50);//------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>VENUS (1)
	

	glPopMatrix();
	//orbitaVenus();
	glRotatef(anglMercurio, 0.0, 1.0, -0.5);
	glTranslatef(13, 0.0, 0.0);
	esfera(2, 100, 50);
	glPopMatrix();

	
	orbitaTierra();
	orbitaMarte();
	orbitaJupiter();
	orbitaSaturno();
	orbitaUrano();
	orbitaNeptuno();
	orbitaPluto();
	glColor3f(0, 0.5, 0.0);//Color Tierra
	glRotatef(anglMercurio, 0.0, 1.0, -0.5);
	glTranslatef(55, 0.0, 0.0);
	esfera(4, 100, 50);//TIERRA
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);//LUNA
	glRotatef(anglMercurio, 0.0, 1.0, -0.5);
	glTranslatef(7, 0.0, 0.0);
	esfera(1, 100, 50);
	glPopMatrix();

	
	
	glColor3f(0.5, 0, 0.0);//MARTE
	glTranslatef(20, 0.0, 0.0);
	esfera(3, 100, 50);
	glPopMatrix();

	//glPushMatrix();//JUPITER
	glColor3f(0.5, 0.5, 0.3);
	glTranslatef(25, 0.0, 0.0);
	esfera(6, 100, 50);
	glPopMatrix();

	glPushMatrix(); 
	glColor3f(0.5, 0.5, 0.5);//LUNA 1 //JUPITER
	glRotatef(anglMercurio, 0.0, 1.0, -0.5);
	glTranslatef(20, 0.0, 0.0);
	esfera(1, 100, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);//LUNA 2 //JUPITER
	glRotatef(anglMercurio, 0.0, 1.0, -0.5);
	glTranslatef(15, 0.0, 0.0);
	esfera(0.7, 100, 50);
	glPopMatrix();
	

	glColor3f(0.4, 0.4, 0.3);//NEPTUNO
	glTranslatef(20, 0.0, 0.0);
	esfera(5, 100, 50);
	glPopMatrix();

	glColor3f(0.4, 0.4, 0.8);//Urano
	glTranslatef(20, 0.0, 0.0);
	esfera(4, 100, 50);
	glPopMatrix();

	glColor3f(0.5, 0.7, 0.8);//PLutón
	glTranslatef(20, 0.0, 0.0);
	esfera(2, 100, 50);
	glPopMatrix();

	glPopMatrix();
	glutSwapBuffers();

}/*
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(-10 + rx, 9 + ry, -10 + rz, px, py, pz, 0.0, 1.0, 0.0);
	glPushMatrix();

	
	orbitaMercurio();
	//glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glPushMatrix();
	glColor3f(0.7, 0.5, 0.0);

	glScalef(sx, sy, sz);
	glLightfv(GL_LIGHT7, GL_POSITION, Posicion);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, amarillo);
	esfera(5, 50, 50);//------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>SOL
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, negro);
	glPopMatrix();

	glScalef(0.2, 0.2, 0.2);
	glPushMatrix();
	glRotatef(anglMercurio, 0.0, 1.0, -0.5);
	glTranslatef(50, 0.0, 0.0);
	glColor3f(1.0, 0.9, 0.0);

	glScalef(0.4, 0.4, 0.4);
	esfera(5, 50, 50);//------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>MERCURIO(2)
	//glPopMatrix();

	glPushMatrix();
	orbitaVenus();

	glPopMatrix();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(1, 0.5, 0.0);
	glPushMatrix();

	glTranslatef(50, 0.0, 0.0);

	glScalef(0.4, 0.4, 0.4);
	esfera(20, 500, 50);
	glPopMatrix();

	glPopMatrix();
	glutSwapBuffers();

}*/
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
		//eje x
	case 'd':
		rx = rx + 0.2;
		break;

	case 'a':
		rx = rx - 0.2;
		break;

	case 'l':
		px = px + 0.8;
		break;
	case 'j':
		px = px - 0.2;
		break;
		//eje y
	case 'q':
		ry = ry + 0.2;
		break;

	case 'e':
		ry = ry - 0.2;
		break;

	case 'u':
		py = py + 0.2;
		break;

	case 'o':
		py = py - 0.2;
		break;

	case 49: //1
		ry = ry + 0.2;
		py = py + 0.2;
		break;

	case 50: //2
		ry = ry - 0.2;
		py = py - 0.2;
		break;
		//eje z

	case 'w':
		rz = rz + 0.2;
		break;

	case 's':
		rz = rz - 0.2;
		break;

	case 27: // escape
		exit(0);
		break;
	}
	glutPostRedisplay();
}

void flechas(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_RIGHT:
		rx = rx + 0.2;
		px = px + 0.2;
		break;
	case GLUT_KEY_LEFT:
		rx = rx - 0.2;
		px = px - 0.2;
		break;
	case GLUT_KEY_UP:
		rz = rz + 0.2;
		pz = pz + 0.2;
		break;

	case GLUT_KEY_DOWN:
		rz = rz - 0.2;
		pz = pz - 0.2;
		break;
	}
	glutPostRedisplay();
}
void update(int value) {

	anglMercurio += 2;
	if (anglMercurio > 360) {
		anglMercurio -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(20, update, 0);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(w, h);
	glutCreateWindow("Volumen de Vista");
	init();
	glutDisplayFunc(display);
	glutSpecialFunc(flechas);
	glutReshapeFunc(reshape);
	glutTimerFunc(25, update, 0);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
