#include<GL/freeglut.h>

struct screen_point_struct{
    GLint x, y;

};

    class Point_on_screen {
    private:
        GLint x, y;
    public:
        Point_on_screen() {
            x = 0;
            y = 0;
        }
        void setcord(GLint x_val, GLint y_val) {
            x = x_val;
            y = y_val;
        }
        GLint getx() const {
            return x;

        }
        GLint gety() const {
            return y;

        }
        void incx() {
            ++x;

        }
            void decy() {
                --y;
            }
        };
    void setpixel(GLint x, GLint y){
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
    }
    void plotFourPoints(screen_point_struct center, Point_on_screen p)
    {
        setpixel(center.x + p.getx() , center.y + p.gety());
        setpixel(center.x - p.getx() , center.y + p.gety());
        setpixel(center.x + p.getx() , center.y - p.gety());
        setpixel(center.x - p.getx() , center.y - p.gety());
    }
    void Midpointalg(screen_point_struct center, GLint rx, GLint ry){

        Point_on_screen Current_point;
        Current_point.setcord(0,ry);
        GLint p1=ry*ry - rx*rx*ry + 0.25*rx*rx;
        GLint dx=2* ry*ry* Current_point.getx();
        GLint dy=2* rx*rx* Current_point.gety();
        while (dx<dy){
            plotFourPoints(center,Current_point);
            Current_point.incx();
            if(p1<0){
                dx=2* ry * ry * Current_point.getx();
                p1=p1+ dx + ry*ry;
            }
            else{
                Current_point.decy();
                dx =2* ry*ry *Current_point.getx();
                dy =2* rx*rx *Current_point.gety();
                p1=p1 + dx - dy + ry*ry;
            }
        }
        GLint p2=ry*ry*(Current_point.getx()+0.5)*(Current_point.getx()+0.5)
                +rx*rx *(Current_point.gety()-1)*(Current_point.gety()-1)
                -rx*rx * ry*ry;
        while (Current_point.gety()>=0){
            plotFourPoints(center,Current_point);
            Current_point.decy();
            if(p2>0){
                dy =2* rx*rx *Current_point.gety();
                p2=p2 - dy + rx*rx;
            }
            else{
                Current_point.incx();
                dx =2* ry*ry *Current_point.getx();
                dy =2* rx*rx *Current_point.gety();
                p2=p2 + dx - dy + rx*rx;
            }
        }
    }
    void init(){
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glMatrixMode(GL_PROJECTION);
        gluOrtho2D(0, 600, 0, 600);
    }
    void display(){
        glClear(GL_COLOR_BUFFER_BIT);
        glPointSize(5);
        screen_point_struct center;
        center.x=300;
        center.y=300;
        glColor3f(0.1f, 0.7f, 0.0f);
        //algorithm
        Midpointalg(center ,200 ,100);
        glFlush();
    }
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,400);
    glutCreateWindow("„Õ„œ Œ«·œ ⁄Ì”Ì «Õ„œ");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
