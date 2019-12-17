#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "draw.cpp"
using namespace std;

const char* vertexShaderSource = "#version 330 core\n layout (location =0) in vec3 aPos;void main () { gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0); }";
const char* fragmentShaderSource = "#version 330 core\nout vec4 FragColor;void main () { FragColor = vec4(1.0f, 1.0f, .5f, 1.0f); }";
void windowResize (GLFWwindow* window, int width, int height);
void draw ();



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

  //bind and combine vertex shader
  unsigned int vertexShader;
  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  //bind and combine fragment shader
  unsigned int fragmentShader;
  fragmentShader = glCreateShader (GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);

  //render loop to keep window open
  while (!glfwWindowShouldClose(window)) {
    draw();
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

