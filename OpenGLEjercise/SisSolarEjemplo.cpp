#include<stdio.h>
#include<stdlib.h>
#include <GL/glut.h>
#include<math.h>
#include<time.h>
#include<windows.h>
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
GLfloat sc[1] = { 0.295 };

double ang = 2 * PI / 300;
double angular = 2 * PI / 50;

void initLighting()
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT7);

    glLightfv(GL_LIGHT7, GL_AMBIENT, Ambiente);
    glLightfv(GL_LIGHT7, GL_DIFFUSE, Difusa);
    glLightfv(GL_LIGHT7, GL_SPECULAR, Especular);
}
void myinit()
{
    glClearColor(0.0, 0.0, 0.0, 0.0); //backgroundcolor es verde
    //gluOrtho2D(0,699,0,699);
    glPointSize(1.0);
    glLineWidth(2.0);
}

void background()
{
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.00, 0.00);
    glVertex3f(-01.00, 01.00, 1);
    glColor3f(.20, 0.0, 0.70);
    glVertex3f(01.00, 1.00, 1);
    glColor3f(0, 0.0, 0.0);
    glVertex3f(1.00, -1.00, 1);
    glColor3f(.70, .10, .20);
    glVertex3f(-1.00, -1.00, 1);
    glEnd();
}

void orbita()
{
    glColor3f(0.5, 0.5, 0.5);

    int i = 0;
    for (i = 0; i < 1; i++) {
        glPushMatrix();
        if (i == 5)
        {
            glRotatef(45, 1.0, 0.0, 0.0);
        }
        else
        {
            glRotatef(63, 1.0, 0.0, 0.0);
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

void esfera(double radio, int longitud, int latitud)
{
    GLUquadricObj* q = gluNewQuadric();
    gluQuadricDrawStyle(q, GLU_FILL);
    gluQuadricNormals(q, GLU_SMOOTH);
    gluQuadricTexture(q, GL_TRUE);
    gluSphere(q, radio, longitud, latitud);
    gluDeleteQuadric(q);
}

void draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //background();
    orbita();
    glPushMatrix();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glPushMatrix();
    glColor3f(0.7, 0.5, 0.0);
    glScalef(sx, sy, sz);
    glLightfv(GL_LIGHT7, GL_POSITION, Posicion);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, amarillo);
    esfera(1, 50, 50);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, negro);
    glPopMatrix();

    glScalef(0.2, 0.2, 0.2);
    glPushMatrix();
    glRotatef(anglMercurio, 0.0, 1.0, -0.5);
    glTranslatef(1.5, 0.0, 0.0);
    glColor3f(1.0, 0.9, 0.0);
    glScalef(0.08, 0.08, 0.08);
    esfera(1, 50, 50);
    glPopMatrix();

    glPopMatrix();
    glFlush();
}

void update(int value) {

    anglMercurio += 2;
    if (anglMercurio > 360) {
        anglMercurio -= 360;
    }

    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Sistema Solar");
    initLighting();
    myinit();
    glutDisplayFunc(draw);
    glutTimerFunc(25, update, 0);
    glutMainLoop();
    return 0;
}