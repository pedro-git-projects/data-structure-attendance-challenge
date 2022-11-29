#include "utils.h"

std::string Utils::boolToInt(bool b) {
	return b ? "true" : "false";
}; 

std::string Utils::booleanToStatus(bool b) {
	return b ? "A" : "I";
};

