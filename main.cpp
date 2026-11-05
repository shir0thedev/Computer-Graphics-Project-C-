#include <GL/glut.h>
#include <windows.h>
#include<math.h>
# define PI  3.14159265358979323846
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")


GLfloat cloud1_x = 30;
GLfloat cloud2_x = 0;
GLfloat cloud3_x = -40;
GLfloat cloud4_x = 60;

GLfloat speed1 = 0.07;
GLfloat speed2 = 0.10;
GLfloat speed3 = 0.05;
GLfloat speed4 = 0.14;

//drumcontrol
GLfloat lefthandmove = 0;
GLfloat righthandmove = 0;

GLfloat hit = 3;
GLubyte changedR = 183;
GLubyte changedG = 112;
GLubyte changedB = 53;

GLubyte hitR = 183;
GLubyte hitG = 112;
GLubyte hitB = 53;


void update(int value)
{

    cloud1_x -= speed1;
    cloud2_x -= speed2;
    cloud3_x -= speed3;
    cloud4_x -= speed4;

    if (cloud1_x < -50) cloud1_x = 110;
    if (cloud2_x < -50) cloud2_x = 110;
    if (cloud3_x < -50) cloud3_x = 110;
    if (cloud4_x < -50) cloud4_x = 110;

    glutPostRedisplay();

    glutTimerFunc(16, update, 0);
}



void drawCircle(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 100;
    GLfloat twicePi = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + radius * cos(i * twicePi / triangleAmount),
            y + radius * sin(i * twicePi / triangleAmount)
        );
    }
    glEnd();
}


void drawOval(float cx, float cy, float rx, float ry)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);

    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416f / 180;
        float x = cx + rx * cos(angle);
        float y = cy + ry * sin(angle);
        glVertex2f(x, y);
    }

    glEnd();
}


void sky()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();



    glBegin(GL_QUADS);
    glColor3f(0.1, 0.2, 0.8);
    glVertex2f(0, 100);
    glVertex2f(100, 100);

    glColor3f(0.7, 0.9, 1);
    glVertex2f(100, -100);
    glVertex2f(-100, -100);

    glEnd();

}


void ground() {

    glBegin(GL_POLYGON);
    glColor3ub(163, 180, 244);
    glVertex2f(0, 0);
    glVertex2f(0, 48.5);
    glVertex2f(70, 48.5);
    glVertex2f(70, 65);
    glVertex2f(100, 65);
    glVertex2f(100, 0);
    glVertex2f(0, 0);
    glEnd();



    glColor3ub(81, 195, 141);
    drawCircle(10, -10, 30);
    drawCircle(30, -10, 30);
    drawCircle(40, -10, 30);


    glColor3ub(139, 252, 109);
    drawCircle(65, -15, 30);
    drawCircle(80, -10, 30);



    glColor3ub(193, 214, 254);
    drawCircle(1.4, 57.5, 10);
    drawCircle(13.4, 48, 8);
    drawCircle(25.6, 44, 8);
    drawCircle(37.1, 44, 10);
    drawCircle(53.7, 42, 10);
    drawCircle(64, 53, 10);
    drawCircle(68, 62.5, 10);
    drawCircle(80, 64.6, 6);
    drawCircle(93.6, 67.2, 12);


    glColor3ub(163, 180, 244);
    drawCircle(1.4, 52.5, 10);
    drawCircle(13.4, 43, 8);
    drawCircle(25.6, 39, 8);
    drawCircle(37.1, 39, 10);
    drawCircle(53.7, 37, 10);
    drawCircle(64, 48, 10);
    drawCircle(68, 57.5, 10);
    drawCircle(80, 59.6, 6);
    drawCircle(93.6, 62.2, 12);

}

void tree() {
    /////treesright


        //wood
    glColor3ub(110, 70, 40);
    glBegin(GL_POLYGON);
    glVertex2f(44, 18.8);
    glVertex2f(45, 18.8);
    glVertex2f(45, 24.8);
    glVertex2f(44, 24.8);
    glEnd();

    //leaf
    glColor3ub(25, 120, 65);
    drawOval(44.5, 30.8, 4, 5);
    drawOval(42.5, 27.8, 3, 4);
    drawOval(46.5, 27.8, 3, 4);


    /////////



    //wood
    glColor3ub(110, 70, 40);
    glBegin(GL_POLYGON);
    glVertex2f(4, 18.8);
    glVertex2f(5, 18.8);
    glVertex2f(5, 24.8);
    glVertex2f(4, 24.8);
    glEnd();

    //leaf
    glColor3ub(25, 120, 65);
    drawOval(4.5, 30.8, 4, 5);
    drawOval(2.5, 27.8, 3, 4);
    drawOval(6.5, 27.8, 3, 4);

}
/////////

void drum() {
    ////drumbehindlegs
    glColor3ub(200, 109, 63);
    glBegin(GL_POLYGON);
    glVertex2f(48, 9.4);
    glVertex2f(49.4, 9.4);
    glVertex2f(49.9, 8.2);
    glVertex2f(48.4, 8.2);
    glEnd();

    glColor3ub(220, 154, 81);
    glBegin(GL_POLYGON);
    glVertex2f(48, 9.4);
    glVertex2f(49.4, 9.4);
    glVertex2f(58, 31.5);
    glVertex2f(56.8, 31.8);
    glVertex2f(48, 9.4);
    glEnd();


    glColor3ub(197, 109, 71);
    glBegin(GL_POLYGON);
    glVertex2f(58, 31.5);
    glVertex2f(59, 31.2);
    glVertex2f(49.9, 8.2);
    glVertex2f(49.4, 9.4);
    glVertex2f(58, 31.5);
    glEnd();




    glColor3ub(200, 109, 63);
    glBegin(GL_POLYGON);
    glVertex2f(62, 9.4);
    glVertex2f(63.4, 9.4);
    glVertex2f(63.9, 8.2);
    glVertex2f(62.4, 8.2);
    glEnd();

    glColor3ub(220, 154, 81);
    glBegin(GL_POLYGON);
    glVertex2f(62, 9.4);
    glVertex2f(63.4, 9.4);
    glVertex2f(72, 31.5);
    glVertex2f(70.8, 31.8);
    glVertex2f(62, 9.4);
    glEnd();


    glColor3ub(197, 109, 71);
    glBegin(GL_POLYGON);
    glVertex2f(72, 31.5);
    glVertex2f(73, 31.2);
    glVertex2f(63.9, 8.2);
    glVertex2f(63.4, 9.4);
    glVertex2f(72, 31.5);
    glEnd();


    ////drumbody


    glColor3ub(212, 124, 113);
    glLineWidth(2);
    glBegin(GL_POLYGON);
    glVertex2f(71.5, 66);
    glVertex2f(71.5, 26);
    glVertex2f(50, 26);
    glVertex2f(50, 66);
    glVertex2f(71.5, 66);

    glEnd();





    glColor3ub(255, 191, 89);
    drawOval(71.5, 46, 3, 20);


    //connecting triangle between drum
    glColor3ub(255, 191, 89);
    glBegin(GL_POLYGON);
    glVertex2f(71.5, 66);
    glVertex2f(73.5, 66);
    glVertex2f(73.5, 62);
    glVertex2f(71.5, 62);
    glVertex2f(71.5, 66);
    glVertex2f(71.5, 26);
    glVertex2f(73.5, 26);
    glVertex2f(73.5, 26);
    glVertex2f(71.5, 26);
    glVertex2f(71.5, 26);
    glEnd();




    glColor3ub(changedR, changedG, changedB);
    drawOval(73.5, 46, 3, 20);

    glColor3ub(255, 191, 89);
    drawOval(50.5, 46, 3, 20);


    glColor3ub(255, 191, 89);
    glBegin(GL_POLYGON);
    glVertex2f(50.5, 30);
    glVertex2f(52.5, 30);
    glVertex2f(52.5, 26);
    glVertex2f(50.5, 26);
    glVertex2f(50.5, 46);
    glVertex2f(50.5, 66);
    glVertex2f(52.5, 66);
    glVertex2f(52.5, 46);
    glVertex2f(50.5, 46);
    glVertex2f(50.5, 66);

    glEnd();




    glColor3ub(212, 124, 113);
    drawOval(52.5, 46, 3, 20);


    glColor3ub(221, 151, 84);
    drawCircle(71.2, 64, 0.7);
    drawCircle(70.2, 59, 0.7);
    drawCircle(69.4, 53, 0.7);
    drawCircle(69.3, 48, 0.7);
    drawCircle(69.5, 43, 0.7);
    drawCircle(69.7, 38, 0.7);
    drawCircle(70.2, 33, 0.7);
    drawCircle(71.2, 28, 0.7);


    ////drumlegs



    glColor3ub(197, 109, 71);
    glBegin(GL_POLYGON);
    glVertex2f(48.3, 39.2);
    glVertex2f(49, 39.5);
    glVertex2f(63.3, 9.8);
    glVertex2f(62.3, 8.7);
    glVertex2f(48.3, 39.2);
    glEnd();

    glColor3ub(219, 152, 81);
    glBegin(GL_POLYGON);
    glVertex2f(60.9, 8.5);
    glVertex2f(62.3, 8.7);
    glVertex2f(48.3, 39.2);
    glVertex2f(47.5, 38.5);
    glVertex2f(60.9, 8.5);
    glEnd();


    glColor3ub(193, 111, 73);
    glBegin(GL_POLYGON);
    glVertex2f(60.3, 39.2);
    glVertex2f(61, 39.5);
    glVertex2f(75.3, 9.8);
    glVertex2f(74.3, 8.7);
    glVertex2f(60.3, 39.2);
    glEnd();

    glColor3ub(221, 151, 84);
    glBegin(GL_POLYGON);
    glVertex2f(72.9, 8.5);
    glVertex2f(74.3, 8.7);
    glVertex2f(60.3, 39.2);
    glVertex2f(59.5, 38.5);
    glVertex2f(72.9, 8.5);
    glEnd();

}

void person() {

    //hat
    glColor3ub(191.0, 188.0, 174.0);
    glBegin(GL_POLYGON);
    glVertex2f(85, 55);
    glVertex2f(87, 54.5);
    glVertex2f(88, 54);
    glVertex2f(89, 53);
    glVertex2f(89.4, 52);
    glVertex2f(89.3, 50);
    glVertex2f(89.1, 49.5);
    glVertex2f(88, 50.2);
    glVertex2f(86.9, 50.9);
    glVertex2f(86, 51);
    glVertex2f(84, 51.5);
    glVertex2f(82, 52);
    glVertex2f(81.5, 52.2);
    glVertex2f(82, 53);
    glVertex2f(83, 54.4);
    glVertex2f(85, 55);
    glEnd();
    //face
    glColor3ub(254, 203, 175);
    glBegin(GL_POLYGON);
    glVertex2f(81.5, 52.2);
    glVertex2f(82, 52);
    glVertex2f(84, 51.5);
    glVertex2f(86, 51);
    glVertex2f(86.9, 50.9);
    glVertex2f(86.6, 50);
    glVertex2f(86.8, 49.3);
    glVertex2f(87.2, 48.5);
    glVertex2f(86.8, 47.8);
    glVertex2f(87.5, 48.3);
    glVertex2f(88, 48.3);
    glVertex2f(88.6, 48);
    glVertex2f(88.5, 47);
    glVertex2f(88.2, 46);
    glVertex2f(87.6, 45.5);
    glVertex2f(87.2, 45.6);
    glVertex2f(87.3, 45);
    glVertex2f(87.5, 44.3);
    glVertex2f(86.3, 44);
    glVertex2f(84.5, 43.1);
    glVertex2f(84.3, 43.7);
    glVertex2f(84, 43.5);
    glVertex2f(83.5, 43.3);
    glVertex2f(83, 43.5);
    glVertex2f(82, 44);
    glVertex2f(81.6, 44.5);
    glVertex2f(81, 46);
    glVertex2f(80.9, 47);
    glVertex2f(81, 48);
    glVertex2f(81.2, 49);
    glVertex2f(81.2, 50);
    glVertex2f(81.25, 51);
    glVertex2f(81.5, 52.2);
    glEnd();

    /////lungi
    glColor3ub(138, 86, 214);
    glBegin(GL_POLYGON);
    glVertex2f(84.5, 26);
    glVertex2f(92.7, 24.4);
    glVertex2f(95, 7);
    glVertex2f(84.5, 6);
    glVertex2f(84.5, 26);
    glEnd();

    //handm(left)




    glColor3f(224, 172, 0);
    glBegin(GL_POLYGON);
    glVertex2f(74.5 - lefthandmove, 49.5);
    glVertex2f(75.5 - lefthandmove, 49.5);
    glVertex2f(75.5 - lefthandmove, 55.5);
    glVertex2f(74.5 - lefthandmove, 55.5);
    glVertex2f(74.5 - lefthandmove, 49.5);
    glEnd();

    glColor3ub(254, 203, 175);
    drawOval(75 - lefthandmove, 47, 1, 4);

    glColor3ub(110, 35, 10);
    drawOval(75 - lefthandmove, 55, 1, 2);


    //torsom
    glColor3ub(232, 232, 232);
    glBegin(GL_POLYGON);
    glVertex2f(78.3 - lefthandmove, 40.6);
    glVertex2f(78 - lefthandmove, 36.3);
    glVertex2f(76.4 - lefthandmove, 38);
    glVertex2f(75.3 - lefthandmove, 40);
    glVertex2f(75 - lefthandmove, 41);
    glVertex2f(74.3 - lefthandmove, 41.4);
    glVertex2f(74.5 - lefthandmove, 45);
    glVertex2f(74.8 - lefthandmove, 46);
    glVertex2f(75.25 - lefthandmove, 47);
    glVertex2f(75.7 - lefthandmove, 47.5);
    glVertex2f(76.5 - lefthandmove, 48);
    glVertex2f(76.5 - lefthandmove, 48);
    glVertex2f(77.3 - lefthandmove, 46.6);
    glVertex2f(78.3 - lefthandmove, 40.6);
    glEnd();



    glColor3ub(232, 232, 232);
    glBegin(GL_POLYGON);
    glVertex2f(78.3, 40.6);
    glVertex2f(78, 36.3);
    glVertex2f(74.3, 36);
    glVertex2f(76.4, 38);
    glVertex2f(75.3, 40);
    glVertex2f(74.3, 38);
    glVertex2f(74.3, 36);
    glVertex2f(78.3, 40.6);
    glEnd();

    //handm(right)




    glColor3ub(224, 172, 0);
    glBegin(GL_POLYGON);
    glVertex2f(78.5 - righthandmove, 49.5);
    glVertex2f(79.5 - righthandmove, 49.5);
    glVertex2f(79.5 - righthandmove, 55.5);
    glVertex2f(78.5 - righthandmove, 55.5);
    glVertex2f(78.5 - righthandmove, 49.5);
    glEnd();

    glColor3ub(254, 203, 175);
    drawOval(79 - righthandmove, 47, 1, 4);

    glColor3ub(110, 35, 10);
    drawOval(79 - righthandmove, 55, 1, 2);


    //torsom
    glColor3ub(232, 232, 232);
    glBegin(GL_POLYGON);
    glVertex2f(82.3 - righthandmove, 40.6);
    glVertex2f(82 - righthandmove, 36.3);
    glVertex2f(80.4 - righthandmove, 38);
    glVertex2f(79.3 - righthandmove, 40);
    glVertex2f(79 - righthandmove, 41);
    glVertex2f(78.3 - righthandmove, 41.4);
    glVertex2f(78.5 - righthandmove, 45);
    glVertex2f(78.8 - righthandmove, 46);
    glVertex2f(79.25 - righthandmove, 47);
    glVertex2f(79.7 - righthandmove, 47.5);
    glVertex2f(80.5 - righthandmove, 48);
    glVertex2f(80.5 - righthandmove, 48);
    glVertex2f(81.3 - righthandmove, 46.6);
    glVertex2f(81.3 - righthandmove, 40.6);
    glEnd();

    //torso
    glColor3ub(232, 232, 232);
    glBegin(GL_POLYGON);
    glVertex2f(84.5, 43.1);
    glVertex2f(84.8, 43.2);
    glVertex2f(86.3, 44);
    glVertex2f(87.5, 44.3);
    glVertex2f(88, 44.3);
    glVertex2f(88.2, 44);
    glVertex2f(89, 42.4);
    glVertex2f(90, 40);
    glVertex2f(90.6, 38);
    glVertex2f(91.1, 36);
    glVertex2f(91.8, 33);
    glVertex2f(92.3, 29);
    glVertex2f(92.6, 27);
    glVertex2f(92.7, 24.4);
    glVertex2f(91, 23.5);
    glVertex2f(90, 23.2);
    glVertex2f(88, 23);
    glVertex2f(87.9, 23);
    glVertex2f(86.5, 24);
    glVertex2f(86.2, 26);
    glVertex2f(85.2, 24);
    glVertex2f(84.5, 24.8);
    glVertex2f(84.5, 30);
    glVertex2f(84.7, 32);
    glVertex2f(84.2, 36.5);
    glVertex2f(82, 36.1);
    glVertex2f(80, 36);
    glVertex2f(78, 36.3);
    glVertex2f(78.3, 40.6);
    glVertex2f(79, 40.8);
    glVertex2f(80, 41);
    glVertex2f(82, 42);
    glVertex2f(84.5, 43.1);

    glEnd();


    //torso and hand move parts









    /////////////////////////////////
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
    glVertex2f(85, 55);
    glVertex2f(87, 54.5);
    glVertex2f(88, 54);
    glVertex2f(89, 53);
    glVertex2f(89.4, 52);
    glVertex2f(89.3, 50);
    glVertex2f(89.1, 49.5);
    glVertex2f(88, 50.2);
    glVertex2f(86.9, 50.9);
    glVertex2f(86, 51);
    glVertex2f(84, 51.5);
    glVertex2f(82, 52);
    glVertex2f(81.5, 52.2);
    glVertex2f(82, 53);
    glVertex2f(83, 54.4);
    glVertex2f(85, 55);
    glEnd();

}




void mosque() {

    ////mosque




    glColor3ub(67, 204, 97);
    drawOval(24.5, 29.2, 7, 4.7);

    //road
    glColor3ub(232, 198, 86);
    drawOval(24.5, 12.2, 7, 4.7);

    glColor3ub(232, 198, 86);
    drawOval(24.5, 7.2, 9, 6.7);

    glColor3ub(232, 198, 86);
    drawOval(27.5, 1.2, 7, 4.7);



    ///leftside
    glColor3ub(234, 231, 178);
    glBegin(GL_POLYGON);
    glVertex2f(11, 14.8);
    glVertex2f(17.3, 14.8);
    glVertex2f(17.3, 21);
    glVertex2f(11, 21);
    glVertex2f(11, 14);
    glEnd();


    glColor3ub(221, 151, 84);
    glBegin(GL_POLYGON);
    glVertex2f(13.5, 14.8);
    glVertex2f(15.8, 14.8);
    glVertex2f(15.8, 21);
    glVertex2f(13.5, 22);
    glVertex2f(13.5, 21);
    glVertex2f(13.5, 14.8);
    glEnd();


    glColor3ub(255, 221, 124);
    glBegin(GL_POLYGON);
    glVertex2f(10.5, 21);
    glVertex2f(17.3, 21);
    glVertex2f(17.3, 22.2);
    glVertex2f(10.5, 22.2);
    glVertex2f(10.5, 21);
    glEnd();





    ////////tall///
    glColor3ub(43, 163, 91);
    drawOval(10.1, 43, 3, 2.7);

    glColor3ub(43, 163, 91);
    glBegin(GL_POLYGON);
    glVertex2f(7.9, 45);
    glVertex2f(10.2, 47.1);
    glVertex2f(12.4, 45);
    glVertex2f(7.9, 45);
    glEnd();


    glColor3ub(255, 252, 192);
    glBegin(GL_POLYGON);
    glVertex2f(8.2, 14.8);
    glVertex2f(12, 14.8);
    glVertex2f(12, 39.2);
    glVertex2f(8.2, 39.2);
    glVertex2f(8.2, 14.8);
    glEnd();

    glColor3ub(253, 218, 143);
    glBegin(GL_POLYGON);
    glVertex2f(7.2, 23);
    glVertex2f(13, 23);
    glVertex2f(13, 24.2);
    glVertex2f(7.2, 24.2);
    glVertex2f(7.2, 23);
    glEnd();

    glColor3ub(253, 218, 143);
    glBegin(GL_POLYGON);
    glVertex2f(8.2, 32.2);
    glVertex2f(12, 32.2);
    glVertex2f(13, 33);
    glVertex2f(7.4, 33);
    glVertex2f(8.2, 32.2);

    glEnd();

    glColor3ub(253, 218, 143);
    glBegin(GL_POLYGON);
    glVertex2f(7.4, 33);
    glVertex2f(13, 33);
    glVertex2f(13, 34);
    glVertex2f(7.4, 34);
    glVertex2f(7.4, 33);

    glEnd();


    glColor3ub(253, 218, 143);
    glBegin(GL_POLYGON);
    glVertex2f(7.9, 39.2);
    glVertex2f(12.3, 39.2);
    glVertex2f(12.3, 40);
    glVertex2f(7.9, 40);
    glVertex2f(7.9, 39.2);

    glEnd();



    glColor3ub(253, 218, 143);
    glBegin(GL_POLYGON);
    glVertex2f(7.9, 40);
    glVertex2f(12.3, 40);
    glVertex2f(12, 41);
    glVertex2f(8.2, 41);
    glVertex2f(7.9, 40);

    glEnd();




    ////////////


    ////rightside///





    ////////tall///
    glColor3ub(43, 163, 91);
    drawOval(36.9, 43, 3, 2.7);

    glColor3ub(43, 163, 91);
    glBegin(GL_POLYGON);
    glVertex2f(34.7, 45);
    glVertex2f(37, 47.1);
    glVertex2f(39.2, 45);
    glVertex2f(34.7, 45);
    glEnd();


    glColor3ub(253, 253, 193);
    glBegin(GL_POLYGON);
    glVertex2f(35, 14.8);
    glVertex2f(38.8, 14.8);
    glVertex2f(38.8, 39.2);
    glVertex2f(35, 39.2);
    glVertex2f(35, 14.8);
    glEnd();

    glColor3ub(253, 218, 143);
    glBegin(GL_POLYGON);
    glVertex2f(34, 23);
    glVertex2f(39.8, 23);
    glVertex2f(39.8, 24.2);
    glVertex2f(34, 24.2);
    glVertex2f(34, 23);
    glEnd();

    glColor3ub(253, 218, 143);
    glBegin(GL_POLYGON);
    glVertex2f(35, 32.2);
    glVertex2f(38.8, 32.2);
    glVertex2f(39.8, 33);
    glVertex2f(34.2, 33);
    glVertex2f(35, 32.2);

    glEnd();

    glColor3ub(253, 218, 143);
    glBegin(GL_POLYGON);
    glVertex2f(34.2, 33);
    glVertex2f(39.8, 33);
    glVertex2f(39.8, 34);
    glVertex2f(34.2, 34);
    glVertex2f(34.2, 33);

    glEnd();


    glColor3ub(253, 218, 143);
    glBegin(GL_POLYGON);
    glVertex2f(34.7, 39.2);
    glVertex2f(39.1, 39.2);
    glVertex2f(39.1, 40);
    glVertex2f(34.7, 40);
    glVertex2f(34.7, 39.2);

    glEnd();



    glColor3ub(253, 218, 143);
    glBegin(GL_POLYGON);
    glVertex2f(34.7, 40);
    glVertex2f(39.1, 40);
    glVertex2f(38.8, 41);
    glVertex2f(35, 41);
    glVertex2f(34.7, 40);

    glEnd();

    ////////////////////////////

    glColor3ub(253, 218, 143);
    glBegin(GL_POLYGON);
    glVertex2f(31, 21);
    glVertex2f(37.8, 21);
    glVertex2f(37.8, 22.2);
    glVertex2f(31, 22.2);
    glVertex2f(31, 21);
    glEnd();


    glColor3ub(234, 231, 178);
    glBegin(GL_POLYGON);
    glVertex2f(31, 14.8);
    glVertex2f(37.3, 14.8);
    glVertex2f(37.3, 21);
    glVertex2f(31, 21);
    glVertex2f(31, 14);
    glEnd();






    ////////////////


    glColor3ub(255, 252, 192);
    glBegin(GL_POLYGON);
    glVertex2f(17.3, 14.8);
    glVertex2f(31.3, 14.8);
    glVertex2f(31.3, 22);
    glVertex2f(17.3, 22);
    glVertex2f(17.3, 14.8);

    glEnd();


    glColor3ub(255, 221, 124);
    glBegin(GL_POLYGON);
    glVertex2f(16.4, 23.4);
    glVertex2f(32, 23.4);
    glVertex2f(32, 22);
    glVertex2f(16.4, 22);
    glVertex2f(16.4, 23.4);

    glEnd();

    glColor3ub(255, 252, 192);
    glBegin(GL_POLYGON);
    glVertex2f(18.4, 25.6);
    glVertex2f(30.2, 25.6);
    glVertex2f(30.2, 23.4);
    glVertex2f(18.4, 23.4);
    glVertex2f(18.4, 25.6);

    glEnd();

    glColor3ub(255, 221, 124);
    glBegin(GL_POLYGON);
    glVertex2f(18, 26.8);
    glVertex2f(30.6, 26.8);
    glVertex2f(30.6, 25.6);
    glVertex2f(18, 25.6);
    glVertex2f(18, 26.8);

    glEnd();

    glColor3ub(67, 204, 97);
    glBegin(GL_POLYGON);
    glVertex2f(18.8, 32);
    glVertex2f(24.9, 38.5);
    glVertex2f(30.2, 32);
    glVertex2f(18.8, 32);
    glEnd();


    glColor3ub(221, 151, 84);
    glBegin(GL_POLYGON);
    glVertex2f(33.5, 15);
    glVertex2f(35.5, 15);
    glVertex2f(35.5, 21);
    glVertex2f(33.5, 21);
    glVertex2f(33.5, 15);

    glEnd();

    glColor3ub(221, 151, 84);
    drawCircle(37, 29, 1);

    glColor3ub(221, 151, 84);
    drawCircle(37, 37, 1);

    glColor3ub(221, 151, 84);
    drawCircle(10, 29, 1);

    glColor3ub(221, 151, 84);
    drawCircle(10, 37, 1);
}

void face() {

    //face

    glColor3ub(254, 203, 175);
    glBegin(GL_POLYGON);
    glVertex2f(81.5, 52.2);
    glVertex2f(88, 50.2);
    glVertex2f(89.1, 49.2);
    glVertex2f(88.6, 48);
    glVertex2f(81.2, 49);
    glVertex2f(81.25, 51);
    glVertex2f(81.5, 52.2);
    glEnd();

    glColor3ub(254, 203, 175);
    drawOval(83.9, 47, 3, 4);

    glColor3ub(254, 203, 175);
    drawOval(87.5, 47, 1, 2);


    /////eyes,nose,mouth


    ///lefteyes
    glColor3ub(156, 117, 12);
    glBegin(GL_LINE_STRIP);
    glVertex2f(81.7, 49);
    glVertex2f(82, 49.2);
    glVertex2f(82.3, 49);
    glVertex2f(82.6, 48.8);
    glEnd();
    ///righteyes
    glColor3ub(156, 117, 12);
    glBegin(GL_LINE_STRIP);
    glVertex2f(84.3, 48.7);
    glVertex2f(84.6, 48.9);
    glVertex2f(84.9, 48.7);
    glVertex2f(85.2, 48.5);
    glEnd();

    ///nose
    glColor3ub(156, 117, 12);
    glBegin(GL_LINE_STRIP);
    glVertex2f(83.3, 49);
    glVertex2f(83.1, 48.5);
    glVertex2f(82.8, 47.8);

    glVertex2f(82.4, 47);
    glVertex2f(83.3, 46.6);
    glEnd();

    ///mouth
    glColor3ub(156, 70, 12);
    glBegin(GL_POLYGON);
    glVertex2f(82.5, 45.2);
    glVertex2f(85.4, 45.2);
    glVertex2f(85.1, 44.3);
    glVertex2f(82.8, 45.2);
    glVertex2f(82.5, 45.2);

    glEnd();


    glColor3ub(60, 180, 110);
    glBegin(GL_POLYGON);
    glVertex2f(6, 0);
    glVertex2f(7, 6);
    glVertex2f(8, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(9, 0);
    glVertex2f(10, 7);
    glVertex2f(11, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(12, 0);
    glVertex2f(13, 5);
    glVertex2f(14, 0);
    glEnd();

    glColor3ub(30, 120, 80);
    glBegin(GL_LINE_STRIP);
    glVertex2f(7, 0);
    glVertex2f(7, 6);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(10, 0);
    glVertex2f(10, 7);
    glEnd();


    glColor3ub(80, 200, 130);
    drawOval(32, 4, 2.5, 4);
    drawOval(35, 4, 2.5, 5);
    drawOval(38, 4, 2.5, 4);


    glColor3ub(40, 140, 90);
    glBegin(GL_LINE_STRIP);
    glVertex2f(32, 1);
    glVertex2f(32, 6);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(35, 1);
    glVertex2f(35, 7);
    glEnd();

    glColor3ub(70, 190, 120);
    drawOval(56, 4, 3, 3);
    drawOval(59, 4, 3, 4);

    glColor3ub(40, 130, 90);
    glBegin(GL_LINE_STRIP);
    glVertex2f(56, 1);
    glVertex2f(56, 6);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(59, 1);
    glVertex2f(59, 7);
    glEnd();


    glColor3ub(60, 170, 110);
    glBegin(GL_POLYGON);
    glVertex2f(72, 0);
    glVertex2f(73, 6);
    glVertex2f(74, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(75, 0);
    glVertex2f(76, 7);
    glVertex2f(77, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(78, 0);
    glVertex2f(79, 5);
    glVertex2f(80, 0);
    glEnd();

    glColor3ub(30, 110, 80);
    glBegin(GL_LINE_STRIP);
    glVertex2f(76, 0);
    glVertex2f(76, 7);
    glEnd();


    glColor3ub(90, 210, 140);
    drawOval(88, 4, 3, 5);
    drawOval(92, 4, 3, 4);

    glColor3ub(45, 150, 100);
    glBegin(GL_LINE_STRIP);
    glVertex2f(88, 1);
    glVertex2f(88, 7);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(92, 1);
    glVertex2f(92, 6);
    glEnd();

    glColor3ub(30, 110, 70);
    glBegin(GL_POLYGON);
    glVertex2f(3, 0);
    glVertex2f(4, 5);
    glVertex2f(5, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(6, 0);
    glVertex2f(7, 6);
    glVertex2f(8, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(9, 0);
    glVertex2f(10, 4);
    glVertex2f(11, 0);
    glEnd();


    glColor3ub(20, 80, 50);
    glBegin(GL_LINE_STRIP);
    glVertex2f(4, 0);
    glVertex2f(4, 5);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(7, 0);
    glVertex2f(7, 6);
    glEnd();

    glColor3ub(35, 120, 75);
    drawOval(27, 3.5, 3.2, 3);
    drawOval(30, 3.5, 3.5, 4);
    drawOval(33, 3.5, 3.2, 3);

    glColor3ub(25, 90, 60);
    glBegin(GL_LINE_STRIP);
    glVertex2f(30, 1);
    glVertex2f(30, 6);
    glEnd();


    glColor3ub(40, 130, 85);
    drawOval(48, 3.5, 2.5, 4);
    drawOval(51, 3.5, 2.5, 3.5);

    glColor3ub(30, 95, 65);
    glBegin(GL_LINE_STRIP);
    glVertex2f(48, 1);
    glVertex2f(48, 6);
    glEnd();

    glColor3ub(25, 100, 65);
    glBegin(GL_POLYGON);
    glVertex2f(70, 0);
    glVertex2f(71, 5);
    glVertex2f(72, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(73, 0);
    glVertex2f(74, 6);
    glVertex2f(75, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(76, 0);
    glVertex2f(77, 4);
    glVertex2f(78, 0);
    glEnd();

    glColor3ub(20, 70, 45);
    glBegin(GL_LINE_STRIP);
    glVertex2f(74, 0);
    glVertex2f(74, 6);
    glEnd();


    glColor3ub(221, 151, 84);
    glBegin(GL_POLYGON);
    glVertex2f(23.5, 14.8);
    glVertex2f(25.8, 14.8);
    glVertex2f(25.8, 21);
    glVertex2f(23.5, 22);
    glVertex2f(23.5, 21);
    glVertex2f(23.5, 14.8);
    glEnd();

    glColor3ub(45, 140, 90);
    drawOval(85, 3.5, 3, 4);
    drawOval(88, 3.5, 3, 3);

    glColor3ub(30, 95, 65);
    glBegin(GL_LINE_STRIP);
    glVertex2f(85, 1);
    glVertex2f(85, 6);
    glEnd();


    glColor3ub(35, 120, 75);
    glBegin(GL_POLYGON);
    glVertex2f(6, 2);
    glVertex2f(7, 6);
    glVertex2f(8, 2);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(9, 2);
    glVertex2f(10, 5);
    glVertex2f(11, 2);
    glEnd();

    glColor3ub(20, 80, 55);
    glBegin(GL_LINE_STRIP);
    glVertex2f(7, 2);
    glVertex2f(7, 6);
    glEnd();


    glColor3ub(40, 135, 85);
    glBegin(GL_POLYGON);
    glVertex2f(34, 3);
    glVertex2f(35, 7);
    glVertex2f(36, 3);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(37, 3);
    glVertex2f(38, 6);
    glVertex2f(39, 3);
    glEnd();

    glColor3ub(25, 95, 65);
    glBegin(GL_LINE_STRIP);
    glVertex2f(35, 3);
    glVertex2f(35, 7);
    glEnd();


    glColor3ub(30, 110, 70);
    glBegin(GL_POLYGON);
    glVertex2f(60, 3);
    glVertex2f(61, 6);
    glVertex2f(62, 3);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(43, 3);
    glVertex2f(44, 7);
    glVertex2f(45, 3);
    glEnd();

    glColor3ub(20, 75, 50);
    glBegin(GL_LINE_STRIP);
    glVertex2f(24, 3);
    glVertex2f(24, 7);
    glEnd();

    glColor3ub(35, 125, 80);
    glBegin(GL_POLYGON);
    glVertex2f(12, 2);
    glVertex2f(13, 6);
    glVertex2f(14, 2);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(25, 2);
    glVertex2f(26, 5);
    glVertex2f(27, 2);
    glEnd();

    glColor3ub(20, 85, 60);
    glBegin(GL_LINE_STRIP);
    glVertex2f(93, 2);
    glVertex2f(93, 6);
    glEnd();

}

void moon() {
    //moon

    glColor3ub(232, 198, 86);
    drawCircle(9, 90, 4);

    glColor3f(0.1f, 0.2f, 0.8f);
    drawCircle(10, 90, 4);

    glPushMatrix();
    glTranslatef(cloud1_x, 0, 0);
    glColor3ub(220, 235, 255);
    drawOval(15, 80, 6, 4);
    drawOval(20, 82, 7, 5);
    drawOval(26, 80, 6, 4);
    drawOval(20, 78, 8, 4);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(cloud2_x, 0, 0);
    glColor3ub(215, 230, 250);
    drawOval(45, 84, 7, 5);
    drawOval(51, 86, 8, 6);
    drawOval(58, 84, 7, 5);
    drawOval(52, 82, 9, 4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloud3_x, 0, 0);
    glColor3ub(225, 240, 255);
    drawOval(75, 80, 6, 4);
    drawOval(80, 82, 7, 5);
    drawOval(86, 80, 6, 4);
    drawOval(80, 78, 8, 4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloud4_x, 0, 0);
    glColor3ub(210, 225, 245);
    drawOval(60, 90, 4, 3);
    drawOval(64, 91, 5, 4);
    drawOval(69, 90, 4, 3);
    glPopMatrix();

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    sky();
    ground();
    tree();
    drum();
    person();
    mosque();
    face();
    moon();

    glFlush();
}





void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);
}



void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'u':
    case 'U':
        lefthandmove = hit;
        changedR = hitR;
        changedG = hitG;
        changedB = hitB;
        PlaySound(TEXT("bass.wav"), NULL, SND_ASYNC | SND_FILENAME);
        break;

    case 'v':
    case 'V':
        righthandmove = hit;
        changedR = hitR;
        changedG = hitG;
        changedB = hitB;
        PlaySound(TEXT("snare.wav"), NULL, SND_ASYNC | SND_FILENAME);
        break;

    case 27:
        exit(0);
        break;
    }

    glutPostRedisplay();
}


void keyboardUp(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'u':
    case 'U':
        lefthandmove = 0;
        changedR = 224; changedG = 172; changedB = 0;
        break;

    case 'v':
    case 'V':
        righthandmove = 0;
        changedR = 224; changedG = 172; changedB = 0;
        PlaySound(TEXT("snare.wav"), NULL, SND_FILENAME | SND_ASYNC);
        break;
    }

    glutPostRedisplay();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1280, 720);
    glutCreateWindow("Mehrab Ibne Khaled");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}
