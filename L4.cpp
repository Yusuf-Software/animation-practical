#include<GL/glut.h>


void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1000.0, 1000.0, -600.0, 600.0);

}

void triangleMaker()
{
    glBegin(GL_TRIANGLE_FAN);

    
    glVertex2i(363, 150);
    glVertex2i(284, 240);
    glVertex2i(268, 150);
    glVertex2i(188, 240);
    glVertex2i(150, 150);
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2i(97, 240);
    glVertex2i(35, 150);

    glEnd();
}

void GL_display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glPointSize(4.0);
 
    glColor3f(1.0, 0.0, 0.0);
    triangleMaker();

    /*glTranslated(-100, 6, 0);
    triangleMaker();*/

    /*glColor3f(0.0, 1.0, 0.0);
    glTranslated(363, 150, 0);
    glRotated(45, 0, 0, 1);
    triangleMaker();*/

    glColor3f(0.0, 0.0, 1.0);
    glScaled(-0.5, -0.5, 1);
    triangleMaker();


    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("User Controlled Transformations");
    init();
    glutDisplayFunc(GL_display);
    glutMainLoop();
}
