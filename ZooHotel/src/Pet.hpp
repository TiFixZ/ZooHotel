#pragma once

#ifndef PET_HPP
#define PET_HPP

#include <string>
#include <memory>
#include "./Utilities.hpp"

#include "Owner.hpp"

namespace ZooHotel {

	enum Size {
		gigant,
		big,
		medium,
		small,
		tyny
	};
	class Pet {
	public:
		Pet() = default;
		Pet(std::string name,
			std::shared_ptr<Owner> owner,
			int uid,
			std::string species,
			std::string bride,
			Size size,
			DateTime::DateTime birthday);

		const std::string& GetName()const;
		const Owner& GetOwner()const;
		const std::shared_ptr<Owner>& GetOwnerPtr()const;
		int GetUID()const;
		const std::string& GetSpecies()const;
		const std::string& GetBride()const;
		Size GetSize()const;
		const DateTime::DateTime& GetBirthday()const;

		void SetName(const std::string& name);
		void SetOwner(std::shared_ptr<Owner> owner);
		void SetUID(int uid);
		void SetSpecies(const std::string& species);
		void SetBride(const std::string& bride);
		void SetSize(Size size);
		void SetBirthday(const DateTime::DateTime& birthday);

		friend std::ostream& operator<<(std::ostream& out, const Pet& obj);
		friend std::istream& operator>>(std::istream& in, Pet& obj);

	private:
		std::string name_;
		std::shared_ptr<Owner> owner_;
		int uid_ = 0;
		std::string species_;
		std::string bride_;
		Size size_ = small;
		DateTime::DateTime birthday_;
	};

}

#endif
