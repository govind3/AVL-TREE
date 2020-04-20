#include <stdio.h> 
#include <stdlib.h>
struct Node 
{    
	struct Node *lchild;    
	int data;    
	int height;   
	 struct Node *rchild;
}*root=NULL;
int NodeHeight(struct Node *p) 
{    
	int hl,hr;    
	hl=p && p->lchild?p->lchild->height:0;    
	hr=p && p->rchild?p->rchild->height:0;        
	return hl>hr?hl+1:hr+1; 
} 
int BalanceFactor(struct Node *p) 
{    
	int hl,hr;    
	hl=p && p->lchild?p->lchild->height:0;    
	hr=p && p->rchild?p->rchild->height:0;        
	return hl-hr; 
} 
struct Node * LLRotation(struct Node *p) 
{    
	struct Node *pl=p->lchild;    
	struct Node *plr=pl->rchild;        
	pl->rchild=p;    
	p->lchild=plr;
    p->height=NodeHeight(p);    
    pl->height=NodeHeight(pl);        
    if(root==p)        
        root=pl;       
    return pl; 
} 
struct Node * RRRotation(struct Node *p) 
{    
	struct Node *pr=p->rchild;    
	struct Node *prl=pr->lchild;        
	pr->lchild=p;    
	p->rchild=prl;
    p->height=NodeHeight(p);    
    pr->height=NodeHeight(pr);        
    if(root==p)        
        root=pr;       
    return pr; 
} 
struct Node * LRRotation(struct Node *p) 
{    
	struct Node *pl=p->lchild;    
	struct Node *plr=pl->rchild;        
	pl->rchild=plr->lchild;    
	p->lchild=plr->rchild;        
	plr->lchild=pl;    
	plr->rchild=p;        
	pl->height=NodeHeight(pl);    
	p->height=NodeHeight(p);    
	plr->height=NodeHeight(plr);        
	if(root==p)        
		root=plr;         
	return plr;
} 
struct Node * RLRotation(struct Node *p) 
{    
	return NULL; 
}
struct Node *RInsert(struct Node *p,int key)
{    
	struct Node *t=NULL;         
	if(p==NULL)    
		{        
			t=(struct Node *)malloc(sizeof(struct Node));        
			t->data=key;        
			t->height=1;        
			t->lchild=t->rchild=NULL;        
			return t;    
		}    
	if(key < p->data)        
		p->lchild=RInsert(p->lchild,key);    
	else 
	if(key > p->data)        
		p->rchild=RInsert(p->rchild,key);        
	p->height=NodeHeight(p);        
	if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)  
	{
	    printf("LL  ImBalancing %d\n",p->data);
		return LLRotation(p);  
	}

	else 
	if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)        
	{
	    printf("LR ImBalancing of :%d\n",p->data);
		return LRRotation(p);  
	}   
	else 
	if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)       
	{
	    printf("RR ImBalancing of :%d\n",p->data);
		return RRRotation(p);  
	}
    else 
    if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)        
    {
	    printf("RL ImBalancing of :%d\n",p->data);
		return RLRotation(p);  
	}   
    return p;    
}
int main() 
{    
	root=RInsert(root,1);    
	RInsert(root,2);
    RInsert(root,3);        
    RInsert(root,4);  
    RInsert(root,5); 
    RInsert(root,6);  
    return 0; 
}