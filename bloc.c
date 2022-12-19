#include "list.h"
#include <stdio.h>
#include "tree_etu.h"
#include <stdlib.h>
#include "bloc.h"

 


t_byte * construction_bloc ( struct byteCoding * index)
{
	struct descripteur_bloc * d_bloc = malloc(sizeof(struct descripteur_bloc));
	if (d_bloc ==NULL)
	{
		 perror("Unable to allocate memory");
                                    return NULL;
	}

	
	t_byte * bloc = malloc (sizeof(TAILLE));
	
	if( bloc == NULL) 
	{
		free(d_bloc); 
		 perror("Unable to allocate memory");
                                    return NULL;
	}

	d_bloc->entete = bloc;


	
	 int p=0 , q=0;
        for (int i=0; i<256; i++)
        {
                if(index[i].occurrence!=0)
              { q++;}
	 }
	d_bloc->entete->nb_Codage = q;
	


		d_bloc->tcd = bloc + sizeof(struct entete);
			for (int j=0; j<256; j++)
		{
			if(index[j].occurrence!=0)
			{
                        d_bloc->tcd[p].occurrence = index[j].occurrence;
                        d_bloc->tcd[p].huffmanCode = index[j].huffmanCode;                        
			d_bloc->tcd[p].nbBits = index[j].nbBits;
                        d_bloc->tcd[p].byte = index[j].byte;
                        p++;
			}
                }

		d_bloc->buffer = bloc + sizeof(struct entete) +q*sizeof(struct byteCoding);

		printf("demain tout ira mieux");
		return bloc; 

        

	
}

void ecriture(const char * nomf, t_byte * bloc){
	
	FILE * flot_s = fopen(nomf,"a"); 
	
	if (!flot_s)
	{
		perror("fopen");
        	exit(EXIT_FAILURE);
	}

	fwrite( bloc, 1 , TAILLE , flot_s);
	
	fclose(flot_s);

	
}








	
       	
	


