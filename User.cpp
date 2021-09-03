#include "User.h"

User::User()
		: m_id(0)
		, m_login("")
		, m_password("")
{}

User::User(const std::string& login, const std::string& password)
		: User(0, login, password)
{}

User::User(unsigned long id, const std::string& login, const std::string& password)
		: m_id(id)
		, m_login(login)
		, m_password(password)
{}

unsigned long User::get_id() const
{
	return m_id;
}

const std::string& User::get_login() const
{
	return m_login;
}

const std::string& User::get_password() const
{
	return m_password;
}

void User::set_id(unsigned long id)
{
	this->m_id = id;
}

void User::set_login(const std::string& login)
{
	this->m_login = login;
}

void User::set_password(const std::string& password)
{
	this->m_password = password;
}

std::ostream& operator<<(std::ostream& os, const User& user)
{
	os << user.m_id << " \"" << user.m_login << "\" \"" << user.m_password << "\"" << std::endl;
	return os;
}
