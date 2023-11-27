// latest with rotate
//#include <windows.h> // for MS Windows

#include <GL/glut.h> // GLUT, include glu.h and gl.h

GLfloat anglePyrmaid = 0.0f;
GLfloat rotAngle = 0.0f;

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void GL_reshape(int width, int height) {
    if (height == 0)
        height = 1;

    if (width == 0)
        width = 1;

    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-1, 1, 1, 1, 1, 1); //for 3d don't use  glOrtho2D
    gluPerspective(65.0f, (GLsizei)width / (GLsizei)height, 0.1f, 120.0f);
}

void GL_display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -6.0f);
    glTranslatef(0.0f, 0.0f, -6.0f);
    glRotatef(anglePyrmaid, 0.0f, 1.0f, 0.0f);

    // Front face: RED
    glPushMatrix();

    glTranslatef(-1, -1, 1);
    glRotatef(rotAngle, 1, 0, 0);
    glTranslatef(1, 1, -1);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    glEnd();
    glPopMatrix();

    // Right face: Blue
    glPushMatrix();

    glTranslatef(1, -1, -1);
    glRotatef(rotAngle, 0, 0, -1);
    glTranslatef(-1, 1, 1);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.0f, 1.0f);

    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();
    glPopMatrix();

    // Back face: Green
    glPushMatrix();

    glTranslatef(1, -1, -1);
    glRotatef(rotAngle, -1, 0, 0);
    glTranslatef(-1, 1, 1);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 1.0f, 0.0f);

    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glEnd();

    glPopMatrix();

    // Left face: Yellow
    glPushMatrix();

    glTranslatef(-1, -1, 1);
    glRotatef(rotAngle, 0, 0, 1);
    glTranslatef(1, 1, -1);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f);

    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glEnd();
    glPopMatrix();

    // Base
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);

    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);

    glEnd();

    glutSwapBuffers();
}

void GL_keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'o':
        // Perform all translations with the 'o' key
        if (rotAngle < 120)
            rotAngle += 10.0f;
        break;
    case 'u':
        // Undo the previous translations with the 'u' key
        if (rotAngle > 0)
            rotAngle -= 10.0f;
        break;
    }
    glutPostRedisplay();
}


void GL_animate() {
    // anglePyrmaid = -30.0f;
    anglePyrmaid += 0.9f;
    if (anglePyrmaid >= 360.0f) {
        anglePyrmaid = 0.0f;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("3D Opening Pyramid ");

    // Calling the functions
    init();
    glutDisplayFunc(GL_display);
    glutReshapeFunc(GL_reshape);
    glutIdleFunc(GL_animate);
    glutKeyboardFunc(GL_keyboard);
    glutMainLoop();

    return 0;
}
