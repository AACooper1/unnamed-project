#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

// Allows GL to deal with resized windows
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

// Close window when the user presses Esc
void checkUserCloseWindow(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

int OpenWindow(int width, int height, std::string windowTitle)
{
	// Start up GLFW
	glfwInit();
	// "Window Hints" are poorly named. They're there to give context to GLFW.
	// Sets OpenGL to current version, 4.6
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	// Core profile (Just the very base stuff, not the deprecated stuff)
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	#include <iostream>
	// Open a window !!!
	GLFWwindow* window = glfwCreateWindow(width, height, "Wow OpenGL???", NULL, NULL);
	// be sad if no window
	if (window == NULL)
	{
		std::cout << "Window couldn't open :(" << std::endl;
		glfwTerminate();
		return -1;
	}
	// This is our main context for the current thread
	glfwMakeContextCurrent(window);

	// Start up GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "GLAD more like BAD :(" << std::endl;
		return -1;
	}

	// Tell OpenGL itself the window size so it knows what coordinates to work with
	// This basically just maps (-1, 1) to the height and width of the viewport (with (0, 0) as the center)
	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// Tell it not to close until _I_ say so >:(
	while (!glfwWindowShouldClose(window))
	{
		// Input
		// This is just "Did they press Esc" right now
		checkUserCloseWindow(window);

		// Code to render a frame goes here :D
		// This here clears the previous frame (immediately before the glfwSwapBuffer line), with the clear color being this BSoD Blue.
		glClearColor(0.1f, 0.1f, 0.4f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Switch between buffers while active
		glfwSwapBuffers(window);
		// Check for Events (i.e., close window)
		glfwPollEvents();
	}

	//
	glfwTerminate();
	return 0;
}