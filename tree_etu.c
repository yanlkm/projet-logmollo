#include "list.h"
#include <stdio.h>
#include "tree_etu.h"
#include <stdlib.h>

char * afficheBit(int code,int  nbBits)
{


        static char tr[33];

        for (int i=(nbBits-1); i>=0; i--)
        {
                       
                {
                        tr[i] = (code % 2 == 0 ? '0' : '1');
                        code /= 2;
                }
             
        }
        tr[nbBits]='\0';

        return tr;
}

void prefixe(struct byteCoding indexedCodeTable[256])

                    {int test;
			   
                             		printf(" test de préfixe : \n");
                        for (int i=0; i<256;i++)

                        {
						if (indexedCodeTable[i].occurrence!=0)
                            {
				char * chaine1 = afficheBit(indexedCodeTable[i].huffmanCode,indexedCodeTable[i].nbBits);
				char vchaine1[32]; 
				strcpy(chaine1,vchaine1);
				for (int j=i;j<256;j++)
				{
                            		if (indexedCodeTable[j].occurrence!=0)
                            	{
			 	char * chaine2 =  afficheBit(indexedCodeTable[j].huffmanCode,indexedCodeTable[j].nbBits);
				
			       	char vchaine2[32];
			strcpy(chaine2,vchaine2);	

				int p=0;
				int k=0;
				int taille1=strlen(chaine1);
				int taille2=strlen(chaine2);
				while ((vchaine1[p]!='\0' && vchaine2[p]!='\0') && vchaine2[p]!=vchaine1[p])
				{
				
					p++;
				}
				 if(p<taille1-1 || p<taille2-1)
                                        {
                                                k=1;
                                                printf(" (k) : %c ,(k) : %c \n",vchaine1[p],vchaine2[p]);
                                        }
				test=k;
                            	}
				}

                            }


                        }
			if(test==1)
			{
			printf("\n erreur de préfixe !\n");
			}
			else
			{
				printf("\n aucun n'est préfixe de l'autre !\n");
			}
		    }
void tree_resetByteOccurrence( struct byteCoding indexedCodeTable[256] )
                    {
                    for (int i =0; i<256; i++)
                    {
                        indexedCodeTable[i].occurrence=0;
			indexedCodeTable[i].byte=(t_byte);
		    }
                    }
void tree_resetByteCoding( struct byteCoding indexedCodeTable[256] )
                    {
                        for (int i =0; i<256; i++)
                        {
                            indexedCodeTable[i].huffmanCode=0;
                            indexedCodeTable[i].nbBits=0;

                        }
                    }
void tree_countByteOccurrence( const t_byte * buffer, int size, struct byteCoding indexedCodeTable[256] )
                   {
                       t_byte cpt;
                       
                         for (int i=0; i<size; i++)
                        { 
                            cpt =*(buffer + i);
                            indexedCodeTable[cpt].occurrence++;
                        } 

                       

                   }
void tree_displayByteCoding(struct byteCoding indexedCodeTable[256])

                    {
			     printf("occur codHuff     nbits           bytes       codeHuffbinaire\n");
                        for (int i=0; i<256;i++)

                        {
                            if (indexedCodeTable[i].occurrence!=0)
                            {
			  char  * s =afficheBit(indexedCodeTable[i].huffmanCode,indexedCodeTable[i].nbBits); 
                            printf( " %2d %6d %12d %16c %8s\n", indexedCodeTable[i].occurrence, indexedCodeTable[i].huffmanCode, indexedCodeTable[i].nbBits,indexedCodeTable[i].byte,s);
                            
			    
			    }
                            }
                           


                    }
struct tree_node * tree_createNode (struct tree_node * father, int * value ) 
                    
                    {
                        
                        
                        struct tree_node * pont = (struct tree_node *)malloc(sizeof(struct tree_node));
                        if (pont==NULL)
                        {
                                perror("Unable to allocate memory");
                                return NULL;      
                        }
                        struct tree_node nd;
                       
                        nd.ndpere=father;
                        nd.valeur_noeud=value;
                        nd.ndfgauche=NULL;
                        nd.ndfdroite=NULL;
                         *pont = nd;
                        return pont;
                        }
                        
                    
struct tree_node * tree_createCodingNode ( struct tree_node * left, 
					   struct tree_node * right )
                       {
                        
                            struct tree_node * tonp = (struct tree_node *)malloc(sizeof(struct tree_node));
                            int * v =  (int*)malloc(sizeof(int));

                            if (tonp==NULL || v ==NULL)
                            {
                                    perror("Unable to allocate memory");
                                    return NULL;      
                            }
			    *v=0;

                            if (left!=NULL && left->valeur_noeud!=NULL) *v+=*(left->valeur_noeud);
			    if (right!=NULL && right->valeur_noeud!=NULL) *v+=*(right->valeur_noeud);
                            struct tree_node nd;
                            nd.ndpere=NULL;
                            nd.valeur_noeud=v;
                            nd.ndfgauche=left;
                            nd.ndfdroite=right;
                            *tonp = nd;
                            return tonp;

                       }

static int compare(s_node * s, void * param)
 {
                        struct tree_node * param_noeud_feuille = (struct tree_node * )param ;
                        struct tree_node* data_snode=GET_LIST_DATA(s,struct tree_node*); 

                        if ( *(param_noeud_feuille->valeur_noeud )== *(data_snode->valeur_noeud)) return 0;

                        if (*(param_noeud_feuille->valeur_noeud )> *(data_snode->valeur_noeud) )return -1;

                        return 1;
}


 struct tree_node * tree_create ( struct byteCoding * indexedCodeTable )
    {
        s_node * l = list_create(); 
        struct tree_node * feuille ; 
        struct tree_node * arbre ; 
        

        for (int i = 0; i<256;i++ ) 
        {
            if (indexedCodeTable[i].occurrence!=0)
            {
            feuille  = tree_createNode (NULL, (int*) &indexedCodeTable[i]) ;
            list_orderedAppend(&l,&compare,feuille); 
            
            }
        }

	printf("list: \n");
        for (s_node * node=l; node != NULL; node = list_next(node))
	{
		printf("| %d ", *GET_LIST_DATA(node, struct tree_node*)->valeur_noeud);
	}
	printf("|\n");
        
        
        struct tree_node  * local_fg;
        struct tree_node  * local_fd;

        while (list_next(l)!=NULL )

        {
            local_fg = GET_LIST_DATA(l,struct tree_node*);
                l=list_headRemove(l);
            local_fd = GET_LIST_DATA(l,struct tree_node*);
                l=list_headRemove(l);

            arbre =  tree_createCodingNode(local_fg,local_fd); 
            list_orderedAppend(&l,&compare,arbre); 
            
        }
        s_node * ptr = l;

            while(ptr != NULL)
        {
            printf("%d \n \n",*GET_LIST_DATA(ptr,struct tree_node*)->valeur_noeud);
        
            ptr=list_next(ptr);
	}
	   if(arbre->ndfgauche==NULL && arbre->ndfdroite==NULL)
	   arbre=tree_createCodingNode(arbre,NULL);

        list_destroy(l);
        
        
        return arbre;
    }

void tree_display( struct tree_node * root, int level ) 
{
    if (root==NULL)return;
    
   
        
       
   tree_display(root->ndfdroite,level+1);
   printf("%*s%d\n ",(level)*(5),"",*(root->valeur_noeud));   
   tree_display(root->ndfgauche,level+1);
         
}
void tree_destroy( struct tree_node * root )
{
    if (root==NULL) return;
	
     
    

    if ((root->ndfgauche)==NULL && (root->ndfdroite)==NULL)
    {
	printf("\ndestruction pere : %d \n",*(root->valeur_noeud));
	return;
    	    
    }
    else{
	    free(root);
    	printf("\n destruction noeud f gauche \n");
        tree_destroy(root->ndfgauche);
	printf("\ndestruction noeud f droite\n");
        tree_destroy(root->ndfdroite);
    }	
    
   

}






void tree_buildHuffmanCode(struct tree_node * root, int level, int code)
{
	 	
	if(root==NULL)
		return ;
	if((root->ndfgauche==NULL) && (root->ndfdroite)==NULL)
	
	{
	struct byteCoding * ad = (struct byteCoding *)(root->valeur_noeud);	
		ad->huffmanCode = code;
	       	ad->nbBits=level;
		
	       	return;
	}	 
		
	
	
		code = code<<1;
		level++;
		
		tree_buildHuffmanCode(root->ndfgauche,level,code);
	 	tree_buildHuffmanCode(root->ndfdroite,level,code+1);
	
	

}

