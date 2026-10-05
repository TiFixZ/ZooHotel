#include "Room.hpp"
#include <iomanip>
#include <utility>

namespace ZooHotel {

	Room::Room(int id, const std::string& address, const std::string& description)
		:id_(id), address_(address), description_(description)
	{}

	void Room::SetId(int id) { id_ = id; }
	void Room::SetAddress(const std::string& address) { address_ = address; }
	void Room::SetDescription(const std::string& description) { description_ = description; }
	int Room::GetId()const { return id_; }
	const std::string& Room::GetAddress()const { return address_; }
	const std::string& Room::GetDescription()const { return description_; }

	void Room::SetPlaceCapacity(int n)
	{
		if (n < 0) throw std::invalid_argument("Invalid capacity");
		if (n < FilledPlaces()) throw std::runtime_error("Trying to destroy filled place");
		if (n < AllPlaces()) {
			for (size_t i = 0; i < places_.size(); ++i) {
				if (places_[i].IsEmpty()) {
					for (size_t j = i + 1; j < places_.size(); ++j) {
						if (!places_[j].IsEmpty()) {
							std::swap(places_[i], places_[j]);
							break;
						}
					}
				}
			}
		}
		places_.resize(n);
		NormalizeBanchID();
	}

	void Room::SetPlaceType(int place_num, Types new_type)
	{
		Banch& place = places_.at(place_num);
		if (!place.IsEmpty()) throw std::runtime_error("Try to change filled place");
		place.SetType(new_type);
	}

	void Room::RemovePlace(int place_num)
	{
		if (!places_.at(place_num).IsEmpty()) throw std::runtime_error("Try to remove filled place");
		places_.erase(places_.begin() + place_num);
		NormalizeBanchID();
	}

	void Room::AddNewPlace(Types new_type)
	{
		places_.push_back(Banch(static_cast<int>(places_.size()), new_type));
	}

	int Room::EmptyPlaces()const
	{
		int count = 0;
		for (const Banch& place : places_) if (place.IsEmpty()) ++count;
		return count;
	}

	int Room::FilledPlaces()const { return AllPlaces() - EmptyPlaces(); }
	int Room::AllPlaces()const { return static_cast<int>(places_.size()); }
	const Pet* Room::WhoAt(int place_num)const { return places_.at(place_num).GetPet(); }
	const Banch& Room::at(int place_num)const { return places_.at(place_num); }
	Banch& Room::at(int place_num) { return places_.at(place_num); }

	void Room::NormalizeBanchID()
	{
		for (size_t i = 0; i < places_.size(); ++i) places_[i].SetId(static_cast<int>(i));
	}

	std::ostream& operator<<(std::ostream& out, const Room& obj)
	{
		out << obj.id_ << ' ' << std::quoted(obj.address_) << ' '
			<< std::quoted(obj.description_) << ' ' << obj.places_.size();
		for (const Banch& place : obj.places_) out << ' ' << place;
		return out;
	}

	std::istream& operator>>(std::istream& in, Room& obj)
	{
		Room temp;
		int count;
		if (!(in >> temp.id_ >> std::quoted(temp.address_)
			>> std::quoted(temp.description_) >> count)) return in;
		if (count < 0) {
			in.setstate(std::ios::failbit);
			return in;
		}
		for (int i = 0; i < count; ++i) {
			Banch place;
			if (!(in >> place)) return in;
			temp.places_.push_back(place);
		}
		obj = temp;
		return in;
	}
}
