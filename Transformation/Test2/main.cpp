#include<windows.h>
#include<GL/freeglut.h>
GLfloat angle=0.0f;
void display() {
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW) ;

glLoadIdentity();
glTranslatef(0.0f, 0.0f, -5.0f);
   glRotatef(angle,0.0f ,1.0f, 1.0f);

   glBegin(GL_QUADS);



glColor3f (0.0f, 0.5f,0.0f);
glVertex3f(0.0f, 1.0f, 0.0f);
glColor3f (1.0f, 1.0f,0.0f);
glVertex3f(-1.0f, -1.0f, 1.0f);
glColor3f (0.0f, 0.0f,0.5f);
glVertex3f(1.0f, -1.0f, 1.0f);

glColor3f (0.5f, 0.5f,0.5f);
glVertex3f(0.0f, 1.0f, 0.0f);
glColor3f (0.0f, 0.0f,1.0f);//
glVertex3f(1.0f, -1.0f, -1.0f);
glColor3f (1.0f, 0.0f,1.0f);//
glVertex3f(1.0f, -1.0f, 1.0f);

glColor3f (1.0f, 0.0f,0.0f);
glVertex3f(0.0f, 1.0f, 0.0f);
glColor3f (0.3f, 0.3f,0.3f);
glVertex3f(-1.0f, -1.0f, -1.0f);
glColor3f (0.0f, 1.0f,0.0f);
glVertex3f(-1.0f, -1.0f, 1.0f);


glColor3f (1.0f, 0.5f,0.0f);
glVertex3f(0.0f, 1.0f, 0.0f);
glColor3f (1.0f, 0.0f,1.0f);
glVertex3f(-1.0f, -1.0f, -1.0f);
glColor3f (0.0f, 1.0f,1.0f);
glVertex3f(1.0f, -1.0f, -1.0f);

glEnd();
glutSwapBuffers();
angle+=0.5;

}

void reshape (GLsizei width, GLsizei height)
{
if (height == 0) height = 1;
GLfloat aspect = (GLfloat) width / (GLfloat) height;
glViewport (0,0, width, height);
glMatrixMode (GL_PROJECTION) ;
glLoadIdentity();
gluPerspective(45.0f, aspect, 0.1f, 100.0f);

}
void timer (int value){
glutPostRedisplay();
glutTimerFunc(15,timer,0);

}

int main(int argc, char** argv)
{

glutInit ( &argc, argv);
glutInitDisplayMode (GLUT_DOUBLE) ;
glutInitWindowSize(640, 450);
glutInitWindowPosition (100, 100);
glutCreateWindow("Transformation Example");
glutDisplayFunc (display) ;
glutReshapeFunc (reshape) ;

glClearColor(0.0f,0.0f,0.0f,1.0f);
glClearDepth(1.0f);
glEnable(GL_DEPTH_TEST);
glutTimerFunc(0,timer,0);
glutMainLoop();
return 0;


}
