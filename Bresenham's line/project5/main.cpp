#include<GL/freeglut.h>
#include<stdio.h>
int first = 0;
int xs,ys ,xf ,yf;
char initialpoint[10],finalpoint[10];

void *font =GLUT_BITMAP_HELVETICA_10;
void showstring(int x,int y, char *string){
glRasterPos2i(x ,y);
int str_length=(int) strlen(string);
for(int i=0; i<=str_length;i++)
    glutBitmapCharacter(font,string[i]);



}

void drawpixel(GLint x,GLint y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}
void bresenham(int x1,int y1,int x2, int y2){
 int dx,dy,p0;
 dx =x2-x1;
 dy =y2-y1;
 int Xinc =(dx<0)?-1:1;
 int Yinc =(dy<0)?-1:1;
 dx=abs(dx);
 dy=abs(dy);
 int xk=x1;
 int yk=y1;
 if (dy<dx){
    p0=2*dy-dx;
    drawpixel(x1,y1);
    for(int k=x1;k<=x2;k++){
    if(p0<0){

        drawpixel(++xk, yk);
        p0+=2*dy;
    }

 else{

     drawpixel(++xk, yk=yk+Yinc);
        p0+=2*dy-2*dx;

 }
    }

}
else{
    p0=2*dx-dy;
    drawpixel(x1,y1);
    for(int k=y1;k<=y2;k++){
    if(p0<0){

        drawpixel(xk, ++yk);
        p0+2*dx;
    }

 else{

     drawpixel(xk=xk+Xinc, ++yk);
        p0+=2*dx-2*dy;

 }
    }


}
}
void display(void)
{

     glClearColor(0.0f, 0.5f, 0.5f, 0.0f);
  glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f);

    showstring(xs+5,ys,initialpoint);
    showstring(xf+5,yf,finalpoint);

    if(first==0){
        int dx=xf-xs;
        int dy =yf-ys;
        if(abs(dy<abs(dx))){
            if(xs<xf)
            bresenham(xs,ys,xf,yf);
            else
                 bresenham(xf,yf,xs,ys);


        }
        else{
            if(ys<yf)
                 bresenham(xs,ys,xf,yf);
            else
                 bresenham(xf,yf,xs,ys);

        }

    }

    glFlush();

}

void mouse (int btn, int state, int x, int y){

if(btn==GLUT_LEFT_BUTTON &&state == GLUT_DOWN)
{
    switch(first){
    case 0:
        sprintf(initialpoint," ");
        sprintf(finalpoint," ");
        xs=x;
        ys=600-y;
        sprintf(initialpoint,"(%d,%d)",xs,ys);
        first=1;
        break;
    case 1:
        xf=x;
        yf=600-y;
        sprintf(finalpoint,"(%d,%d)",xf,yf);
        first=0;
        break;




    }

    drawpixel(x,600-y);

}
}
int main (int argc ,char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(0,0);
glutInitWindowSize(800,600);


glutCreateWindow("Bresenham's LDA");
gluOrtho2D(0,800,0,600);

 glClearColor(1.0f, 1.0f, 0.0f, 0.0f);
 glClear(GL_COLOR_BUFFER_BIT);

glutDisplayFunc(display);
glutMouseFunc(mouse);
glutMainLoop();
return 0;


}
