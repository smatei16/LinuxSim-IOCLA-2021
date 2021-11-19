#ifndef utils
#define utils

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_INPUT_LINE_SIZE 300

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

struct Dir;
struct File;

typedef struct Dir{
	char *name;
	struct Dir* parent;
	struct File* head_children_files;
	struct Dir* head_children_dirs;
	struct Dir* next;
} Dir;

typedef struct File {
	char *name;
	struct Dir* parent;
	struct File* next;
} File;


void touch (Dir* parent, char* name);

void mkdir (Dir* parent, char* name);

void ls (Dir* parent);

void rm (Dir* parent, char* name);

void rmdir (Dir* parent, char* name);

void cd(Dir** target, char *name);

char *pwd (Dir* target);

void stop (Dir* target);

void tree (Dir* target, int level);

void mv(Dir* parent, char *oldname, char *newname);


#endif