Shader = {

  vertex = [[
  #version 330
  layout (location = 0) in vec3 a_position;
  layout (location = 1) in vec2 a_uv;
  uniform mat4 u_m_matrix;
  uniform mat4 u_p_matrix;
  uniform int u_time;
  out vec3 normal;
  out vec2 uv;
  void main() {
	  uv = a_uv;
    gl_Position = u_p_matrix* u_m_matrix * vec4(a_position, 1.0);
  }
  ]] ,
  
  fragment = [[
  #version 330
  in vec2 uv;
  uniform sampler2D u_sample;
  out vec4 fragColor;
  void main() {
    fragColor = texture(u_sample, uv);
  } 
  ]] 

};
