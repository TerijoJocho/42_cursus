#ifndef SAMPLE_CLASS_H
#define SAMPLE_CLASS_H

//donner un certain acces a ma variable privée à l'utilisateur
class Sample {

public:

        Sample(void);
        ~Sample(void);

        int     getFoo(void) const;//ne va pas modifier l'instance courante de la classe car va acceder que en lecture
        bool    setFoo(int v);

private:
        int     _foo;
    
};

#endif