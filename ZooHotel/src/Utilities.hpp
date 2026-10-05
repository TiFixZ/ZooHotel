#pragma once

#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <chrono>
#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>

namespace ZooHotel {

	namespace Demo {

		inline int F00() { return -1; }
		int F01();
		extern int g_var;
	}

	enum Types {
		small_cage = 0,
		large_cage,
		small_room,
		large_room
	};

	namespace DateTime {

		class DateTime {
		public:
			DateTime();
			DateTime(const std::string& iso_time);

			std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds>
				TimePoint()const;
			std::string IsoTime()const;

			void SetYear(std::chrono::years year);
			void SetYear(int year);
			void SetYear(std::string year);

			void SetMonths(std::chrono::month month);
			void SetMonths(int month);
			void SetMonths(std::string month);

			bool operator ==(const DateTime& other)const;
			bool operator <(const DateTime& other)const;

		private:
			std::string iso8601str;

			bool ParseISOString(const std::string& iso_time);
			void UpdateString(
				std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds>& tp);
		};
	}
}

#endif
