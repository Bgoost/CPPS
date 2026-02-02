#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer& other) {*this = other;}
Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t	num = reinterpret_cast<uintptr_t>(ptr);
    // num = (num & ~0xFFULL) | 0xAB;

	return (num);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	// try {
	// 	if ((raw & 0xFF) != 0xAB) {
	// 		throw std::runtime_error("Error: Corrupted data detected during deserialization.");
	// 	}
	// 	uintptr_t clean = raw & ~0xFFULL;
		Data *data = reinterpret_cast<Data*>(raw);
		return (data);

	// } catch (const std::exception& e) {
	// 	std::cerr << e.what() << std::endl;
	// 	return (0);
	// }
    
}

Serializer&	Serializer::operator=(const Serializer& var)
{
	if (this != &var)
		return (*this);
	return (*this);
}