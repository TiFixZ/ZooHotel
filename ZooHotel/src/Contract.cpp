#include "Contract.hpp"
#include <iomanip>
#include <stdexcept>

namespace ZooHotel {

	Contracts::Contracts(std::shared_ptr<Owner> owner) :owner_(owner) {
	}

	Contracts::Contracts(int uid,
		std::shared_ptr<Owner> owner,
		std::shared_ptr<Pet> pet,
		std::shared_ptr<Banch> banch,
		std::shared_ptr<Room> room,
		const std::string& address,
		const DateTime::DateTime& start_time,
		const DateTime::DateTime& end_time,
		std::shared_ptr<Employee> employee)
		:uid_(uid), owner_(owner), pet_(pet), bunch_(banch), room_(room),
		address_(address), start_time_(start_time), end_time_(end_time), employee_(employee) {
	}

	void Contracts::SetUID(int uid) {
		uid_ = uid;
	}

	void Contracts::SetOwner(std::shared_ptr<Owner> owner) {
		owner_ = owner;
	}

	void Contracts::SetPet(std::shared_ptr<Pet> pet) {
		pet_ = pet;
	}

	void Contracts::SetBanch(std::shared_ptr<Banch> banch) {
		bunch_ = banch;
	}

	void Contracts::SetRoom(std::shared_ptr<Room> room) {
		room_ = room;
	}

	void Contracts::SetAddress(const std::string& address) {
		address_ = address;
	}

	void Contracts::SetStartTime(const DateTime::DateTime& start_time) {
		start_time_ = start_time;
	}

	void Contracts::SetEndTime(const DateTime::DateTime& end_time) {
		end_time_ = end_time;
	}

	void Contracts::SetEmployee(std::shared_ptr<Employee> employee) {
		employee_ = employee;
	}

	int Contracts::GetUID()const {
		return uid_;
	}

	const Owner& Contracts::GetOwner()const {
		if (owner_ == nullptr)throw std::runtime_error("Contract has no owner");
		return *owner_;
	}

	const std::shared_ptr<Owner>& Contracts::GetOwnerPtr()const {
		return owner_;
	}

	const Pet& Contracts::GetPet()const {
		if (pet_ == nullptr)throw std::runtime_error("Contract has no pet");
		return *pet_;
	}

	const std::shared_ptr<Pet>& Contracts::GetPetPtr()const {
		return pet_;
	}

	const Banch& Contracts::GetBanch()const {
		if (bunch_ == nullptr)throw std::runtime_error("Contract has no banch");
		return *bunch_;
	}

	const std::shared_ptr<Banch>& Contracts::GetBanchPtr()const {
		return bunch_;
	}

	const Room& Contracts::GetRoom()const {
		if (room_ == nullptr)throw std::runtime_error("Contract has no room");
		return *room_;
	}

	const std::shared_ptr<Room>& Contracts::GetRoomPtr()const {
		return room_;
	}

	const std::string& Contracts::GetAddress()const {
		return address_;
	}

	const DateTime::DateTime& Contracts::GetStartTime()const {
		return start_time_;
	}

	const DateTime::DateTime& Contracts::GetEndTime()const {
		return end_time_;
	}

	const Employee& Contracts::GetEmployee()const {
		if (employee_ == nullptr)throw std::runtime_error("Contract has no employee");
		return *employee_;
	}

	const std::shared_ptr<Employee>& Contracts::GetEmployeePtr()const {
		return employee_;
	}

	std::ostream& operator<<(std::ostream& out, const Contracts& obj) {
		out << obj.uid_ << ' ' << (obj.owner_ ? 1 : 0);
		if (obj.owner_)out << ' ' << *obj.owner_;
		out << ' ' << (obj.pet_ ? 1 : 0);
		if (obj.pet_)out << ' ' << *obj.pet_;
		out << ' ' << (obj.bunch_ ? 1 : 0);
		if (obj.bunch_)out << ' ' << *obj.bunch_;
		out << ' ' << (obj.room_ ? 1 : 0);
		if (obj.room_)out << ' ' << *obj.room_;
		out << ' ' << std::quoted(obj.address_) << ' '
			<< std::quoted(obj.start_time_.IsoTime()) << ' '
			<< std::quoted(obj.end_time_.IsoTime()) << ' ' << (obj.employee_ ? 1 : 0);
		if (obj.employee_)out << ' ' << *obj.employee_;
		return out;
	}

	std::istream& operator>>(std::istream& in, Contracts& obj) {
		Contracts temp;
		int has_owner;
		int has_pet;
		int has_banch;
		int has_room;
		int has_employee;
		std::string start_time;
		std::string end_time;
		if (!(in >> temp.uid_ >> has_owner))return in;
		if (has_owner != 0 && has_owner != 1) {
			in.setstate(std::ios::failbit);
			return in;
		}
		if (has_owner) {
			temp.owner_ = std::make_shared<Owner>();
			if (!(in >> *temp.owner_))return in;
		}
		if (!(in >> has_pet))return in;
		if (has_pet != 0 && has_pet != 1) {
			in.setstate(std::ios::failbit);
			return in;
		}
		if (has_pet) {
			temp.pet_ = std::make_shared<Pet>();
			if (!(in >> *temp.pet_))return in;
		}
		if (!(in >> has_banch))return in;
		if (has_banch != 0 && has_banch != 1) {
			in.setstate(std::ios::failbit);
			return in;
		}
		if (has_banch) {
			temp.bunch_ = std::make_shared<Banch>();
			if (!(in >> *temp.bunch_))return in;
		}
		if (!(in >> has_room))return in;
		if (has_room != 0 && has_room != 1) {
			in.setstate(std::ios::failbit);
			return in;
		}
		if (has_room) {
			temp.room_ = std::make_shared<Room>();
			if (!(in >> *temp.room_))return in;
		}
		if (!(in >> std::quoted(temp.address_) >> std::quoted(start_time)
			>> std::quoted(end_time) >> has_employee))return in;
		if (has_employee != 0 && has_employee != 1) {
			in.setstate(std::ios::failbit);
			return in;
		}
		try {
			temp.start_time_ = DateTime::DateTime(start_time);
			temp.end_time_ = DateTime::DateTime(end_time);
		}
		catch (const std::exception&) {
			in.setstate(std::ios::failbit);
			return in;
		}
		if (has_employee) {
			temp.employee_ = std::make_shared<Employee>();
			if (!(in >> *temp.employee_))return in;
		}
		obj = temp;
		return in;
	}
}
