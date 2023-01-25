#include<GL/freeglut.h>
#include<math.h>

struct screen_point_struct{

GLint x,y;
};
class point_on_screen{
private:
    GLint x,y;

public:
    point_on_screen(){
        x=0;
        y=0;

    }
  void setcord(GLint x_val,GLint y_val){

  x=x_val;
  y=y_val;

  }
  GLint X_value()const{
   return x;
  }
  GLint Y_value()const{
   return y;
  }
    void incx(){
    ++x;
    }
void decy(){
    --y;
    }


};
void setpixel(GLint x,GLint y);
void init();
void display();
void MidPointAlg(screen_point_struct center ,GLint radius);
void plotin8octants(screen_point_struct center ,point_on_screen p);

void MidPointAlg(screen_point_struct center ,GLint radius){

    point_on_screen current_point;
    current_point.setcord(0,radius);
    plotin8octants(center,current_point);

    GLint p = 1 - radius;
    while(current_point.X_value()<current_point.Y_value()){

        current_point.incx();
        if(p<0){
            p+=2*current_point.X_value()+1;
        }
        else{
            current_point.decy();
            p+=2*current_point.X_value()+1-2*current_point.Y_value();
        }
         plotin8octants(center,current_point);
    }
}
void plotin8octants(screen_point_struct center ,point_on_screen p){

setpixel(center.x+p.X_value(),center.y+p.Y_value());
setpixel(center.x-p.X_value(),center.y+p.Y_value());
setpixel(center.x+p.X_value(),center.y-p.Y_value());
setpixel(center.x-p.X_value(),center.y-p.Y_value());



setpixel(center.x+p.Y_value(),center.y+p.X_value());
setpixel(center.x-p.Y_value(),center.y+p.X_value());
setpixel(center.x+p.Y_value(),center.y-p.X_value());
setpixel(center.x-p.Y_value(),center.y-p.X_value());



}
void setpixel(GLint x,GLint y){

    glBegin(GL_POINTS);

    glVertex2i(x,y);





    glEnd();

}
void init(){
glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0,600,0,600);

}
void display(){

glClear(GL_COLOR_BUFFER_BIT);
glPointSize(5);

screen_point_struct center;
center.x=300;
center.y=300;
glColor3f(0.5f,0.0f,0.5f);
MidPointAlg(center,200);


glFlush();

}
int main(int argc,char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

glutInitWindowPosition(100,100);
glutInitWindowSize(600,600);
glutCreateWindow("Midpoint Circle Drawing Algrorithm ");
init();
glutDisplayFunc(display);
glutMainLoop();

return 0;

}
