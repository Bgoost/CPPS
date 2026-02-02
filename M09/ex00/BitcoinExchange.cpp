#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& dataFile) {
    loadData(dataFile);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadData(const std::string& filename) {
    std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open database file");

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::string::size_type pos = line.find(',');
		if (pos == std::string::npos) {
			continue;
		}

		std::string date = line.substr(0, pos);
		std::string rateStr = line.substr(pos + 1);
		float rate = static_cast<float>(std::atof(rateStr.c_str()));

		_db.insert(std::make_pair(date, rate));
	}
	file.close();
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_db.clear();
		_db.insert(other._db.begin(), other._db.end());
	}
	return (*this);
}

float BitcoinExchange::getExchangeRate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _db.find(date);
	if (it != _db.end()) {
		return it->second;
	}
    return -1.0f;
}

bool isLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

void isValidDate(const std::string &date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        throw std::runtime_error("Error: invalid date format (expected YYYY-MM-DD)");

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2009 || year > 2022)
        throw std::runtime_error("Error: invalid year");
    if (month < 1 || month > 12)
        throw std::runtime_error("Error: invalid month");

    int daysInMonth[] = {31, (isLeapYear(year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day < 1 || day > daysInMonth[month - 1])
        throw std::runtime_error("Error: invalid day");
}

void isValidValue(const std::string value)
{
	char*	endptr;
	double	val;

	val = std::strtod(value.c_str(), &endptr);
	if (*endptr != '\0')
		throw std::runtime_error("Error: invalid value");
	if (val < 0)
		throw std::runtime_error("Error: not a positive number");
	if (val > 1000)
		throw std::runtime_error("Error: too large a number");
}

void isValidLine(const std::string date, const std::string value)
{
	isValidDate(date);
	isValidValue(value);
}

std::string BitcoinExchange::closestDate(const std::string fileDate)
{
	std::map<std::string, float>::iterator	it;
	
	it = _db.find(fileDate); 
	if (it != _db.end())
	{
		return (fileDate);
	}
	else
	{
		it = _db.upper_bound(fileDate);
		it--;
		return (it->first);
	}
}

void BitcoinExchange::calculatePrice(const std::string inputFileName)
{
	std::fstream	inFile;
	std::string	buffer;
	std::string	date;
	std::string	value;

	inFile.open(inputFileName.c_str(), std::ios_base::in);
	if (inFile.fail())
		throw std::runtime_error("Error: could not open input file");
	std::getline(inFile, buffer);
	buffer.clear();
	while (true)
	{
		std::getline(inFile, buffer);
		if (inFile.eof())
			break;
		std::string::size_type	pos;
		
		pos = buffer.find(" | ", 0);
		if (pos != buffer.npos)
		{
			date = buffer.substr(0, pos);
			value = buffer.substr(pos + 3, buffer.npos);
		}
		else
		{
			std::cout << "Error: invalid format" << std::endl;
			continue;
		}
		try {
			isValidLine(date, value);
			float price = getExchangeRate(closestDate(date)) * static_cast<float>(std::atof(value.c_str()));
			std::cout << date << " -> " << value << " = " << price << std::endl;
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		buffer.clear();
	}
}