#ifdef __APPLE__ 
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else 
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#endif
#include <stdio.h>
#include <math.h>
#include "circulo.h"
#define ESC 27 

float R,G,B;
void init(void);
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);
void display(void);



int main(int argc, char** argv)
{
	glutInit(&argc, argv); 
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize (512, 512);  
    glutInitWindowPosition (100, 100); 
    glutCreateWindow ("Palhaço"); 
    init(); 
    glutReshapeFunc(reshape); 
    glutDisplayFunc(display); 
    glutKeyboardFunc(keyboard); 
    glutMainLoop(); 
    return EXIT_SUCCESS;	
}

void init(void){
    glClearColor(1.0, 1.0, 1.0, 1.0); //Limpa a tela com a cor branca;
    R = 0.0;
    G = 0.0;
    B = 0.0;
}

void reshape(int w, int h)
{
	// Reinicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

    // Definindo o Viewport para o tamanho da janela
	glViewport(0, 0, w, h);

 //   glOrtho (0, 512, 0, 512, -1 ,1); 

//   glOrtho (-256, 256, -256, 256, -1 ,1); // Nesse caso, continuamos com 512 pixels, porem o
                                            // centro dos eixos passa a se localizar no centro
                                            // da tela.

   glOrtho (-(w/2), (w/2),-(h/2),(h/2), -1 ,1);   // Nesse caso, ficamos com a quantidade de pixels variavel,
                                                    // dependente da largura e altura da janela, e o
                                                    // centro dos eixos continua a se localizar no centro
                                                    // da tela.
    
  
	glMatrixMode(GL_MODELVIEW);
}


void keyboard(unsigned char key, int x, int y){
    switch (key) {
        case ESC: exit(EXIT_SUCCESS); break; 
    }
}

void display(void){
	//chapeu
	glPushMatrix();
		glClear(GL_COLOR_BUFFER_BIT); 
		glLoadIdentity();
		glColor3f(0,0,1);
		glBegin(GL_TRIANGLES);
			glVertex2f(0,502);
			glVertex2f(-50,462);
			glVertex2f(50,462);
		glEnd();
	glPopMatrix();
	
	//cabeça
	glPushMatrix();
		glColor3f(1,1,0);
		glTranslatef(0,420,0);
		desenhaCirculo(40,100,true);
	glPopMatrix();
	
	//corpo	
		glColor3f(0,0,1);
		glBegin(GL_TRIANGLE_STRIP);
			glVertex2f(-50,380);
			glVertex2f(50,380);
			glVertex2f(-50,260);
			glVertex2f(50,260);
		glEnd();
		
		glPushMatrix();
			glColor3f(1,1,0);
			glRotatef(75,0,0,1);
			glTranslatef(55,180,0);
			glBegin(GL_TRIANGLE_STRIP);
				glVertex2f(250,180);
				glVertex2f(300,180);
				glVertex2f(250,150);
				glVertex2f(300,150);
			glEnd();
		glPopMatrix();
		
		glPushMatrix();
			glColor3f(1,1,0);
			glRotatef(105,0,0,1);
			glTranslatef(55,-505,0);
			glBegin(GL_TRIANGLE_STRIP);
				glVertex2f(250,180);
				glVertex2f(300,180);
				glVertex2f(250,150);
				glVertex2f(300,150);
			glEnd();
		glPopMatrix();
		
		glPushMatrix();
			glColor3f(1,1,0);
			glRotatef(25,0,0,1);
			glTranslatef(-160,-145,0);
			glBegin(GL_TRIANGLE_STRIP);
				glVertex2f(250,180);
				glVertex2f(300,180);
				glVertex2f(250,150);
				glVertex2f(300,150);
			glEnd();
		glPopMatrix();
		
		glPushMatrix();
			glColor3f(1,1,0);
			glRotatef(155,0,0,1);
			glTranslatef(-145,-182,0);
			glBegin(GL_TRIANGLE_STRIP);
				glVertex2f(250,180);
				glVertex2f(300,180);
				glVertex2f(250,150);
				glVertex2f(300,150);
			glEnd();
		glPopMatrix();
		
		//pernas e braços
		glColor3f(1,0,0);
		glPushMatrix();
			glRotatef(15,0,0,1);
			glBegin(GL_TRIANGLE_STRIP);
				glVertex2f(145,305);
				glVertex2f(315,305);
				glVertex2f(145,355);
				glVertex2f(315,355);
			glEnd();
		glPopMatrix();
		
		glColor3f(1,0,0);
		glPushMatrix();
			glTranslatef(-188,753,0);
			glRotatef(-195,0,0,1);
			glBegin(GL_TRIANGLE_STRIP);
				glVertex2f(-55,325);
				glVertex2f(-230,325);
				glVertex2f(-55,375);
				glVertex2f(-230,375);
			glEnd();
		glPopMatrix();
		
		glPushMatrix();
			glColor3f(1,0,0);
			glRotatef(-15,0,0,1);
			glTranslatef(-65,235,0);
			glBegin(GL_TRIANGLE_STRIP);
				glVertex2f(0,0);
				glVertex2f(0,-175);
				glVertex2f(-50,0);
				glVertex2f(-50,-175);
			glEnd();
		glPopMatrix();
		
		glPushMatrix();
			glRotatef(15,0,0,1);
			glTranslatef(65,235,0);
			glColor3f(1,0,0);
			glBegin(GL_TRIANGLE_STRIP);
				glVertex2f(0,0);
				glVertex2f(0,-175);
				glVertex2f(50,0);
				glVertex2f(50,-175);
			glEnd();
		glPopMatrix();
		
		// Olhos
		glColor3f(0, 0, 0); 
		glPushMatrix();
		glTranslatef(-15, 445, 0); 
		desenhaCirculo(8, 100, true); 
		glPopMatrix();

		glPushMatrix();
		glTranslatef(15, 445, 0); 
		desenhaCirculo(8, 100, true); 
		glPopMatrix();
		
		
		glColor3f(1, 1, 1); 
		for (int i = -20; i <= 20; i += 10) {
		    glPushMatrix();
		    glTranslatef(i, 400, 0); 
		    desenhaCirculo(5, 100, true); 
		    glPopMatrix();
		}
		
		// Nariz
		glColor3f(1, 0, 0); 
		glPushMatrix();
		glTranslatef(0, 420, 0);
		desenhaCirculo(10, 100, true); 
		glPopMatrix();
		
	
		glColor3f(0, 1, 0); 
		for (int i = 0; i < 3; i++) {
		    glPushMatrix();
		    glTranslatef(0, 350 - i * 30, 0); 
		    desenhaCirculo(15, 100, true); 
		    glPopMatrix();
}

    glFlush();

}







