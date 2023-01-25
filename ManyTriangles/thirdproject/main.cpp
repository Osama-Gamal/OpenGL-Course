#include<GL/freeglut.h>
void display(){
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);

    glColor3f(1.0,0.0,0.0);
    glVertex3f(-0.9,0.1,0.0);
    glVertex3f(-0.1,0.1,0.0);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-0.5,0.8,0.0);

    glColor3f(0.0,1.0,0.0);
    glVertex3f(-0.9,-0.1,0.0);
    glVertex3f(-0.1,-0.1,0.0);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-0.5,-0.8,0.0);

    glColor3f(0.0,0.0,1.0);
    glVertex3f(0.9,0.1,0.0);
    glVertex3f(0.1,0.1,0.0);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(0.5,0.8,0.0);

    glColor3f(1.0,1.0,0.0);
    glVertex3f(0.9,-0.1,0.0);
    glVertex3f(0.1,-0.1,0.0);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(0.5,-0.8,0.0);


    glEnd();


     glFlush();

}
int main(int argc,char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

glutInitWindowPosition(100,100);
glutInitWindowSize(600,400);
glutCreateWindow("My First GL Program");

glutDisplayFunc(display);

glutMainLoop();

return 0;
}
