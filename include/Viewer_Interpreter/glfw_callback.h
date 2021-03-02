#ifndef GLFW_CALLBACK_H
#define GLFW_CALLBACK_H
//#undef OpenglAlg
#include "Viewer_OpenglAlg.h"
#include <Viewer_World_Manager/Viewer_World_Manager.h>
#include<GLFW/glfw3.h>
#ifdef __cplusplus
extern "C" {
#endif


void viewer_cursor_position_callback(GLFWwindow* window,double x,double y);
void viewer_mouse_button_callback(GLFWwindow* window,int button,int action,int mods);
void viewer_framebuffer_size_callback(GLFWwindow* window,int w,int h);
void viewer_key_callback(GLFWwindow* ,int,int,int,int );
void viewer_scroll_callback(GLFWwindow* window,double x,double y);

/* warting for accomplished*/
void viewer_animation(Viewer_World*);
/*drag */
void viewer_drop_callback(GLFWwindow* window,int count,const char** paths);
/* get char*/
void veiwer_set_char_callback(GLFWwindow* window,unsigned int );

void viewer_set_callback(GLFWwindow* window);




/*
glfwSetDropCallback(window, drop_callback);

The callback function receives an array of paths encoded as UTF-8.

void drop_callback(GLFWwindow* window, int count, const char** paths)
{
int i;
for (i = 0;  i < count;  i++)
    handle_dropped_file(paths[i]);
}

*/

//
#ifdef __cplusplus
}
#endif
#endif

