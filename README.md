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

针对各种平台只需将上面`--demo=n`替换为`--demo=y`
##### complier freetype

freetype已经支持cmake

#### Tutorial

##### 抽象层

* 库的概念

一个窗口对应一个“世界”，用户利用c语言描述“世界”，然后调用解释器解释。(库还不够解释多个“世界”，也就是多个窗口，以后会支持)。

一个世界有多个“物种”，每个物种有多个“个体”。

用户可以自己在"世界"注册新的”物种“，然后就可以创建该“物种”的个体了，当然你需要在解释器中增加对其的解释。比如你可以注册自己的”灯光物种“，然后在解释器中添加自己的解释代码。（正如上面介绍的，创建物种仅仅依赖c语言，而解释器部分则自己决定）

目前该库默认注册的”物种“有：


* 物种

| 物种名       | 对应的结构体名 |对应的事物|
| ------------ | -------------- |-----------|
| Points       | Viewer_Points | 点集 |
| Edges        | Viewer_Edges | 线段集合 |
| Faces        | Viewer_Faces | 任意多边形集合 |
| Intera       | Viewer_Intera | 交互器(包含各种鼠标 ，键盘时间等回调函数  ) |
| Camera       | Viewer_Camera | 相机 |
| Texture      | Viewer_Texture | 纹理 |
| UI_Mesh      | Viewer_UI_Mesh | UI的网格 |
| Cursor_Shape | Viewer_Cursor_Shape | 鼠标形状 |
| Texts        | Viewer_Texts | 文字 |





* c语言的4阶矩阵

此库中的四阶矩阵利用宏实现了c++的模板功能，假如你要获得适配double类型的Viewer_Matrix4x4,你需要在头文件加入viewer_Matrix4x4_func_declare(double)，那么就会展开相关的函数声明，然后再在源文件中加入一句viewer_Matrix4x4_func(double)，那么就会展开相关函数的定义。之后对矩阵调用Matrix4x4_init_double()初始化，就可以使用了。

| 内部函数                                        | 意义                                                         |
| ----------------------------------------------- | ------------------------------------------------------------ |
| void (*transpose)( Matrix4x4 \*)                | 对矩阵进行转置                                               |
| Matrix4x4\*(mult)(Matrix4x4\*A,Matrix4x4\* B)   | 返回AB,返回的结果不用时，调用Matrix4x4_free进行内存销毁      |
| Matrix4x4 \*(\*inverse)(Matrix4x4 \*);          | 返回$$A^-$$,当A退化时，返回NULL,当结果矩阵不使用时，调用Matrix4x4_free进行内存销毁 |
| void (\*identity)(Matrix4x4 \*);                | 初始化当前矩阵为单位阵                                       |
| void (\*zero)(Matrix4x4\*)                      | 初始化当前矩阵为0矩阵                                        |
| void \*(\*det)(Matrix4x4 \*);                   | 返回当前矩阵的行列式，值是void\*(根据实际情况转化其为相应的数值) |
| void (\*copy_data)(Matrix4x4\*A, Matrix4x4\*B); | 将B的值赋给A                                                 |
| void \* data                                    | 矩阵的元素值，是一个储存16数值的数组                         |
| void (\*print_self)(Matrix4x4 \*);              | 打印矩阵数值                                                 |



##### 解释器层

* 本库的默认解释器

本库的默认解释器是基于opengl,

##### demo





