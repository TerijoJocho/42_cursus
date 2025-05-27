class phoneBook {
public:
	phoneBook();                                  // Constructeur par défaut
	phoneBook(const phoneBook& other);            // Constructeur de copie
	phoneBook& operator=(const phoneBook& other); // Opérateur d’affectation
	~phoneBook();                                 // Destructeur

	bool ft_add_contact(std::string fN, std::string lN, std::string nn,
	                    std::string pN, std::string dS);
	void ft_search_contact(phoneBook& repertoire) const;

private:
	int count;
	int index;
	Contact contact[8];
};

