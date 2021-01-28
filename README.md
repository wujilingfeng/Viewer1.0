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




