#ifndef INTERACTOR_GLOBALINFO_H
#define INTERACTOR_GLOBALINFO_H
#include <tools_node.h>
#define VIEWER_ARROW_CURSOR 0x00036001
#define VIEWER_IBEAM_CURSOR   0x00036002
#define VIEWER_CROSSHAIR_CURSOR   0x00036003
#define VIEWER_HAND_CURSOR   0x00036004
#define VIEWER_HRESIZE_CURSOR   0x00036005
#define VIEWER_VRESIZE_CURSOR   0x00036006

#define VIEWER_MOUSE_BUTTON_LEFT 0
#define VIEWER_MOUSE_BUTTON_RIGHT 1
#define VIEWER_MOUSE_BUTTON_MIDDLE 2
#define VIEWER_PRESS 1
#define VIEWER_RELEASE 0
#define VIEWER_REPEAT 2
#define VIEWER_MOD_SHIFT 1
#define VIEWER_MOD_CONTROL 2
#define VIEWER_MOD_ALT 4
#define VIEWER_MOD_SUPER 8
#define VIEWER_KEY_CONTROL 341
#define VIEWER_KEY_ALT 342
#define VIEWER_KEY_0 48
#define VIEWER_KEY_9 57
#define VIEWER_KEY_A 65
#define VIEWER_KEY_B 66
#define VIEWER_KEY_C 67
#define VIEWER_KEY_D 68
#define VIEWER_KEY_E 69
#define VIEWER_KEY_F 70
#define VIEWER_KEY_G 71
#define VIEWER_KEY_H 72
#define VIEWER_KEY_I 73
#define VIEWER_KEY_J 74
#define VIEWER_KEY_K 75
#define VIEWER_KEY_L 76
#define VIEWER_KEY_M 77
#define VIEWER_KEY_N 78
#define VIEWER_KEY_O 79
#define VIEWER_KEY_P 80
#define VIEWER_KEY_Q 81
#define VIEWER_KEY_R 82
#define VIEWER_KEY_S 83
#define VIEWER_KEY_T 84
#define VIEWER_KEY_U 85
#define VIEWER_KEY_Z 90

#ifdef __cplusplus
extern "C" {
#endif
typedef struct Interactor_GlobalInfo{
	float run_time;
	float *mouse_coord;
	int *resolution;
	int mouse_button;
	int mouse_action;
	int key;
	int key_action;
	int key_mods;
	int mouse_mods;
	unsigned char *readpixelcolor;
	void* pick_something;
	int drop_count;
	char** paths;
	void *prop;
	void* window;
}Interactor_GlobalInfo;

static inline void GlobalInfo_init(Interactor_GlobalInfo *ginf)
{
	ginf->prop=NULL;
	ginf->window=NULL;
	ginf->pick_something=NULL;
	ginf->mouse_coord=(float*)malloc(sizeof(float)*2);
	ginf->resolution=(int*)malloc(sizeof(int)*2); 
	ginf->resolution[0]=800;
	ginf->resolution[1]=600;
	ginf->readpixelcolor=(unsigned char*)malloc(sizeof(unsigned char)*36);
	for(int i=0;i<36;i++)
	{
		ginf->readpixelcolor[i]=0;
	}
	ginf->key_action=0;
	ginf->mouse_action=0;
	ginf->drop_count=0;
	ginf->paths=NULL;
}
//void GlobalInfo_init(Interactor_GlobalInfo* ginf);
typedef struct Viewer_Intera
{

	int state;
	Interactor_GlobalInfo* g_info;
	int (*compute_state)(struct Viewer_Intera* );
	void(*cursor_position_callback)(struct Viewer_Intera*);
	void(*mouse_button_callback)(struct Viewer_Intera*);
	void(*framebuffer_size_callback)(struct Viewer_Intera*);
	void(*key_callback)(struct Viewer_Intera*);
	void(*scroll_callback)(struct Viewer_Intera*,double,double);
	void (*drop_callback)(struct Viewer_Intera*);
	void (*animation)(struct Viewer_Intera*);
	void *representation;
	void *prop;
	
}Viewer_Intera;
int Viewer_Intera_default_compute_state(Viewer_Intera*);
//void Viewer_Intera_init(Viewer_Intera*);

static inline void Viewer_Intera_init(Viewer_Intera* m_v_i)
{
	m_v_i->state=-1;
	m_v_i->prop=NULL;
	m_v_i->representation=NULL;
	m_v_i->g_info=NULL;
	m_v_i->compute_state=Viewer_Intera_default_compute_state;
	m_v_i->cursor_position_callback=NULL;
	m_v_i->mouse_button_callback=NULL;
	m_v_i->framebuffer_size_callback=NULL;
	m_v_i->key_callback=NULL;
	m_v_i->scroll_callback=NULL;
	m_v_i->animation=NULL;
	m_v_i->drop_callback=NULL;
}
#ifdef __cplusplus
}
#endif
#endif
