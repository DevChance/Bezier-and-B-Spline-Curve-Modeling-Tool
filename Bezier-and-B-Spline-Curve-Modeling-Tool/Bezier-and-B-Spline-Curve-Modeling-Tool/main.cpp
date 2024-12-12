/*************************************************************************/
/***** Curve Modeling and Visualization Framework: Skeleton Code     *****/
/***** Adapted from the University of California: San Diego Computer *****/
/***** Graphics Course. Originally structured by UCSD faculty and    *****/
/***** updated for modern OpenGL practices. This serves as the       *****/
/***** starting point for interactive curve rendering using Bezier   *****/
/***** and B-Spline methods.                                         *****/
/*************************************************************************/

#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include "shaders.h"
#include "WorkingScene.h"

#define ASSIGNMENT_NAME "Bezier and B-Spline Curve Modeling Tool"

// Create a global scene object to manage curve rendering and user interactions
WorkingScene scene;

// Shader-related global variables
GLuint vertexshader, fragmentshader, shaderprogram; // Shader objects
GLuint VAO, VBO; // Vertex Array Object and Vertex Buffer Object
GLuint projectionPos, modelviewPos, colorPos; // Uniform variable locations

// Renders the scene, updating the view and drawing the curves
void display() {
	// ModelViewProjection matrix defines the transformation for rendering
	float m[] = { 2.0, 0, 0, 0,
				 0, 2.0, 0, 0,
				 0, 0, 2.0, 0,
				-1.0, -1.0, 0, 1.0 }; // Basic scaling and translation

	// Identity matrix for the projection
	float projection[] = { 1.0, 0, 0, 0,
						   0, 1.0, 0, 0,
						   0, 0, 1.0, 0,
						   0, 0, 0, 1.0 };

	// Pass transformation matrices to the shaders
	glUniformMatrix4fv(modelviewPos, 1, GL_FALSE, m);
	glUniformMatrix4fv(projectionPos, 1, GL_FALSE, projection);

	// Clear the framebuffer and prepare for rendering
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBindVertexArray(VAO);
	if (scene.theOnlyCurve) {
		scene.theOnlyCurve->draw(scene.levelOfDetail); // Render the active curve
	}
	glBindVertexArray(0);
	glutSwapBuffers(); // Display the rendered content
}

// Initializes OpenGL shaders and buffers, and sets up the rendering pipeline
void init() {
	// Initialize shaders for vertex and fragment processing
	vertexshader = initshaders(GL_VERTEX_SHADER, "shaders/nop.vert.glsl");
	fragmentshader = initshaders(GL_FRAGMENT_SHADER, "shaders/nop.frag.glsl");
	shaderprogram = initprogram(vertexshader, fragmentshader);

	// Retrieve uniform variable locations in the shader program
	projectionPos = glGetUniformLocation(shaderprogram, "projection");
	modelviewPos = glGetUniformLocation(shaderprogram, "modelview");
	colorPos = glGetUniformLocation(shaderprogram, "color");

	// Generate and configure Vertex Array Object (VAO) and Vertex Buffer Object (VBO)
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, 0, 0, GL_STATIC_DRAW); // No initial data in the buffer
	glEnableVertexAttribArray(0); // Enable attribute 0 for vertex positions
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), 0); // Describe vertex data
	glBindVertexArray(0);

	// Pass the color uniform location to the scene for curve rendering
	scene.colorPos = colorPos;
}

// Main function: Sets up OpenGL context and initializes the application
int main(int argc, char* argv[]) {
	glutInit(&argc, argv); // Initialize GLUT library
	glutInitWindowSize(scene.width, scene.height); // Set initial window size
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); // Configure display mode
	glutCreateWindow(ASSIGNMENT_NAME); // Create the application window

	// Initialize GLEW to manage OpenGL extensions
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		std::cerr << "Error: " << glewGetString(err) << std::endl;
	}

	init(); // Perform application-specific initialization

	// Register callback functions for user interactions and rendering
	glutDisplayFunc(display);
	glutKeyboardFunc(scene.keyboard);
	glutMouseFunc(scene.mouse);
	glutReshapeFunc(scene.reshape);
	glutPassiveMotionFunc(scene.passiveMotion);
	glutMotionFunc(scene.drag);
	glutMainLoop(); // Enter the main event loop

	// Clean up resources before exiting
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	return 0;
}
