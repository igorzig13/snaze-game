#include "config.h"

// === Auxiliars Functions === 
/*! This function remove quotes of the paths.
 * @param path File path from which the quotes will be removed.
 */
void Config::remove_quotes(std::string& path) {
    size_t start = 0;
    size_t end = path.size() - 1;

    // Check if the first or last character is a quote.
    if (path.front() == '\"') { start = 1; }
    if (path.back() == '\"') { end = path.size() - 2; }

    // Modify the original string to remove the leading and trailing quotes.
    path = path.substr(start, end - start + 1);
}

// === Special Members === 
/*!
 * The default construcutor.
 */
Config::Config() : 
input_file(""), fps(0), lives(0), food(0), playertype(Intelligence::BACKTRACK) { /*empty*/ }

/*!
 * The default destrucutor.
 */
Config::~Config() { /*empty*/ }

// === Members === 
/*!
* This function set the input informed by glife.ini.
* @param filename Name of the config file.
* @return The file input.
*/
std::string Config::set_input_file(IniParser &filename) {
    std::string input; //!<- String of the name of input.
    bool informed = filename.get_string("", "input_file", input);  //!<- Show if the data was provided.

	/// Check if input was be informed.    
    if(!informed) {
        throw std::runtime_error("The < input_file > not be informed in [config/snaze.ini]");
    }

    remove_quotes(input);

    return input;
}

/*!
* This function set the number of frames per second; by default, this value is 5.
* @param filename Name of the config file.
* @return Nuber of fps.
*/
int Config::set_fps(IniParser &filename) {
    int fps;
    bool informed = filename.get_int("Render", "fps", fps);  //!<- Show if the data was provided.

    /// Check if input was be informed.
    if(!informed) { fps = 5; }

    if(fps <= 0) {
        throw std::invalid_argument("Used a negative value or zero in < fps > when a positive integer was expected.");
    }

    return fps;
}

/*!
* This function set the number lives in game; by default, this value is 5.
* @param filename Name of the config file.
* @return Number of lives.
*/
int Config::set_lives(IniParser &filename) {
    int lives;
    bool informed = filename.get_int("General", "lives", lives);  //!<- Show if the data was provided.

    /// Check if input was be informed.
    if(!informed) { fps = 5; }

    if(fps <= 0) {
        throw std::invalid_argument("Used a negative value or zero in < fps > when a positive integer was expected.");
    }

    return lives;
}

/*!
* This function set the number foods in game; by default, this value is 10.
* @param filename Name of the config file.
* @return Number of foods.
*/
int Config::set_food(IniParser &filename) {
    int food;
    bool informed = filename.get_int("General", "food", food);  //!<- Show if the data was provided.

    /// Check if input was be informed.
    if(!informed) { fps = 10; }

    if(fps <= 0) {
        throw std::invalid_argument("Used a negative value or zero in < fps > when a positive integer was expected.");
    }

    return food;
}

/*!
* This function set the type of intelligence of snake; by default, this value is BACKTRACK.
* @param filename Name of the config file.
* @return Type of intelligence.
*/
Intelligence Config::set_playertype(IniParser &filename) {
    std::vector<std::string> intelligences = {"backtrack", "random"};  //!<- Vector with all intelligences.

    std::string intelligence; 
    bool informed = filename.get_string("General", "playertype", intelligence);  //!<- Show if the data was provided.

    /// Convert the string of intelligence to lowercase to "map" in enum class intelligence. 
    std::transform(intelligence.begin(), intelligence.end(), intelligence.begin(), ::tolower);

    /// Check if the intelligence type was informed or is valid.
    if (!informed || std::find(intelligences.begin(), intelligences.end(), intelligence) == intelligences.end()) 
    { intelligence = "backtrack"; }

    if (intelligence == "backtrack") { return Intelligence::BACKTRACK; }
    
    return Intelligence::RANDOM; 
}

/*!
* This function use others functions to set all members class.
* @param filename Name of the config file.
*/
void Config::load(const std::string &filename) {
	IniParser reader;

	if (!reader.load(filename)) {
		throw std::runtime_error(">>> Failed to load or parse the config file.");
	}

    /// Set the input file.
	input_file = set_input_file(reader);
	
    // Set the image control.
	fps = set_fps(reader);

    /// Set settings control.
    lives = set_lives(reader);
    food = set_food(reader);
    playertype = set_playertype(reader);
}