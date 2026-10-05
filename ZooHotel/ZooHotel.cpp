#include <iostream>
#include <sstream>
#include "src/Banch.hpp"

int main()
{
	auto owner = std::make_shared<ZooHotel::Owner>(
		"Ivan", "Petrov", "Ivanovich", "0000000000", "00000000000", "owner@example.com", 1);
	ZooHotel::Pet pet("Barsik", owner, 1, "Cat", "British shorthair",
		ZooHotel::small, ZooHotel::DateTime::DateTime("2022-05-10 00:00:00"));
	ZooHotel::Banch banch(1, ZooHotel::small_cage, &pet);

	std::stringstream owner_stream, pet_stream, banch_stream;
	owner_stream << *owner;
	pet_stream << pet;
	banch_stream << banch;

	ZooHotel::Owner read_owner;
	ZooHotel::Pet read_pet;
	ZooHotel::Banch read_banch;
	if (!(owner_stream >> read_owner) || !(pet_stream >> read_pet) ||
		!(banch_stream >> read_banch)) {
		std::cerr << "Read error\n";
		return 1;
	}

	std::cout << read_owner << '\n' << read_pet << '\n' << read_banch << '\n';
}
