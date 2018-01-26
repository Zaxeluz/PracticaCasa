// Graficos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"

#include <iostream>
using namespace std;

GLfloat red, green, blue;

void actualizar()
{
	//Aqui esta bien par cambiar los valores
	//De las variables del programa!	

	/*red += 0.001;
	green += 0.002;
	blue += 0.003;

	if (red > 1) red = 0;
	if (green > 1) green = 0;
	if (blue > 1) blue = 0;*/
}

/*glBegin(GL_LINE_LOOP);
glBegin(GL_QUADS);
glBegin(GL_POLYGONS);
*/

void dibujar()
{
	//Rutina de Dibujo
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.7f, 1.0f);
	glVertex3f(-1.0f, -0.4f, 0.0f);

	glColor3f(0.0f, 0.7f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);

	glColor3f(0.0f, 0.7f, 1.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);

	glColor3f(0.0f, 0.7f, 1.0f);
	glVertex3f(1.0f, -0.4f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES); //Inicia la rutina con un modo de dibujo

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.9f, 0.0f, 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.5f, 0.3f, 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.1f, 0.0f, 0.0f);

	glEnd(); //Termina la rutina

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-0.8f, -0.4f, 0.0f);

	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-0.8f, 0.0f, 0.0f);

	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-0.2f, 0.0f, 0.0f);

	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-0.2f, -0.4f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.55f, -0.4f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.55f, -0.2f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.45f, -0.2f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.45f, -0.4f, 0.0f);
	glEnd();

}

void dibujar2()
{

}

int main()
{
	//Declaración de ventana.
	GLFWwindow * window;
	//Propiedades de la ventana.
	GLfloat ancho = 800;
	GLfloat alto = 800;

	//Inicialización de GLFW.
	if (!glfwInit())
	{
		//Si no se inició bien, terminar la ejecución.
		exit(EXIT_FAILURE);
	}

	//Inicializar la ventana.
	window = glfwCreateWindow(ancho, alto, "Gráficos", NULL, NULL);

	//Verificar si se creó bien la ventana.
	if (!window)
	{
		//Cerrar todos los procesos de GLFW
		glfwTerminate();
		//Terminar ejecución.
		exit(EXIT_FAILURE);
	}

	//Establecer "window" como contexto.
	glfwMakeContextCurrent(window);

	//Se trae las funciones de OpenGL Moderno.
	glewExperimental = true;

	//Inicializar GLEW
	GLenum glewError = glewInit();

	//Verificar que GLEW se inicializó bien.
	if (glewError != GLEW_OK)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	red = green = blue = 0.0f;
	//Ciclo de dibujo.
	while (!glfwWindowShouldClose(window))
	{
		//Establecer el area de render (viewport).
		glViewport(0, 0, ancho, alto);
		//Establecer el color con el que se limpia la pantalla.
		glClearColor(red, green, blue, 1);
		//Limpiar la pantalla.
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de dibujo.
		actualizar();
		dibujar();

		//Intercambio de buffers.
		glfwSwapBuffers(window);

		//Buscar señales de entrada
		glfwPollEvents();


	}
	/*ok*/
	glfwDestroyWindow(window);
	glfwTerminate();



	return 0;
}


