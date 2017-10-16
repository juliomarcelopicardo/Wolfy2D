/** Copyright Julio Marcelo Picardo. SouthBros 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/

#include "GL/glew.h"
#include "Wolfy2D/globals.h"
#include "core/window.h"
#include "core/core.h"



namespace W2D {

/*******************************************************************************
***                               Callbacks                                  ***
*******************************************************************************/
void InputMouseButtonCB(GLFWwindow* window, int32 button, int32 action, int32 mods) {


}

void InputScrollCB(GLFWwindow* window, double xoffset, double yoffset) {

}

void InputKeyCB(GLFWwindow* window, int32 key, int32 scancode, int32 action, int32 mods) {

}
void InputCharCB(GLFWwindow* window, uint32 c) {

}


void SetWindowCallbacks() {
  auto* window = Core::instance().window_.glfw_window_;

  glfwSetScrollCallback(window, InputScrollCB);
  glfwSetMouseButtonCallback(window, InputMouseButtonCB);
  glfwSetKeyCallback(window, InputKeyCB);
  glfwSetCharCallback(window, InputCharCB);
}


/*******************************************************************************
***                       GLFW / GLEW library methods                        ***
*******************************************************************************/
void InitGLFW() {
  if (!glfwInit()) {
    exit(EXIT_FAILURE);
  }
}

void InitGLEW() {
  glfwMakeContextCurrent(Core::instance().window_.glfw_window_);
  if (glewInit() != GLEW_OK) {
    exit(EXIT_FAILURE);
  }
  //Viewport dimensions
  glViewport(0, 0, Core::instance().window_.width_, Core::instance().window_.height_);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
}




/*******************************************************************************
********************************************************************************
***                                                                          ***
***                          WOLFY2D WINDOW CLASS                            ***
***                                                                          ***
********************************************************************************
*******************************************************************************/


/*******************************************************************************
***                        Constructor and destructor                        ***
*******************************************************************************/

  CoreWindow::CoreWindow() {
    width_ = 800;
    height_ = 600;
    is_opened_ = false;
    is_already_initialized_ = false;
  }

  CoreWindow::~CoreWindow() {}

/*******************************************************************************
***                               Public methods                             ***
*******************************************************************************/

  void CoreWindow::init(const int32 width, const int32 height, const char * name) {


    if (is_already_initialized_) {
      exit(EXIT_FAILURE);
    }

    InitGLFW();
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    width_ = width;
    height_ = height;
    glfw_window_ = glfwCreateWindow(width, height, name, nullptr, nullptr);
    checkWindow();
    glfwSetWindowPos(glfw_window_, 30, 30);

    // Window and Input Callbacks
    SetWindowCallbacks();

    InitGLEW();

    glfwSetInputMode(glfw_window_, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    is_already_initialized_ = true;
    is_opened_ = true;
  }


  void CoreWindow::close() {
    
    glfwDestroyWindow(glfw_window_);
    glfwTerminate();
  }

  void CoreWindow::frame() {

    glfwSwapBuffers(glfw_window_);
    is_opened_ = !glfwWindowShouldClose(glfw_window_);
    double x, y;
    glfwGetCursorPos(glfw_window_, &x, &y);
    mouse_position_ = { (float)x, (float)y };
    glfwPollEvents(); //Esto es para detectar el tema del raton, teclado y todo eso.
  }

  void CoreWindow::clear(float red, float green, float blue) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(red, green, blue, 0.0f); 
  }

  /*******************************************************************************
  ***                             Error checkings                              ***
  *******************************************************************************/
  void CoreWindow::checkResolution() {
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    
  }

  void CoreWindow::checkWindow() {
    if (!glfw_window_) {
      glfwTerminate();
      exit(EXIT_FAILURE);
    }
  }

  void CoreWindow::checkCursorPosition() {

    if (mouse_position_.x < 0.0) {
      mouse_position_.x = 0.0;
    }
    if (mouse_position_.x < 0.0) {
      mouse_position_.x = 0.0;
    }

    if (mouse_position_.x > width_) {
      mouse_position_.x = width_;
    }
    if (mouse_position_.x > height_) {
      mouse_position_.x = height_;
    }
  }

/*******************************************************************************
***                              Private methods                             ***
*******************************************************************************/

  
}; /* W2D */
