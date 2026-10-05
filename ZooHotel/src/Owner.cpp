#include "Owner.hpp"
#include <iomanip>

namespace ZooHotel {

	Owner::Owner(
		std::string name,
		std::string surename,
		std::string patrinomic,
		std::string passport,
		std::string phone,
		std::string email,
		int uid)
		:name_(name),
		surename_(surename),
		patrinomic_(patrinomic),
		passport_(passport),
		phone_(phone),
		email_(email),
		uid_(uid)
	{}

	Owner::Owner(
		std::string name,
		std::string surename,
		std::string passport,
		std::string phone,
		std::string email,
		int uid)
		:name_(name),
		surename_(surename),
		passport_(passport),
		phone_(phone),
		email_(email),
		uid_(uid)
	{}

	void Owner::SetName(const std::string& name)
	{
		name_ = name;
	}

	void Owner::SetSurename(const std::string& surename)
	{
		surename_ = surename;
	}

	void Owner::SetPatrinomic(const std::string& patrinomic)
	{
		patrinomic_ = patrinomic;
	}

	void Owner::SetPassport(const std::string& passport)
	{
		passport_ = passport;
	}

	void Owner::SetPhone(const std::string& phone)
	{
		phone_ = phone;
	}

	void Owner::SetEmail(const std::string& email)
	{
		email_ = email;
	}

	void Owner::SetUID(int uid)
	{
		uid_ = uid;
	}

	const std::string& Owner::GetName()const
	{
		return name_;
	}

	const std::string& Owner::GetSurename()const
	{
		return surename_;
	}

	const std::string& Owner::GetPatrinomic()const
	{
		return patrinomic_;
	}

	const std::string& Owner::GetPassport()const
	{
		return passport_;
	}

	const std::string& Owner::GetPhone()const
	{
		return phone_;
	}

	const std::string& Owner::GetEmail()const
	{
		return email_;
	}

	int Owner::GetUID()const
	{
		return uid_;
	}

	static bool ReadOwnerChar(std::istream& in, char expected)
	{
		char tmp;
		if (!(in >> tmp) || tmp != expected) {
			in.setstate(std::ios::failbit);
			return false;
		}
		return true;
	}

	static bool ReadOwnerString(std::istream& in, std::string& value)
	{
		in >> std::ws;
		if (in.peek() != '"') {
			in.setstate(std::ios::failbit);
			return false;
		}
		return bool(in >> std::quoted(value));
	}

	static bool ReadOwnerKey(std::istream& in, const char* key)
	{
		std::string buffer;
		if (!ReadOwnerString(in, buffer) || buffer != key) {
			in.setstate(std::ios::failbit);
			return false;
		}
		return ReadOwnerChar(in, ':');
	}

	std::ostream& operator<<(std::ostream& out, const Owner& obj)
	{
		out << "{\"name\": " << std::quoted(obj.name_) <<
			", \"surename\": " << std::quoted(obj.surename_) <<
			", \"patrinomic\": " << std::quoted(obj.patrinomic_) <<
			", \"passport\": " << std::quoted(obj.passport_) <<
			", \"phone\": " << std::quoted(obj.phone_) <<
			", \"email\": " << std::quoted(obj.email_) <<
			", \"uid\": " << obj.uid_ << " }";
		return out;
	}

	std::istream& operator>>(std::istream& in, Owner& obj)
	{
		Owner tmp;
		if (ReadOwnerChar(in, '{') &&
			ReadOwnerKey(in, "name") && ReadOwnerString(in, tmp.name_) &&
			ReadOwnerChar(in, ',') &&
			ReadOwnerKey(in, "surename") && ReadOwnerString(in, tmp.surename_) &&
			ReadOwnerChar(in, ',') &&
			ReadOwnerKey(in, "patrinomic") && ReadOwnerString(in, tmp.patrinomic_) &&
			ReadOwnerChar(in, ',') &&
			ReadOwnerKey(in, "passport") && ReadOwnerString(in, tmp.passport_) &&
			ReadOwnerChar(in, ',') &&
			ReadOwnerKey(in, "phone") && ReadOwnerString(in, tmp.phone_) &&
			ReadOwnerChar(in, ',') &&
			ReadOwnerKey(in, "email") && ReadOwnerString(in, tmp.email_) &&
			ReadOwnerChar(in, ',') &&
			ReadOwnerKey(in, "uid") && (in >> tmp.uid_) &&
			ReadOwnerChar(in, '}')) {
			obj = tmp;
		}
		return in;
	}

}
