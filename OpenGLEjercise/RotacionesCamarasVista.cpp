

#include < GL/glut.h>
#include < stdio.h>
#include < stdlib.h>

GLfloat posObjeto = -5.0f;
int lookAt=0;
GLfloat anguloCamaraY = 0.0f;
GLfloat anguloCamaraX = 0.0f;
GLfloat anguloCamaraZ= 0.0f;
GLfloat anguloCamara2Z = 0.0f;
int perspectiva=0;
GLfloat anguloEsfera = 0.0f;
int hazPerspectiva = 0;
int esferaSolida = 0;

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (perspectiva){
        gluPerspective(60.0f, (GLfloat)width/(GLfloat)height, 1.0f, 40.0f);
    }else{
        glOrtho(-10,10,-10,10,1,40);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void pintarEsfera(){
    glColor3f(1.0f, 0.0f, 0.0f);
    glutWireSphere(0.5f,16,16);
}

void pintarTronco(){
    glPushMatrix();
    glTranslatef (0.0f,3.0f,0.0f);
    pintarEsfera();
    glPopMatrix();
    glColor3f(0.8f, 0.8f, 0.8f);
    glScalef(2.0f, 4.0f, 1.0f);
    glutSolidCube(1);
}

// función que muestra por pantalla la escena.
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    ////////////////////////////////////////////
    // movimiento y posicionamiento de la camara.
    ////////////////////////////////////////////
    if (!lookAt){
        glTranslatef(0.0f, 0.0f, posObjeto); // zoom

        // eje horizontal.
        glRotatef(anguloCamaraY, 0.0f, 1.0f, 0.0f);
        // eje vertical.
        glRotatef(anguloCamaraX,1.0f,0.0f,0.0f);
    } else {
        gluLookAt(-5,10,5,0,0,0,1,12,4);
    }
    ////////////////////////////////////////////
    ////////////////////////////////////////////
    glPushMatrix();
    glTranslatef(-5.0f,0.0f,0.0f);
    pintarEsfera();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5.0f,0.0f,0.0f);
    pintarEsfera();
    glPopMatrix();

    glPushMatrix();
    pintarTronco();
    glPopMatrix();

    glutSwapBuffers();
}
void init() {
    glClearColor(0,0,0,0);
    glEnable(GL_DEPTH_TEST);
}

// función que permite interactuar con la escena mediante el teclado
void keyboard(unsigned char key, int x, int y){
    switch(key) {
// SELECCIONAR LA PERSPECTIVA
    case 'p':
    case 'P':
        perspectiva=1;
        reshape(400,400);
        display();
        break;

    case 'o':
    case 'O':
        perspectiva=0;
        reshape(400,400);
        display();
        break;

// ROTAR CAMARA LA DERECHA
    case '1':
        anguloCamaraY++;
        printf("Angulo de rotacion de la camara en torno al eje Y: %i \n",((int)anguloCamaraY % 360));
        display();
        break;
// ROTAR CAMARA LA IZQUIERDA
    case '2':
        anguloCamaraY--;
        printf("Angulo de rotacion de la camara en torno al eje Y: %i \n",((int)anguloCamaraY % 360));
        display();
        break;
// ROTAR CAMARA HACIA ARRIBA
    case '3':
        anguloCamaraX++;
        printf("Angulo de rotacion de la camara en torno al eje X: %i \n",((int)anguloCamaraX % 360));
        display();
        break;
// ROTAR CAMARA HACIA ABAJO
    case '4':
        anguloCamaraX--;
        printf("Angulo de rotacion de la camara en torno al eje X: %i \n",((int)anguloCamaraX % 360));
        display();
        break;
    case '5':
        posObjeto++;
        display();
        break;
    case '6':
        posObjeto--;
        display();
        break;
    case '7':
        if (lookAt==0){
            lookAt=1;
        }else{
            lookAt=0;
        }
        display();
        break;
    case 27: // escape
        exit(0);
        break;
    }
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Cubo");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
