#include "list.h"
#include <stdio.h>
#include "tree_etu.h"
#include <stdlib.h>

void tree_resetByteOccurrence( struct byteCoding indexedCodeTable[256] )
                    {
                    for (int i =0; i<256; i++)
                    {
                        indexedCodeTable[i].occurrence=0;
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
                        for (int i=0; i<256;i++)

                        {
                            if (indexedCodeTable[i].occurrence!=0)
                            {
                            printf( " ocur = %d\n", indexedCodeTable[i].occurrence);
                            printf( " codhuff = %d\n", indexedCodeTable[i].huffmanCode);
                            printf( " nbits = %d\n", indexedCodeTable[i].nbBits);
                            printf( " bytes = %c\n", indexedCodeTable[i].byte); 
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
                            
                             int p = *(left->valeur_noeud) + *(right->valeur_noeud);
                            *v=p;
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

        
        
        
        struct tree_node  * local_fg;
        struct tree_node  * local_fd;

        while (list_next(l)!=NULL )

        {
            local_fg = GET_LIST_DATA(l,struct tree_node*);
                l=list_headRemove(l);
            local_fd = GET_LIST_DATA(l,struct tree_node*);
                l=list_headRemove(l);

            arbre =  tree_createCodingNode(local_fd,local_fg); 
            list_orderedAppend(&l,&compare,arbre); 
            
        }
        s_node * ptr = l;

            while(ptr != NULL)
        {
            printf("%d \n \n",*GET_LIST_DATA(ptr,struct tree_node*)->valeur_noeud);
        
            ptr=list_next(ptr);

        }
        list_destroy(l);
        
        
        return arbre;
    }

void tree_display( struct tree_node * root, int level ) 
{
    if (root==NULL)return ;
    for (int i=0;i<level;i++)
    {
        printf("--");
    }
    if ((root->ndfgauche)==NULL && (root->ndfdroite)==NULL)return;
        printf("%d \n ",*(root->valeur_noeud));
        
       tree_display(root->ndfgauche,level+1);
       tree_display(root->ndfdroite,level+1);  



       
}
void tree_destroy( struct tree_node * root )
{
    if (root==NULL) return;
    
    if ((root->ndfgauche)==NULL && (root->ndfdroite)==NULL)
    {
        free(root->valeur_noeud);
        tree_destroy(root->ndfgauche);
        tree_destroy(root->ndfdroite);
        
    }
    free(root);

}



