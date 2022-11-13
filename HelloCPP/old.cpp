#include <iostream>

//Cli
#include <SDL2/SDL.h>
#include <glad/glad.h>

//Xcode
//#include <SDL2/SDL.h>
//#include <SDL2/SDL_opengl.h>
//#include <OpenGL/OpenGL.h>
//#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

//Other?
//#include <GL\GLU.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <gl.h>
//#include <glu.h>
//#include <glut.h>
//#include <OpenGL/gl2.h>
//#include <GLUT/glut.h> // Header File For The GLut Library
//#include <gl\gl.h>                // Заголовочные файлы для библиотеки OpenGL32
//#include <gl\glu.h>              // Заголовочные файлы для библиотеки GLu32
//#include <gl\glaux.h>              // Заголовочные файлы для библиотеки GLaux

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* window = NULL;
SDL_GLContext context;

//int flags = SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN;
int flags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;
bool isRunning = true;

auto random(int min, int max) -> int {
    return min + rand() % (( max + 1 ) - min);
}

bool initGL() {
    bool success = true;
    GLenum error = GL_NO_ERROR;
    
    //Initialize Projection Matrix
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    
    //Check for error
    error = glGetError();
    if( error != GL_NO_ERROR ) {
        printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
        success = false;
    }
    
    //Initialize Modelview Matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    
    //Check for error
    error = glGetError();
    if( error != GL_NO_ERROR ) {
        printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
        success = false;
    }
    
    //Initialize clear color
    glClearColor( 0.f, 0.f, 0.f, 1.f );
    
    //Check for error
    error = glGetError();
    if( error != GL_NO_ERROR ) {
        printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
        success = false;
    }
    
    return success;
}

bool init() {
    srand( (unsigned int)time(NULL) );
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    
    //Use OpenGL 2.1
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 2 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    
    window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, flags);
    if( window == NULL || window == 0 ) {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    
    context = SDL_GL_CreateContext(window);
    if( context == NULL ) {
        printf( "OpenGL context could not be created! SDL Error: %s\n", SDL_GetError() );
        return false;
    }
    
    if( SDL_GL_SetSwapInterval( 1 ) < 0 ) {
        printf( "Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError() );
        return false;
    }
    
    if( !initGL() ) {
        printf( "Unable to initialize OpenGL!\n" );
        return false;
    }
    
    return true;
}

void render() {
    //Render triangle
}

int main( int argc, char* args[] ) {
    if (init())
        isRunning = true;
    else
        printf( "Unable to init SDL " );
    
    if (isRunning) {
        printf( "Drawing on the screen " );
        
        SDL_Event e;
        bool quit = false;
        while( quit == false ){
            render();
            while( SDL_PollEvent( &e ) ){
                if( e.type == SDL_QUIT )
                    quit = true;
            }
        }
        SDL_Quit();
    }
    
    printf( "Hello world " );
    
    return 0;
}
