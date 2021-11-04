#include <stdlib.h>
#include <GL/glut.h>

void init(void)
{
	GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat position[] = { 0.0, 3.0, 2.0, 0.0 };
	GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat local_view[] = { 0.0 };

	glClearColor(0.0, 0.1, 0.1, 0.0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void display(void)
{
	GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };
	GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat no_shininess[] = { 0.0 };
	GLfloat low_shininess[] = { 5.0 };
	GLfloat high_shininess[] = { 100.0 };
	GLfloat mat_emission[] = { 0.3, 0.2, 0.2, 0.0 };

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* dibujar esfera en la primera fila, primera columna
	*  solo reflexión difusa; sin ambiente o especular
    */
	glPushMatrix();
	glTranslatef(-3.75, 3.0, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glutSolidSphere(1.0, 16, 16);
	glPopMatrix();


	/* dibujar esfera en la primera fila, segunda columna
	*  reflexión difusa y especular; brillo bajo; sin ambiente
	*/

	glPushMatrix();
	glTranslatef(-1.25, 3.0, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glutSolidSphere(1.0, 16, 16);
	glPopMatrix();


	/* dibujar esfera en la primera fila, tercera columna
	* reflexión difusa y especular; alto brillo sin ambiente
	*/

	/* dibujar esfera en la primera fila, cuarta columna
	* reflexión difusa; emisión; sin reflexión ambiental o especular
	*/

	/* dibujar esfera en la segunda fila, primera columna
	* Reflexión ambiental y difusa; no especular
	*/

	/* dibujar esfera en la segunda fila, segunda columna
	* Reflexión ambiental, difusa y especular; brillo bajo
	*/

	/* dibujar esfera en la segunda fila, tercera columna
	* Reflexión ambiental, difusa y especular; alto brillo
	*/

	/*dibujar esfera en la segunda fila, cuarta columna
	* Reflexión ambiental y difusa; emisión; no especular
	*/

	/* dibujar esfera en la tercera fila, primera columna
	 * ambiente coloreado y reflexión difusa; no especular
	*/

	/* dibujar esfera en la tercera fila, segunda columna
	 * reflexión ambiental, difusa y especular coloreada; brillo bajo
	*/

	/* dibujar esfera en la tercera fila, tercera columna
	* reflexión ambiental, difusa y especular coloreada; alto brillo
	*/

	/* dibujar esfera en la tercera fila, cuarta columna
	 * ambiente coloreado y reflexión difusa; emisión; no especular
	*/

	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= (h * 2))
		glOrtho(-6.0, 6.0, -3.0 * ((GLfloat)h * 2) / (GLfloat)w,
			3.0 * ((GLfloat)h * 2) / (GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-6.0 * (GLfloat)w / ((GLfloat)h * 2),
			6.0 * (GLfloat)w / ((GLfloat)h * 2), -3.0, 3.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		exit(0);
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 450);
	glutCreateWindow(argv[0]);
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
