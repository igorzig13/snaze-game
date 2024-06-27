#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <algorithm>

#include "ini_parser.h"

enum class Intelligence {
	RANDOM = 0,
	BACKTRACK
};

/*!
 * This class functions to set all the initialization information 
 * for the game.
 */
class Config {
public:
	
	//=== Special Members.
    /// Constructor.
    Config();
    /// Destructor.
    ~Config();

	//=== Members. 
	/// Set input_file.
	std::string set_input_file(IniParser &filename);
	/// Set fps.
	int set_fps(IniParser &filename);
	/// Set lives.
	int set_lives(IniParser &filename);
	/// Set food.
	int set_food(IniParser &filename);
	/// Set playertype.
	Intelligence set_playertype(IniParser &filename);
	/// /// Set all members with others methods.
	void load(const std::string &filename);
	
	//=== Attribute accessors members.
	/// Get input_file.
	std::string get_input_file() { return input_file; };
	/// Get fps.
	int get_fps() { return fps; };
	/// Get lives.
	int get_lives() { return lives; };
	/// Get food.
	int get_food() { return food; };
	/// Get playertype.
	Intelligence get_playertype() { return playertype; };
	
	//=== Auxiliary functions.
	/// Remove quotes of the paths.
	void remove_quotes(std::string& path);

private:
	std::string input_file; 
	int fps; 
	int lives; 
	int food; 
	Intelligence playertype;
};

#endif // CONFIG_H