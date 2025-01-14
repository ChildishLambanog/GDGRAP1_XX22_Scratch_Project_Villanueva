#include <GLFW/glfw3.h>
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(600, 600, "Rafael Ira R. Villanueva", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_POLYGON);

		float resultsX[8];
		float resultsY[8];
		resultsX[0] = -0.25;
		resultsY[0] = 1;

		float degrees = 45;
		//converting degrees to radians
		float radian = degrees * M_PI / 180;

		for (int i = 0; i < 7; i++)
		{
			float x, y, result1, result2, result3, result4;

			result1 = resultsX[i] * cos(radian);
			result2 = resultsY[i] * sin(radian);
			result3 = resultsX[i] * sin(radian);
			result4 = resultsY[i] * cos(radian);
			x = result1 - result2;
			y = result3 + result4;

			resultsX[i + 1] = x;
			resultsY[i + 1] = y;
		}

		float rotate = 8.45;

		float nRadian = rotate * M_PI / 180;

		for (int i = 0; i < 8; i++)
		{
			float newX, newY;

			newX = (resultsX[i] * cos(nRadian)) - (resultsY[i] * sin(nRadian));
			newY = (resultsX[i] * sin(nRadian)) + (resultsY[i] * cos(nRadian));

			resultsX[i] = newX;
			resultsY[i] = newY;

		}

		float translate = 0.048;

		for (int i = 0; i < 8; i++)
		{
			float newY;

			newY = translate + resultsY[i];

			resultsY[i] = newY;
		}

		for (int i = 0; i < 8; i++)
		{
			glVertex2f(resultsX[i], resultsY[i]);
		}
 
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}