#include <fstream>
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "error: wrong number of arguments" << std::endl;
		return (1);
	}
	else
	{
		std::string filename(argv[1]), s1(argv[2]), s2(argv[3]);
		std::string replace = filename + ".replace";
		// flux d'entrer
		std::ifstream ifs;
		// flux de sortie
		std::ofstream ofs;
		//ouvre les fichiers
		ifs.open(filename.c_str(), std::ifstream::in);
		ofs.open(replace.c_str(), std::ofstream::out);
		// verif si les fichiers sont ouvert
		if (!ifs.is_open() || !ofs.is_open())
		{
			std::cerr << "error: cannot open input or output file" << std::endl;
			return (1);
		}

		std::string line;
		size_t	pos;
		while (getline(ifs, line))
		{
			pos = 0;
			// lorsqu'on trouve s1 à pos/lorsque la position de s1 matches dans line(?)
			while ((pos = line.find(s1, pos)) != std::string::npos)
			{
				// on efface ce qu'il y a dans line, à pos, d'une taille de s1
				line.erase(pos, s1.length());
				// on insert dans line, à pos, s2
				line.insert(pos, s2);
				// on fait avancer pos pour ne pas avoir de boucle infini
				pos += s2.length();
			}
			// on ecrit la line dans le flus de sortie
			ofs << line << std::endl;
		}
		ifs.close();
		ofs.close();
	}
	return (0);
}
