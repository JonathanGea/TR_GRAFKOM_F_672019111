// TR GRAFKOM
// 6 JULI 2021
// Jonathan Gea 672019111
// Theoputra berkat zega 672019302

#include<windows.h>
#include<gl/glut.h>

void init(void);
void tampil(void);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void keyboard(unsigned char, int, int);
void ukuran(int, int);

int is_depth;

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 600);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Jonathan Gea - 672019111");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}
void init(void)
{
    glClearColor(0.5, 0.5, 0.5, 0.0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
}

void balok(int Titik_x1, int Titik_y1, int Titik_z1,int Titik_x2, int Titik_y2, int Titik_z2)
{
    glPushMatrix ();
    glBegin(GL_QUADS);
    glVertex3f( Titik_x1,Titik_y1,Titik_z1);
    glVertex3f( Titik_x2,Titik_y1,Titik_z1);
    glVertex3f( Titik_x2,Titik_y2,Titik_z1);
    glVertex3f( Titik_x1,Titik_y2,Titik_z1); //--- depan
    glVertex3f( Titik_x1,Titik_y1,Titik_z1);
    glVertex3f( Titik_x1,Titik_y2,Titik_z1);
    glVertex3f( Titik_x1,Titik_y2,Titik_z2);
    glVertex3f( Titik_x1,Titik_y1,Titik_z2); //--- kiri
    glVertex3f( Titik_x1,Titik_y2,Titik_z2);
    glVertex3f( Titik_x1,Titik_y1,Titik_z2);
    glVertex3f( Titik_x2,Titik_y2,Titik_z2);
    glVertex3f( Titik_x2,Titik_y1,Titik_z2); //--- belakang
    glVertex3f( Titik_x2,Titik_y2,Titik_z2);
    glVertex3f( Titik_x2,Titik_y1,Titik_z2);
    glVertex3f( Titik_x2,Titik_y1,Titik_z1);
    glVertex3f( Titik_x2,Titik_y2,Titik_z1); //--- kanan
    glVertex3f( Titik_x2,Titik_y2,Titik_z2);
    glVertex3f( Titik_x2,Titik_y2,Titik_z1);
    glVertex3f( Titik_x1,Titik_y2,Titik_z1);
    glVertex3f( Titik_x1,Titik_y2,Titik_z2); //--- atas
    glVertex3f( Titik_x2,Titik_y1,Titik_z2);
    glVertex3f( Titik_x2,Titik_y1,Titik_z1);
    glVertex3f( Titik_x1,Titik_y1,Titik_z1);
    glVertex3f( Titik_x1,Titik_y1,Titik_z2); //--- bawah
    glEnd();
    glPopMatrix();
}

void tampil(void)
{
    if (is_depth)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    else
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }
    glColor3f(1,1,1);
    balok(-130,-16,60,130,-10,-60);
    glColor3f (1.0, 1.0, 0.6);
    balok(-120,-10,50,120,0,-50);
    //--------------------------------------------
    glColor3f (0.2, 0.5, 1.0);
    balok(-70,0,16,70,80,-41); // utama kaca
    balok(-5,37,26,5,75,25); // bagian kaca menara
    balok(-2,83,24,2,88,23);


    glColor3f (0.5, 0.5, 0.5);
    for (int z =0; z <47; z++)
    {
        balok(-69+ (3*z),0,17,-70+(3*z),80,17);
    }
    for (int z =0; z <12; z++)
    {
        balok(-70,0+(7*z),17,70,1+(7*z),17);
    }

    glColor3f (0.0, 0.7, 0.0);
    balok(-70,80,16,70,81,-41);
    glColor3f (0.2, 0.5, 1.0);
    balok(20,0,20,110,30,-41);  // 1
    balok(-20,0,20,-110,30,-41); // -1

    glColor3f (1.0, 1.0, 0.8);
    balok(20,30,20,100,40,-40);
    balok(-20,30,20,-100,40,-40);
    balok(20,40,20,90,50,-40);
    balok(-20,40,20,-90,50,-40);
    balok(20,50,20,80,60,-40);
    balok(-20,50,20,-80,60,-40);

    // objekk --------------------------------------------------

    balok(-75,5,-25,-75,30,0); //papan
    glColor3f(1.0, 0.0, 0.0);
    balok(-60,10,-40,-50,10,5);
    balok(-58,0,-38,-58,10,2);
    balok(-58,0,-38,-52,10,-38);
    balok(-58,0,2,-52,10,2);

    glColor3f(0.0, 1.0, 0.0);//kursi 1
    balok(-45,7,0,-50,7,-10);
    balok(-45,7,0,-50,0,0);
    balok(-45,7,-10,-50,0,-10);
    balok(-45,7,0,-45,15,-10);

    glColor3f(1.0, 0.0, 1.0);//kursi 2
    balok(-45,7,-35,-50,7,-25);
    balok(-45,7,-35,-50,0,-35);
    balok(-45,7,-25,-50,0,-25);
    balok(-45,7,-35,-45,15,-25);

    glColor3f(0.7, 0.5, 0.0);//lemari
    balok(-70,0,-28,-75,25,-35);
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-70,10,-28);
    glVertex3f(-70,10,-35);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-70,20,-28);
    glVertex3f(-70,20,-35);
    glEnd();

    glColor3f(0.5,0.8,0.8);//tempat sampah
    balok(-30,0,-35,-35,10,-40);
    balok(-30,10,-40,-35,13,-40);
    balok(-30,10,-40,-30,13,-37);
    balok(-35,10,-40,-35,13,-37);
    balok(-35,13,-40,-30,13,-37);
    balok(-75,5,-25,-75,30,0); //papan
    glColor3f(1.0, 0.0, 0.0);
    balok(-60,10,-40,-50,10,5);
    balok(-58,0,-38,-58,10,2);
    balok(-58,0,-38,-52,10,-38);
    balok(-58,0,2,-52,10,2);

    glColor3f(0.0, 1.0, 0.0);//kursi 1
    balok(-45,7,0,-50,7,-10);
    balok(-45,7,0,-50,0,0);
    balok(-45,7,-10,-50,0,-10);
    balok(-45,7,0,-45,15,-10);

    glColor3f(1.0, 0.0, 1.0);//kursi 2
    balok(-45,7,-35,-50,7,-25);
    balok(-45,7,-35,-50,0,-35);
    balok(-45,7,-25,-50,0,-25);
    balok(-45,7,-35,-45,15,-25);

    glColor3f(0.7, 0.5, 0.0);//lemari
    balok(-70,0,-28,-75,25,-35);
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-70,10,-28);
    glVertex3f(-70,10,-35);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-70,20,-28);
    glVertex3f(-70,20,-35);
    glEnd();

    glColor3f(0.5,0.8,0.8);//tempat sampah
    balok(-30,0,-35,-35,10,-40);
    balok(-30,10,-40,-35,13,-40);
    balok(-30,10,-40,-30,13,-37);
    balok(-35,10,-40,-35,13,-37);
    balok(-35,13,-40,-30,13,-37);

    balok(-10,10,25,10,80,16); // start menara depan
    balok(-11,80,26,11,81,6); // pembatas
    balok(-8,81,23,8,90,8); // 1
    balok(-9,90,24,9,91,7); // pembatas 1
    balok(-6,91,23,6,100,8); // 2
    balok(-7,100,26,7,101,5); // pembatas 2
    glColor3f (0.4, 1.0, 0.8);
    balok(-6,101,23,6,108,8); // kubah
    glColor3f (0, 0, 0);
    balok(-2,108,18,2,113,12);
    balok(-1,113,16,1,125,14);

    glColor3f (0.0,1.0,1.0);
    for (int j = 0 ; j <= 2; j++)
    {
        for (int i = 0; i <=7-j; i++)
        {
            balok(23+(i*10),32+(j*10),21,28+(i*10),38+(j*10),20);
            balok(22+(i*10),30.5+(j*10),21,29+(i*10),31.5+(j*10),20); // garis bawah
            balok(-23-(i*10),32+(j*10),21,-28-(i*10),38+(j*10),20);
            balok(-22-(i*10),30.5+(j*10),21,-29-(i*10),31.5+(j*10),20); // garis bawah
        }
    }
    glColor3f (1.0, 0.9, 0.6);
    for (int i = 0; i <=3; i++)
    {
        balok(25+(i*25 ),0,40,30+(i*25),30,32);
        balok(-25-(i*25 ),0,40,-30-(i*25),30,32);
    }

    balok(15,0,23,20,30,15);
    balok(-15,0,23,-20,30,15);
    balok(15,0,50,20,30,42); // depan
    balok(-15,0,50,-20,30,42);
    balok(-15,17,50,-20,30,15); // samping kiri
    balok(15,17,50,20,30,15); // samping kanan
    balok(-20,30,50,20,35,15); // atas

    balok(25,25,40,105,30,15);
    balok(-25,25,38,-105,30,15);

    balok(25,9,40,100,17,32);
    balok(-25,9,40,-100,17,32);

//===================================================================================================================
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 3.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(3.0, 0.0, 0.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -3.0);
        break;
    case 'a':
    case 'A':
        glTranslatef(-3.0, 0.0, 0.0);
        break;
    case '7':
        glTranslatef(0.0, 3.0, 0.0);
        break;
    case '9':
        glTranslatef(0.0, -3.0, 0.0);
        break;
    case '2':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case '8':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case '6':
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case '4':
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case '1':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case '3':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;

void identity()
{
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
}

void idle()
{
    if (!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y)
{
    identity();
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }

}
void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0)
        tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}
