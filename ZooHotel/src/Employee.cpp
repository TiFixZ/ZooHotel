#include "Employee.hpp"
#include <iomanip>
#include <stdexcept>

namespace ZooHotel {

	Employee::Employee(
		Role role,
		const std::string &name,
		const std::string &surename,
		const std::string &patrinomic,
		const std::string &passport,
		const std::string &phone,
		const std::string &email,
		int uid,
		const std::string &password)
		:name_(name), surename_(surename), patrinomic_(patrinomic),
		passport_(passport), phone_(phone), email_(email), uid_(uid), password_(password)
	{
		SetRole(role);
	}

	void Employee::SetRole(Role new_role) {
		if (new_role != Role::admin && new_role != Role::staff) {
			throw std::invalid_argument("Invalid employee role");
		}
		role_ = new_role;
	}

	void Employee::SetName(const std::string& new_name) {
		name_ = new_name;
	}

	void Employee::SetSurename(const std::string& new_surename) {
		surename_ = new_surename;
	}

	void Employee::SetPatrinomic(const std::string& new_patrinomyc) {
		patrinomic_ = new_patrinomyc;
	}

	void Employee::SetPassport(const std::string& new_passport) {
		passport_ = new_passport;
	}

	void Employee::SetPhone(const std::string& new_phone) {
		phone_ = new_phone;
	}

	void Employee::SetEmail(const std::string& new_email) {
		email_ = new_email;
	}

	void Employee::SetUID(int new_uid) {
		uid_ = new_uid;
	}

	void Employee::SetPassword(const std::string& new_password) {
		password_ = new_password;
	}

	Employee::Role Employee::GetRole() const {
		return role_;
	}

	const std::string& Employee::GetName() const {
		return name_;
	}

	const std::string& Employee::GetSurename() const {
		return surename_;
	}

	const std::string& Employee::GetPatrinomic() const {
		return patrinomic_;
	}

	const std::string& Employee::GetPassport() const {
		return passport_;
	}

	const std::string& Employee::GetPhone() const {
		return phone_;
	}

	const std::string& Employee::GetEmail() const {
		return email_;
	}

	const std::string& Employee::GetPassword() const {
		return password_;
	}

	int Employee::GetUID() const {
		return uid_;
	}

	std::ostream& operator<<(std::ostream& out, const Employee& obj) {
		out << static_cast<int>(obj.role_) << ' '
			<< std::quoted(obj.name_) << ' '
			<< std::quoted(obj.surename_) << ' '
			<< std::quoted(obj.patrinomic_) << ' '
			<< std::quoted(obj.passport_) << ' '
			<< std::quoted(obj.phone_) << ' '
			<< std::quoted(obj.email_) << ' '
			<< obj.uid_ << ' '
			<< std::quoted(obj.password_);
		return out;
	}

	std::istream& operator>>(std::istream& in, Employee& obj) {
		Employee temp;
		int role = 0;
		if (in >> role
			>> std::quoted(temp.name_)
			>> std::quoted(temp.surename_)
			>> std::quoted(temp.patrinomic_)
			>> std::quoted(temp.passport_)
			>> std::quoted(temp.phone_)
			>> std::quoted(temp.email_)
			>> temp.uid_
			>> std::quoted(temp.password_)) {
			if (role != static_cast<int>(Employee::Role::admin)
				&& role != static_cast<int>(Employee::Role::staff)) {
				in.setstate(std::ios::failbit);
			}
			else {
				temp.role_ = static_cast<Employee::Role>(role);
				obj = temp;
			}
		}
		return in;
	}

}
