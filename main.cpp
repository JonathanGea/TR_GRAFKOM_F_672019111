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
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
}
void balok(int TitikTengah_X, int TitikTengah_Z, int titik_Y, int tinggi, int panjang, int lebar)
{
    // panjang=panjang/2;
    // lebar=lebar/2;
    glBegin(GL_QUADS);
    glVertex3f( TitikTengah_X + panjang, titik_Y, TitikTengah_Z + lebar);
    glVertex3f( TitikTengah_X + panjang, tinggi, TitikTengah_Z + lebar);
    glVertex3f( TitikTengah_X + panjang, tinggi, TitikTengah_Z - lebar);
    glVertex3f( TitikTengah_X + panjang, titik_Y, TitikTengah_Z - lebar); //--
    glVertex3f( TitikTengah_X - panjang, titik_Y, TitikTengah_Z + lebar);
    glVertex3f( TitikTengah_X - panjang, tinggi, TitikTengah_Z + lebar);
    glVertex3f( TitikTengah_X - panjang, tinggi, TitikTengah_Z - lebar);
    glVertex3f( TitikTengah_X - panjang, titik_Y, TitikTengah_Z - lebar); //---
    glVertex3f( TitikTengah_X + panjang, titik_Y, TitikTengah_Z + lebar);
    glVertex3f( TitikTengah_X + panjang, tinggi, TitikTengah_Z + lebar);
    glVertex3f( TitikTengah_X - panjang, tinggi, TitikTengah_Z + lebar);
    glVertex3f( TitikTengah_X - panjang, titik_Y, TitikTengah_Z + lebar);//--
    glVertex3f( TitikTengah_X + panjang, titik_Y, TitikTengah_Z - lebar);
    glVertex3f( TitikTengah_X + panjang, tinggi, TitikTengah_Z - lebar);
    glVertex3f( TitikTengah_X - panjang, tinggi, TitikTengah_Z - lebar);
    glVertex3f( TitikTengah_X - panjang, titik_Y, TitikTengah_Z - lebar); //--
    glVertex3f( TitikTengah_X - panjang, tinggi, TitikTengah_Z + lebar);
    glVertex3f( TitikTengah_X - panjang, tinggi, TitikTengah_Z - lebar);
    glVertex3f( TitikTengah_X + panjang, tinggi, TitikTengah_Z - lebar);
    glVertex3f( TitikTengah_X + panjang, tinggi, TitikTengah_Z + lebar); //--
    glVertex3f( TitikTengah_X - panjang, titik_Y, TitikTengah_Z + lebar);
    glVertex3f( TitikTengah_X - panjang, titik_Y, TitikTengah_Z - lebar);
    glVertex3f( TitikTengah_X + panjang, titik_Y, TitikTengah_Z - lebar);
    glVertex3f( TitikTengah_X + panjang, titik_Y, TitikTengah_Z + lebar);
    glEnd();
}
void segiempatz(int x1, int y1, int x2, int y2, int z )  // segiempat ( kiri , titik bawah , kanan , tinggi , posisi z , r,g,b)
{
    glBegin(GL_QUADS);
    glVertex3f(x2, y1, z);
    glVertex3f(x2, y2, z);
    glVertex3f(x1, y2, z);
    glVertex3f(x1, y1, z);
    glEnd();
}
void segiempatx(int y1, int z1, int y2, int z2, int x )
{
    glBegin(GL_QUADS);
    glVertex3f(x, y1, z2);
    glVertex3f(x, y2, z2);
    glVertex3f(x, y2, z1);
    glVertex3f(x, y1, z1);
    glEnd();
}
void segiempaty(int x1, int z1, int x2, int z2, int y )
{
    glBegin(GL_QUADS);
    glVertex3f(x1, y, z2);
    glVertex3f(x2, y, z2);
    glVertex3f(x2, y, z1);
    glVertex3f(x1, y, z1);
    glEnd();
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
    segiempaty(-90,40,90,-40,-10); // dasar
    //==========================================
    glColor3f(1,1,0);
    balok(0,-15,0,40,80,20);
    glColor3f(1,0,0);
    balok(0,-15,40,60,76,20);
    glColor3f(0,1,0);
    balok(0,-15,60,80,72,20);
    glColor3f(1,1,1);
    balok(0,-15,80,100,68,20);
    glColor3f(1,0,1);
    balok(0,-15,100,110,62,20);
    glColor3f(0,0,1);
    balok(0,5,0,120,10,5);
    glColor3f(0,1,1);
    balok(0,5,120,130,8,5);
    glColor3f(1.5,1,1);
    balok(0,5,130,140,6,5);
    glColor3f(1,1,1);
    balok(0,5,140,160,1,1);

    //===========================
    glColor3f(0,0,1.5);
    balok(0,-10,-10,0,80,40); // bawah
    glColor3f(1,0,1.5);
    balok(0,35,-10,-2,15,5);
    glColor3f(0.5,0,1.5);
    balok(0,40,-10,-5,15,5);

    //------------------star tiang---------
    glColor3f(1,1,1);
    balok(-20,25,0,40,2,2);
    balok(20,25,0,40,2,2);
    balok(-20,15,0,40,2,2);
    balok(20,15,0,40,2,2);// ------------- dua tiang utama
    balok(-78,15,0,40,2,2);
    balok(-62,15,0,40,2,2);
    balok(-46,15,0,40,2,2);
    balok(-30,15,0,40,2,2);// ------------- tiang kiri
    balok(78,15,0,40,2,2);
    balok(62,15,0,40,2,2);
    balok(46,15,0,40,2,2);
    balok(30,15,0,40,2,2);
    //------------------end tiang---------
    //------------------star atas tiang ---------
    balok(49,15,40,45,31,2);
    balok(-49,15,40,45,31,2);
    //------------------star atas tiang ---------
    //------------------star atas tiang ---------
    balok(54,14,15,30,26,1);
    balok(-54,14,15,30,26,1);
    balok(0,18,30,40,22,7);
    //------------------end atas tiang ---------
    //-============-+++++++++++++=== -
    glColor3f(0,0,0);
    for (int j = 0; j<3; j++)
    {
        for(int i =0 ; i < 8-j; i++)
        {
            segiempatz(30.0+((i)*5),45.0+(j*20),34.0+(i*5),55.0+(j*20),6);
            segiempatz(-30.0-((i)*5),45.0+(j*20),-34.0-(i*5),55.0+(j*20),6);
        }
    }
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
