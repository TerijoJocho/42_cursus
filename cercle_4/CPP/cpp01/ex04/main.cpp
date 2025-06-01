/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:03:41 by terijo            #+#    #+#             */
/*   Updated: 2025/06/01 18:22:14 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "error: wrong number of arguments" << std::endl;
        return (1);    
    }
    else
    {
        std::string     filename = argv[1], s1(argv[2]), s2(argv[3]);
        //flux d'entrer
        std::ifstream   ifs(filename);
        //flux de sortie
        std::ofstream   ofs(filename + ".replace");
        //verif si les fichiers sont ouvert
        if (!ifs.is_open() || !ofs.is_open())
        {
            std::cerr << "error: cannot open input or output file" << std::endl;  
            return (1);
        }
        std::string     line;
        while (getline(ifs, line))
        {
            size_t  pos = 0;
            //lorsqu'on trouve s1 à pos/lorsque la position de s1 matches dans line(?)
            while ((pos = line.find(s1, pos)) != std::string::npos)
            {
                //on efface ce qu'il y a dans line, à pos, d'une taille de s1
                line.erase(pos, s1.length());
                //on insert dans line, à pos, s2
                line.insert(pos, s2);
                //on fait avancer pos pour ne pas avoir de boucle infini
                pos += s2.length();
            }
            //on ecrit la line dans le flus de sortie
            ofs << line << std::endl;
        }
    } 
    return (0);
}