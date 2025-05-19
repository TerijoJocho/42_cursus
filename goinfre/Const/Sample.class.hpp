#ifndef SAMPLE_CLASS_H
#define SAMPLE_CLASS_H

class Sample {
    public:

        float const pi;
        int         qd;

        Sample(float const f);//constructor
        ~Sample(void);//destructor

        //fonction membre ne modifiera jamais l'instance courante de la class
        //toujours declarer en const une fonction 
        //qui ne modifie pas l'instance de la classe, cad this->
        void    bar(void)const;
};

#endif