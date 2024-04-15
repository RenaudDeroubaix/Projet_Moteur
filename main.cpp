#include "common/utils.hpp"
#include "common/InputManager.hpp"
#include "common/Camera.hpp"
#include "common/GameObject.hpp"
#include "common/Scene.hpp"
#include "common/Graph.hpp"
#include "common/Room.hpp"

using namespace glm;

GLFWwindow* window;

// settings
const unsigned int SCR_WIDTH = 1024;
const unsigned int SCR_HEIGHT = 768;

// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;


double InputManager::previousX = 0.0;
double InputManager::previousY = 0.0;
double InputManager::deltaX = 0.0;
double InputManager::deltaY = 0.0;

/*******************************************************************************/

int main( void )
{
    InputManager I_M;
    
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  
    // Set the mouse at the center of the screen
    glfwPollEvents();
    // Open a window and create its OpenGL context
    window = glfwCreateWindow( SCR_WIDTH, SCR_HEIGHT, "TP3", NULL, NULL);
    
    
    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    // Hide the mouse and enable unlimited mouvement
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    
    if( window == NULL ){
        fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
        getchar();
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        return -1;
    }
   
    //Dark blue background
    glClearColor(0.8f, 0.8f, 0.8f, 0.0f);
    //Enable depth test
    glEnable(GL_DEPTH_TEST);
    //Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);
    //Cull triangles which normal is not towards the camera
    //glEnable(GL_CULL_FACE);
    //glEnable(GL_CULL_BACK);
    //Create and compile our GLSL program from the shaders
   
    
    
    ///// init a newscene
    Scene s;
    Node sol;
    makeRoom(s,10,8,3,glm::vec3(5.0f),sol);
    //Node plan = s.make_node(Plane);
    //s.scalenode(plan , glm::vec3(4.f));
    Node cube = s.make_node(Cube);
    
    s.get_data(cube)->set_color(glm::vec3(0.1f , 0.3f, 1.f)); 
    s.scalenode(cube , glm::vec3(0.1f , 0.1f , 0.1f));
    s.translatenode(cube, glm::vec3(0.0 , 0.05, .0));
    sol.addChild(cube);

    glm::vec3 camera_initpos =  glm::vec3(0.f , 1.f , 2.f) +  s.get_data(s.get_node_list()[0])->getpos()  ;
    glm::vec3 camera_inittarget = normalize(s.get_data(s.get_node_list()[0])->getpos() - camera_initpos ); 
    Camera *camera = new Camera
    (
        SCR_WIDTH ,SCR_HEIGHT ,
        camera_initpos, camera_inittarget
    );
   
    double lastTime = glfwGetTime();
    int nbFrames = 0;
    
    s.initscene();
    s.loadtexturesinscene();
    
    do{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        I_M.Input_Camera(camera , deltaTime);
        I_M.Input_GameObject(s.get_data(cube) , deltaTime);
        //camera->be_orbital(s.get_data(s.get_node_list()[0])->getpos() ,deltaTime ,0);

        
        glm::mat4 vm = camera->getViewMatrix();
        glm::mat4 pm = camera->getProjectionMatrix();
        s.drawscene(vm, pm , sol);
    
        
        glfwSwapBuffers(window);
        glfwPollEvents();

    } // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0 );

    s.deletescene();
    glfwTerminate();
    return 0;
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
