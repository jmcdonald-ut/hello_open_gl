/* main.c
 * By Jonathon McDonald
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "xsys.h"

/* Initializes the program and returns a newly created window. */
GLFWwindow* init()
{
    glfwSetErrorCallback(xglfw_error_handler);
    if (!glfwInit()) {
        xexit("GLFW failed to initialize.");
    }

    return xglfw_create_window(640, 480, "Bermuda Triangle", NULL, NULL);
}

/* Cleans up the program and returns success code. */
int end()
{
    glfwTerminate();
    return EXIT_SUCCESS;
}

/* Readies the view port and returns the ratio. */
float prepare_view_port(GLFWwindow* window)
{
    int width = 0, height = 0;

    glfwGetFramebufferSize(window, &width, &height);
    assert(width > 0);
    assert(height > 0);

    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);

    return width / (float)height;
}

/* Resets the current OpenGL matrix to the identity matrix. This comment is
    kind of wrong, will fix. */
void prepare_identity_matrix(float ratio)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
}

/* Draws a triangle using the current OpenGL context. */
void draw_triangle()
{
    glBegin(GL_TRIANGLES);
    {
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);

        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);

        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
    }
    glEnd();
}

/* Renders a triangle that rotates. */
void render(GLFWwindow* window)
{
    float ratio = prepare_view_port(window);
    prepare_identity_matrix(ratio);

    glLoadIdentity();
    glRotatef((float)glfwGetTime() * 50.f, 0.f, 0.f, 1.f);

    draw_triangle();

    // Swap the window buffer with the buffer we've drawn to.
    glfwSwapBuffers(window);
}

/* Main entry point that begins execution of our program. */
int main(int argc, char* argv[])
{
    GLFWwindow* window = init();
    assert(NULL != window);

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    while (!glfwWindowShouldClose(window)) {
        render(window);

        // Poll for queued window events like being moved, resized, or closed.
        glfwPollEvents();
    }

    return end();
}
