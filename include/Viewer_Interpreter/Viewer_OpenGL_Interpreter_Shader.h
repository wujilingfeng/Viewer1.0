#ifndef VIEWER_OPENGL_INTERPRETER_LOAD_RENDER_H
#define VIEWER_OPENGL_INTERPRETER_LOAD_RENDER_H
#include<ft2build.h>
#include FT_FREETYPE_H
#include "glfw_callback.h"

#include <config.h>

//#include "Viewer_OpenglAlg.h"

//#include <Viewer_World_Manager/Viewer_World_Manager.h>
//#include<GLFW/glfw3.h>
//#include "glfw_callback.h"
//#include <config.h>
#ifdef __cplusplus
extern "C"
{
#endif
#define Viewer_oisp Viewer_Opengl_Interpreter_Shader_Program
#define Viewer_oispp Viewer_Opengl_Interpreter_Shader_Program_Prop
RB_Tree_func_declare(char)
typedef struct Viewer_FrameBuffer{
    GLuint framebuffer;
    GLuint colortex;
    GLuint rbo;
    void* prop;
}Viewer_FrameBuffer;
static inline void viewer_framebuffer_init(Viewer_FrameBuffer* vfb)
{
        vfb->framebuffer=0;
        vfb->colortex=0;
        vfb->rbo=0;
        vfb->prop=NULL;
}
//void Viewer_FrameBuffer_init(Viewer_FrameBuffer* vfb);
typedef struct Viewer_Opengl_Interpreter_Shader_Program_Prop{

    Viewer_FrameBuffer vfb1,vfb2;
    unsigned int num;
    void* prop;
}Viewer_Opengl_Interpreter_Shader_Program_Prop;

static inline void viewer_opengl_interpreter_shader_program_prop_init(Viewer_oispp*voispp )
{
    viewer_framebuffer_init(&(voispp->vfb1));
    viewer_framebuffer_init(&(voispp->vfb2));
    voispp->num=0;
}

//void Viewer_Opengl_Interpreter_Shader_Program_Prop_init(Viewer_oispp*voispp );
typedef struct Viewer_Opengl_Interpreter_Shader_Program
{
    ShaderInfo* shaders;
    GLuint program;
    void(*load_data)(struct Viewer_Opengl_Interpreter_Shader_Program*);
    void(*render)(struct Viewer_Opengl_Interpreter_Shader_Program*);
    GLuint *VAO;
    GLuint**Buffers;
    GLuint* tex;
    struct Viewer_World *vw;
    Viewer_FrameBuffer *vfb;
    //struct Viewer_Opengl_Interpreter* voi;
    void* prop;

}Viewer_Opengl_Interpreter_Shader_Program;


static inline void viewer_opengl_interpreter_shader_program_init(Viewer_Opengl_Interpreter_Shader_Program*voisp)
{
    voisp->shaders=(ShaderInfo*)malloc(sizeof(ShaderInfo)*3);;
    voisp->program=0;
    voisp->load_data=NULL;
    voisp->render=NULL;
    voisp->VAO=NULL;
    voisp->Buffers=NULL;
    voisp->tex=NULL;
    voisp->vw=NULL;
    voisp->vfb=(Viewer_FrameBuffer*)malloc(sizeof(Viewer_FrameBuffer));
    viewer_framebuffer_init(voisp->vfb);
   // Viewer_FrameBuffer_init((voisp->vfb));

    //voisp->voi=NULL;
    voisp->prop=NULL;
}
//void Viewer_Opengl_Interpreter_Shader_Program_init(Viewer_Opengl_Interpreter_Shader_Program*);
GLuint* test_add_array_to_shader(Viewer_oisp* voisp);



void Viewer_default_load_data(Viewer_oisp* voisp);

void Viewer_default_render(Viewer_oisp* voisp);


void Viewer_load_quad_data(Viewer_oisp* voisp);
void Viewer_render_quad(Viewer_oisp* voisp);

void Viewer_load_ui_data(Viewer_Opengl_Interpreter_Shader_Program *voisp);
void Viewer_render_ui(Viewer_Opengl_Interpreter_Shader_Program*voisp);

#undef Viewer_oisp
#undef Viewer_oispp
#ifdef __cplusplus
}
#endif
#endif