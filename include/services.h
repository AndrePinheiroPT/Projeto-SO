#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <glib.h>
#include "defs.h"

typedef struct index{
	char title[200];
	char authors[200];
	char path[64];
	int year;
} Index;

#define SAVE_FILE "../saves"// Save file to save meta information presented on the tree
#define PNUM 20
void print_debug(const char *msg);

void print_client(const char *msg, int fdout);

gint compare_str(gconstpointer a, gconstpointer b, gpointer user_data);

gint print_index(gpointer key, gpointer value, gpointer data);

gint print_index_debug(gpointer key, gpointer value, gpointer data);

void print_index_queue(gpointer data, gpointer user_data);

int indexDocument(GTree *tree, Index *in, int fdout, int maxNodes, GQueue *insertionOrder, int numNodes);

int checkKey(GTree *tree, char index[], int fdout);

int deleteKey(GTree *tree, char index[], int fdout, int fdsave, GQueue *insertionOrder, int numNodes);

int searchKeywordByKey(GTree *tree, char index[], char word[],int fdout);

int searchKeyword(char word[], int numProc,int fdout);

int saveMetaInfo(GTree *tree,int fdout);

int buildMetaInfo(GTree *tree, int fd, int maxNodes, GQueue *insertionOrder);

gint findWord(gpointer key, gpointer value, gpointer data);

gint saveMetaInfoNode(gpointer key, gpointer value, gpointer data);