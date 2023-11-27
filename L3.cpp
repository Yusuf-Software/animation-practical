#include<GL/glut.h>


void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 400.0, 0.0, 400.0);

}

void GL_display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glPointSize(4.0);


    // glBegin(GL_LINES);
    // glVertex2i(40, 20);
    // glVertex2i(70, 20);
    // glVertex2i(90, 50);
    // glVertex2i(70, 90);
    // glVertex2i(40, 90);
    // glVertex2i(10, 50);



    // glBegin(GL_TRIANGLE_STRIP);
    // glColor3f(1.0, 0.0, 0.0);
    // glVertex2i(350, 250);
    // glVertex2i(295, 150);
    // glVertex2i(257, 220);
    // glVertex2i(187, 148);
    // glVertex2i(156, 232);
    // glBegin(GL_LINE_STRIP);
    // glColor3f(1.0, 1.0, 0.0);
    // glVertex2i(85, 175);
    // glVertex2i(35, 240);    


    //glBegin(GL_TRIANGLE_FAN);
    //glColor3f(1.0, 0.0, 0.0);
    //glVertex2i(354, 110);
    //glVertex2i(292, 253);
    //glVertex2i(240, 110);
    //glVertex2i(200, 253);
    //glVertex2i(121, 110);
    //glBegin(GL_LINE_STRIP);
    //glColor3f(1.0, 1.0, 0.0);
    //glVertex2i(105, 253);
    // glVertex2i(25, 110); 


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 0.0, 0.0);
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
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("User Controlled Transformations");
    init();
    glutDisplayFunc(GL_display);
    glutMainLoop();
}
