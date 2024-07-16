#include <iostream>
#include <chrono>
#include <iomanip>
#include "./date/include/date/tz.h"


int main() {
    // Get the current system time in UTC
    auto now = std::chrono::system_clock::now();

    // Specify the target time zone
    auto tz = date::locate_zone("America/New_York"); // Replace with your desired time zone

    // Convert the current time to the target time zone
    auto local_time = date::make_zoned(tz, now).get_local_time();
    
    // Convert local time to UTC
    //auto utc_time = date::make_zoned("UTC", local_time).get_sys_time();

    // Calculate the UTC offset in hours and minutes
   // auto offset = local_time - utc_time;

    // Convert offset to hours and minutes
   // auto hours = std::chrono::duration_cast<std::chrono::hours>(offset);
   // auto minutes = std::chrono::duration_cast<std::chrono::minutes>(offset - hours);

    // Print the UTC offset
    //std::cout << "UTC Offset for " << tz->name() << ": ";
    //if (hours.count() >= 0)
    //    std::cout << "+";
   // std::cout << hours.count() << " hours " << minutes.count() << " minutes" << std::endl;

    return 0;
}

