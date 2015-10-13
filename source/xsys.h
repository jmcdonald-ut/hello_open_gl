/* xsys.h
 * By Jonathon McDonald
 */
#include <stdlib.h>
#include <GLFW/glfw3.h>

void* xmalloc(size_t);
void xfree(void*);
void xexit(const char*);
GLFWwindow* xglfw_create_window(int, int, const char*, GLFWmonitor*, GLFWwindow*);
void xglfw_error_handler(int, const char*);
