#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

#include "ini_parser.h"

/// === Members ===
/*!
* Loads the INI file specified by filename.
* @param filename The path to the INI file.
* @return true if the file was successfully loaded, false otherwise.
*/
bool IniParser::load(const std::string& filename) {
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return false;
    }

    std::string line, current_section;
    
    while (std::getline(file, line)) {
        /// Remove leading and trailing whitespace
        line = trim(line);

        /// Check for comments or empty lines
        if (line.empty() || line[0] == ';' || line[0] == '#') { continue; }
        if (line.find(';') != std::string::npos) { line = line.substr(0, line.find(';')); }

        /// 
        if (line.front() == '[' && line.back() == ']') {
            /// Set section header
            current_section = line.substr(1, line.size() - 2);
        } else {
            
            /// Key-value pair
            std::istringstream line_stream(line);
            std::string key, value;
            
            if (std::getline(line_stream, key, '=') && std::getline(line_stream, value)) {
                
                /// Remove leading and trailing whitespace from key and value
                key = trim(key);
                value = trim(value);

                data[current_section][key] = value;
            }
        }
    }
    return true;
}

/*!
 * Retrieves a string value from the specified section and key.
 * @param section The section name in the INI file.
 * @param key The key whose value is to be retrieved.
 * @param out Reference to store the retrieved string value.
 * @return true if the value was found and retrieved, false otherwise.
 */
bool IniParser::get_string(const std::string& section, const std::string& key, std::string& out) const {
    auto section_it = data.find(section);  //!< Iterator to section in the map "data".
    
    /// Check if the section exist.
    if (section_it != data.end()) {
        auto key_it = section_it->second.find(key);  //!< Iterator to key in the map "data".

        /// Check if the section exist.
        if (key_it != section_it->second.end()) {
            out = key_it->second;
            return true;
        }
    }
    
    return false;
}

/*!
 * Retrieves an integer value from the specified section and key.
 * @param section The section name in the INI file.
 * @param key The key whose value is to be retrieved.
 * @param out Reference to store the retrieved integer value.
 * @return true if the value was found and retrieved successfully, false otherwise.
 */
bool IniParser::get_int(const std::string& section, const std::string& key, int& out) const {
    std::string value;  //!< Temporary string variable to store the retrieved value as string.

    /// Check if the value was informed in the section and key.
    if (get_string(section, key, value)) {
        /// Convert the retrieved string value to integer and assign to 'out'.
        try {
            out = std::stoi(value);
            return true;
        } catch (const std::exception& e) {
            throw std::invalid_argument("Invalid argument: the value for key '" + key + "' in section '" + section + "' is not a valid integer.");
        }
    }

    return false;
}

/*!
 * Retrieves a boolean value from the specified section and key.
 * @param section The section name in the INI file.
 * @param key The key whose value is to be retrieved.
 * @param out Reference to store the retrieved boolean value.
 * @return true if the value was found and retrieved successfully, false otherwise.
 */
bool IniParser::get_bool(const std::string& section, const std::string& key, bool& out) const {
    std::string value;   //!< Temporary string variable to store the retrieved value as string.
    
    /// Check if the value was informed in the section and key.
    if (get_string(section, key, value)) {
        /// Convert the retrieved string value to bool and assign to 'out'.
        out = string_to_bool(trim(value));  
        return true;
    }
    return false;
}


/*!
 * Trims leading and trailing whitespace characters from a string.
 * @param str The string to trim.
 * @return The trimmed string.
 */
std::string IniParser::trim(const std::string& str) const {
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

/*!
 * Converts a string to a boolean value.
 * @param str The string representation of the boolean ("true" or "false").
 * @return The boolean value represented by the string.
 */
bool IniParser::string_to_bool(const std::string& str) const {
    std::string lower_str = str;  //!< Make a copy of the input string.
    /// Convert the string to lowercase for case-insensitive comparison
    std::transform(lower_str.begin(), lower_str.end(), lower_str.begin(), [](unsigned char c) { return std::tolower(c); });
    
    /// Check if the lowercased string matches known true values
    if (lower_str == "true" || lower_str == "1" || lower_str == "yes") { return true; }
    else if (lower_str == "false" || lower_str == "0" || lower_str == "no") { return false; }
    else { throw std::invalid_argument("Invalid argument used in string to bool."); }
}