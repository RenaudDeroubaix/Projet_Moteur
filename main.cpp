
#include "common/utils.hpp"
#include "common/InputManager.hpp"
#include "common/Camera.hpp"
#include "common/GameObject.hpp"
#include "common/Scene.hpp"
#include "common/Graph.hpp"
#include "common/Room.hpp"
#include "common/Physics.hpp"
#include "common/SceneManager.hpp"
#include "common/texteRender.hpp"
#define MINIAUDIO_IMPLEMENTATION
#include "common/miniaudio.h"



using namespace glm;

GLFWwindow* window;

std::vector<GLuint> programID_list;

// timing
float deltaTimeRendu = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

double InputManager::previousX = 0;
double InputManager::previousY = 0;
unsigned int InputManager::view = 0;

/*******************************************************************************/



void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount)
{
    ma_decoder* pDecoder = (ma_decoder*)pDevice->pUserData;
    if (pDecoder == NULL) {
        return;
    }

    ma_decoder_read_pcm_frames(pDecoder, pOutput, frameCount, NULL);

    (void)pInput;
}


int main( void )
{
    SceneManager SM;
    InputManager& I_M = SM.getInputManager();

    ma_result result;
    ma_decoder decoder;
    ma_device_config deviceConfig;
    ma_device device;


    result = ma_decoder_init_file("../src/music/007_James Bond_Theme.wav", NULL, &decoder);
    if (result != MA_SUCCESS) {
        return -2;
    }

    deviceConfig = ma_device_config_init(ma_device_type_playback);
    deviceConfig.playback.format   = decoder.outputFormat;
    deviceConfig.playback.channels = decoder.outputChannels;
    deviceConfig.sampleRate        = decoder.outputSampleRate;
    deviceConfig.dataCallback      = data_callback;
    deviceConfig.pUserData         = &decoder;

    if (ma_device_init(NULL, &deviceConfig, &device) != MA_SUCCESS) {
        printf("Failed to open playback device.\n");
        ma_decoder_uninit(&decoder);
        return -3;
    }

    if (ma_device_start(&device) != MA_SUCCESS) {
        printf("Failed to start playback device.\n");
        ma_device_uninit(&device);
        ma_decoder_uninit(&decoder);
        return -4;
    }

    
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  
    // Open a window and create its OpenGL context
    window = glfwCreateWindow( SM.SCR_WIDTH, SM.SCR_HEIGHT, "Moteur_Camera", NULL, NULL);
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

     // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // Set the mouse at the center of the screen
    glfwPollEvents();
    //glfwSetCursorPos(window, SM.SCR_WIDTH/2.0, SM.SCR_HEIGHT/2.0);
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
    GLuint progID = LoadShaders( "../src/shaders/vertex_shader.glsl" , "../src/shaders/fragment_shader.glsl");
    GLuint programIDHUD = LoadShaders( "../src/shaders/vertex_text.glsl" , "../src/shaders/frag_text.glsl");
    texteRender hud(programIDHUD);
    programID_list.push_back(progID);
    Scene s;
    s.setprogIdList(programID_list);
    SM.addSceneToList(&s);
    SM.initScene();
    Physics p;

    Scene s2;
    s2.setprogIdList(programID_list);
    SM.addSceneToList(&s2);
 
    double lastTime = glfwGetTime();
    int nbFrames = 0;
    I_M.current_cam = static_cast<Camera*>(SM.getCurrentScene().get_camera_list()[0]);
    //glfwSwapInterval(0); //pour uncap les fps

    do{ 
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //std::cout<<"test"<<std::endl;
        Scene& currentScene=SM.getCurrentScene();
        SM.hasEventHappened(currentScene.getNodePlayer());
        //std::cout << &currentScene << std::endl;
        float currentFrame = glfwGetTime();
        deltaTimeRendu = currentFrame - lastFrame;
        lastFrame = currentFrame;
        //std::cout <<"rendu : "<< 1.f/deltaTimeRendu << std::endl;

    
       
        I_M.Input_GamePlay(currentScene , currentScene.getNodePlayer()->getData(), deltaTimeRendu);
        if(currentScene.get_reset_s()){
            SM.resetCurrentScene();
            currentScene=SM.getCurrentScene();
            //std::cout << SM.getScene_i() << std::endl;
            I_M.current_cam = static_cast<Camera*>(SM.getCurrentScene().get_camera_list()[0]);
        }
        if(SM.getGameState() != 2){
            if(!currentScene.get_pause_s()){
                SM.unpause();
                p.applyForce(currentScene , deltaTimeRendu);
                SM.DetecterParNPC(currentScene.getNodePlayer()->getData() , deltaTimeRendu); 
                SM.set_light_on_off( static_cast<GameObject*>(I_M.current_cam));
                
            }
            else{SM.pause();}
        }
        currentScene.drawscene(I_M.current_cam , currentScene.get_node_list()[0]);
        

        GLint oldVAO;
        // Appeler glGetIntegerv en passant l'adresse de la variable oldVAO
        glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &oldVAO);
        //glBindFramebuffer(GL_FRAMEBUFFER, 0); 
        hud.renderTXT(SM.SCR_WIDTH,SM.SCR_HEIGHT,I_M.view , SM.getScene_i(),SM.getGameState(), 1/deltaTimeRendu);
        glBindVertexArray(oldVAO);
        
        glfwSwapBuffers(window);
        glfwPollEvents();

    } // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0 );
    glDeleteProgram(progID);
    glDeleteProgram(programIDHUD);


    ma_device_uninit(&device);
    ma_decoder_uninit(&decoder);
    
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
