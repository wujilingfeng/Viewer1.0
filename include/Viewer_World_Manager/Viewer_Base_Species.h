#ifndef VIEWER_BASE_SPECIES_H
#define VIEWER_BASE_SPECIES_H
#include<Math/Viewer_Matrix4x4.h>
#include <tools_node.h>
#include<time.h>
#define Matrix4x4 Viewer_Matrix4x4_

#ifdef __cplusplus
extern "C" {
#endif
typedef struct Viewer_Something{
	char* name;
	int name_id;
	int id;
	unsigned int create_date;
	int disappear;
	
	int viewport[4];

	int marked_element;
	void* mesh;

	//Node* history_avatar;

	void* evolution;
	void* prop;
}Viewer_Something;
//void Viewer_Something_init( Viewer_Something*);
static inline void Viewer_Something_init(Viewer_Something*ms)
{
	//gldeletevertexarray
	//gldeletebuffer
	time_t timep;
    struct tm *p;
    time(&timep);
    p = localtime(&timep); 
  //  printf ("%d%d%d ", (1900+p->tm_year), (1+p->tm_mon), p->tm_mday);
 //   printf("%d:%d:%d\n", p->tm_hour, p->tm_min, p->tm_sec);
    ms->create_date=p->tm_sec+p->tm_min*100+p->tm_hour*10000+p->tm_mday*1000000+(1+p->tm_mon)*100000000;
   // printf("create_date:%d\n",ms->create_date);
	ms->name=0;
	ms->name_id=-1;
	ms->id=-1;
	//ms->create_date=-1;
	ms->disappear=0;
	memset(ms->viewport,0,sizeof(int)*4);
	ms->marked_element=-1;
	ms->mesh=NULL;
	//ms->history_avatar=NULL;
	ms->evolution=0;
	ms->prop=NULL;
}
typedef struct Viewer_Texture
{
	char* image_file;
	int width,height,n;
	unsigned char* data;
	float* each_face_texture_coord;
	unsigned int tex;
	void* prop;
}Viewer_Texture;


static inline void Viewer_Texture_init(Viewer_Texture*mt)
{
	mt->image_file=NULL;
	mt->width=0;
	mt->height=0;
	mt->n=0;
	mt->data=NULL;
	mt->each_face_texture_coord=0;
	mt->tex=0;
	mt->prop=NULL;
}
typedef struct Viewer_Faces
{


	float *Data,*color,*normal;
	unsigned int* Data_index;
	unsigned int normal_rows;
	unsigned int color_rows;
	//
	unsigned int* marked_faces_index;
	

    	unsigned int Data_index_rows;
	unsigned int Data_rows;
	float triangle_coordinate[3];	
	
	void(*compute_normal)(struct Viewer_Faces*);
	void (*random_color)(struct Viewer_Faces*);
	void (*set_color)(struct Viewer_Faces*,float*);
	int is_reversal_normal;
	Matrix4x4 *mat;
	Viewer_Something* texture;
	int is_transparent;
	void* evolution;
	void* prop;

	unsigned int VAO,*Buffers;
}Viewer_Faces;
void Viewer_Faces_set_color(Viewer_Faces*,float*);
void Viewer_Faces_compute_normal(Viewer_Faces*);
void Viewer_Faces_random_color(Viewer_Faces*);
//void Viewer_Faces_init(Viewer_Faces*);

static inline void Viewer_Faces_init(Viewer_Faces* mf)
{
    mf->Data=0;mf->color=0;
    mf->Data_index=0;
    mf->normal=0;
    mf->marked_faces_index=0;
   
    mf->evolution=0;
    mf->Data_index_rows=0;
  	mf->color_rows=0;
	mf->normal_rows=0;
    mf->Data_rows=0;
	mf->compute_normal=Viewer_Faces_compute_normal;
    mf->random_color=Viewer_Faces_random_color;
	mf->set_color=Viewer_Faces_set_color;
	mf->texture=0;
	mf->mat=(Matrix4x4*)malloc(sizeof(Matrix4x4));
	Matrix4x4_init_float(mf->mat);
	mf->is_reversal_normal=0;
	mf->is_transparent=0;

    mf->triangle_coordinate[0]=1;mf->triangle_coordinate[1]=0;mf->triangle_coordinate[2]=0;   
 	mf->prop=NULL;

    //
    mf->VAO=0;mf->Buffers=NULL;
   // mf->texture=(Mesh_viewer_texture*)malloc(sizeof(Mesh_viewer_texture));
   // Mesh_viewer_texture_init(mf->texture);

}
typedef struct Viewer_Camera
{
/*this matrix represent the rotation of camera(camera lens)and location*/
	/*the three order matrix of this matrix should be Unitary matrix*/
	Matrix4x4* matrix;
	/*this matrix is to accelerate computing*/
	Matrix4x4* matrix_inverse;
	Matrix4x4* Proj;
	//void (*set_using)(struct Viewer_world*,struct Viewer_Camera* c);
	int is_using;
/**/
	float focal_distance;
	void* prop;

}Viewer_Camera;
//void Viewer_Camera_init(Viewer_Camera*);
static inline void Viewer_Camera_init(Viewer_Camera*mc)
{
    mc->matrix=(Matrix4x4*)malloc(sizeof(Matrix4x4));
    Matrix4x4_init_float(mc->matrix); 
    //mc->matrix_inverse=(Matrix4x4*)malloc(sizeof(Matrix4x4));
    //Matrix4x4_init_float(mc->matrix_inverse);
	mc->Proj=(Matrix4x4*)malloc(sizeof(Matrix4x4));
	Matrix4x4_init_float(mc->Proj);
    mc->prop=0;
    mc->is_using=0;
    mc->focal_distance=1;
    float* data=(float*)(mc->matrix->data);
    data[2*4+3]=-5;
    mc->matrix_inverse=mc->matrix->inverse(mc->matrix);

}
typedef struct Viewer_Points
{
	float *Data,*color;
	unsigned int Data_rows;
	
	//unsigned int color_rows;
	//
	void (*set_color)(struct Viewer_Points*,float*);
	void (*random_color)(struct Viewer_Points*);	
	void* evolution;
	Matrix4x4* mat;
	float pointsize;
	void *prop;

	unsigned int VAO,*Buffers;
}Viewer_Points;
void Viewer_Points_random_color(struct Viewer_Points* mp);

void Viewer_Points_set_color(Viewer_Points*vp,float*c);
static inline void Viewer_Points_init(struct Viewer_Points* mp)
{
    mp->Data=0;mp->color=NULL;
    
   
    mp->prop=NULL;
    mp->evolution=NULL;
    mp->set_color=Viewer_Points_set_color;
    mp->random_color=Viewer_Points_random_color;
    mp->Data_rows=0; 

 //   mp->color_rows=0;
//
	mp->mat=(Matrix4x4*)malloc(sizeof(Matrix4x4));
    Matrix4x4_init_float(mp->mat);
	mp->pointsize=3.0;

    ///
    mp->VAO=0;mp->Buffers=NULL;
	
}
//void Viewer_Points_init(struct Viewer_Points*);

typedef struct Viewer_Edges
{
	float *Data,*color;
	unsigned int* Data_index;
	
    	unsigned int Data_index_rows,Data_rows,color_rows;
	
	float edgesize;
	void (*set_color)(struct Viewer_Edges*,float*);
	void (*random_color)(struct Viewer_Edges*);
	Matrix4x4* mat;
	
	void* evolution;
	void *prop;

	unsigned int VAO,*Buffers;
}Viewer_Edges;

void Viewer_Edges_set_color(Viewer_Edges*,float*v);
void Viewer_Edges_random_color(Viewer_Edges*me);
static inline void Viewer_Edges_init(struct Viewer_Edges* me)
{
    me->Data=NULL;me->color=0;
    me->Data_index=0;
   
    me->prop=0;
    me->evolution=0;
    me->Data_index_rows=0;
    me->Data_rows=0;
	me->color_rows=0;
	me->mat=(Matrix4x4*)malloc(sizeof(Matrix4x4));
	me->set_color=Viewer_Edges_set_color;
	me->random_color=Viewer_Edges_random_color;
    Matrix4x4_init_float(me->mat);
	me->edgesize=2.0;
//
     me->VAO=0;  me->Buffers=NULL;
}
//void Viewer_Edges_init(struct Viewer_Edges*);
typedef struct Viewer_Cursor_Shape{
	char *shape_name;
	char *image_path;
	//void (*set_using)(struct Viewer_world*,struct Viewer_Cursor_Shape*);
	int is_using;	
	void * obj;
	void* prop;	

}Viewer_Cursor_Shape;

//void Viewer_Cursor_Shape_init(struct Viewer_Cursor_Shape* vcs);

static inline void Viewer_Cursor_Shape_init(struct Viewer_Cursor_Shape* vcs)
{
    vcs->shape_name=NULL;
    vcs->image_path=NULL;
    vcs->is_using=0;
    vcs->obj=NULL;
    vcs->prop=NULL;  
}

typedef struct Viewer_Texts{
	char * str;
	float xy[2],scale;	
	float colors[16];
	char* font_path;
	unsigned int VAO;
	unsigned int VBO[4];

	Matrix4x4 *mat;
	Matrix4x4* Proj;

	void* prop;
	void *prop1;
}Viewer_Texts;
//void Viewer_Texts_init(struct Viewer_Texts*vtext );

static inline void Viewer_Texts_init(struct Viewer_Texts*vtext )
{
    vtext->str=NULL;
    vtext->xy[0]=0;vtext->xy[1]=0;
    vtext->scale=1;
   // vtext->color[0]=0;vtext->color[1]=0;vtext->color[2]=0,vtext->color[3]=1;
    vtext->font_path=NULL;
    vtext->mat=(Matrix4x4*)malloc(sizeof(Matrix4x4));
    Matrix4x4_init_float(vtext->mat);
    vtext->Proj=(Matrix4x4*)malloc(sizeof(Matrix4x4));
    Matrix4x4_init_float(vtext->Proj);

    vtext->VAO=0;vtext->VBO[0]=0;vtext->VBO[1]=0;vtext->VBO[2]=0;
    vtext->prop=NULL;vtext->prop1=NULL;
}
void Viewer_Texts_initn(struct Viewer_Texts* vtext,char const *str,float x,float y,float s,float* c,char const *font_path);

typedef struct Viewer_UI_Mesh{

	float *Data,*color;
	unsigned int* Data_index;
	unsigned int color_rows;
	unsigned int* marked_faces_index;

    unsigned int Data_index_rows;
	unsigned int Data_rows;
	float triangle_coordinate[3];	
	
	void (*random_color)(struct Viewer_UI_Mesh*);
	void (*set_color)(struct Viewer_UI_Mesh*,float*);
	Matrix4x4 *mat;
	Matrix4x4* Proj;
	Viewer_Something* texture;
	Viewer_Something* intera;
	int is_transparent;
	int disappear;
	int update;
	void* evolution;
	void* prop;

	unsigned int VAO,*Buffers;
}Viewer_UI_Mesh;
void Viewer_UI_Mesh_set_color(Viewer_UI_Mesh* vum,float *c);
void Viewer_UI_Mesh_random_color(Viewer_UI_Mesh* vum);
static inline void Viewer_UI_Mesh_init(Viewer_UI_Mesh* vum)
{
    vum->Data=NULL;vum->color=NULL;
    vum->Data_index=NULL;

    vum->marked_faces_index=NULL;
   
    vum->evolution=NULL;
    vum->Data_index_rows=0;
    vum->color_rows=0;
    vum->Data_rows=0;
    vum->random_color=Viewer_UI_Mesh_random_color;
    vum->set_color=Viewer_UI_Mesh_set_color;
    vum->mat=(Matrix4x4*)malloc(sizeof(Matrix4x4));
    Matrix4x4_init_float(vum->mat);
    vum->Proj=(Matrix4x4*)malloc(sizeof(Matrix4x4));
    Matrix4x4_init_float(vum->Proj);
    vum->prop=NULL;
    vum->disappear=0;
    vum->is_transparent=0;
    vum->texture=NULL;vum->intera=NULL;
    vum->update=0;
    vum->VAO=0;vum->Buffers=NULL;
    /*mf->compute_normal=Viewer_Faces_compute_normal;
    mf->random_color=Viewer_Faces_random_color;
    
    mf->is_reversal_normal=0;
    mf->is_transparent=0;

    mf->triangle_coordinate[0]=1;mf->triangle_coordinate[1]=0;mf->triangle_coordinate[2]=0;   
    //
*/
}
//void Viewer_UI_Mesh_init(Viewer_UI_Mesh* vum);

#ifdef __cplusplus
}
#endif
#undef Matrix4x4
#endif
