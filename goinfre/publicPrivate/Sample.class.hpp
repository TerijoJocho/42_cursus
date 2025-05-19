#ifndef SAMPLE_CLASS_H
#define SAMPLE_CLASS_H

class Sample {
//tout ce que l'utilisateur peut acceder(?)
    public:

        int publicFoo;

        Sample(void);
        ~Sample(void);

        void    publicBar(void)const;
    
//tout ce qui est utile a la class maiis qui ne regarde pas l'utilisateur
    private:

        int _privateFoo;

        void    _privateBar(void)const;
};

#endif