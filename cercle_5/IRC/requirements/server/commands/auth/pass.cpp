/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:39:27 by aarmitan          #+#    #+#             */
/*   Updated: 2025/11/12 11:42:34 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../server.hpp"

bool	server::handlePass(client* cli, message& msg)
{
	if(msg.getParams().empty())
	{
		std::string	error = ":" + this->_serverName + " 461 * :Not enough parameters\r\n";
		cli->enqueueLine(error);
		polloutActivate(cli);
		return false;
	}
	if (msg.getParams()[0] != this->getPassWord())
	{
		std::string	error = ":" + this->_serverName + " 464 * :Password incorrect\r\n";
		cli->enqueueLine(error);
		polloutActivate(cli);
		return false;
	}
	cli->setPass(msg.getParams()[0]);

	if (!cli->getRegistered() && !cli->getNick().empty() && !cli->getUser().empty() && !cli->getPass().empty())
		sendWelcomeIfRegistrationComplete(cli);
	return true;
}
