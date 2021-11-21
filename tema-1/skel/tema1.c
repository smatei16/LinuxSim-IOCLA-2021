#include "utils.h"

int main () {

	Dir *dir = calloc(1, sizeof(Dir));	
	char* input = calloc(MAX_INPUT_LINE_SIZE, sizeof(char));
	char* name = calloc(MAX_INPUT_LINE_SIZE, sizeof(char));

	do
	{
		/*
		Summary:
			Reads from stdin a string and breaks it down into command and in
			case it needs into a name.
		*/
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
		
		

		else if(!strcmp(input, "stop"))
			break;

	
	} while (1);

	
	return 0;
}
