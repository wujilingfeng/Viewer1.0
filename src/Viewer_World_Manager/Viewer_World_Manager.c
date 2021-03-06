#include<Viewer_World_Manager/Viewer_World_Manager.h>

//glDeleteVertexArrays;
//glDeleteBuffers
/*void Mesh_viewer_world_registe1(Mesh_viewer_world*m,char**c,int size)
{
	for(int i=0;i<size;i++)
	{
		int species_id=m->species_id++;
		int le=strlen(c[i]);
		char *cp=(char*)malloc(sizeof(char)*(le+1));
		cp[le]='\0';
		strcpy(cp,c[i]);
		m->something_id[species_id]=0;
		m->species_name_registe[species_id]=cp;
		m->species[species_id]=NULL;
	}

}*/

Node* viewer_world_find_species(Viewer_World*mw,char* c)
{
	if(c==NULL||c[0]=='\0')
	{
		return NULL;
	}
	//int num=0;
	Node * re=NULL;
	int i=0,j=0;
	while(c[i]!='\0')
	{

		while(c[j]!=','&&c[j]!='\0')
		{
			//printf("%d ",j);
			j++;

		}
		char *temp_c=(char*)malloc(sizeof(char)*(j-i+1));
		//char* temp_c=(char*)malloc(sizeof(char)*(j-i+1));
		temp_c[j-i]='\0';
		for(int k=0;k<j-i;k++)
		{
			temp_c[k]=c[i+k];

		}
		int* id=(int *)malloc(sizeof(int));
		*id=-1;
       		 RB_Tree* tree=mw->species_name_registe;
		RB_Tree_Trav*it=tree->begin(tree);
		for(;it->it!=NULL;it->next(it))
		{
			if(strcmp(temp_c,(char*)(it->second(it)))==0)
			{
				*id=*((int*)(it->first(it)));
				break;
			}
		}
		free(it);
		re=node_pushback(re,(void*)id);
		
        	free(temp_c);
		if(c[j]=='\0')
		{
			break;
		}
		i=j+1;
		j=j+1;
	}
	
	return node_reverse(re);
}



Node* viewer_world_find_registe(Viewer_World*m,char*c)
{
	if(c==NULL||c[0]=='\0')
	{return NULL;}
	Node* re=0;
	int i=0,j=0;
	while(c[i]!='\0')
	{

		while(c[j]!=','&&c[j]!='\0')
		{
			//printf("%d ",j);
			j++;

		}
		char* temp_c=(char*)malloc(sizeof(char)*(j-i+1));
		temp_c[j-i]='\0';
		for(int k=0;k<j-i;k++)
		{
			temp_c[k]=c[i+k];
		}
		Node* id=viewer_world_find_species(m,temp_c);
		if(id==NULL)
		{
			break;
		}
		else if(*((int*)(id->value))!=-1)
		{
			free(temp_c);
			re=node_overlying(re,id->value);
		}
		else
		{
			int species_id=m->species_id++;
			RB_int rbt;
			rbt.key=species_id;
			rbt.value=malloc(sizeof(int));
			*((int*)(rbt.value))=0;
			m->something_id->insert(m->something_id,&rbt);
			rbt.value=(void*)temp_c;
			m->species_name_registe->insert(m->species_name_registe,&rbt);
			RB_Tree* s_map=(RB_Tree*)malloc(sizeof(RB_Tree));
			rb_tree_init_int(s_map);
			rbt.value=(void*)s_map;
			m->species2somethings->insert(m->species2somethings,&rbt);
			int *temp_id=(int*)malloc(sizeof(int));
			*temp_id=species_id;
			re=node_pushback(re,(void*)temp_id);
			free(id->value);
		}
		free_node(id);
		if(c[j]=='\0')
		{
			break;
		}
		i=j+1;
		j=j+1;
	}
    //Mesh_viewer_world_printself(m);

	return node_reverse(re);
}

void viewer_world_printself(Viewer_World*mw)
{
	RB_Tree_Trav* iter=mw->species2somethings->begin(mw->species2somethings);
    for(;iter->it!=NULL;iter->next(iter))
    {
        printf("name_id:%d\n",*((int*)(iter->first(iter))));
        RB_Tree* temp=(RB_Tree*)(iter->second(iter));
        RB_Tree_Trav* iter1=temp->begin(temp);
        for(;iter1->it!=NULL;iter1->next(iter1))
        {
            Viewer_Something* vs=(Viewer_Something*)(iter1->second(iter1));
            printf("name:%s,id: %d,create_time:%u\n",vs->name,vs->id,vs->create_date);
        }
        free(iter1);
    }
    free(iter);
}


Node* viewer_world_from_something_evolute(Node*lis,struct Viewer_World* mw)
{
	Node* re=0;
	if(lis==0)
	{
		return re;
	}
	if(lis->value==0)
	{
		return re;
	}
	Node* iter=lis;
	while(iter!=0)
	{
		Viewer_Something* ms=(Viewer_Something*)(iter->value);
		void *value=0;
		if(strcmp(ms->name,"Points")==0)
		{
			Viewer_Points* temp_e=(Viewer_Points*)malloc(sizeof(Viewer_Points));
            Viewer_Points_init(temp_e);
			value=(void*)temp_e;
		}
		else if(strcmp(ms->name,"Edges")==0)
		{
			Viewer_Edges* temp_e=(Viewer_Edges*)malloc(sizeof(Viewer_Edges));
            Viewer_Edges_init(temp_e);
			value=(void*)temp_e;

		}
		else if(strcmp(ms->name,"Faces")==0)
		{

			Viewer_Faces* temp_e=(Viewer_Faces*)malloc(sizeof(Viewer_Faces));
            Viewer_Faces_init(temp_e);
			value=(void*)temp_e;
		}
        else if(strcmp(ms->name,"Intera")==0)
        {  
            Viewer_Intera* temp_e=(Viewer_Intera*)malloc(sizeof(Viewer_Intera)); 
            Viewer_Intera_init(temp_e);
            if(mw!=0)
            {
                temp_e->g_info=mw->g_info;
            }
            value=(void*)temp_e;

        }
        else if(strcmp(ms->name,"Camera")==0)
        {
            Viewer_Camera* temp_e=(Viewer_Camera*)malloc(sizeof(Viewer_Camera));
            Viewer_Camera_init(temp_e);
            value=(void*)temp_e;
        
        }
        else if(strcmp(ms->name,"Texture")==0)
        {
            Viewer_Texture*temp_e=(Viewer_Texture*)malloc(sizeof(Viewer_Texture));
            Viewer_Texture_init(temp_e);
            value=(void*)temp_e;
        }
        else if(strcmp(ms->name,"Cursor_Shape")==0)
        {
            Viewer_Cursor_Shape * temp_e=(Viewer_Cursor_Shape*)malloc(sizeof(Viewer_Cursor_Shape));
            Viewer_Cursor_Shape_init(temp_e);
            value=(void*)temp_e;
        }
        else if(strcmp(ms->name,"Texts")==0)
        {
            Viewer_Texts*temp_e=(Viewer_Texts*)malloc(sizeof(Viewer_Texts));
            Viewer_Texts_init(temp_e);
            value=(void*)temp_e;     
        }
        else if(strcmp(ms->name,"UI_Mesh")==0)
        {
            Viewer_UI_Mesh* temp_e=(Viewer_UI_Mesh*)malloc(sizeof(Viewer_UI_Mesh));
            Viewer_UI_Mesh_init(temp_e);
            value=(void*)temp_e;  
        }


		ms->evolution=value;
		re=node_pushback(re,value);
		iter=(Node*)(iter->Next);
	}
	return node_reverse(re);
}
Node* viewer_world_create_something(struct Viewer_World*mw,char *c)
{
	Node* id_list=viewer_world_find_registe(mw,c),*re=0;
	Node* iter_n=id_list;
	if(id_list==NULL)
	{return NULL;}
	int i=0,j=0;
	while(c[i]!='\0')
	{

		while(c[j]!=','&&c[j]!='\0')
		{
			//printf("%d ",j);
			j++;

		}
		char* temp_c=(char*)malloc(sizeof(char)*(j-i+1));
		temp_c[j-i]='\0';
		for(int k=0;k<j-i;k++)
		{
			temp_c[k]=c[i+k];

		}
		Viewer_Something* ms=(Viewer_Something*)malloc(sizeof(Viewer_Something));
		Viewer_Something_init(ms);
		ms->name=temp_c;
		ms->name_id=*((int*)iter_n->value);
		free(iter_n->value);
        RB_int rbt,*rbt1;
        rbt.key=ms->name_id;
        rbt1=(RB_int*)(mw->something_id->find(mw->something_id,&rbt));
        ms->id=*((int*)(rbt1->value));
        *((int*)(rbt1->value))=*((int*)(rbt1->value))+1;
         rbt.key=ms->name_id;
         rbt1=mw->species2somethings->find(mw->species2somethings,&rbt);
         rbt.key=ms->id;rbt.value=(void*)(ms);
         RB_Tree* tree1=(RB_Tree*)(rbt1->value);
         tree1->insert(tree1,&rbt);
		re=node_pushback(re,(void*)ms);
		if(c[j]=='\0')
		{
			break;
		}
		iter_n=(Node*)(iter_n->Next);
		
		i=j+1;
		j=j+1;
	}

    
	free_node(id_list);
	

    re=node_reverse(re);
    Node* temp_node=viewer_world_from_something_evolute(re,mw);
	free_node(temp_node);
	return re;
}


//

void viewer_world_remove_something(struct Viewer_World* mw,Viewer_Something* ms)
{
    RB_int rbt,*rbt1;
    rbt.key=ms->name_id;
    rbt1=(RB_int*)(mw->species2somethings->find(mw->species2somethings,&rbt));    
    if(rbt1!=NULL)
    {

        RB_Tree* tree=(RB_Tree*)(rbt1->value);
        rbt.key=ms->id;
        tree->erase(tree,&rbt);
        //rbt1=(RB_int*)(tree->find(tree,&rbt)) 
    }
}
RB_Tree_Trav viewer_world_species_begin(struct Viewer_World*vw,char * name)
{
    RB_Tree_Trav re;
    rb_tree_trav_init(&re);
    Node* names_id=vw->find_species(vw,name);
    RB_int rbt,*rbt1=NULL;
    rbt.key=*((int*)(names_id->value));
    free(names_id->value);
    free_node(names_id);

    rbt1=(RB_int*)vw->species2somethings->find(vw->species2somethings,&rbt);
    RB_Tree* tree=NULL;
    RB_Tree_Trav* iter1=NULL;
    if(rbt1!=NULL)
    {
        tree=((RB_Tree*)(rbt1->value));
        iter1=tree->begin(tree);
        re=*iter1;
        free(iter1);
    }
    return re;
}
RB_Tree_Trav viewer_world_species_end(struct Viewer_World* vw,char* name)
{
   RB_Tree_Trav re;
   rb_tree_trav_init(&re);
   return re;
}
/*void Mesh_viewer_add_face_data(Mesh_viewer_faces*mf,float* v,int v_cols,int v_rows,int *index,int i_cols,int i_rows,float *color )
{   if(v!=0&&index!=0)
    {
        mf->Data=(float*)malloc(sizeof(float)*3*i_cols*i_rows);
        mf->Data_index=(unsigned int*)malloc(sizeof(unsigned int)*i_cols*i_rows);
        mf->Data_index_rows=i_rows;
        for(int i=0;i<i_rows;i++)
        {
            for(int j=0;j<i_cols;j++)
            {
                mf->Data_index[i*i_cols+j]=index[i*i_cols+j];
                int temp_i=index[i*i_cols+j];
                for(int k=0;k<3;k++)
                {
                    if(k<v_cols)
                    {
                        Data[(i*i_cols+j)*3+k]=v[temp_i*v_cols+k];
                    }
                        Data[(i*i_cols+j)*3+k]=0;
                
                }
                
            }
        }
    
    }
    if(color!=0)
    {
        mf->color=(float*)malloc(sizeof(float)*3*i_cols*i_rows);

    
    
    }
    
}
*/

