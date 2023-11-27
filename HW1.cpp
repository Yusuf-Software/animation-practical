// original


#include <iostream>
#include <GL/glut.h>

void Quad() {
	glBegin(GL_QUADS);
	glVertex2i(-20, 10);
	glVertex2i(25, 15);
	glVertex2i(15, -20);
	glVertex2i(-15, -15);
	glEnd();
}

void QuadStrip() {
	glBegin(GL_QUAD_STRIP);

	glColor3f(0.2, 0.5, 0.8);  // Blueish
	glVertex2i(-25, 20);
	glColor3f(0.8, 0.1, 0.2);  // Reddish
	glVertex2i(20, 25);
	glColor3f(0.1, 0.7, 0.2);  // Greenish
	glVertex2i(-15, -20);
	glColor3f(0.9, 0.9, 0.2);  // Yellowish
	glVertex2i(15, -15);

	glColor3f(0.2, 0.5, 0.8);  // Blueish
	glVertex2i(-25, 20);
	glColor3f(0.8, 0.1, 0.2);  // Reddish
	glVertex2i(20, 25);
	glColor3f(0.1, 0.7, 0.2);  // Greenish
	glVertex2i(-15, -15);
	glColor3f(0.9, 0.9, 0.2);  // Yellowish
	glVertex2i(15, -20);

	glEnd();
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void GL_display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();

	glLineWidth(2);

	QuadStrip();

	glColor3f(0.8, 0.1, 0.2);  // Reddish
	glTranslatef(-45.0, 0.0, 0.0);
	Quad();

	glPushMatrix();
	glTranslatef(-20, 10, 0.0);
	glRotatef(160.0, 0.0, 0.0, 1.0);
	glTranslatef(20, -10, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	Quad();
	glPopMatrix();

	glTranslatef(15, -20.0, 0.0);
	glScalef(-0.5, -0.5, 1.0);
	glColor3f(0.2, 0.7, 0.8);  // Bluish-greenish
	glTranslatef(-15.0, 20.0, 0.0);
	Quad();

	glPopMatrix();
	glutSwapBuffers();
}

void GL_reshape(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-70, 70, -70, 70);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("User Controlled Transformations");
	init();
	glutDisplayFunc(GL_display);
	glutReshapeFunc(GL_reshape);
	glutMainLoop();
	return 0;
}
