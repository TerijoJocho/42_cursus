#ifndef SAMPLE_CLASS_H
#define SAMPLE_CLASS_H

//attributs/fonctions non membre/n'appartenant pas a une instance mais à la class
//cad si on modifier un attribut non member, elle se modifie dans toutes les instances
//car elle appartient a la class
//dans cette exemple on veut savoir combien d'instances ont été réallisées
class Sample {

public:

        Sample(void);
        ~Sample(void);

       static int       getNbInst(void);//fonction non membre/de l'instance

private:
        static int     _nbInst;//attribut non membre/de l'instance
    
};

#endif