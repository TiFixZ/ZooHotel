#pragma once

#ifndef OWNER_HPP
#define OWNER_HPP

#include <string>
#include <iostream>

namespace ZooHotel {

	class Owner {
	public:
		Owner() = default;
		Owner(
			std::string name,
			std::string surename,
			std::string patrinomic,
			std::string passport,
			std::string phone,
			std::string email,
			int uid	);

		Owner(
			std::string name,
			std::string surename,
			std::string passport,
			std::string phone,
			std::string email,
			int uid);

		void SetName(const std::string& name);
		void SetSurename(const std::string& surename);
		void SetPatrinomic(const std::string& patrinomic);
		void SetPassport(const std::string& passport);
		void SetPhone(const std::string& phone);
		void SetEmail(const std::string& email);
		void SetUID(int uid);

		const std::string& GetName()const;
		const std::string& GetSurename()const;
		const std::string& GetPatrinomic()const;
		const std::string& GetPassport()const;
		const std::string& GetPhone()const;
		const std::string& GetEmail()const;
		int GetUID()const;

		friend std::ostream& operator<<(
			std::ostream& out,
			const Owner& obj);
		friend std::istream& operator>>(
			std::istream& in,
			Owner& obj);

	private:
		std::string name_;
		std::string surename_;
		std::string patrinomic_;
		std::string passport_;
		std::string phone_;
		std::string email_;
		int uid_ = 0;

	};
}
#endif
