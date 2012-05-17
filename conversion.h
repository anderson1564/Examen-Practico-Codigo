#include <sstream>
#include <string>

template <class T> std::string to_str(const T & x)
{std::stringstream ss; ss << x; return ss.str();}

template <class T> int to_int(const T & x)
{std::stringstream ss; ss << x; int r; ss >> r; return r;}

template <class T> long long to_long(const T & x)
{std::stringstream ss; ss << x; long long r; ss >> r; return r;}

int from_str_to_int(std::string & str)
{
	std::string tmp;
	for (int i = 0; i<str.size(); ++i)
		if (str[i] >= '0' && str[i] <= '9')
			tmp += str[i];
	return to_int(tmp);
}
