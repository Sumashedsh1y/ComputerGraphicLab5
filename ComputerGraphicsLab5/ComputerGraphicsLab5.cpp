#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
using namespace sf;
int main()
{
	RenderWindow window(VideoMode(720, 720), "OPENGL");
	GLfloat starColor[8][3] = {
		1, 1, 0,
		1, 1, 0,
		1, 1, 0,
		1, 1, 0,
		1, 1, 0,
		1, 1, 0,
		1, 1, 0,
		1, 1, 0,
	};
	GLfloat starVertex[8][3] = {
		0.1,0.1,0,
		0.3,0,0,
		0.1,-0.1,0,
		0,-0.3,0,
		-0.1,-0.1,0,
		-0.3,0,0,
		-0.1,0.1,0,
		0.0,0.3,0
	};
	GLuint starFace[8][3] = {
		5, 0, 2,
		2, 0, 5,
		1, 4, 6,
		6, 4, 1,
		3, 0, 6,
		6, 0, 3,
		4, 7, 2,
		2, 7, 4,
	};
	GLfloat star2Color[8][3] = {
		1, 1, 0,
		1, 1, 0,
		1, 1, 0,
		1, 1, 0,
		1, 1, 0,
		1, 1, 0,
		1, 1, 0,
		1, 1, 0,
	};
	GLfloat star2Vertex[8][3] = {
		0.1,0.1,0,
		0.3,0,0,
		0.1,-0.1,0,
		0,-0.3,0,
		-0.1,-0.1,0,
		-0.3,0,0,
		-0.1,0.1,0,
		0.0,0.3,0
	};
	GLuint star2Face[12][3] = {
		5, 6, 4,
		4, 6, 5,
		1, 0, 2,
		2, 0, 1,
		3, 2, 4,
		4, 2, 3,
		6, 7, 0,
		0, 7, 6,
		4, 6, 0,
		0, 6, 4,
		0, 4, 2,
		2, 4, 0,
	};
	GLfloat cubeColor[8][3] = {
		0.2, 0, 0,
		0.3, 0, 0,
		0.4, 0, 0,
		0.5, 0, 0,
		0.6, 0, 0,
		0.7, 0, 0,
		0.8, 0, 0,
		1, 0, 0
	};
	GLfloat pyramidColor[11][3] = {
		0.3, 0, 0,
		0.35, 0, 0,
		0.43, 0, 0,
		0.50, 0, 0,
		0.56, 0, 0,
		0.62, 0, 0,
		0.70, 0, 0,
		0.77, 0, 0,
		0.83, 0, 0,
		0.9, 0, 0,
		1, 0, 0
	};
	GLint cubeVertex[8][3] = {
		 1, 1, 1,
		 1, 1, -1,
		 1, -1, 1,
		 1, -1, -1,
		 -1, 1, 1,
		 -1, 1, -1,
		 -1, -1, 1,
		 -1, -1, -1
	};
	GLuint cubeFace[6][4] = {
		0, 4, 5, 1,
		7, 3, 1, 5,
		3, 7, 6, 2,
		2, 6, 4, 0,
		5, 4, 6, 7,
		2, 0, 1, 3
	};

	GLfloat pyramidVertex[7][3]{};
	GLuint pyramidFaces[11][3]{};
	pyramidVertex[0][0] = 0;
	pyramidVertex[0][1] = 1.5;
	pyramidVertex[0][2] = 0;
	for (int i = 0; i < 6; i++) {
		pyramidVertex[i + 1][0] = cos(M_PI / 3 * i);
		pyramidVertex[i + 1][2] = sin(M_PI / 3 * i);
		pyramidVertex[i + 1][1] = 0;
	}
	for (int i = 1; i <= 6; i++) {
		pyramidFaces[i - 1][1] = i;
		pyramidFaces[i - 1][2] = i % 6 + 1;
		pyramidFaces[i - 1][0] = 0;
	}
	for (int i = 1; i < 6; i += 2) {
		pyramidFaces[6 + i / 2][2] = i;
		pyramidFaces[6 + i / 2][1] = i % 6 + 1;
		pyramidFaces[6 + i / 2][0] = (i + 1) % 6 + 1;
	}

	pyramidFaces[9][0] = 5;
	pyramidFaces[9][1] = 3;
	pyramidFaces[9][2] = 1;
	pyramidFaces[10][0] = 2;
	pyramidFaces[10][1] = 1;
	pyramidFaces[10][2] = 3;


	window.setVerticalSyncEnabled(true);
	glClearColor(0, 0.5, 0, 0);
	glLoadIdentity();
	glViewport(0, 0, 720, 720);
	glShadeModel(GL_FLAT);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnable(GL_CULL_FACE);
	glScalef(0.4, 0.4, 0.4);
	while (window.isOpen())
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::KeyPressed:
				switch (event.key.code) {
				case Keyboard::Left:
					glTranslatef(-0.1, 0, 0);
					break;
				case Keyboard::Right:
					glTranslatef(0.1, 0, 0);
					break;
				case Keyboard::Up:
					glTranslatef(0, 0.1, 0);
					break;
				case Keyboard::Down:
					glTranslatef(0, -0.1, 0);
					break;
				case Keyboard::Add:
					glScalef(1.1, 1.1, 1.1);
					break;
				case Keyboard::Subtract:
					glScalef(0.9, 0.9, 0.9);
					break;
				case Keyboard::Q:
					glRotatef(10, 0, 0, 1);
					break;
				case Keyboard::E:
					glRotatef(-10, 0, 0, 1);
					break;
				case Keyboard::W:
					glRotatef(10, 0, 1, 0);
					break;
				case Keyboard::S:
					glRotatef(-10, 0, 1, 0);
					break;
				case Keyboard::A:
					glRotatef(10, 1, 0, 0);
					break;
				case Keyboard::D:
					glRotatef(-10, 1, 0, 0);
					break;
				default:
					break;
				}
				break;
			case Event::MouseWheelScrolled:
				if (event.mouseWheelScroll.wheel == Mouse::VerticalWheel) {
					double approach = event.mouseWheelScroll.delta > 0 ? 1.1 : 0.9;
					glScalef(approach, approach, approach);
				}
				break;
			default:
				break;
			}
		}
		glPushMatrix();
		glTranslatef(0, 1, 0);
		glScalef(1, 1, 1);
		glColorPointer(3, GL_FLOAT, 0, starColor);
		glVertexPointer(3, GL_FLOAT, 0, starVertex);
		glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, starFace);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, -1, 0);
		glScalef(1, 1, 1);
		glColorPointer(3, GL_FLOAT, 0, star2Color);
		glVertexPointer(3, GL_FLOAT, 0, star2Vertex);
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, star2Face);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-1, 0, 0);
		glScalef(0.6, 0.6, 0.6);
		glColorPointer(3, GL_FLOAT, 0, cubeColor);
		glVertexPointer(3, GL_INT, 0, cubeVertex);
		glDrawElements(GL_QUADS, 24, GL_UNSIGNED_INT, cubeFace);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(1, -0.5, 0);
		glScalef(0.8, 0.8, 0.8);
		glColorPointer(3, GL_FLOAT, 0, pyramidColor);
		glVertexPointer(3, GL_FLOAT, 0, pyramidVertex);
		glDrawElements(GL_TRIANGLES, 33, GL_UNSIGNED_INT, pyramidFaces);
		glPopMatrix();
		window.display();
	}
}