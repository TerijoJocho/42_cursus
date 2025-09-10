#include "myVect2.hpp"

//clear && c++ main.cpp myVect2.cpp myVect2.hpp && valgrind --leak-check=full --show-leak-kinds=all ./a.out
int	main(void)
{
	myVect2		v1;
	myVect2		v2(1, 2);
	const myVect2	v3(v2);
	myVect2		v4 = v2;

    std::cout << "v1 = " << v1 << std::endl;
	std::cout << "v2 = " << v2 << std::endl;
	std::cout << "v4++ = " << v4++ << std::endl;
	std::cout << "++v4 = " << ++v4 << std::endl;
	std::cout << "v4-- = " << v4-- << std::endl;
	std::cout << "--v4 = " << --v4 << std::endl;

    std::cout << std::endl;

	std::cout << "v1 == v1 -> " << (v1 == v1) << std::endl;
	std::cout << "v1" << v1 << " != " << "v2" << v2 << " -> " << (v1 != v2) << std::endl;
	std::cout << "v1 != v1 -> " << (v1 != v1) << std::endl;

    std::cout << std::endl;

    std::cout << "v2" << v2 << ", v3" << v3 << std::endl;
	v2 += v3;
	std::cout << "v2 += v3 -> " << "v2" << v2 << std::endl;

    std::cout << std::endl;

    std::cout << "v1" << v1 << ", v2" << v2 << std::endl;
	(v1 -= v2);
	std::cout << "v1 -= v2 -> " << "v1" << v1 << std::endl;

    std::cout << std::endl;

    std::cout << "v2" << v2 << ", v3" << v3 << std::endl;
	v2 = v3 + v3;
	std::cout << "v2 = v3 + v3 -> " << "v2" << v2 << std::endl;

    std::cout << std::endl;

    std::cout << "v2" << v2 << std::endl;
	v2 = 3 * v2;
	std::cout << "v2 = 3 * v2 -> " << "v2" << v2 << std::endl;

    std::cout << std::endl;

    std::cout << "v2" << v2 << ", v3" << v3 << std::endl;
	v2 += v2 += v3;
	std::cout << "v2 += v2 += v3 -> " << "v2" << v2 << std::endl;

    std::cout << std::endl;

	std::cout << "v1" << v1 << " == " << "v3" << v3 << " -> " << (v1 == v3) << std::endl;
	std::cout << "v1" << v1 << " == " << "v1" << v1 << " -> " << (v1 == v1) << std::endl;
	std::cout << "v1" << v1 << " != " << "v3" << v3 << " -> " << (v1 != v3) << std::endl;
}
