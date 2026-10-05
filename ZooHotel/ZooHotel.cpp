#include <iostream>
#include <sstream>
#include "src/Banch.hpp"
#include "src/Contract.hpp"

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

	auto employee = std::make_shared<ZooHotel::Employee>(
		ZooHotel::Employee::Role::staff, "Petr", "Ivanov", "Petrovich",
		"1111111111", "11111111111", "employee@example.com", 2, "pass");
	auto room = std::make_shared<ZooHotel::Room>(1, "Lenina 10", "Room for cats");
	room->SetPlaceCapacity(1);
	room->at(0).SetHolder(&pet);
	ZooHotel::Contracts contract(1, owner, std::make_shared<ZooHotel::Pet>(pet),
		std::make_shared<ZooHotel::Banch>(banch), room, "Lenina 10",
		ZooHotel::DateTime::DateTime("2026-04-13 10:00:00"),
		ZooHotel::DateTime::DateTime("2026-04-16 10:00:00"), employee);

	std::stringstream employee_stream, contract_stream;
	employee_stream << *employee;
	contract_stream << contract;
	ZooHotel::Employee read_employee;
	ZooHotel::Contracts read_contract;
	if (!(employee_stream >> read_employee) || !(contract_stream >> read_contract)) {
		std::cerr << "Read error\n";
		return 1;
	}
	std::cout << read_employee << '\n' << read_contract << '\n';
}
