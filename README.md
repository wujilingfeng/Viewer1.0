#### Viewer

   可视化库，该库的目标是给一种用户可以抽象描述可视化事物而无视工程实现的工具库。比如一个数学专业的人员只需要学习c语言的成本就可以实现自己想要的的可视化任务，而无需耗费大量的成本在各种可视化工程框架中。该库目前也支持UI框架，它同样有上述的特点。

   该库的框架分为抽象描述部分和工程实现部分，抽象描述部分建立在c语言上，目前工程解释器部分是基于opengl实现的。抽象描述部分只依赖c语言，不依赖任何工程部分。

​	欢迎基于其他工程框架写的解释器，这样可以方便的将此库移植到其他平台，比如WebGL。



#### Dedenpencies

glfw：用于opengl的窗口系统。

glad: opengl的实现库。

freetype: 字体渲染库

cstructures: c语言的数据结构库 

在linux你需要先运行
```bash
sudo apt install cmake xorg-dev libglu1-mesa-dev build-essential libgl1-mesa-dev
```
#### Compile
##### compile library only

glfw cstructures freetype glad文件放在thirdpart中

for windows cl

```bash
xmake f --configure=y --demo=n
xmake
```

for windows mingw(暂时只能通过cmake来做)

```bash
xmake f -p mingw --configure=y --demo=n
xmake project -k cmake
```

for linux

```bash
xmake f --configure=y --demo=n
xmake
```

##### complier library and demo

将freetype glfw cstructures编译好的lib库放到lib文件

针对各种平台只需将上面`--demo=n`替换为`--demo=y`,再加入`--demo_path=`选项。

for linux

```bash
xmake f --configure=y --demo=y --demo_path=Demo
xmake
```





##### complier freetype

freetype已经支持cmake

#### Tutorial

##### 抽象层

* 库的概念

用户利用c语言描述“世界”，然后调用解释器解释。

一个世界有多个“物种”，每个物种有多个“个体”。

用户可以自己在"世界"注册新的”物种“，然后就可以创建该“物种”的个体了，当然你需要在解释器中增加对其的解释。比如你可以注册自己的”灯光物种“，然后在解释器中添加自己的解释代码。（正如上面介绍的，创建物种仅仅依赖c语言，而解释器部分则自己决定）

目前该库默认注册的”物种“有：


* 物种

| 物种名       | 对应的结构体名 |对应的事物|
| ------------ | -------------- |-----------|
| Points       | Viewer_Points | 点集 |
| Edges        | Viewer_Edges | 线段集合 |
| Faces        | Viewer_Faces | 任意多边形集合 |
| Intera       | Viewer_Intera | 交互器(包含各种鼠标 ，键盘，拖拽,时间,拾取等回调函数  ) |
| Camera       | Viewer_Camera | 相机 |
| Texture      | Viewer_Texture | 纹理 |
| UI_Mesh      | Viewer_UI_Mesh | UI的网格 |
| Cursor_Shape | Viewer_Cursor_Shape | 鼠标形状 |
| Texts        | Viewer_Texts | 文字 |

上面所有结构体在Viewer_World_Manager文件夹的头文件内，里面几乎所有变量望文生义。

* 世界管理(Viewer_World)

以下结构体Viewer_World的内部成员变量解释

| 成员                                              | 含义                                                         |
| ------------------------------------------------- | ------------------------------------------------------------ |
| Node\* (\*find_species)( Viewer_World\*,char\*)   | 查找物种，并按顺序返回当前物种的id。如果返回NULL,表示字符串不合适。id=-1表示没有此物种。例如find_speces(&vw,"Points,Faces")会返回链表，这个链表按顺序储存id变量 |
| Node\*(\*registe)(Viewer_World\*,char\*);         | 注册物种，如果返回NULL,表示字符串不合适。按顺序返回物种id    |
| Node\*(\*create_something)(Viewer_World\*,char\*) | 创建个体，按顺序返回物种                                     |
| g_info                                            | 储存了当前所有交互信息，比如鼠标和键盘状态，拖拽的文件路径，拾取信息 |
|                                                   |                                                              |
|                                                   |                                                              |
|                                                   |                                                              |
|                                                   |                                                              |
|                                                   |                                                              |





* c语言的4阶矩阵

此库中的四阶矩阵利用宏实现了c++的模板功能，假如你要获得适配double类型的Viewer_Matrix4x4,你需要在头文件加入viewer_Matrix4x4_func_declare(double)，那么就会展开相关的函数声明，然后再在源文件中加入一句viewer_Matrix4x4_func(double)，那么就会展开相关函数的定义。之后对矩阵调用Matrix4x4_init_double()初始化，就可以使用了。

| 内部函数                                        | 意义                                                         |
| ----------------------------------------------- | ------------------------------------------------------------ |
| void (*transpose)( Matrix4x4 \*)                | 对矩阵进行转置                                               |
| Matrix4x4\*(mult)(Matrix4x4\*A,Matrix4x4\* B)   | 返回AB,返回的结果不用时，调用Matrix4x4_free进行内存销毁      |
| Matrix4x4 \*(\*inverse)(Matrix4x4 \*);          | 返回$A^-$,当A退化时，返回NULL,当结果矩阵不使用时，调用Matrix4x4_free进行内存销毁 |
| void (\*identity)(Matrix4x4 \*);                | 初始化当前矩阵为单位阵                                       |
| void (\*zero)(Matrix4x4\*)                      | 初始化当前矩阵为0矩阵                                        |
| void \*(\*det)(Matrix4x4 \*);                   | 返回当前矩阵的行列式，值是void\*(根据实际情况转化其为相应的数值) |
| void (\*copy_data)(Matrix4x4\*A, Matrix4x4\*B); | 将B的值赋给A                                                 |
| void \* data                                    | 矩阵的元素值，是一个储存16数值的数组                         |
| void (\*print_self)(Matrix4x4 \*);              | 打印矩阵数值                                                 |



##### 解释器层

* 本库的默认解释器

本库的默认解释器是基于opengl,该解释器主要通过创建shader来运行。实际上该库也是创建了几个默认shader来对上述"世界"进行解释，以下代码展示如何添加自己的shader program

```c
#define Viewer_oisp Viewer_Opengl_Interpreter_Shader_Program
Viewer_Opengl_Interpreter voi;//创建解释器
Viewer_Opengl_Interpreter_initd(&voi,&vw);/*vw是传入的"世界",该初始化函数会默认创建几个shader program*/
Viewer_oisp *voisp=voi->create_shader_program(voi,pv,pf,load,render);/*插入创建了一个shader program,其中pv,pf分别是顶点着色器和片元着色器的路径，load是加载资源的函数指针，render是渲染函数的指针*/
```

load函数举例

```c
static void load_data(Viewer_Opengl_Interpreter_Shader_Program*voisp)
{
    if(voisp->program==0)
    { 
        _Shader_(voisp->shaders);
        voisp->program=_Program_(voisp->shaders); 
    }
    //glUseProgram(voisp->program);

	float vertices2[] = {
		-0.6f, -0.6f, 0.6f, 
		0.6f, -0.6f, 0.6f, 
		-0.6f, 0.6f, 0.6f, 
		0.6f, 0.6f, 0.6f,  
		-0.6f, -0.6f, 0.8f, 
		0.6f, -0.6f, 0.8f, 
		-0.6f, 0.6f, 0.8f, 
		0.6f, 0.6f, 0.8f,  
	};
	unsigned int indices[] = {  
    0, 1, 2, 
    1, 2, 3,  
	4,5,6,5,6,7,

	0,1,4,1,4,5,
	2,3,6,3,6,7,

	0,2,4,2,4,6,
	1,3,4,3,4,7
	};
    voisp->VAO=(GLuint*)malloc(sizeof(GLuint));
    voisp->Buffers=(GLuint**)malloc(sizeof(GLuint*));
    voisp->Buffers[0]=(GLuint*)malloc(sizeof(GLuint)*2);
    GLuint*VAO=voisp->VAO;
    GLuint*VBO=voisp->Buffers[0];

	glGenVertexArrays(1, VAO);
	glGenBuffers(2, VBO);
	glBindVertexArray(*VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBO[1]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
 
}
```

render函数举例

```c
static void render(Viewer_Opengl_Interpreter_Shader_Program* voisp)
{
    //glViewport(0,0,500,500);
	glUseProgram(voisp->program);
    glUniform4f(glGetUniformLocation(voisp->program, "ourColor"), 0.5f, 0.5, 0.7f, 0.5f);

    Matrix4x4 model,temp_m;
    Matrix4x4_init_float(&model);Matrix4x4_init_float(&temp_m);
    float *data=(float*)(temp_m.data);
    float tempx=0.9*((float)glfwGetTime()),tempy=0.65*((float)glfwGetTime());
    data[0*4+0]=cos(tempx);data[0*4+1]=-sin(tempx)*sin(tempy);
    data[0*4+2]=sin(tempx)*cos(tempy);
    data[1*4+1]=cos(tempy);
    data[1*4+2]=sin(tempy);
    data[2*4+0]=-sin(tempx);
    data[2*4+1]=-cos(tempx)*sin(tempy);
    data[2*4+2]=cos(tempx)*cos(tempy);
    model.mult(&model,&temp_m);
    ((float*)model.data)[2*4+3]=2.0;
    Matrix4x4 *p=Projection(M_PI/3.0f,800.0/600.0,0.5f,200.0f);
	glUniformMatrix4fv(glGetUniformLocation(voisp->program, "Proj"), 1, GL_TRUE, (float*)(p->data));
    glUniformMatrix4fv(glGetUniformLocation(voisp->program,"Object_Matrix"),1,GL_TRUE,(float*)(model.data));
    Matrix4x4_free(p);
    free(model.data);free(temp_m.data);

    // render box
    //glViewport(0.0,0.0,300,200);
    glBindVertexArray(voisp->VAO[0]);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

}
```

pv举例

```glsl
#version 330 core
layout (location = 0) in vec3 aPos;
uniform mat4 Proj;
uniform mat4 Object_Matrix;

void main()
{
	gl_Position = Proj*Object_Matrix*vec4(aPos, 1.0);
}

```

pf举例

```glsl
#version 330 core
out vec4 FragColor;
uniform vec4 ourColor;
void main()
{    
	FragColor = ourColor;
}
```

##### let's start

所有的"物种"都是Something,所以所有”物种“结构体都属于Viewer_Something结构体。这个结构体储存了所有物种必要的属性。

首先需要创建一个世界

```c
Viewer_World vw;
Viewer_World_init(&vw);//初始化这个世界
```

如果这时你对它进行解释，你会获得一个只有背景的窗口,如下:

```c
Viewer_Opengl_Interpreter voi;//创建解释器
Viewer_Opengl_Interpreter_initd(&voi,&vw);//初始化解释器,传入世界vw
voi.interpreter(&voi);//解释
```

你可以修改vw的background_color[4]变量，它将影响背景颜色。



接下来我们想要在”世界“vw里描述一些东西，比如点集。

但是在描述点集前，你需要先描述一个相机（人眼），因为只有相机（人眼）才能成像。最后的画面均是来自此相机(人眼)的画面。

（你可以创建多个相机，并设置其中一个可用）

```c

```



现在描述点集：

```c
Node*n=vw.create_something(&vw,"Points");
Viewer_Something* vs=(Viewer_Something*)(n->value);
Viewer_Points* vp=(Viewer_Something*)(vs->evolution);
free_node(node_reverse(n));
```

这样你将领取一些结构体，你修改vp结构体内的变量也就是描述点集的过程。

以上代码代码几乎是定式的。比如再描述一些线段:

```c
n=vw.create_something(&vw,"Edges");
vs=(Viewer_Something*)(n->value);
Viewer_Edges* ve=(Viewer_Edges*)(vs->evolution);
free_node(node_reverse(n));
```

如果你想要一次创建多个"个体",比如一次创建上述的Points和Edges,你可以

```c
Node* n=vw.create_something(&vw,"Points,Edges");
Node* nit=n;
Viewer_Something* vs=(Viewer_Something*)(nit->value);
Viewer_Points * vp=(Viewer_Points*)(vs->evolution);
nit=(Node*)(nit->Next);
vs=(Viewer_Something*)(nit->value);
Viewer_Edges * ve=(Viewer_Edges*)(vs->evolution);
```

* 如何描述多边形集合

在Viewer_Faces结构体内有这样几个变量Data_rows,Data_index_rows,Data,Data_index.

Data_rows表示这些多边形有多少个点，Data_index表示有多少个多边形。

Data的数组长度应该Data_rows*3,因为每个点有x,y,z三个分量，这些点的顺序决定了点的索引:0,1,2.....

Data_index也是数组（长度视具体描述而定），它表示这些索引表示的多边形。它将按顺序读取数组，首先读取的数假设为x，那么x表示接下来的多边形有x个点，后面的x个数表示这些点的索引，这样就描述了一个多边形，然后再向后读取一个数y,那么接下来的多边形有y个点.........

以下是一个例子

```c

```





#### 需要改进的地方

* viewerport和拾取方面的配合
* 似乎g_info需要读取多个离屏渲染的像素
* UI_Mesh点的位置需要动态，颜色需要动态







