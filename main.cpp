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
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(250, 80);
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

void balok(int TitikTengah_X, int TitikTengah_Z, int titik_Y, int tinggi, int panjang, int lebar, int R, int G, int B )
{
    glBegin(GL_QUADS);
    glColor3f(R, G, B);
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
    glVertex3f( TitikTengah_X - panjang, titik_Y, TitikTengah_Z - lebar);
    glEnd();
}

void segiempat(int x1, int y1, int x2, int y2, int z,int R, int G, int B  )  // segiempat ( kiri , titik bawah , kanan , tinggi , posisi z , r,g,b)
{
    glBegin(GL_QUADS);
    glColor3f(R, G, B);
    glVertex3f(x2, y1, z);
    glVertex3f(x2, y2, z);
    glVertex3f(x1, y2, z);
    glVertex3f(x1, y1, z);
    glEnd();
}
void segiempatz(int z1, int y1, int z2, int y2, int x,int R, int G, int B  )  // segiempat ( kiri , titik bawah , kanan , tinggi , posisi z , r,g,b)
{
    glBegin(GL_QUADS);
    glColor3f(R, G, B);
    glVertex3f(x, y1, z2);
    glVertex3f(x, y2, z2);
    glVertex3f(x, y2, z1);
    glVertex3f(x, y1, z1);
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
    // dasar
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-40.0, 0.0, 70.0);  //
    glVertex3f(-40.0, 0.0, -60.0); // belakang
    glVertex3f(50.0, 0.0, -60.0); // belakang
    glVertex3f(50.0, 0.0, 70.0);
    glEnd();

    baru(-75,5,-25,-75,30,0); //papan
    glColor3f(1.0, 0.0, 0.0);
    balok(-60,10,-40,-50,10,5);
    balok(-58,0,-38,-58,10,2);
    baru(-58,0,-38,-52,10,-38);
    baru(-58,0,2,-52,10,2);

    glColor3f(0.0, 1.0, 0.0);//kursi 1
    baru(-45,7,0,-50,7,-10);
    baru(-45,7,0,-50,0,0);
    baru(-45,7,-10,-50,0,-10);
    baru(-45,7,0,-45,15,-10);

    glColor3f(1.0, 0.0, 1.0);//kursi 2
    baru(-45,7,-35,-50,7,-25);
    baru(-45,7,-35,-50,0,-35);
    baru(-45,7,-25,-50,0,-25);
    baru(-45,7,-35,-45,15,-25);

    glColor3f(0.7, 0.5, 0.0);//lemari
    baru(-70,0,-28,-75,25,-35);
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
    baru(-30,0,-35,-35,10,-40);
    baru(-30,10,-40,-35,13,-40);
    baru(-30,10,-40,-30,13,-37);
    baru(-35,10,-40,-35,13,-37);
    baru(-35,13,-40,-30,13,-37);balok(-75,5,-25,-75,30,0); //papan
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

void identity() {
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
}

void idle() {
    if (!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y) {
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
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}
