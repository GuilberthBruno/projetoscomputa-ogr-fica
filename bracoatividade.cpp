
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
#include <stdlib.h>

#define ESC 27


static int ombro = 0, cotovelo = 0, punho = 0, visao = 0, mao = 0, anelar = 0, indicador = 0, polegar = 0;


void init(void);
void keyboard (unsigned char key, int x, int y);
void display(void);
void reshape (int w, int h);


int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Computacao Grafica: Braco Robotico");
    init ();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

  return EXIT_SUCCESS;
}


void init(void){
    glClearColor (1.0, 1.0, 1.0, 1.0); 
    glEnable(GL_DEPTH_TEST); 
}


void reshape (int w, int h){
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    gluPerspective(60, (float)w/(float)h , 1.0, 12.0); 
    gluLookAt(0.0,0.0,7.0,  
              0.0,1.0,0.0,  
              0.0,1.0,0.0); 
    
    glMatrixMode (GL_MODELVIEW);

}

// Fucao callback para controle das teclas comuns
void keyboard (unsigned char key, int x, int y){
	switch (key) {
		case 'o': ombro = (ombro - 5) % 360; break; 
		case 'O': ombro = (ombro + 5) % 360; break; 
		case 'c': cotovelo = (cotovelo - 5) % 360; break; 
		case 'C': cotovelo = (cotovelo + 5) % 360; break; 
		case 'm' : punho = (punho - 5) % 360; break;
		case 'M' : punho = (punho + 5) % 360; break;
		case 'y' : visao = (visao - 5) % 360; break;
		case 'Y' : visao = (visao + 5) % 360; break;
		case 'i' : indicador = (indicador - 5) % 360; break;
		case 'I' : indicador = (indicador + 5) % 360; break;
		case 'p' : polegar = (polegar - 5) % 360; break;
		case 'P' : polegar = (polegar + 5) % 360; break;
		case 'a' : anelar = (anelar - 5) % 360; break;
		case 'A' : anelar = (anelar + 5) % 360; break;
		case ESC: exit(EXIT_SUCCESS); break; 
	}
    glutPostRedisplay();
}


void display(void){
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Base
	glPushMatrix();
        glTranslatef(0.0, -2.0, 0.0);
        glRotatef(-90, 1, 0, 0);
        glColor3f(0.0, 0.0, 0.0);
        glutWireCone(1.0, 1.0, 30, 30);
    glPopMatrix();
    
    //Ombro
    glPushMatrix();
        glTranslatef(0.0, -1.0, 0.0);
        glColor3f(0.0, 0.0, 0.0);
       glutSolidSphere(0.5, 30, 30); 
    glPopMatrix();

    //Movimento do braco
    glPushMatrix();
        glRotatef ((GLfloat) visao, 0.0, 1.0, 0.0);
        glTranslatef (0.0, -1.0, 0.0);
        glRotatef ((GLfloat) ombro, 0.0, 0.0, 1.0);
        glTranslatef (0.0, 1.0, 0.0);
        
        // Braco
        glPushMatrix();
           glRotatef(90, 0, 0, 1);
            glScalef (2.0, 0.5, 0.5);
            glColor3f(0.0,0.0,1.0);
            glutSolidCube(1.0); 
        glPopMatrix();

        //Cotovelo
        glPushMatrix();
            glTranslatef(0.0, 1.0, 0.0);
            glColor3f(0.0, 0.0, 0.0);
           glutSolidSphere(0.4, 30, 30); 
        glPopMatrix();

        //Movimento do antebraco
       glPushMatrix();
			glTranslatef (0.0, 1.0, 0.0);
			glRotatef ((GLfloat) cotovelo, 0.0, 0.0, 1.0);
			glTranslatef (0.0, 1.0, 0.0);
         // Antebraco
            glPushMatrix();
                glRotatef(90, 0, 0, 1);
                glScalef (2.0, 0.4, 0.4);
                glColor3f(0.0,1.0,0.0);
                glutSolidCube (1.0); 
    		glPopMatrix();
    		
    		glPushMatrix();
	        	glColor3f(0,0,0);
	        	glTranslatef(0,1.2,0);
	        	glutSolidSphere(0.3,30,30);        
	        glPopMatrix();
			
			//Mão
			glPushMatrix();
				glColor3f(1,0,0);
				glRotatef((GLfloat) punho,0,1,0);
				glRotatef(90,0,0,1);
				glScalef(1.5,0.3,0.3);
				glTranslatef(1,0,0);
				glutSolidCube(1.0);
				
				//Anelar
				glPushMatrix();
					glColor3f(1,1,0);
					glTranslatef(0.6,0.3,0.4);
					glRotatef((GLfloat) anelar,0,1,0);
					glScalef(0.5,0.5,0.5);
					glutSolidCube(0.5);
				glPopMatrix();
				
				//Indicador
				glPushMatrix();
					glColor3f(1,1,0);
					glTranslatef(0.6,0.3,-0.4);
					glRotatef((GLfloat) indicador,0,1,0);
					glScalef(0.5,0.5,0.5);
					glutSolidCube(0.5);
				glPopMatrix();
				
				//Polegar
				glPushMatrix();
					glColor3f(1,1,0);
					glTranslatef(0.6,-0.4,0.0);
					glRotatef((GLfloat) polegar,0,1,0);
					glScalef(0.5,0.5,0.5);
					glutSolidCube(0.5);
				glPopMatrix();
			
			glPopMatrix();
			
			
        glPopMatrix();
        
    glPopMatrix();

    glutSwapBuffers();
}

