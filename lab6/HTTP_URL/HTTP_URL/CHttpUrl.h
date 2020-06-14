#pragma once

#include <iostream>

enum Protocol
{
	HTTP,
	HTTPS
};

class CHttpUrl
{
public:
	CHttpUrl(std::string const& url);

	CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol = HTTP);
	CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, unsigned short port);

	std::string GetURL() const;
	std::string GetDomain() const;
	std::string GetDocument() const;
	Protocol GetProtocol() const;
	unsigned short GetPort() const;

private:
	void ParseUrl(std::string const& url);
	Protocol StringToProtocol(std::string error);
	unsigned short StringToUnsignedShortPort(const std::string& port, Protocol& protocol);

	std::string m_domain;
	std::string m_document;
	Protocol m_protocol;
	unsigned short m_port;
};
