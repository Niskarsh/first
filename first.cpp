#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

void windowResize (GLFWwindow* window, int width, int height);

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
  glfwSetFramebufferSizeCallback(window, windowResize);

  //render loop to keep window open
  while (!glfwWindowShouldClose(window)) {
    //swapping next draw buffer
    glfwSwapBuffers(window);
    //invokes respective callbacks
    glfwPollEvents();
  }
  glfwTerminate();
  return 0;
}

void windowResize (GLFWwindow* window, int width, int height) {
  glViewport(100, 100, width, height);
}
