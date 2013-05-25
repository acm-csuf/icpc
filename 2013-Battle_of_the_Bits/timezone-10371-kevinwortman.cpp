// Accepted solution for 10371 "Time Zones"
//
// Kevin Wortman
//
// This solution is based on a simple-minded approach of modeling time
// exactly as a physical clock would, with an hour number 1-12, minute
// number 0-59, and am/pm flag. Time is moved forward or backward one
// minute at a time. This is inefficient but easy to verify for
// correctness.

#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

struct Time {
  int hour, minute;
  bool am;

  void parse() {
    string time_str;
    cin >> time_str;

    if (time_str == "midnight") {
      hour = 12;
      minute = 0;
      am = true;
    } else if (time_str == "noon") {
      hour = 12;
      minute = 0;
      am = false;
    } else {
      // Manually parse time digits. This could probably be done more
      // elegantly with a stringstream.
      assert(time_str[1] == ':' || time_str[2] == ':');
      int min_i;
      if (time_str[1] == ':') {
	hour = time_str[0] - '0';
	min_i = 2;
      } else {
	hour = (time_str[0] - '0')*10 + time_str[1]-'0';
	min_i = 3;
      }

      minute = (time_str[min_i]-'0')*10 + time_str[min_i+1]-'0';
    
      assert((hour >= 1) && (hour <= 12));
      assert((minute >= 0) && (minute < 60));

      string am_pm;
      cin >> am_pm;

      switch (am_pm[0]) {
      case 'a': am = true; break;
      case 'p': am = false; break;
      default:  assert(false);
      }
    }
  }

  void print() {
    if (hour == 12 && minute == 0)
      cout << (am ? "midnight" : "noon") << endl;
    else
      cout << hour
	   << ":"
	   << ((minute < 10) ? "0" : "") << minute
	   << " "
	   << (am ? "a.m." : "p.m.")
	   << endl;
  }

  void add_minute() {
    ++minute;
    if (minute == 60) {
      minute = 0;
      ++hour;
      if (hour == 13)
	hour = 1;
      else if (hour == 12)
	am = !am;
    }
  }

  void subtract_minute() {
    --minute;
    if (minute == -1) {
      minute = 59;
      --hour;
      if (hour == 0)
	hour = 12;
      else if (hour == 11)
	am = !am;
    }
  }

  void offset(int half_hours) {
    if (half_hours == 0)
      return;

    int count = abs(half_hours) * 30;
    bool add = half_hours > 0;
    for (int i = 0; i < count; ++i)
      if (add)
	add_minute();
      else
	subtract_minute();
  }
};

int main() {
  
  map<string, int> zone_to_half_hour;

  zone_to_half_hour["UTC"] = 0;
  zone_to_half_hour["GMT"] = 0;
  zone_to_half_hour["BST"] = 2;
  zone_to_half_hour["IST"] = 2;
  zone_to_half_hour["WET"] = 0;
  zone_to_half_hour["WEST"] = 2;
  zone_to_half_hour["CET"] = 2;
  zone_to_half_hour["CEST"] = 4;
  zone_to_half_hour["EET"] = 4;
  zone_to_half_hour["EEST"] = 6;
  zone_to_half_hour["MSK"] = 6;
  zone_to_half_hour["MSD"] = 8;
  zone_to_half_hour["AST"] = -8;
  zone_to_half_hour["ADT"] = -6;
  zone_to_half_hour["NST"] = -7;
  zone_to_half_hour["NDT"] = -5;
  zone_to_half_hour["EST"] = -10;
  zone_to_half_hour["EDT"] = -8;
  zone_to_half_hour["CST"] = -12;
  zone_to_half_hour["CDT"] = -10;
  zone_to_half_hour["MST"] = -14;
  zone_to_half_hour["MDT"] = -12;
  zone_to_half_hour["PST"] = -16;
  zone_to_half_hour["PDT"] = -14;
  zone_to_half_hour["HST"] = -20;
  zone_to_half_hour["AKST"] = -18;
  zone_to_half_hour["AKDT"] = -16;
  zone_to_half_hour["AEST"] = 20;
  zone_to_half_hour["AEDT"] = 22;
  zone_to_half_hour["ACST"] = 19;
  zone_to_half_hour["ACDT"] = 21;
  zone_to_half_hour["AWST"] = 16;

  int N;
  cin >> N;
  for (int n = 0; n < N; ++n) {
    Time t;
    t.parse();
    
    string from_zone, to_zone;
    cin >> from_zone >> to_zone;

    assert(zone_to_half_hour.find(from_zone) != zone_to_half_hour.end());
    assert(zone_to_half_hour.find(to_zone) != zone_to_half_hour.end());
    int from_offset = zone_to_half_hour[from_zone];
    int to_offset = zone_to_half_hour[to_zone];
    int total_offset = to_offset - from_offset;

    t.offset(total_offset);

    t.print();
  }

  return 0;
}
  
