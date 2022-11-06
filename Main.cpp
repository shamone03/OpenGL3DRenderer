#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

const char* vertexShaderSource =
	"#version 330 core" 
	"layout (location = 0) in vec3 aPos;"
	"void main() {"
	"	glPosition = vec4(aPos.x, aPos.y, aPos.z, 1.0);"
	"}";

const char* fragmentShaderSource =
	"#version 330 core"
	"out vec4 FragColor;"
	"void main() {"
	"	FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);"
	"}";

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(1600, 900, "OpenGL", NULL, NULL);

	if (!window) {
		std::cout << "no window created" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	gladLoadGL();
	glViewport(0, 0, 800, 800);

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//             put source in this / array of strings to source code
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	//                     length of arrays
	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);

	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	// reference to array of references
	// VBO = vertex buffer object
	GLuint VAO, VBO;

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//														static means vertices will be modified once and used many times
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	
	
	glClearColor(1, 187.f/255.f, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);

	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};
	
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents(); // update window
	}
	
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}