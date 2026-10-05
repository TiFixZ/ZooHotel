#include "Pet.hpp"
#include <iomanip>
#include <stdexcept>

namespace ZooHotel {

	Pet::Pet(std::string name,
		std::shared_ptr<Owner> owner,
		int uid,
		std::string species,
		std::string bride,
		Size size,
		DateTime::DateTime birthday)
		: name_(name), owner_(owner), uid_(uid), species_(species),
		bride_(bride), size_(size), birthday_(birthday) {
	}

	const std::string& Pet::GetName()const {
		return name_;
	}

	const Owner& Pet::GetOwner()const {
		if (owner_ == nullptr)throw std::runtime_error("Pet has no owner");
		return *owner_;
	}

	const std::shared_ptr<Owner>& Pet::GetOwnerPtr()const {
		return owner_;
	}

	int Pet::GetUID()const {
		return uid_;
	}

	const std::string& Pet::GetSpecies()const {
		return species_;
	}

	const std::string& Pet::GetBride()const {
		return bride_;
	}

	Size Pet::GetSize()const {
		return size_;
	}

	const DateTime::DateTime& Pet::GetBirthday()const {
		return birthday_;
	}

	void Pet::SetName(const std::string& name) {
		name_ = name;
	}

	void Pet::SetOwner(std::shared_ptr<Owner> owner) {
		owner_ = owner;
	}

	void Pet::SetUID(int uid) {
		uid_ = uid;
	}

	void Pet::SetSpecies(const std::string& species) {
		species_ = species;
	}

	void Pet::SetBride(const std::string& bride) {
		bride_ = bride;
	}

	void Pet::SetSize(Size size) {
		size_ = size;
	}

	void Pet::SetBirthday(const DateTime::DateTime& birthday) {
		birthday_ = birthday;
	}

	std::ostream& operator<<(std::ostream& out, const Pet& obj) {
		out << std::quoted(obj.name_) << ' ' << obj.uid_ << ' '
			<< std::quoted(obj.species_) << ' ' << std::quoted(obj.bride_) << ' '
			<< static_cast<int>(obj.size_) << ' '
			<< std::quoted(obj.birthday_.IsoTime()) << ' ' << (obj.owner_ ? 1 : 0);
		if (obj.owner_)out << ' ' << *obj.owner_;
		return out;
	}

	std::istream& operator>>(std::istream& in, Pet& obj) {
		Pet temp;
		int size;
		int has_owner;
		std::string birthday;
		if (!(in >> std::quoted(temp.name_) >> temp.uid_
			>> std::quoted(temp.species_) >> std::quoted(temp.bride_)
			>> size >> std::quoted(birthday) >> has_owner))return in;
		if (size < gigant || size > tyny || (has_owner != 0 && has_owner != 1)) {
			in.setstate(std::ios::failbit);
			return in;
		}
		try {
			temp.birthday_ = DateTime::DateTime(birthday);
		}
		catch (const std::exception&) {
			in.setstate(std::ios::failbit);
			return in;
		}
		temp.size_ = static_cast<Size>(size);
		if (has_owner) {
			temp.owner_ = std::make_shared<Owner>();
			if (!(in >> *temp.owner_))return in;
		}
		obj = temp;
		return in;
	}

}
