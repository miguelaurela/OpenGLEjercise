#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

static float Xvalor = 0.0, Yvalor = 0.0; // Coordienadas de la esfera.
static float Angulo = 0.0; // Angulo para rotar la esfera.

void pintarEscena(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();

	// Configurar la posicion de la esfera.
	glTranslatef(Xvalor, Yvalor, -5.0);
	glRotatef(Angulo, 1.0, 1.0, 1.0);

	glColor3f(0.0, 0.0, 0.0);
	glutWireSphere(0.5, 16, 10);

	glutSwapBuffers();
}

// Rutina de inicialización.
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'r':
		Xvalor = Yvalor = Angulo = 0.0;
		glutPostRedisplay();
		break;
	case ' ':
		Angulo += 10.0;
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

void specialKeyInput(int key, int x, int y)
{
	if (key == GLUT_KEY_UP) Yvalor += 0.1;
	if (key == GLUT_KEY_DOWN) Yvalor -= 0.1;
	if (key == GLUT_KEY_LEFT) Xvalor -= 0.1;
	if (key == GLUT_KEY_RIGHT) Xvalor += 0.1;
	glutPostRedisplay();
}


void printInteraction(void)
{
	std::cout << "Interacción:" << std::endl;
	std::cout << "Presione las teclas de flecha para mover la esfera." << std::endl
		<< "Presione la barra espaciadorea para rotar la esfera." << std::endl
		<< "Presione r to resetear." << std::endl;
}

// Main routina.
int main2(int argc, char** argv)
{
	printInteraction();
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Mover Esfera");
	glutDisplayFunc(pintarEscena);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	// Registre la función de devolución de llamada para la entrada de teclas no ASCII. 
	glutSpecialFunc(specialKeyInput);
	setup();

	glutMainLoop();
}
