#ifndef SAMPLE_CLASS_H
#define SAMPLE_CLASS_H

//comparaison de deux class en c++(askip en C on pouuvait faire sur des strcut)
class Sample {

public:

        Sample(int v);//initialise l'attribut foo
        ~Sample(void);

        int     getFoo(void) const;//accesseur pour avoir la valeur de foo
        int     compare(Sample *other) const;//fonction de comparaison entre l'instance courante et celle passer en parametre par son adresse

private:
        int     _foo;
    
};

#endif