/* ---------------------------------------------------------------
   Log Mollo: compresseur de journaux en ligne
   Gestion des codes de huffman
   S. Rubini, UBO
   ---------------------------------------------------------------
*/
#include "list.h"
#include <stdio.h>
#include "tree_etu.h"
#include <stdlib.h>

#ifndef _BLOC_H
#define _BLOC_H
#define TAILLE 32*1024



struct entete {
int nbBits ; 
int nb_Codage; 
int nbMaxBits; 
int taille_bloc; 

};
struct descripteur_bloc {
	struct entete * entete;

	t_byte * buffer;

	struct tree_node * node ; 

       	struct byteCoding * tcd ;
}; 


t_byte * construction_bloc (struct byteCoding index[256]); 
void ecriture(const char * nomf , t_byte * bloc);



#endif
