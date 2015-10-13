/* xsys.c
 * By Jonathon McDonald
 */
#include <stdio.h>
#include <stdlib.h>
#include "xsys.h"

/* Allocates `size` amount of bytes in memory and returns a pointer. */
void* xmalloc(size_t size)
{
    void* ptr = malloc(size);
    if (NULL == ptr) {
        xexit("xmalloc failed");
    }

    return ptr;
}

/* Frees the allocated memory. Outputs a warning if the pointer is null. */
void xfree(void* ptr)
{
    if (NULL == ptr) {
        fputs("xfree expects a valid pointer, but was given NULL.", stderr);
    }

    free(ptr);
}

/* Prints a message to stderr and exits with a failure. */
void xexit(const char* message)
{
    if (NULL == message) {
        fputs("xexit expects a valid pointer, was given NULL.", stderr);
    } else {
        fputs(message, stderr);
    }

    exit(EXIT_FAILURE);
}

/* Initializes a new window instance or exits on failure. */
GLFWwindow* xglfw_create_window(int width, int height, const char* title,
    GLFWmonitor* monitor, GLFWwindow* share)
{
    GLFWwindow* pointer = glfwCreateWindow(width, height, title, monitor, share);
    if (NULL == pointer) {
        xexit("Failed to initialize a GLFW window.");
    }

    return pointer;
}

/* Handles errors emitted by GLFW by printing them to stderr and exiting. */
void xglfw_error_handler(int error, const char* description)
{
    xexit(description);
}
