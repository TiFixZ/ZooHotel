#pragma once

#ifndef BANCH_HPP
#define BANCH_HPP

#include "Pet.hpp"
#include "Utilities.hpp"

namespace ZooHotel {

	class Banch {
	public:
		Banch();
		Banch(int id, Types type, Pet* holder = nullptr);
		Banch(const Banch&) = default;
		Banch& operator=(const Banch&) = default;

		void SetId(int id);
		void SetType(Types type);
		void SetHolder(Pet* holder);

		int GetId()const;
		Types GetType()const;
		const Pet* GetPet()const;

		bool IsEmpty()const;
		bool IsSuitedFor(const Pet* pet)const;

		friend std::ostream& operator<<(std::ostream& out, const Banch& obj);
		friend std::istream& operator>>(std::istream& in, Banch& obj);

	private:
		int id_;
		Types type_;
		Pet* holder_;
		std::shared_ptr<Pet> owned_holder_;
	};
}

#endif
