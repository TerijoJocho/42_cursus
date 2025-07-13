#include "BitcoinExchange.hpp"

/*-----------------------------CLASS DEFINITION--------------------------------*/
BitcoinExchange::BitcoinExchange(std::string& dbFilename) : _filename(dbFilename)
{
    this->loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    (void)other;
}

BitcoinExchange &BitcoinExchange ::operator=(const BitcoinExchange &other)
{
    (void)other;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void    BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::fstream    fs;
    fs.open(filename, std::fstream::in);
    if (!fs.is_open())
        throw std::ios_base::failure("Failed to open file '" + filename + "'");    
    
    std::string line;
    std::getline(fs, line);
    while(std::getline(fs, line))
    {
        if (line.empty())
            continue;

        if (line.size() < 12 || line[10] != ',')    
        {
            std::cerr << "Error: Invalid format:" << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, 10);
        std::string valueStr = line.substr(11);

        std::stringstream   ss(valueStr); //outils qui converti les str en numeric
        float   value;                    //variable pour stocker le numeric
        ss >> value;                      //balance le str dans le numeric
        
        this->_database.insert(std::make_pair(date, value));
    }

    fs.close();
}

void    BitcoinExchange::processInputFile() const
{
    this->checkInput(this->_filename);

    std::fstream    fs;
    fs.open(this->_filename, std::fstream::in);

    std::string line;
    std::getline(fs, line);

    while(std::getline(fs, line))
    {
        if (line.empty())
            continue;

        if (!this->isValidDate(line.substr(0, 10)))
        {
            std::cerr << "Error: bad input => " << line.substr(0, 10) << std::endl;
            continue;
        }
        if (line.substr(10, 3) != " | ")
        {
            std::cerr << "Error: invalid format => " << line << std::endl;
            continue;
        }
        if (!this->isValidValue(line.substr(13)))
            continue;

        std::stringstream   ss(line.substr(13));
        float               f;
        ss >> f;
        std::cout << line.substr(0, 10) << " => " << line.substr(13) << " = " << this->getExchangeRateForDate(line.substr(0, 10), f) << std::endl;
    }
    fs.close();
}

float   BitcoinExchange::getExchangeRateForDate(const std::string& date, float& value) const
{
    std::map<std::string, float>::const_iterator    it = this->_database.upper_bound(date);

    if (it != this->_database.begin())
        it--;
    else
        throw std::runtime_error("No earlier date available in database");
    return static_cast<float>(it->second * value);
}

bool    BitcoinExchange::isValidDate(const std::string& line) const
{
    if (!isdigit(line[0]) || !isdigit(line[1]) || !isdigit(line[2]) || !isdigit(line[3]))
        return false;
    if (line[4] != '-')
        return false;
    if (!isdigit(line[5]) || !isdigit(line[6]))
        return false;
    if (line[7] != '-')
        return false;
    if (!isdigit(line[8]) || !isdigit(line[9]))
        return false;
    return true;
}
    
bool    BitcoinExchange::isValidValue(const std::string& value) const
{
    for (size_t i = 0; i < value.size(); i++)
    {
        std::stringstream   ss(value);
        float               f;
        ss >> f;

        if (f < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            return false;
        }
        
        if (f > 1000)
        {
            std::cerr << "Error: number too large." << std::endl;
            return false;
        }
    }
    return true;
}

void    BitcoinExchange::checkInput(std::string file) const
{
    if (file.empty())
        throw std::invalid_argument("File name is empty");

    if (file.find(".txt", 0) == std::string::npos)
        std::cerr << "Warning: file does not have .txt extension. Proceeding anyway." << std::endl;

    std::fstream    fs;
    fs.open(file, std::fstream::in);
    if (!fs.is_open())
        throw std::ios_base::failure("Failed to open file '" + file + "'");    
    
    fs.close();
}
