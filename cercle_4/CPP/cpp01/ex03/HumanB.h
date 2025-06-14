#ifndef HUMANB_H
# define HUMANB_H

# pragma once
# include "Weapon.h"

class HumanB
{
  public:
	HumanB();
	HumanB(std::string name);
	~HumanB();
	void attack(void) const;
	// on recois une reference et pas un pointeur
	// pour eviter que l'utilisateur envoie un ptr == NULL
	// evite de faire des verif de if partout
	void setWeapon(Weapon &weapon);

  private:
	std::string name;
	Weapon *weaponPtr;
};

#endif
