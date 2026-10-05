#pragma once

#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>
#include <iostream>

namespace ZooHotel {

	class Employee {
	public:
		enum class Role {
			admin,
			staff
		};
		Employee() = default;
		Employee(
			Role role,
			const std::string &name,
			const std::string &surename,
			const std::string &patrinomic,
			const std::string &passport,
			const std::string &phone,
			const std::string &email,
			int uid,
			const std::string &password);

		void SetRole(Role new_role);
		void SetName(const std::string& new_name);
		void SetSurename(const std::string& new_surename);
		void SetPatrinomic(const std::string& new_patrinomyc);
		void SetPassport(const std::string& new_passport);
		void SetPhone(const std::string& new_phone);
		void SetEmail(const std::string& new_email);
		void SetUID(int new_uid);
		void SetPassword(const std::string& new_password);

		Role GetRole() const;
		const std::string& GetName() const;
		const std::string& GetSurename() const;
		const std::string& GetPatrinomic() const;
		const std::string& GetPassport() const;
		const std::string& GetPhone() const;
		const std::string& GetEmail() const;
		const std::string& GetPassword() const;
		int GetUID() const;

		friend std::ostream& operator<<(std::ostream& out, const Employee& obj);
		friend std::istream& operator>>(std::istream& in, Employee& obj);

	private:
		Role role_ = Role::staff;
		std::string name_;
		std::string surename_;
		std::string patrinomic_;
		std::string passport_;
		std::string phone_;
		std::string email_;
		int uid_ = 0;
		std::string password_;
	};

}

#endif
