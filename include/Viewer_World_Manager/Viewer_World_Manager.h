//#include<Mesh_IO/Mesh_IO.h>
#ifndef VIEWERER_WORLD_MANAGER_H
#define VIEWERER_WORLD_MANAGER_H

#include<string.h>
#include<time.h>
#include "Viewer_Base_Species.h"
#include "Interactor_GlobalInfo.h"
#include <tools_rbtree.h>
#ifdef  __cplusplus
extern "C" {
#endif



//void Mesh_viewer_world_registe1(Mesh_viewer_world*,char**,int);

typedef struct Viewer_World{
	int species_id;
	RB_Tree *species2somethings;//<int,<int Viewer_Something>>
	RB_Tree *species_name_registe;//<int, char*>
	RB_Tree *something_id;//<int,int>
	//std::map<int,std::map<int,Mesh_viewer_something*>*>species2somethings;
	//std::map<int,char*>species_name_registe;
//use for give a single name
	//std::map<int,int>something_id;
	Interactor_GlobalInfo *g_info;
	Node* (*create_something)(struct Viewer_World*,char*);
	void (*remove_something)(struct Viewer_World*,Viewer_Something*);
	void (*print_self)(struct Viewer_World*);
	Node* (*find_species)(struct Viewer_World*,char*);
	Node*(*registe)(struct Viewer_World*,char*);
	RB_Tree_Trav  (* species_begin)(struct Viewer_World*,char*);
	RB_Tree_Trav(*species_end)(struct Viewer_World*,char*);
	float background_color[4];
	//char cursor_shape[40];	
	void *prop;
	void* *prop1;
}Viewer_World;
/*查找物种并返回ids,比如Viewer_World_find_species(vw,"Points,Edges")*/
Node* viewer_world_find_species(struct Viewer_World*,char*);
Node* viewer_world_find_registe(struct Viewer_World*,char*);
Node* viewer_world_from_something_evolute(Node*,struct Viewer_World*);
Node* viewer_world_create_something(struct Viewer_World*,char *);


void viewer_world_remove_something(struct Viewer_World*,Viewer_Something*);
/*viewer_world_species_begin(vw,"Points")*/
RB_Tree_Trav viewer_world_species_begin(struct Viewer_World*,char *);
RB_Tree_Trav viewer_world_species_end(struct Viewer_World* ,char*);

void viewer_world_printself(Viewer_World*);


//void Mesh_viewer_add_face_data(Mesh_viewer_faces*,double *v,int v_cols,int v_rows,int *index,int i_cols,int i_rows,double *color);

static inline void viewer_world_init(struct Viewer_World*m)
{
	//m->things_id=0;
	//char str[]="points,edges,faces";
	m->species_id=0;
	m->species2somethings=(RB_Tree*)malloc(sizeof(RB_Tree));
	rb_tree_init_int(m->species2somethings);
	m->species_name_registe=(RB_Tree*)malloc(sizeof(RB_Tree));
	rb_tree_init_int(m->species_name_registe);
	m->something_id=(RB_Tree*)malloc(sizeof(RB_Tree));
	rb_tree_init_int(m->something_id);
    m->g_info=(Interactor_GlobalInfo*)malloc(sizeof(Interactor_GlobalInfo));
    GlobalInfo_init(m->g_info);
   char str[]="Points,Edges,Faces,Intera,Camera,Texture,UI_Mesh,Cursor_Shape,Texts";
	Node* node=viewer_world_find_registe(m,str);
    node=node_reverse(node);
    free_node_value(node);
    free_node(node);
 	m->find_species=viewer_world_find_species;
    m->create_something=viewer_world_create_something;
    m->remove_something=viewer_world_remove_something;
    m->print_self=viewer_world_printself;
    m->species_begin=viewer_world_species_begin; 
    m->species_end=viewer_world_species_end;
    m->registe=viewer_world_find_registe;
    m->background_color[0]=0.2;m->background_color[1]=0.5;m->background_color[2]=1.0;m->background_color[3]=1.0;
//    strcpy(m->cursor_shape,"VIEWER_ARROW_CURSOR");

 	m->prop=NULL;
    m->prop1=NULL;
}

typedef struct Viewer_World_Manager{
	int size;
	RB_Tree* container;	

}Viewer_World_Manager;



static inline void viewer_world_manager_init(Viewer_World_Manager*vwm)
{

	vwm->size=0;
	vwm->container=(RB_Tree*)malloc(sizeof(RB_Tree));
	rb_tree_init_int(vwm->container);

}

#ifdef __cplusplus
}
#endif
#endif
