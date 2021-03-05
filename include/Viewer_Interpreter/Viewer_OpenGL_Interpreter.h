#ifndef VIEWER_OPENGL_INTERPRETER_H
#define VIEWER_OPENGL_INTERPRETER_H
#include<ft2build.h>
#include FT_FREETYPE_H
#include "Viewer_OpenGL_Interpreter_Shader.h"
//#include "glfw_callback.h"
#ifdef __cplusplus
extern "C"
{
#endif

#define Viewer_oisp Viewer_Opengl_Interpreter_Shader_Program

typedef struct Viewer_Opengl_Interpreter
{
	Viewer_World* world;
	void (*interpreter)(struct Viewer_Opengl_Interpreter*);
	void (*update_data)(struct Viewer_Opengl_Interpreter*);
	Node* user_shader_program;
    int update;
    //int s_e;
	struct Viewer_oisp*(*create_shader_program)(struct Viewer_Opengl_Interpreter* voi,char*s1,char*s2,void(*load_data)(struct Viewer_oisp*),void(*render)(struct Viewer_oisp*),Viewer_World* vw);
	void *prop;
}Viewer_Opengl_Interpreter;
//void Viewer_Opengl_Interpreter_init(Viewer_Opengl_Interpreter*);
void Viewer_Opengl_Interpreter_interpreter(Viewer_Opengl_Interpreter*moi);
struct Viewer_oisp* Viewer_create_shader_program(Viewer_Opengl_Interpreter* voi,char*s1,char*s2,void(*load_data)(struct Viewer_oisp*),void(*render)(struct Viewer_oisp*),Viewer_World* vw);
void Viewer_Interpreter_update_data(Viewer_Opengl_Interpreter* voi);
static inline void viewer_opengl_interpreter_init(Viewer_Opengl_Interpreter*moi)
{
    moi->world=NULL;
  /*  char* p_v=(char*)malloc(sizeof(char)*60);
    memset(p_v,0,sizeof(char)*60);
    strcat(strcat(p_v,MESH_VIEWER_PATH),"/mesh.vert");
    char* p_f=(char*)malloc(sizeof(char)*60);
    memset(p_f,0,sizeof(char)*60);
    strcat(strcat(p_f,MESH_VIEWER_PATH),"/mesh.frag");
    moi->shaders=(ShaderInfo*)malloc(sizeof(ShaderInfo)*3);
    moi->shaders[0].type=GL_VERTEX_SHADER;
    moi->shaders[0].filename=p_v;
    moi->shaders[1].type=GL_FRAGMENT_SHADER;
    moi->shaders[1].filename=p_f;
    moi->shaders[2].type=GL_NONE;
    moi->shaders[2].filename=NULL;*/
    moi->interpreter=Viewer_Opengl_Interpreter_interpreter;
      moi->update_data=Viewer_Interpreter_update_data;
    moi->user_shader_program=NULL;
    moi->create_shader_program=Viewer_create_shader_program;
   /* char* p_v=(char*)malloc(sizeof(char)*120);
    memset(p_v,0,sizeof(char)*120);
    strcat(strcat(p_v,MESH_VIEWER_PATH),"/mesh.vert");
    char* p_f=(char*)malloc(sizeof(char)*120);
    memset(p_f,0,sizeof(char)*120);
    strcat(strcat(p_f,MESH_VIEWER_PATH),"/mesh.frag");
    moi->create_shader_program(moi,p_v,p_f,Viewer_default_load_data,Viewer_default_render);
    memset(p_v,0,sizeof(char)*120);
    strcat(strcat(p_v,MESH_VIEWER_PATH),"/ui.vert");
    memset(p_f,0,sizeof(char)*120);
    strcat(strcat(p_f,MESH_VIEWER_PATH),"/ui.frag");
    moi->create_shader_program(moi,p_v,p_f,load_data2,render2);
    free(p_v);free(p_f);
    */
    //moi->s_e=0;
    moi->update=0;
    moi->prop=NULL; 
}

void viewer_opengl_interpreter_initd(Viewer_Opengl_Interpreter*,Viewer_World* );

//struct Viewer_oisp* Viewer_create_shader_program(strcut Viewer_Opengl_Interpreter* voi,char*s1,char*s2,void(*load_data)(struct Viewer_oisp*),void(*render)(struct Viewer_oisp*));





#undef Viewer_oisp
#ifdef __cplusplus
}
#endif
#endif
