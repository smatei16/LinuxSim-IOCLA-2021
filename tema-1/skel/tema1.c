#include "utils.h"

int main () {

	Dir *dir = createDir(NULL, "home");
	Dir *root = dir;
	char* input = calloc(MAX_INPUT_LINE_SIZE, sizeof(char));
	char* name = calloc(MAX_INPUT_LINE_SIZE, sizeof(char));

	do
	{
		scanf("%s", input);
		
		if(!strcmp(input, "touch"))
		{
			scanf("%s", name);
			touch(dir, name);	
		}

		else if(!strcmp(input, "mkdir"))
		{
			scanf("%s", name);
			mkdir(dir, name);
		}

		else if(!strcmp(input, "ls"))
			ls(dir);

		else if(!strcmp(input, "rm"))
		{
			scanf("%s", name);
			rm(dir, name);
		}

		else if(!strcmp(input, "rmdir"))
		{
			scanf("%s", name);
			rmdir(dir, name);
		}

		else if(!strcmp(input, "cd"))
		{
			scanf("%s", name);
			cd(&dir, name);
		}

		else if(!strcmp(input, "tree"))
			tree(dir, 0);

		else if(!strcmp(input, "pwd"))
		{
			char *message = pwd(dir);
			printf("%s\n", message);
			free(message);
		}

		else if(!strcmp(input, "mv"))
		{
			scanf("%s", name);
			char* name2 = calloc(MAX_INPUT_LINE_SIZE, sizeof(char));
			scanf("%s", name2);
			mv(dir, name, name2);
			free(name2);
		}
		
		else if(!strcmp(input, "stop"))
		{
			stop(root);
			break;
		}
	
	} while (1);

	free(input);
	free(name);

	
	return 0;
}
