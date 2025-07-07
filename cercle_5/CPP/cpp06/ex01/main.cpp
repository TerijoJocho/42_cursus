#include "Serializer.hpp"
#include "Data.hpp"

int	main(void)
{
	Data*	ptr = new Data;

	ptr->x = 0;
	ptr->y = 1;
	std::cout << "Pointer address: " << ptr << std::endl;

	uintptr_t address = Serializer::serialize(ptr);
	std::cout << "Pointer address serialized: " << address << std::endl;

	std::cout << "Pointer address deserialized: " << Serializer::deserialize(address) << std::endl;

	delete ptr;
	return (0);
}
