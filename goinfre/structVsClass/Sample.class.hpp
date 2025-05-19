#ifndef SAMPLE_CLASS_H
#define SAMPLE_CLASS_H

class Sample1 {

        int publicFoo;

        Sample1(void);
        ~Sample1(void);

        void    bar(void)const;
    
};

struct Sample2 {

        int publicFoo;

        Sample2(void);
        ~Sample2(void);

        void    bar(void)const;
    
};

#endif