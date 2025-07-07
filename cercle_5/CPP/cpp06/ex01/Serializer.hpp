#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# pragma once
#include "Data.hpp"
#include <stdint.h>
#include <iostream>

class Serializer
{
  public:
	~Serializer();

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

  private:
	Serializer();
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &other);
};

#endif

//uintptr_t type entier non signe, assez grand peut contenir un pointeur
// cad peut avoir l'adresse memoire d'un pointeur sans perte d'info
//no n'utilise pas unsigned long ou size_t car ils ne contiennent pas forcement une adresse
// sur certaine machine un pointeur peut etre plus grand ou petit que ces types
