#pragma once

#include <typeinfo>
#include <iostream>

// Works for strings, vectors, deques 
template<typename T, typename X>
inline bool exists_in(T group, X member)
{
	try {
		if (typeid(group[0]).name() == typeid(member).name())
		{
			for(X i : group)
				if (member == i)
					return true;
		}
		else
		{
			std::cout << "The Groups member type: ";
			std::cout << typeid(group[0]).name();
			std::cout << " is different from the member type passed in: ";
			std::cout << typeid(member).name() << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return false;
}