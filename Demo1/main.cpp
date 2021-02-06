#include<Viewer_Interpreter/Viewer_OpenGL_Interpreter.h>
#include<config.h>
int main()
{
    Viewer_World vw;
    Viewer_World_init(&vw);
    Viewer_Opengl_Interpreter voi;
    Viewer_Opengl_Interpreter_initd(&voi,&vw);
    voi.interpreter(&voi);

    return 0;
}
