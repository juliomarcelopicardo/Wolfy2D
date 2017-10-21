/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#include "GL/glew.h"
#include "Wolfy2D/globals.h"
#include "core/wnd.h"
#include "core/core.h"



namespace W2D {

#pragma region CALLBACKS

/*******************************************************************************
***                               Callbacks                                  ***
*******************************************************************************/
void InputMouseButtonCB(GLFWwindow* window, int32 button, int32 action, int32 mods) {
  auto& mouse_button = Core::instance().window_.input_.mouse_button_[button];
  switch (action) {
  case GLFW_PRESS:
    mouse_button.is_down = true;
    mouse_button.is_pressed = true;
    mouse_button.is_up = false;
    break;
  case GLFW_RELEASE:
    mouse_button.is_down = false;
    mouse_button.is_pressed = false;
    mouse_button.is_up = true;
    break;
  }
}

void InputScrollCB(GLFWwindow* window, double xoffset, double yoffset) {
  Core::instance().window_.input_.mouse_wheel_ += (float)yoffset;
}

void InputKeyCB(GLFWwindow* window, int32 key, int32 scancode, int32 action, int32 mods) {
  
  if (ButtonStatus* button = Core::instance().window_.input_.getButton(key)) {
    switch (action) {
    case GLFW_PRESS:
      button->is_down = true;
      button->is_pressed = true;
      button->is_up = false;
      break;
    case GLFW_RELEASE:
      button->is_down = false;
      button->is_pressed = false;
      button->is_up = true;
      break;
    }
  }

  ImGuiIO& io = ImGui::GetIO();
  if (action == GLFW_PRESS) { io.KeysDown[key] = true; }    
  if (action == GLFW_RELEASE) { io.KeysDown[key] = false; }
   

  (void)mods; // Modifiers are not reliable across systems
  io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
  io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
  io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
  io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
}

void InputCharCB(GLFWwindow* window, uint32 c) {
  ImGuiIO& io = ImGui::GetIO();
  if (c > 0 && c < 0x10000) { io.AddInputCharacter((uint16)c); }
}


void SetWindowCallbacks() {
  auto* window = Core::instance().window_.glfw_window_;

  glfwSetScrollCallback(window, InputScrollCB);
  glfwSetMouseButtonCallback(window, InputMouseButtonCB);
  glfwSetKeyCallback(window, InputKeyCB);
  glfwSetCharCallback(window, InputCharCB);
}

#pragma endregion

#pragma region GLFW/GLEW


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
#pragma endregion

#pragma region WINDOW

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

Wnd::Wnd() {
  width_ = 800;
  height_ = 600;
  is_opened_ = false;
  is_already_initialized_ = false;
}

Wnd::~Wnd() {}

/*******************************************************************************
***                               Public methods                             ***
*******************************************************************************/

void Wnd::init(const int32 width, const int32 height, const char * name) {

  auto& core = Core::instance();

  if (is_already_initialized_) {
    exit(EXIT_FAILURE);
  }

  InitGLFW();
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  width_ = width;
  height_ = height;
  glfw_window_ = glfwCreateWindow(width, height, name, nullptr, nullptr);
  if (!glfw_window_) {
    glfwTerminate();
    printf("\n Error: Init window failed.");
    exit(EXIT_FAILURE);
  }
  glfwSetWindowPos(glfw_window_, 30, 30);

  // Window and Input Callbacks
  SetWindowCallbacks();

  InitGLEW();
  InitImGui();

  // Initialize the base objects.
  core.geometry_.init();
  core.material_.init("./../data/materials/shader.lua");
  core.sprite_.calculateProjectionMatrix(); // we calculate once as it wont change.

  glfwSetInputMode(glfw_window_, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
  is_already_initialized_ = true;
  is_opened_ = true;
}


void Wnd::close() {

  ShutdownImGui();
  glfwDestroyWindow(glfw_window_);
  glfwTerminate();
}

void Wnd::frame() {

  RenderImGui();
  glfwSwapBuffers(glfw_window_);
  is_opened_ = !glfwWindowShouldClose(glfw_window_);
  double x, y;
  glfwGetCursorPos(glfw_window_, &x, &y);
  input_.mouse_position_ = { (float)x, (float)y };
  input_.checkCursorPosition();
  input_.refreshButtonsUp();
  glfwPollEvents(); 
}

void Wnd::clear(float red, float green, float blue) {

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(red, green, blue, 1.0f); 
  FrameImGui();
}




/*******************************************************************************
***                              Private methods                             ***
*******************************************************************************/

#pragma endregion
  
}; /* W2D */
