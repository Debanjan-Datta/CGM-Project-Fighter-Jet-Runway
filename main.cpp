#include<bits/stdc++.h>
#include<GL/glut.h>

GLfloat p=0,q=0,r=0;

void runway();

void init()
{
    glClearColor(0.7f,1.0f,1.0f,0.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,500.0,0.0,500.0);
}

void update(int value)
{
    p+=10.0;
    q-=2.0;
    r+=10;
    if(q<=-60.0)
        q=0.0;
    glutPostRedisplay();
    glutTimerFunc(200,update,0);
}


void FighterJet_Body(void)
{
    glClear(GL_COLOR_BUFFER_BIT);//clear display window
    runway();


    glPushMatrix();
    glTranslated(p,r,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);//rectangular body
    glVertex2f(0.0,30.0);
    glVertex2f(0.0,55.0);
    glVertex2f(135.0,55.0);
    glVertex2f(135.0,30.0);
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslated(p,r,0.0);
    glColor3f(0.1,0.1,0.0);
    glBegin(GL_POLYGON);//upper triangle jet
    glVertex2f(135.0,55.0);
    glVertex2f(150.0,50.0);
    glVertex2f(155.0,45.0);
    glVertex2f(160.0,40.0);
    glVertex2f(135.0,40.0);
    glEnd();
    glPopMatrix();



    glPushMatrix();//triangle divider
    glTranslated(p,r,0.0);
    glColor3f(1.0,0.1,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(135.0,55.0);
    glVertex2f(150.0,50.0);
    glVertex2f(155.0,45.0);
    glVertex2f(160.0,40.0);
    glVertex2f(135.0,40.0);
    glEnd();
    glPopMatrix();


    glPushMatrix();//lower triangle
    glTranslated(p,r,0.0);
    glColor3f(0.0,0.5,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(135.0,40.0);
    glVertex2f(160.0,40.0);
    glVertex2f(160.0,37.0);
    glVertex2f(145.0,30.0);
    glVertex2f(135.0,30.0);
    glEnd();
    glPopMatrix();


    glPushMatrix();//tail
    glTranslated(p,r,0.0);
    glColor3f(0.0,0.5,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(0.0,55.0);
    glVertex2f(0.0,80.0);
    glVertex2f(10.0,80.0);
    glVertex2f(40.0,55.0);
    glEnd();
    glPopMatrix();


    glPushMatrix();//left wing
    glTranslated(p,r,0.0);
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(65.0,55.0);
    glVertex2f(50.0,70.0);
    glVertex2f(75.0,70.0);
    glVertex2f(90.0,55.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//right wing
    glTranslated(p,r,0.0);
    glColor3f(0.0,0.5,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(70.0,40.0);
    glVertex2f(100.0,40.0);
    glVertex2f(80.0,15.0);
    glVertex2f(50.0,15.0);
    glEnd();

    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}



void runway()
{
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);//black runway
    glVertex2f(0.0,0.0);
    glVertex2f(0.0,100.0);
    glVertex2f(500.0,100.0);
    glVertex2f(500.0,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(q,0.0,0.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);//white stripes on runway
    glVertex2f(0.0,40.0);
    glVertex2f(8.0,60.0);
    glVertex2f(58.0,60.0);
    glVertex2f(50.0,40.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(q,0.0,0.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(100.0,40.0);
    glVertex2f(108.0,60.0);
    glVertex2f(158.0,60.0);
    glVertex2f(150.0,40.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(q,0.0,0.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(200.0,40.0);
    glVertex2f(208.0,60.0);
    glVertex2f(258.0,60.0);
    glVertex2f(250.0,40.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(q,0.0,0.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(300.0,40.0);
    glVertex2f(308.0,60.0);
    glVertex2f(358.0,60.0);
    glVertex2f(350.0,40.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(q,0.0,0.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(400.0,40.0);
    glVertex2f(408.0,60.0);
    glVertex2f(458.0,60.0);
    glVertex2f(450.0,40.0);
    glEnd();
    glPopMatrix();
}


int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1400.0,680.0);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Fighter Jet Runway");
    glutDisplayFunc(FighterJet_Body);
    init();
    glutTimerFunc(100,update,0);
    glutMainLoop();
    return 0;
}
