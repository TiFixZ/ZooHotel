#include "Banch.hpp"

namespace ZooHotel {

	Banch::Banch()
		:id_(0),
		type_(Types::small_cage),
		holder_(nullptr)
	{}

	Banch::Banch(int id, Types type, Pet* holder)
		:id_(id),
		type_(Types::small_cage),
		holder_(nullptr)
	{
		SetType(type);
		SetHolder(holder);
	}

	void Banch::SetId(int id)
	{
		id_ = id;
	}

	void Banch::SetType(Types type)
	{
		if (type < small_cage || type > large_room) {
			throw std::invalid_argument("Invalid place type");
		}
		Types old_type = type_;
		type_ = type;
		if (holder_ && !IsSuitedFor(holder_)) {
			type_ = old_type;
			throw std::runtime_error("Animal didn't match");
		}
	}

	void Banch::SetHolder(Pet* holder)
	{
		if (holder && !IsSuitedFor(holder)) {
			throw std::runtime_error("Animal didn't match");
		}
		if (holder != owned_holder_.get()) owned_holder_.reset();
		holder_ = holder;
	}

	int Banch::GetId()const
	{
		return id_;
	}

	Types Banch::GetType()const
	{
		return type_;
	}

	const Pet* Banch::GetPet()const
	{
		return holder_;
	}

	bool Banch::IsEmpty()const
	{
		return !holder_;
	}

	bool Banch::IsSuitedFor(const Pet* pet)const
	{
		if (!pet) return false;
		switch (type_) {
		case small_cage: return pet->GetSize() >= small;
		case large_cage: return pet->GetSize() >= medium;
		case small_room: return pet->GetSize() >= big;
		case large_room: return true;
		}
		return false;
	}

	std::ostream& operator<<(std::ostream& out, const Banch& obj)
	{
		out << obj.id_ << ' ' << static_cast<int>(obj.type_) << ' ' <<
			(obj.holder_ ? 1 : 0);
		if (obj.holder_) out << ' ' << *obj.holder_;
		return out;
	}

	std::istream& operator>>(std::istream& in, Banch& obj)
	{
		int id, type, has_holder;
		if (!(in >> id >> type >> has_holder)) return in;
		if (type < small_cage || type > large_room ||
			(has_holder != 0 && has_holder != 1)) {
			in.setstate(std::ios::failbit);
			return in;
		}

		Banch temp(id, static_cast<Types>(type));
		if (has_holder) {
			auto pet = std::make_shared<Pet>();
			if (!(in >> *pet)) return in;
			if (!temp.IsSuitedFor(pet.get())) {
				in.setstate(std::ios::failbit);
				return in;
			}
			temp.owned_holder_ = pet;
			temp.holder_ = pet.get();
		}
		obj = temp;
		return in;
	}
}
