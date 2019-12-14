#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

int main ()
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  //Making window object
  GLFWwindow* window = glfwCreateWindow(800, 600, "First", NULL, NULL);
  if (window==NULL) {
    cout << "window creation failed\n" << endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  //making sure glad is loaded
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    cout << "Failed to initialize GLAD" << endl;
    return -1;
  }

  //start rendering
  glViewport(100, 100, 800, 600);
  return 0;
}
