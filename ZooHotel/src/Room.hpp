#pragma once

#ifndef ROOM_HPP
#define ROOM_HPP

#include <vector>
#include <string>
#include "Banch.hpp"

namespace ZooHotel {

	class Room {
	public:
		Room() = default;
		Room(int id, const std::string& address, const std::string& description);

		void SetId(int id);
		void SetAddress(const std::string& address);
		void SetDescription(const std::string& description);
		int GetId()const;
		const std::string& GetAddress()const;
		const std::string& GetDescription()const;

		void SetPlaceCapacity(int n);
		void SetPlaceType(int place_num, Types new_type);
		void RemovePlace(int place_num);
		void AddNewPlace(Types new_type);

		int EmptyPlaces()const;
		int FilledPlaces()const;
		int AllPlaces()const;
		const Pet* WhoAt(int place_num)const;
		const Banch& at(int place_num)const;
		Banch& at(int place_num);

		friend std::ostream& operator<<(std::ostream& out, const Room& obj);
		friend std::istream& operator>>(std::istream& in, Room& obj);

	private:
		void NormalizeBanchID();
		int id_ = 0;
		std::string address_;
		std::string description_;
		std::vector<Banch> places_;
	};
}

#endif
