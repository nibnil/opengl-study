#define GLUT_DISABLE_ATEXIT_HACK
#include <iostream>
// #include <GL/freeglut.h>
#include <GL/glut.h>

typedef GLint vertex3[3];


// void init(){
//     glClearColor(1.0, 1.0, 1.0, 0.0);  //backgroup: red, green, blue, alpha
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     gluOrtho2D(0.0, 200.0, 0.0, 150.0);
//     // gluortho3
// }

GLint xRaster = 25, yRaster = 150;
GLsizei winWidth = 600, winHeight = 500;
GLubyte label[36] = {'J', 'a', 'n', 'F', 'e', 'b', 'M', 'a', 'r', 'A', 'p', 'r', 'M', 'a', 'y', 'J', 'u', 'n',
                     'J', 'u', 'l', 'A', 'u', 'g', 'S', 'e', 'p', 'O', 'c', 't', 'N', 'o', 'v', 'D', 'e', 'c'};


void init(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

GLint dataValue[12] = {420, 342, 324, 310, 262, 185, 190, 196, 217, 240, 312, 438};

void lineGraph(){
    GLint month, k;
    GLint x = 30;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINE_STRIP);
    for(k = 0; k < 12; k++){
        glVertex2i(x + k*50, dataValue[k]);
    }
    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    for (k = 0; k < 12; k++){
        glRasterPos2i(xRaster + k * 50, dataValue[k] - 4);
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '*');
    }
    glColor3f(0.0, 0.0, 0.0);
    xRaster = 20;
    for(month = 0; month<12; month++){
        glRasterPos2i(xRaster, yRaster);
        for(k = 3*month; k < 3*month + 3; k++){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, label[k]);
        }
        xRaster += 50;
    }
    glFlush();

    
}

void winReshapeFcn(GLint newWidth, GLint newHeight){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, GLdouble(newWidth), 0.0, GLdouble(newHeight));
    glClear(GL_COLOR_BUFFER_BIT);
}

// void quad(GLint n1, GLint n2, GLint n3, GLint n4){
//     vertex3 pt[8] {{0, 0, 0}, {0, 20, 0}, {20, 00, 0}, {20, 20, 0}, {0, 0, 20}, {0, 20, 20}, {20, 0, 20}, {20, 20, 20}};
//     glBegin(GL_QUADS);
//     glVertex3iv(pt[n1]);
//     glVertex3iv(pt[n2]);
//     glVertex3iv(pt[n3]);
//     glVertex3iv(pt[n4]);
//     glEnd();
//     // glFlush();
// }

// void cube(){
//     quad(6, 2, 3, 7);
//     quad(5, 1, 0, 4);
//     quad(7, 3, 1, 5);
//     quad(4, 0, 2, 6);
//     quad(2, 0, 1, 3);
//     quad(7, 5, 4, 6);
//     glFlush();
// }

// void lineSegment(){
//     glClear(GL_COLOR_BUFFER_BIT);
//     // glColor3f(0.0, 0.4, 0.2);  //RGB, 0.0~1.0
//     //glBegin(GL_LINES);
//     // glVertex2i(180, 15);
//     // glVertex2i(10, 145);
//     // glVertex2i(1, 1);
//     // glVertex2i(100, 50);
//     //glEnd();
//     // glBegin(GL_POINTS);
//     // glVertex2i(50, 100);
//     // glVertex2i(75, 150);
//     // glVertex2i(100, 200);
//     // glEnd()
//     // glBegin(GL_LINE_LOOP);
//     // glVertex2i(10, 10);
//     // glVertex2i(75, 50);
//     // glVertex2i(10, 50);
//     // glVertex2i(75, 10);
//     // glEnd();
//     // glFlush();
//     // glBegin(GL_POLYGON);
//     // glRecti(10, 10, 75, 50);
//     // glEnd();
//     // glFlush();
//     // glBegin(GL_POINTS);
//     // glVertex2i(10, 10);
//     // glVertex2i(75, 50);
//     // glVertex2i(100, 200);
//     // glEnd();
//     // glFlush();
//     // int point1[] = {10, 10};
//     // int point2[] = {75, 50};
//     // int point3[] = {10, 50};
//     // int point4[] = {75, 10};
//     // glBegin(GL_POINTS);
//     // glVertex2iv(point1);
//     // glVertex2iv(point2);
//     // glVertex2iv(point3);
//     // glVertex2iv(point4);
//     // glEnd();
//     // glFlush();
//     // int point1[] = {10, 10};
//     // int point2[] = {75, 50};
//     // int point3[] = {10, 50};
//     // int point4[] = {75, 10};
//     // glBegin(GL_LINES);
//     // glVertex2iv(point1);
//     // glVertex2iv(point2);
//     // glVertex2iv(point3);
//     // glVertex2iv(point4);
//     // glEnd();
//     // glFlush();
//     // int point1[] = {10, 10};
//     // int point2[] = {10, 50};
//     // int point3[] = {75, 50};
//     // int point4[] = {75, 10};
//     // glBegin(GL_POLYGON);
//     // glVertex2iv(point1);
//     // glVertex2iv(point2);
//     // glVertex2iv(point3);
//     // glVertex2iv(point4);
//     // glEnd();
//     // glFlush();
//     cube();
// }

// void cube1(){
//     glClear(GL_COLOR_BUFFER_BIT);
//     glColor3f(0.0, 0.4, 0.2);  //RGB, 0.0~1.0
//     // vertex3 pt[8] = {{0, 0, 0}, {0, 20, 0}, {20, 00, 0}, {20, 20, 0}, {0, 0, 20}, {0, 20, 20}, {20, 0, 20}, {20, 20, 20}};
//     vertex3 pt[8] = {{0, 0, 0}, {0, 100, 0}, {100, 0, 0}, {100, 100, 0}, {0, 0, 100}, {0, 100, 100}, {100, 0, 100}, {100, 100, 100}};
//     glEnableClientState(GL_VERTEX_ARRAY);
//     glVertexPointer(3, GL_INT, 0 ,pt);
//     GLubyte vertIndex[] = {6, 2, 3, 7, 5,  1, 0, 4, 7, 3, 1, 5, 4, 0 ,2, 6, 2, 0, 1, 3, 7, 5, 4, 6};
//     glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, vertIndex);
//     glFlush();
// }


// int main(int argc, char** argv){
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  //mode
//     glutInitWindowPosition(640, 20);    // windows position
//     glutInitWindowSize(400, 300);       //windows size
//     glutCreateWindow("Example");         //title
//     init();
//     // glutDisplayFunc(lineSegment);
//     glutDisplayFunc(cube1);

//     glutMainLoop();
//     return 0;
// }

// int main(){
//     std::cout << "helloworld" << std::endl;
//     return 0;
// }


int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("Line Chart Data Plot");
    init();
    glutDisplayFunc(lineGraph);
    glutReshapeFunc(winReshapeFcn);
    glutMainLoop();
}