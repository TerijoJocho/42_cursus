#include "bsq.h"

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		if (exec_bsq(stdin) == -1)
		{
			fprintf(stderr, "Error: invalid map\n");
			return (-1);
		}
	}
	else if (argc == 2)
	{
		if (convert_file(argv[1]) == -1)
		{
			fprintf(stderr, "Error: invalid map\n");
			return (-1);
		}
	}
	else
		return (-1);
	return (0);
}
