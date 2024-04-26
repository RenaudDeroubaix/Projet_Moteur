
#include "common/utils.hpp"
#include "common/InputManager.hpp"
#include "common/Camera.hpp"
#include "common/GameObject.hpp"
#include "common/Scene.hpp"
#include "common/Graph.hpp"
#include "common/Room.hpp"
#include "common/Physics.hpp"
#include "common/SceneManager.hpp"

using namespace glm;

GLFWwindow* window;

// settings
const unsigned int SCR_WIDTH = 1024;
const unsigned int SCR_HEIGHT = 768;

// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

double InputManager::previousX = 0;
double InputManager::previousY = 0;
unsigned int InputManager::view = 0;
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
    window = glfwCreateWindow( SCR_WIDTH, SCR_HEIGHT, "Moteur_Camera", NULL, NULL);
    
    
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
    SceneManager SM;
    Scene s;
    SM.addSceneToList(&s);
    Physics p;
    Node sol;
    makeRoom(s,10,8,3,glm::vec3(5.0f),sol);
    
    
   
    
    Node cube = s.make_node_cube();
    s.get_data(cube)->set_color(glm::vec3(0.1f , 0.3f, 1.f)); 
    s.scalenode(cube , glm::vec3(0.1f , 0.1f , 0.1f));
    s.translatenode(cube, glm::vec3(0.0 , 0.05, .0));

    s.get_data(cube)->getgameObjectInfo().setHasPhysics(true);
    s.get_data(cube)->calculateBoundingBox();
    s.get_data(cube)->setMasse(40.f);
    
    Node SecurityCam1 = s.make_node_camera(true,SCR_WIDTH , SCR_HEIGHT);
    Node SecurityCam2 = s.make_node_camera(false,SCR_WIDTH , SCR_HEIGHT);
    s.get_data(SecurityCam1)->set_pos(glm::vec3(-1.0 , 1 , -1 ));
    s.get_data(SecurityCam2)->set_pos(glm::vec3(0 , 0.9 ,0));

    
    sol.addChild(cube);
    sol.addChild(SecurityCam1);
    sol.addChild(SecurityCam2);

   
    double lastTime = glfwGetTime();
    int nbFrames = 0;
    
    s.initscene();

   
    I_M.current_cam = static_cast<Camera*>(s.get_data(SecurityCam1));
    s.calculateBoundingBoxRecursive(sol);
    s.loadtexturesinscene();
    
    do{
        Scene& currentScene=SM.getCurrentScene();
       // std::cout<<&s<<std::endl;
       // std::cout<<&currentScene<<std::endl;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        
        I_M.Input_GamePlay(currentScene , currentScene.get_data(cube) , deltaTime);
        p.applyForce(currentScene , deltaTime);
        glm::mat4 vm = I_M.current_cam->getViewMatrix();
        glm::mat4 pm = I_M.current_cam->getProjectionMatrix();
        
        currentScene.drawscene(vm, pm , sol);
        
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
