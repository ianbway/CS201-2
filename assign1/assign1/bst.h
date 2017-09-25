// Ian Braudaway
// Header file for BST class
#ifndef __BST_INCLUDED__
#define __BST_INCLUDED__

#include <stdio.h>

typedef struct BSTNODE BSTNODE;
typedef struct BST BST;

extern BST *newBST(void(*display)(FILE *, void *, void *), int(*comparator)(void *, void *));
extern void insertBST(BST *tree, void *key, void *value);
extern void *findBST(BST *tree, void *key);
extern int sizeBST(BST *tree);
extern void displayBST(FILE *fp, BST *tree);

#endif
