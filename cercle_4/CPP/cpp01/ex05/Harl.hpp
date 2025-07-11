#ifndef HARL_H
# define HARL_H

# pragma once
# include <iostream>

class Harl
{
  private:
	void debug(void) const;
	void info(void) const;
	void warning(void) const;
	void error(void) const;

  public:
	Harl();
	~Harl();
	void complain(std::string level);
};

#endif
