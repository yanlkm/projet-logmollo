#include "list.h"
#include "stdio.h"
#include "tree_etu.h"
#include "string.h"
#include "stdlib.h"





int main()

{
    struct tree_node pere;
    struct tree_node pere1;
    struct tree_node pere2;

    

    const t_byte * chaine ="mmmarieeeeeeiiiiiiaaaallloooo";
    int size = strlen(chaine);
    struct byteCoding tab[256];

    tree_resetByteOccurrence( tab );
    tree_resetByteCoding( tab );

    tree_countByteOccurrence( chaine, size, tab );
    tree_displayByteCoding(tab);
    printf("\n");
   
    
   

    

    /*s_node * ptr,*l=list_create();
    int a=2,b=3,c=4;

    list_orderedAppend(&l,&compare,&a);
    list_orderedAppend(&l,&compare,&c);
    list_orderedAppend(&l,&compare,&b);

    ptr=l;

    while(ptr != NULL)
    {
        printf("%d \n",*GET_LIST_DATA(ptr,int*));
        ptr=list_next(ptr);

    }*/

    
    /*int nb=10,nc=122,nd=15;
  
    pere.valeur_noeud=&nb;
    pere.ndpere=NULL;
    pere.ndfdroite=NULL;
    pere.ndfgauche=NULL;
    pere1.valeur_noeud=&nc;
    pere1.ndpere=NULL;
    pere1.ndfdroite=NULL;
    pere1.ndfgauche=NULL;
    pere2.valeur_noeud=&nd;
    pere2.ndpere=NULL;
    pere2.ndfdroite=NULL;
    pere2.ndfgauche=NULL;
    

    struct tree_node * pa = tree_createNode (&pere, &nb);
    struct tree_node * pb = tree_createNode (&pere1, &nd);
    struct tree_node * pc = tree_createNode (&pere2, &nc);

    printf("\n%d",*(pa->valeur_noeud));
    printf("\n%d",*(pb->valeur_noeud));
    printf("\n%d",*(pc->valeur_noeud));
    printf("\n");
    



    list_orderedAppend(&l,&compare,pb);
    list_orderedAppend(&l,&compare,pa);
    list_orderedAppend(&l,&compare,pc);*/
   
   struct tree_node *  truc = tree_create(tab);

   int n=0;
tree_destroy(truc);
   tree_display(truc,n);

   


   

    
    
    
    return 0;


    
}