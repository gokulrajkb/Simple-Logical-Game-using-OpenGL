#include<stdio.h>
#include<gl/glut.h>
#include<math.h>
#include<Windows.h>
#include<stdlib.h>
int  i=0, m=0, h=0, f=0, b=0,start=0,w=0,qqq=0;
int sh = 0, ww = 1000, hh = 1000;
float pi = 3.142;
void init()
{
	gluOrtho2D(0, 1000, 0, 1000);
}
void hen()
{
	int ss = 150, mm = 155,e=0;
	glBegin(GL_POLYGON);//body
	glColor3f(0.7, 0.2, 0.1);
	glVertex2f(400 + ss, 700+e);
	glColor3f(0.7, 0.2, 0.1);
	glVertex2f(350 +ss , 650+e);
	glColor3f(1, 0, 0);
	glVertex2f(400 +ss , 650+e);
	glColor3f(1, 0, 0);
	glVertex2f(350 +ss , 630+e);
	glColor3f(0.7, 0.2, 0.1);
	glVertex2f(380 + ss, 630+e);
	glColor3f(0.7, 0.2, 0.1);
	glVertex2f(360 + ss, 570+e);
	glColor3f(0.7, 0.2, 0.1);
	glVertex2f(430 + ss, 600+e);
	glColor3f(0.7, 0.2, 0.1);
	glVertex2f(500 + ss, 500+e);
	glColor3f(0.7, 0.2, 0.1);
	glVertex2f(800 + ss, 500+e);
	glColor3f(0.7, 0.2, 0.1);
	glVertex2f(650 + ss, 600+e);
	glColor3f(0.7, 0.2, 0.1);
	glVertex2f(800+ ss, 400+e);
	glColor3f(0.7, 0.2, 0.1);
	glVertex2f(500 + ss, 600+e);
	glEnd();

	glBegin(GL_POLYGON);//body
	glColor3f(0, 0, 1);
	glVertex2f(400+mm, 640);
	glVertex2f(410+mm, 640);
	glVertex2f(410+mm, 650);
	glVertex2f(400+mm, 650);
	glEnd();

	glBegin(GL_LINES);//body
	glColor3f(1, 0, 0);
	glVertex2f(700, 500);
	glVertex2f(700, 450);
	glEnd();

	glBegin(GL_LINES);//body
	glColor3f(1, 0, 0);
	glVertex2f(730, 500);
	glVertex2f(730, 450);
	glEnd();
}
void boat(int x,int y)
{
	
			glBegin(GL_POLYGON);//BOAT
			glColor3f(0.7, 0.2, 0.1);
			glVertex2f(400+x , 150+y);
			glVertex2f(550+x, 150+y);
			glVertex2f(600+x, 200+y);
			glVertex2f(350+x, 200+y);
			glEnd();

			glBegin(GL_POLYGON);//stick
			glColor3f(1, 0, 1);
			glVertex2f(350+x, 150+y);
			glVertex2f(360+x, 150+y);
			glVertex2f(460+x, 200+y);
			glVertex2f(450 + x, 200 + y);
			glEnd();
	
}
typedef struct
{
	int x;
	int y;
}point;
typedef struct
{
	int x, y, font;
}tr;
double inc = pi / 6, ang1 = 3 * pi / 2;	//tree construction
point pp, pq;
//used to draw  tree
point getpoint(int x, int y, int a, int b, double t)
{
	point s;
	s.x = x + a*cos(t);
	s.y = y + b*sin(t);
	return s;
}
tr ts1[8] = { { 50, 350, 3 }, { 50, 720, 2 }, { 80, 200, 2 }, { 680, 750, 3 }, { 900, 550, 2 } }; // postion to construct trees ... used in main screen
//to draw tree
void tree(GLint x, GLint y, GLint font)
{
	GLfloat inc, p, q, r, s, a, b, t1, t2;
	inc = font * 10;
	p = x + inc;
	r = x - inc;
	q = s = y;
	a = font * 5;
	b = font * 20;
	t2 = 3 * pi / 2;
	t1 = pi / 2;

	glColor3f(0.7, 0.2, 0.1);

	point p1, p2;
	double ang1 = 3 * pi / 2, ang2 = 3 * pi / 2;
	while (ang2 >= pi / 2)								// to draw the stem of tree
	{
		p1 = getpoint(p, q, a, b, ang2);
		p2 = getpoint(r, s, a, b, ang1);
		glColor3f(0.7, 0.2, 0.1);
		glBegin(GL_LINES);
		glVertex2f(p1.x, p1.y);
		glVertex2f(p2.x, p2.y);
		glEnd();

		ang1 += 0.01;
		ang2 -= 0.01;
	}

	b = font * 50;
	a = font * 15;
	glColor3f(0, 0.8, 0.1122);

	point pp, pq;
	glColor3f(0, 0.8, 0.1122);					//color and code to draw the leaves of the tree
	glBegin(GL_POLYGON);
	for (double i = 0; i<pi; i += 0.3142)
	{
		pp = getpoint(x, y + font * 10, a, b, i);
		pq = getpoint(x, y + font * 10, a + 10, b + 10, i + 0.1571);
		glVertex2f(pp.x, pp.y);
		glVertex2f(pq.x, pq.y);
	}
	pp = getpoint(x, y + font * 10, a, b, i);
	glVertex2f(pp.x, pp.y);
	glEnd();

	glFlush();

}
void d1()
{
	int i;
for (i = 0; i < 5;i++)
		tree(ts1[i].x, ts1[i].y, ts1[i].font);
}
void river( )
{

	glColor3f(0.9, 0.9, 1);//river
	glBegin(GL_POLYGON);
	glVertex2f(400, 0);
	glColor3f(0.1, 0, 1);
	glVertex2f(900, 0);
	glColor3f(0.3, 0.6, 1);
	glVertex2f(426, 770);
	glColor3f(0.2, 0, 1);
	glVertex2f(200, 770);
	glColor3f(0.2, 0.7, 1);
	glEnd();
}
void city()
{
	int x = 780,x1=650,x2=400;
	glBegin(GL_POLYGON);//house
	glColor3f(1, 0.2, 1);
	glVertex2f(100+x, 700);
	glVertex2f(200 + x, 700);
	glVertex2f(200 + x, 800);
	glVertex2f(100 + x, 800);
	glEnd();

	glBegin(GL_POLYGON);//door
	glColor3f(1, 1, 1);
	glVertex2f(145 + x, 700);
	glVertex2f(165 + x, 700);
	glVertex2f(165 + x, 740);
	glVertex2f(145 + x, 740);
	glEnd();

	glBegin(GL_POLYGON);//top
	glColor3f(0, 1, 0);
	glVertex2f(80 + x, 800);
	glVertex2f(220 + x, 800);
	glVertex2f(150 + x, 850);
	glEnd();

	glBegin(GL_POLYGON);//house 2
	glColor3f(1, 0.2, 1);
	glVertex2f(100 + x1, 700);
	glVertex2f(200 + x1, 700);
	glVertex2f(200 + x1, 800);
	glVertex2f(100 + x1, 800);
	glEnd();

	glBegin(GL_POLYGON);//door 2
	glColor3f(1, 1, 1);
	glVertex2f(145 + x1, 700);
	glVertex2f(165 + x1, 700);
	glVertex2f(165 + x1, 740);
	glVertex2f(145 + x1, 740);
	glEnd();

	glBegin(GL_POLYGON);//top 2
	glColor3f(0, 1, 0);
	glVertex2f(80 + x1, 800);
	glVertex2f(220 + x1, 800);
	glVertex2f(150 + x1, 850);
	glEnd();

	glBegin(GL_POLYGON);//house 3
	glColor3f(1, 0.2, 1);
	glVertex2f(100 + x2, 700);
	glVertex2f(200 + x2, 700);
	glVertex2f(200 + x2, 800);
	glVertex2f(100 + x2, 800);
	glEnd();

	glBegin(GL_POLYGON);//door 3
	glColor3f(1, 1, 1);
	glVertex2f(145 + x2, 700);
	glVertex2f(165 + x2, 700);
	glVertex2f(165 + x2, 740);
	glVertex2f(145 + x2, 740);
	glEnd();

	glBegin(GL_POLYGON);//top 3
	glColor3f(0, 1, 0);
	glVertex2f(80 + x2, 800);
	glVertex2f(220 + x2, 800);
	glVertex2f(150 + x2, 850);
	glEnd();

}
void house()
{
	glBegin(GL_POLYGON);//house man
	glColor3f(1, 0.2,1);
	glVertex2f(100, 700);
	glVertex2f(200, 700);
	glVertex2f(200, 800);
	glVertex2f(100, 800);
	glEnd();

	glBegin(GL_POLYGON);//door man
	glColor3f(1, 1, 1);
	glVertex2f(145, 700);
	glVertex2f(165, 700);
	glVertex2f(165, 740);
	glVertex2f(145, 740);
	glEnd();

	glBegin(GL_POLYGON);//top man
	glColor3f(0, 1, 0);
	glVertex2f(80, 800);
	glVertex2f(220, 800);
	glVertex2f(150, 850);
	glEnd();
}
void Background()
{
glColor3f(0,0.6,0.25);//grass
glBegin(GL_POLYGON);
glVertex2f(0,0);
glColor3f(0,0.6,0.25);
glVertex2f(1360,0);
glColor3f(0,0.6,0.25);
glVertex2f(1360,770);
glColor3f(0,0.6,0.25);
glVertex2f(0,770);
glColor3f(0,0.6,0.25);
glEnd();

glColor3f(0.9, 0.9, 0.95);//sky
glBegin(GL_POLYGON);
glVertex2f(0, 770);
glColor3f(0.4, 0.5, 1);
glVertex2f(1360, 770);
glColor3f(0.3, 0.5, 1);
glVertex2f(1360, 1000);
glColor3f(0.3, 0.4, 1);
glVertex2f(0, 1000);
glColor3f(0.5, 0.8, 1);
glEnd();

}
void hen(int x,int y)
{
	int i = 12, j = 151;
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(900+x, 300+y);
	glVertex2f(950+x, 300+y);
	glVertex2f(950+x, 350+y);
	glVertex2f(900+x, 350+y);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex2f(990  + x, 350 + y);
	glVertex2f(990  + x, 340 + y);
	glVertex2f(950  + x, 330 + y);
	glVertex2f(950  + x, 340 + y);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex2f(940  + x, 350 + y);
	glVertex2f(940  + x, 340 + y);
	glVertex2f(900  + x, 330 + y);
	glVertex2f(900  + x, 340 + y);
	glEnd();

	if (h == 0 || h == 3)
	{

		glBegin(GL_POLYGON);
		glColor3f(255, 255, 255);
		glVertex2f(905 + x + i, 150 + y + j);
		glVertex2f(910 + x + i, 150 + y + j);
		glVertex2f(905 + x + i, 120 + y + j);
		glVertex2f(910 + x + i, 120 + y + j);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(255, 255, 255);
		glVertex2f(925 + x + i, 150 + y + j);
		glVertex2f(920 + x + i, 150 + y + j);
		glVertex2f(925 + x + i, 120 + y + j);
		glVertex2f(920 + x + i, 120 + y + j);
		glEnd();
	}

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 1);
	glVertex2f(900 + x + i, 225 + y + j);
	glVertex2f(910 + x + i, 225 + y + j);
	glVertex2f(905 + x + i, 220 + y + j);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 1);
	glVertex2f(920 + x + i, 225 + y + j);
	glVertex2f(930 + x + i, 225 + y + j);
	glVertex2f(920 + x + i, 220 + y + j);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 1);
	glVertex2f(910 + x + i, 215 + y + j);
	glVertex2f(920 + x + i, 215 + y + j);
	glVertex2f(920 + x + i, 210 + y + j);
	glVertex2f(910 + x + i, 210 + y + j);
	glEnd();
}
void fox(int x, int y)
{
	int m = 725, n = 225;
	glBegin(GL_POLYGON);
	glColor3f(255, 215, 0);
	glVertex2f(800 + x, 300 + y);
	glVertex2f(850 + x, 300 + y);
	glVertex2f(850 + x, 350 + y);
	glVertex2f(800 + x, 350 + y);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex2f(100 + x + m, 100 + y + n);
	glVertex2f(130 + x + m, 100 + y + n);
	glVertex2f(130 + x + m, 90 + y + n);
	glVertex2f(100 + x + m, 90 + y + n);
	glEnd();

}
void bag(int x, int y)
{
	int i=-89, j=252,m=720,n=350;
	glBegin(GL_POLYGON);
	glColor3f(255, 228, 196);
	glVertex2f(800 + x, 400 + y);
	glVertex2f(850 + x, 400 + y);
	glVertex2f(850 + x, 450 + y);
	glVertex2f(800 + x, 450 + y);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex2f(100+m+x,100+n+y);
	glVertex2f(110+m+x,100+n+y);
	glVertex2f(115+m+x,70+n+y);
	glVertex2f(107+m+x,60+n+y);
	glVertex2f(95+m+x,70+n+y);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex2f(900-20 + x, 450 + y);
	glVertex2f(900-20 + x, 440 + y);
	glVertex2f(870-20 + x, 430 + y);
	glVertex2f(870-20 + x, 440 + y);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex2f(930-100 + x, 450 + y);
	glVertex2f(930-100 + x, 440 + y);
	glVertex2f(900-100 + x, 430 + y);
	glVertex2f(900-100 + x, 440 + y);
	glEnd();

	if (b == 0 || b == 3)
	{

		glBegin(GL_POLYGON);
		glColor3f(0, 0, 0);
		glVertex2f(905 + x+i, 150 + y+j);
		glVertex2f(910 + x+i, 150 + y+j);
		glVertex2f(905 + x+i, 120 + y+j);
		glVertex2f(910 + x+i, 120 + y+j);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0, 0, 0);
		glVertex2f(925 + x+i, 150 + y+j);
		glVertex2f(920 + x+i, 150 + y+j);
		glVertex2f(925 + x+i, 120 + y+j);
		glVertex2f(920 + x+i,120 + y+j);
		glEnd();
	}

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 1);
	glVertex2f(900 + x+i, 225 + y+j);
	glVertex2f(910 + x+i, 225 + y+j);
	glVertex2f(905 + x+i, 220 + y+j);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 1);
	glVertex2f(920 + x+i, 225 + y+j);
	glVertex2f(930 + x+i, 225 + y+j);
	glVertex2f(920 + x+i, 220 + y+j);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 1);
	glVertex2f(910 + x+i, 215 + y+j);
	glVertex2f(920 + x+i, 215 + y+j);
	glVertex2f(920 + x+i, 210 + y+j);
	glVertex2f(910 + x+i, 210 + y+j);
	glEnd();

}
void man(int x, int y)
{
	int o =800, n =11;
	glBegin(GL_POLYGON);
	//glColor3f(128,128,0);
	glColor3f(0.7, 0.2, 0.1);
	glVertex2f(900 + x, 100 + y);
	//glColor3f(0, 1, 0);
	glVertex2f(930 + x, 100 + y);
	//glColor3f(1, 0, 1);
	glVertex2f(930 + x, 200 + y);
	//glColor3f(0, 1, 0);
	glVertex2f(900 + x, 200 + y);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex2f(100 + x + o, 100 + y + n);
	glVertex2f(130 + x + o, 100 + y + n);
	glVertex2f(130 + x + o, 90 + y + n);
	glVertex2f(100 + x + o, 90 + y + n);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex2f(900 + x, 180 + y);
	glVertex2f(900 + x, 170 + y);
	glVertex2f(870 + x, 160 + y);
	glVertex2f(870 + x, 170 + y);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex2f(930 + x, 180 + y);
	glVertex2f(930 + x, 170 + y);
	glVertex2f(900 + x, 160 + y);
	glVertex2f(900 + x, 170 + y);
	glEnd();

	if (m==0||m==3)
	{

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	glVertex2f(905 + x, 100 + y);
	glVertex2f(910 + x, 100 + y);
	glVertex2f(905 + x, 70 + y);
	glVertex2f(910 + x, 70 + y);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	glVertex2f(925 + x, 100 + y);
	glVertex2f(920 + x, 100 + y);
	glVertex2f(925 + x, 70 + y);
	glVertex2f(920 + x, 70 + y);
	glEnd();
}

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 1);
	glVertex2f(900+x,225+y);
	glVertex2f(910+x,225+y);
	glVertex2f(905+x,220+y);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 1);
	glVertex2f(920 + x, 225 + y);
	glVertex2f(930 + x, 225 + y);
	glVertex2f(920 + x, 220 + y);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 1);
	glVertex2f(910 + x, 215 + y);
	glVertex2f(920 + x, 215 + y);
	glVertex2f(920+ x, 210 + y);
	glVertex2f(910 + x, 210 + y);
	glEnd();


}
void circle(int x,int y,int r)
{
	float i, angle;
	glColor3f(1, 0, 0);
//	glBegin(GL_POLYGON);
	glBegin(GL_LINE_STRIP);
	for (i = 0; i < 360; i++)
	{
		angle = 3.142 / 180 * i;
		glVertex2f(x+915 + cos(angle)*r, y+220 + sin(angle)*r);

	}
	glEnd();
}
void hat(int x, int y, int r)
{
	float i, angle;
	int m = 790, n =122;
	glColor3f(1, 0, 0);
		glBegin(GL_POLYGON);
		for (i = 0; i < 180; i++)
	{
		angle = 3.142 / 180 * i;
		glVertex2f(x + 915 + cos(angle)*r, y + 220 + sin(angle)*r);

	}
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(100 + x + m, 100 + y+n);
	glVertex2f(150 + x + m, 100 + y + n);
	glVertex2f(150 + x + m, 90 + y + n);
	glVertex2f(100 + x + m, 90 + y + n);
	glEnd();
}

void sun()
{
	float angle;    //sun
	glPushMatrix();
	glTranslatef(250, 900, 0);
	glColor3f(1, 1, 0);
	glBegin(GL_TRIANGLE_STRIP);
	for (i = 0; i<360; i++)
	{
		angle = (3.1415 / 4.0)*i;
		glVertex2f(40 * cos(angle) + 0.5, 40 * sin(angle) + 0.5);
		glVertex2f(30 * cos(angle) + 0.5, 30 * sin(angle) + 0.5);
		glVertex2f(0.5, 0.5);
	}
	glEnd();
	glPopMatrix();
}

void mouse(int button, int state, int x, int y)
{
	int qq = 600,x1,y1;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		x1 = x;
		y1 = y;
		//printf("\n%d %d\n", x, y);
		//printf("\n%d %d\n", x1, y1);
		y1 = qq - y1;
		
		if ((x1>540 && x1<560)&&(y1>60 && y1<120))
		{
			if (m == 0)
				m = 1;
			glutPostRedisplay();
				
		}

		if((x1>370 && x1<390) && (y1>120 && y1<180))
		{
			if (m == 1)
				m = 0;
			glutPostRedisplay();

		}

		if ((x1>540 && x1<570) && (y1>180 && y1<210))
		{
			if ( h == 0 &&(b == 0||b==3) &&( f == 0||f==3))
				h = 1;
			glutPostRedisplay();

		}
		if ((x1>480 && x1<510) && (y1>240 && y1<270))
		{
			if (( h == 0||h==3) && b == 0 && (f == 0||f==3))
				b = 1;
			glutPostRedisplay();
		}
		if ((x1>480 && x1<510) && (y1>180 && y1<210))
		{
		
			if (( h == 0||h==3) &&( b == 0||b==3) && f == 0)
				f= 1;
			glutPostRedisplay();
		}
		if ((x1>375 && x1<500) && (y1>100 && y1<120))
		{
			
			if (m == 1)
				sh = 1;
			if (f == 1&&(m==1||m==2))
				f = 2;
			if (m == 1&&(m==1||m==2))
				m = 2;
			if (h == 1&&(m==1||m==2))
				h = 2;
			if (b == 1&&(m==1||m==2))
				b = 2;
			glutPostRedisplay();
		}
		if ((x1>280 && x1<330) && (y1>120 && y1<150))
		{
		
			if ((m == 2||m==3) && sh == 1)
			{
				if (h == 2)
					h = 3;
				if (b == 2)
					b = 3;
				if (f == 2)
					f = 3;
			
			}
			glutPostRedisplay();
		}
		if ((x1>150&& x1<180) && (y1>150 && y1<180))
		{
			
			if (m == 2 || m == 3)
			{
				if ((h == 0 || h == 3) && (b == 0 || b == 3) && f == 3)
				{
					if (f == 3)
						f = 2;
				}
			}
			glutPostRedisplay();
		}

		if ((x1>90 && x1<120) && (y1>240 && y1<270))
		{

			if (m == 2 || m == 3)
			{
				if (h == 3 && (b == 0 || b == 3) && (f == 0 || f == 3))
				{
					if (h == 3)
						h = 2;
				}
			}
			glutPostRedisplay();
		}
		if ((x1>120 && x1<150) && (y1>300 && y1<330))
		{

			if (m == 2 || m == 3)
			{
				if ((h == 0 || h == 3) && b == 3 && (f == 0 || f == 3))
				{
					if (b == 3)
						b = 2;
				}
			}
			glutPostRedisplay();
		}

		if ((x1>200 && x1<330) && (y1>100 && y1<120))
		{
			if (m == 2)
			{
				m = 1;
				if (h == 2)
					h = 1;
				if (b == 2)
					b = 1;
				if (f == 2)
					f = 1;
				sh = 0;
			}
			glutPostRedisplay();
		}
		if ((x1>480 && x1<510) && (y1>120 && y1<150))
		{
			if (m == 1||m==0)
			{
				if (h == 1)
					h = 0;
				if (b == 1)
					b = 0;
				if(f == 1)
					f = 0;
			
			}
			glutPostRedisplay();
		}

		if ((x1>210 && x1<230) && (y1>120 && y1<180))
		{
			if (m == 2)
			{
				m = 3;	
			}
			glutPostRedisplay();
		}


	if ((x1>120 && x1<140) && (y1>60 && y1<120))
		{
			//printf("hrrr");
			if (m == 3)
			{
				m = 2;

			}
			glutPostRedisplay();
		}

	}

}

void drawhit(const char * message, int x, int y)
{
	glPushMatrix();
	glScalef(0.4, 0.4, 0.3);
	glTranslatef(x, y, 0);
	while (*message)
	{
		glColor3f(0, 0, 1);
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *message++);
	}
	glPopMatrix();
}
void key(unsigned char d,int x,int y)
{
	
	if (d == 's')
		w = 1;
	glutPostRedisplay();
	if (d == 'x')
		exit(0);
	if (d == 'b')
	{
		qqq = 1;
	}
}
void display()
{
	
		glClear(GL_COLOR_BUFFER_BIT);
		Background();
		river();
		if (qqq == 1)
		{
			drawhit("LOGICAL MOVE", 650, 1500);
			drawhit("*****_____________*****", 150, 1450);
			drawhit("Developed By:", 250, 1200);
			drawhit("Gokul.K.B", 1250, 1100);
			drawhit("Ashik.M.S", 1250, 900);
			drawhit("***______________***", 180, 800);
			drawhit("Back: Press space", 650, 150);
			qqq = 0;
			start == 0;

		}
		if (start == 0)
		{
			drawhit("PRESS SPACEBAR TO START", 400, 1200);
			drawhit("x) EXIT", 600, 1000);
			drawhit("b) ABOUT", 600, 850);
			start = 1;
		}
			if (sh == 0)
			{
				boat(260, 0);
			}
			if (sh == 1)
			{
				boat(-30, 0);	
			}
			
			if (f == 0)
			{
				fox(0, 0);
			}
			if (f == 1)
			{
				fox(0, -100);
			}
			if (f == 2)
			{
				fox(-300, -100);
			}
			if (b == 0)
			{
				bag(0, 0);
				circle(-90,252,22);
			}
			if (b == 1)
			{
				bag(0, -200);
				circle(-90, 52, 22);
			}
			if (b == 2)
			{
				bag(-320, -200);
				circle(-410, 52, 22);
			}
			if (h == 0)
			{
				hen(0, 0);
					circle(10, 155, 22);
			}
			if (h == 1)
			{
				hen(-100, -100);
				circle(-90, 52, 22);
			}
			if (h == 2)
			{
				hen(-400, -100);
				circle(-390, 52, 22);
			}
			if (m == 0)
			{

				man(0, 0);
				circle(0, 0, 20);
				hat(0,20,20);
			}
			if (m == 1)
			{

				man(-280, 100);
				circle(-280, 100, 20);
				hat(-280, 120, 20);
			}
			if (m == 2)
			{
				man(-550, 100);
				circle(-550,100, 20);
				hat(-550, 120, 20);
			}
			if (h == 3)
			{
				hen(-750, 100);
				circle(-738, 252, 22);

			}
			if (b == 3)
			{
				bag(-600, 100);
				circle(-688, 352, 22);
			}
			if (f == 3)
			{
				fox(-550, -50);
			}
			if (m == 3)
			{
				man(-700, 0);
				circle(-700, 0, 20);
				hat(-700, 20, 20);
			}	
		d1();
		sun();
		city();
		house();
		if(m==3&& h==3&&b==3&&f==3&&sh==1)
		{
			drawhit("YOU WIN", 750, 1200);
			drawhit("PRESS X TO EXIT  ", 550, 1000);
		}
		if(h==0&&b==0&&(f==1||f==3)&&m!=0)
		{
			drawhit("YOU LOST", 750, 1200);
			drawhit("TRY AGAIN", 750, 1000);
			drawhit("PRESS X TO EXIT  ", 550, 800);
		}
		if (h == 0 &&( b == 1||b==3) && f == 0 && m != 0)
		{
			drawhit("YOU LOST", 750, 1200);
			drawhit("TRY AGAIN", 750, 1000);
			drawhit("PRESS X TO EXIT  ", 550, 800);
		}
		if (h == 3 && b == 3&&m!=3&&(f==0||f==1||f==2))
		{
			drawhit("YOU LOST", 750, 1200);
			drawhit("TRY AGAIN", 750, 1000);
			drawhit("PRESS X TO EXIT  ", 550, 800);
		}
		
		if (f == 3 && h == 3 &&m!=3&& (b == 0 || b == 1 || b == 2))
		{
			drawhit("YOU LOST", 750, 1200);
			drawhit("TRY AGAIN", 750, 1000);
			drawhit("PRESS X TO EXIT  ", 550, 800);
		}
		glFlush();
}
void reshape(int ww, int hh)
{
	glViewport(0, 0, ww, hh);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w < h)
		glOrtho(-2, +2, -2 * hh / ww, +2 * hh / ww, -10, +10);
	else
		glOrtho(-2* ww / hh, +2 * ww / hh, -2, +2, -10, +10);
	glMatrixMode(GL_MODELVIEW);
}
void main()
{
	printf("\t\t*****************  LOGICAL MOVE  ********************\n\n\n");
	printf("  Description:\n\n");
	printf("\t       A police man has to shift a ROBBER , WITNESS and GOLD BOX across the river with out losing anyone.\n");
	printf("\t       Make logical decisions to complet this logical game . Follow the instructions and Restrictions to complete the game\n\n");
	printf("  Restrictions:\n");
	printf("\n\n\t1) Police is must inorder to move boat\n\t2) Only one object can be carried through boat at a time\n");
	printf("\t3) But all the three objects can be together\n");
	printf("\t4) Robber and Witness should not be together (police must be present)");
	printf("\t\t5) Robber and Gold should not be together (police must be present)\n\n");
	printf("  Instructions:\n\n");
	printf("\t1) you can make as many moves you need\n\t2) you can move objects too and fro\n\t3) Use mouse to choose the objects\n");

	glutInitDisplayMode(GLUT_DEPTH|GLUT_SINGLE);
	glutInitWindowSize(600, 600);
	glutCreateWindow("gokul");
	init();
//	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(key);
	glutMouseFunc(mouse);
	glutMainLoop();
}