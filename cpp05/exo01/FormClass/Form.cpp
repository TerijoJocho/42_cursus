#include "Form.hpp"

Form::Form(std::string const name, int const gradeToSign, int const gradeToExecute)
		: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false)
{

}

Form::~Form()
{
}

Form::Form(const Form &other)
	: _name(other.getName()), _gradeToSign(other.getGradeToSign()),
		_gradeToExecute(other.getGradeToExecute()), _isSigned(false)
{

}

Form &Form::operator=(const Form &other)
{

}

