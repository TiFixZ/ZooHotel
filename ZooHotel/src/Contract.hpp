#pragma once

#ifndef CONTRACT_HPP
#define CONTRACT_HPP

#include <string>
#include <iostream>
#include <memory>

#include "Pet.hpp"
#include "Owner.hpp"
#include "Room.hpp"
#include "Banch.hpp"
#include "Utilities.hpp"
#include "Employee.hpp"

namespace ZooHotel {

	class Contracts {
	public:
		Contracts() = default;
		Contracts(std::shared_ptr<Owner> owner);
		Contracts(int uid,
			std::shared_ptr<Owner> owner,
			std::shared_ptr<Pet> pet,
			std::shared_ptr<Banch> banch,
			std::shared_ptr<Room> room,
			const std::string& address,
			const DateTime::DateTime& start_time,
			const DateTime::DateTime& end_time,
			std::shared_ptr<Employee> employee);

		void SetUID(int uid);
		void SetOwner(std::shared_ptr<Owner> owner);
		void SetPet(std::shared_ptr<Pet> pet);
		void SetBanch(std::shared_ptr<Banch> banch);
		void SetRoom(std::shared_ptr<Room> room);
		void SetAddress(const std::string& address);
		void SetStartTime(const DateTime::DateTime& start_time);
		void SetEndTime(const DateTime::DateTime& end_time);
		void SetEmployee(std::shared_ptr<Employee> employee);

		int GetUID()const;
		const Owner& GetOwner()const;
		const std::shared_ptr<Owner>& GetOwnerPtr()const;
		const Pet& GetPet()const;
		const std::shared_ptr<Pet>& GetPetPtr()const;
		const Banch& GetBanch()const;
		const std::shared_ptr<Banch>& GetBanchPtr()const;
		const Room& GetRoom()const;
		const std::shared_ptr<Room>& GetRoomPtr()const;
		const std::string& GetAddress()const;
		const DateTime::DateTime& GetStartTime()const;
		const DateTime::DateTime& GetEndTime()const;
		const Employee& GetEmployee()const;
		const std::shared_ptr<Employee>& GetEmployeePtr()const;

		friend std::ostream& operator<<(std::ostream& out, const Contracts& obj);
		friend std::istream& operator>>(std::istream& in, Contracts& obj);

	private:
		int uid_ = 0;
		std::shared_ptr<Owner> owner_;
		std::shared_ptr<Pet> pet_;
		std::shared_ptr<Banch> bunch_;
		std::shared_ptr<Room> room_;
		std::string address_;
		DateTime::DateTime start_time_;
		DateTime::DateTime end_time_;
		std::shared_ptr<Employee> employee_;
	};
}

#endif
