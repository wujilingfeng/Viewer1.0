#include <Viewer_Interpreter/glfw_callback.h>

void update_intera_information(GLFWwindow*window,Interactor_GlobalInfo*g_info)
{	
	double x,y;
        glfwGetCursorPos(window,&x,&y);
        g_info->mouse_coord[0]=x;
	g_info->mouse_coord[1]=y;
	int key=glfwGetKey(window,GLFW_KEY_F);
	if(key==GLFW_PRESS)
	{
        g_info->key=GLFW_KEY_F;
        g_info->key_action=GLFW_PRESS;
	}
    int mouse_action=glfwGetMouseButton(window,GLFW_MOUSE_BUTTON_LEFT);
    //printf("mous_action%d\n",mouse_action);
    if(mouse_action==GLFW_PRESS)
    {
        	g_info->mouse_button=GLFW_MOUSE_BUTTON_LEFT;
        	g_info->mouse_action=mouse_action;
    
    }
}
void viewer_cursor_position_callback(GLFWwindow* window,double x,double y)
{
    //
    Viewer_World* mw=(Viewer_World*)(glfwGetWindowUserPointer(window));
    Interactor_GlobalInfo* g_info=mw->g_info;
    g_info->mouse_coord[0]=(float)x;
    g_info->mouse_coord[1]=(float)y;
    char intera[]="Intera";
    Node* id=mw->find_species(mw,intera);
	RB_int rbt;
	rbt.key=*((int*)(id->value));
    RB_int *rbt1=(RB_int*)mw->species2somethings->find(mw->species2somethings,&rbt);
	RB_Tree* tree=NULL;
    RB_Tree_Trav* iter1=NULL;
    if(rbt1!=NULL)
    {
	    tree=(RB_Tree*)(rbt1->value);
        iter1=tree->rbegin(tree);
        for(;iter1->it!=NULL;iter1->prev(iter1))
        {
	        Viewer_Something* vs=((Viewer_Something*)(iter1->second(iter1)));
            Viewer_Intera* mi=(Viewer_Intera*)(vs->evolution);
            mi->compute_state(mi);
            if(mi->cursor_position_callback!=0)
            {
                mi->cursor_position_callback(mi);
            }
            if(mi->state>=0)
            {
                break;
            }
        }
	    free(iter1);
    }
    free_node_value(id);
    free_node(id);
    
    return;

}
void viewer_mouse_button_callback(GLFWwindow* window,int button,int action,int mods)
{
    
    Viewer_World* mw=(Viewer_World*)(glfwGetWindowUserPointer(window));
    Interactor_GlobalInfo* g_info=mw->g_info;
   // glReadPixels(g_info->mouse_coord[0],g_info->resolution[1]-g_info->mouse_coord[1],3,3,GL_RGBA,GL_UNSIGNED_BYTE,g_info->readpixelcolor);
 //   printf("%d\n",g_info->mouse_button);
  
    g_info->mouse_button=button;
    g_info->mouse_action=action;
	g_info->mouse_mods=mods;

    char intera[]="Intera";
    Node* id=mw->find_species(mw,intera);
    RB_int rbt,*rbt1;
	rbt.key=*((int*)(id->value));
	rbt1=mw->species2somethings->find(mw->species2somethings,&rbt);
	RB_Tree *tree=NULL;
    RB_Tree_Trav* iter1=NULL;
    if(rbt1!=NULL)
    {
        tree=(RB_Tree*)(rbt1->value);
        iter1=tree->rbegin(tree);
        for(;iter1->it!=NULL;iter1->prev(iter1))
        {
	        Viewer_Something* vs=(Viewer_Something*)(iter1->second(iter1));
            Viewer_Intera* mi=(Viewer_Intera*)(vs->evolution);
            mi->compute_state(mi);
            if(mi->mouse_button_callback!=NULL)
            {
                mi->mouse_button_callback(mi);
            }
            if(mi->state>=0)
            {
                break;
            }
    
        }
	    free(iter1);
    }
    free_node_value(id);
    free_node(id);
    return;
}
void viewer_framebuffer_size_callback(GLFWwindow* window,int w,int h)
{
    //w,h以像素为单位
    Viewer_World* mw=(Viewer_World*)(glfwGetWindowUserPointer(window));
    Interactor_GlobalInfo* g_info=mw->g_info;
    
    g_info->resolution[0]=w;
    g_info->resolution[1]=h;
    //glViewport(0.0,0.0,w,h);
    char intera[]="Intera";
    Node* id=mw->find_species(mw,intera);
    RB_int rbt,*rbt1;
	rbt.key=*((int*)(id->value));
	rbt1=mw->species2somethings->find(mw->species2somethings,&rbt);
	RB_Tree* tree=(RB_Tree*)(rbt1->value);
  	RB_Tree_Trav* iter1=tree->rbegin(tree);
    for(;iter1->it!=NULL;iter1->prev(iter1))
    {
		Viewer_Something* vs=(Viewer_Something*)(iter1->second(iter1));
        Viewer_Intera* mi=(Viewer_Intera*)(vs->evolution);
        mi->compute_state(mi);
        if(mi->framebuffer_size_callback!=0)
        {
        
            mi->framebuffer_size_callback(mi);
        }
        if(mi->state>=0)
        {
            break;
        }
    
    
    }
	free(iter1);
    free_node_value(id);
    free_node(id);


    return;
}
void viewer_key_callback(GLFWwindow* window,int key,int scancode,int action,int mods)
{
    Viewer_World* mw=(Viewer_World*)(glfwGetWindowUserPointer(window));
    //printf("%d\n",action);
    Interactor_GlobalInfo* g_info=mw->g_info;
    
    g_info->key=key;
    g_info->key_action=action;
//    printf("key action:%d\n",action);
    g_info->key_mods=mods;

    //printf("key:%d key_action:%d\n",key,action);    
    char intera[]="Intera";
    Node* id=mw->find_species(mw,intera);
    RB_int rbt,*rbt1;
	rbt.key=*((int*)(id->value));
	
	rbt1=mw->species2somethings->find(mw->species2somethings,&rbt);
	RB_Tree* tree=(RB_Tree*)(rbt1->value);
	RB_Tree_Trav* iter1=tree->rbegin(tree);

    for(;iter1->it!=NULL;iter1->prev(iter1))
    {
		Viewer_Something* vs=(Viewer_Something*)(iter1->second(iter1));
        Viewer_Intera* mi=(Viewer_Intera*)(vs->evolution);
        mi->compute_state(mi);
        if(mi->key_callback!=0)
        {
        
            mi->key_callback(mi);
        }
        if(mi->state>=0)
        {
            break;
        }
    
    
    }
	free(iter1);
    free_node_value(id);
    free_node(id);
    


    return;
}
void viewer_scroll_callback(GLFWwindow* window,double x,double y)
{
    Viewer_World* mw=(Viewer_World*)(glfwGetWindowUserPointer(window));
    //Interactor_GlobalInfo* g_info=mw->g_info;

    char intera[]="Intera";
    Node* id=mw->find_species(mw,intera);
     RB_int rbt,*rbt1;
	rbt.key=*((int*)(id->value));
	
	rbt1=mw->species2somethings->find(mw->species2somethings,&rbt);
	RB_Tree* tree=(RB_Tree*)(rbt1->value);
	RB_Tree_Trav* iter1=tree->rbegin(tree);
    for(;iter1->it!=NULL;iter1->prev(iter1))
    {
		Viewer_Something* vs=(Viewer_Something*)(iter1->second(iter1));
        Viewer_Intera* mi=(Viewer_Intera*)(vs->evolution);
        mi->compute_state(mi);
        if(mi->scroll_callback!=NULL)
        {
            mi->scroll_callback(mi,x,y);
        }
        if(mi->state>=0)
        {
            break;
        } 
    }
	free(iter1);
    free_node_value(id);
    free_node(id);
    return;
}
void viewer_drop_callback(GLFWwindow* window,int count,const char** paths)
{
    /*for(int i=0;i<count;i++)
    {
        printf("path:%s\n",paths[i]);
    }*/
    Viewer_World* mw=(Viewer_World*)(glfwGetWindowUserPointer(window));
    Interactor_GlobalInfo* g_info=mw->g_info;
    //printf("count:%d\n",g_info->drop_count);
    for(int i=0;i<g_info->drop_count;i++)
    {
        free(g_info->paths[i]);
    } 
    if(g_info->paths!=NULL)
    {
//        printf("dsfsd\n");
        free(g_info->paths);
        g_info->paths=NULL;
    }
    g_info->drop_count=count;
    g_info->paths=(char**)malloc(sizeof(char*)*count);
    for(int i=0;i<g_info->drop_count;i++)
    {
        g_info->paths[i]=(char*)malloc(sizeof(char)*200);
        strcpy(g_info->paths[i],paths[i]);

      //  printf("%s\n",g_info->paths[i] );
    }
    char intera[]="Intera";
    Node* id=mw->find_species(mw,intera);
     RB_int rbt,*rbt1;
    rbt.key=*((int*)(id->value));
    
    rbt1=mw->species2somethings->find(mw->species2somethings,&rbt);
    RB_Tree* tree=(RB_Tree*)(rbt1->value);
    RB_Tree_Trav* iter1=tree->rbegin(tree);
    for(;iter1->it!=NULL;iter1->prev(iter1))
    {
        Viewer_Something* vs=(Viewer_Something*)(iter1->second(iter1));
        Viewer_Intera* mi=(Viewer_Intera*)(vs->evolution);
        mi->compute_state(mi);
        if(mi->drop_callback!=NULL)
        {       
            mi->drop_callback(mi);
        }
        if(mi->state>=0)
        {
            break;
        } 
    }
    free(iter1);
    free_node_value(id);
    free_node(id);
    return;
}

void veiwer_set_char_callback(GLFWwindow* window,unsigned int codepoint)
{
    printf("%u \n",codepoint);
}
void viewer_set_callback(GLFWwindow* window)
{
    glfwSetMouseButtonCallback(window,viewer_mouse_button_callback);
    glfwSetCursorPosCallback(window,viewer_cursor_position_callback);
    glfwSetKeyCallback(window,viewer_key_callback); 
    glfwSetFramebufferSizeCallback(window,viewer_framebuffer_size_callback);
    glfwSetScrollCallback(window,viewer_scroll_callback);
    glfwSetDropCallback(window,viewer_drop_callback);
    glfwSetCharCallback(window,veiwer_set_char_callback);
}
