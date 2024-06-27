#ifndef INI_PARSER_H
#define INI_PARSER_H

#include <string>
#include <map>

/*
 * A class to parse and retrieve values from an INI file.
 */
class IniParser {
public:
    
    // === Members.
    /// Loads the INI file specified by filename.
    bool load(const std::string& filename);
    /// Retrieves a string value from the specified section and key.
    bool get_string(const std::string& section, const std::string& key, std::string& out) const;
    /// Retrieves an integer value from the specified section and key.
    bool get_int(const std::string& section, const std::string& key, int& out) const;
    /// Retrieves a boolean value from the specified section and key.
    bool get_bool(const std::string& section, const std::string& key, bool& out) const;

private:
    std::map<std::string, std::map<std::string, std::string>> data;  //!< Map to store the parsed INI data.

    // === Auxiliary methods.
    /// Trims leading and trailing whitespace characters from a string.
    std::string trim(const std::string& str) const;
    /// Converts a string to a boolean value.
    bool string_to_bool(const std::string& str) const;
};

#endif // INI_PARSER_H
