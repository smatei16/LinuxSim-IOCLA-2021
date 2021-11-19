#include "utils.h"

//creeaza un fisier nou
File* createFile(Dir* parent, char* name)
{
    File* newFile = calloc(1, sizeof(File));
    newFile->name = calloc(MAX_INPUT_LINE_SIZE, sizeof(char));
    strcpy(newFile->name, name);
    newFile->next = NULL;
    newFile->parent = parent;

    return newFile;
}

//creeaza un director nou
Dir* createDir(Dir* parent, char* name)
{
    Dir* newDir = calloc(1, sizeof(Dir));
    newDir->head_children_dirs = NULL;
    newDir->head_children_files = NULL;
    newDir->name = calloc(MAX_INPUT_LINE_SIZE, sizeof(char));
    strcpy(newDir->name, name);
    newDir->next = NULL;
    newDir->parent = parent;

    return newDir;
}

//verifica daca un anumit fisier exista intr-un director
int checkFile(Dir* parent, char* name)
{
    File* aux = parent->head_children_files;
    while(aux != NULL)
    {
        if(strcmp(aux->name, name) == 0)
            return 1;
        aux = aux->next;
    }
    return 0;
}

//verifica daca exista un anumit director intr-un director
int checkDir(Dir* parent, char* name)
{
    Dir* aux = parent->head_children_dirs;
    while(aux != NULL)
    {
        if(strcmp(aux->name, name) == 0)
            return 1;
        aux = aux->next;
    }
    return 0;
}

//implementeaza comanda touch
void touch (Dir* parent, char* name)
{   
    if(parent == NULL) exit(1);

    //verific daca exista deja un fisier/director cu acest nume
    if(checkFile(parent, name) || checkDir(parent, name))
        printf("File already exists\n");

    //daca fisierul nu exista, il creez
    else
    {
        File* newFile = createFile(parent, name);

        //daca folderul este gol atunci va fi primul fisier din lista
        if(parent->head_children_files == NULL)
            parent->head_children_files = newFile;
    
        //daca folderul nu este gol, parcurg lista pana la ultimul fisier si il adaug la coada
        else
        {
        File* aux = parent->head_children_files;
        while(aux->next != NULL)
            aux = aux->next;
        aux->next = newFile;
        }
    }
}

//implementeaza comanda mkdir
void mkdir (Dir* parent, char* name)
{
    if(parent == NULL) exit(1);

    //verific daca exista deja un fisier/director cu acest nume
    if(checkFile(parent, name) || checkDir(parent, name))
        printf("Directory already exists\n");

    //daca directorul nu exista, il creez
    else
    {
        Dir* newDir = createDir(parent, name);

        //daca folderul este gol atunci va fi primul director din lista
        if(parent->head_children_dirs == NULL)
            parent->head_children_dirs = newDir;
        
        //daca folderul nu este gol, parcurg lista pana la ultimul director si il adaug la coada
        else
        {
            Dir* aux = parent->head_children_dirs;
            while(aux->next != NULL)
                aux = aux->next;
            aux->next = newDir;
        }
    }
}

//implementeaza comanda ls
void ls (Dir* parent)
{
    if(parent == 1) exit(1);

    //afisez numele directoarelor
    Dir* auxDir = parent->head_children_dirs;
    while(auxDir != NULL)
    {
        printf("%s\n", auxDir->name);
        auxDir = auxDir->next;
    }

    //afisez numele fisierelor
    File* auxFile = parent->head_children_files;
    while(auxFile != NULL)
    {
        printf("%s\n", auxFile->name);
        auxFile = auxFile->next;
    }
}