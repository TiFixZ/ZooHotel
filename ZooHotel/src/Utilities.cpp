#include "Utilities.hpp"

int ZooHotel::Demo::F01()
{
	return 0;
}

int ZooHotel::Demo::g_var;

namespace ZooHotel {
	namespace DateTime {

		DateTime::DateTime()
			:iso8601str("1970-01-01 00:00:00")
		{}

		DateTime::DateTime(const std::string& iso_time)
		{
			if (!ParseISOString(iso_time)) {
				throw std::invalid_argument("Invalid date");
			}
			iso8601str = iso_time;
		}

		bool DateTime::ParseISOString(const std::string& iso_time)
		{
			if (iso_time.size() != 19) return false;
			if (iso_time[4] != '-' || iso_time[7] != '-' || iso_time[10] != ' ' ||
				iso_time[13] != ':' || iso_time[16] != ':') return false;
			for (size_t i = 0; i < iso_time.size(); ++i) {
				if (i == 4 || i == 7 || i == 10 || i == 13 || i == 16) continue;
				if (iso_time[i] < '0' || iso_time[i] > '9') return false;
			}
			std::tm tm{};
			std::istringstream in(iso_time);
			in >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
			if (in.fail() || in.peek() != std::char_traits<char>::eof()) return false;
			auto date = std::chrono::year{ tm.tm_year + 1900 } /
				std::chrono::month{ static_cast<unsigned>(tm.tm_mon + 1) } /
				std::chrono::day{ static_cast<unsigned>(tm.tm_mday) };
			return date.ok() && tm.tm_hour >= 0 && tm.tm_hour < 24 &&
				tm.tm_min >= 0 && tm.tm_min < 60 && tm.tm_sec >= 0 && tm.tm_sec < 60;
		}

		std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds>
			DateTime::TimePoint()const
		{
			std::tm tm{};
			std::istringstream in(iso8601str);
			in >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
			auto date = std::chrono::year{ tm.tm_year + 1900 } /
				std::chrono::month{ static_cast<unsigned>(tm.tm_mon + 1) } /
				std::chrono::day{ static_cast<unsigned>(tm.tm_mday) };
			return std::chrono::sys_days{ date } + std::chrono::hours{ tm.tm_hour } +
				std::chrono::minutes{ tm.tm_min } + std::chrono::seconds{ tm.tm_sec };
		}

		std::string DateTime::IsoTime()const
		{
			return iso8601str;
		}

		void DateTime::SetYear(std::chrono::years year)
		{
			SetYear(static_cast<int>(year.count()));
		}

		void DateTime::SetYear(int year)
		{
			std::ostringstream out;
			out << std::setfill('0') << std::setw(4) << year << iso8601str.substr(4);
			DateTime temp(out.str());
			iso8601str = temp.IsoTime();
		}

		void DateTime::SetYear(std::string year)
		{
			size_t pos;
			int value = std::stoi(year, &pos);
			if (pos != year.size()) throw std::invalid_argument("Invalid year");
			SetYear(value);
		}

		void DateTime::SetMonths(std::chrono::month month)
		{
			SetMonths(static_cast<unsigned>(month));
		}

		void DateTime::SetMonths(int month)
		{
			std::ostringstream out;
			out << iso8601str.substr(0, 5) << std::setfill('0') << std::setw(2) << month <<
				iso8601str.substr(7);
			DateTime temp(out.str());
			iso8601str = temp.IsoTime();
		}

		void DateTime::SetMonths(std::string month)
		{
			size_t pos;
			int value = std::stoi(month, &pos);
			if (pos != month.size()) throw std::invalid_argument("Invalid month");
			SetMonths(value);
		}

		bool DateTime::operator ==(const DateTime& other)const
		{
			return iso8601str == other.iso8601str;
		}

		bool DateTime::operator <(const DateTime& other)const
		{
			return iso8601str < other.iso8601str;
		}

		void DateTime::UpdateString(
			std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds>& tp)
		{
			auto days = std::chrono::floor<std::chrono::days>(tp);
			std::chrono::year_month_day date(days);
			std::chrono::hh_mm_ss time(tp - days);
			std::ostringstream out;
			out << std::setfill('0') << std::setw(4) << static_cast<int>(date.year()) << '-' <<
				std::setw(2) << static_cast<unsigned>(date.month()) << '-' <<
				std::setw(2) << static_cast<unsigned>(date.day()) << ' ' <<
				std::setw(2) << time.hours().count() << ':' <<
				std::setw(2) << time.minutes().count() << ':' <<
				std::setw(2) << time.seconds().count();
			if (!ParseISOString(out.str())) throw std::invalid_argument("Invalid date");
			iso8601str = out.str();
		}
	}
}
