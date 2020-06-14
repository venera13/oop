#include "CHttpUrl.h"
#include "CUrlParsingError.h"

#include <string>
#include <algorithm>
#include <regex>

std::string GetUrlDocument(const std::string document)
{
	std::string resultDocument = document;
	if (document.empty() || document[0] != '/')
	{
		resultDocument = '/' + document;
	}
	return resultDocument;
}

std::string ProtocolToString(const Protocol protocol)
{
	return protocol == Protocol::HTTP ? "http" : "https";
}

CHttpUrl::CHttpUrl(std::string const& url)
{
	ParseUrl(url);
}

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol)
	: m_protocol(protocol)
{
	if (domain.empty() || document.empty())
	{
		throw CUrlParsingError("Invalid params");
	}
	if (protocol == Protocol::HTTPS)
	{
		m_port = 443;
	}
	else
	{
		m_port = 80;
	}
	m_domain = domain;
	m_document = GetUrlDocument(document);
}

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, unsigned short port)
	: m_protocol(protocol)
{
	if (domain.empty() || document.empty())
	{
		throw CUrlParsingError("Invalid params");
	}
	m_port = port;
	m_domain = domain;
	m_document = GetUrlDocument(document);
}

void CHttpUrl::ParseUrl(std::string const& url)
{
	std::regex ex("([\\w]*)://([^/ :]+):?([^/ ]*)(/?[^ #?]*)\\x3f?([^ #]*)#?([^ ]*)");

	std::smatch urlMatchResult;

	if (std::regex_match(url, urlMatchResult, ex))
	{
		m_protocol = StringToProtocol(urlMatchResult[1]);
		m_domain = urlMatchResult[2];
		m_document = GetUrlDocument(urlMatchResult[4]);
		m_port = StringToUnsignedShortPort(urlMatchResult[3], m_protocol);
	}
	else
	{
		throw CUrlParsingError("Invalid url");
	}
}

Protocol CHttpUrl::StringToProtocol(std::string url)
{
	std::transform(url.begin(), url.end(), url.begin(), ::tolower);
	Protocol protocol;

	if (url == "https" || url == "https://")
	{
		protocol = Protocol::HTTPS;
	}
	else if (url == "http" || url == "http://")
	{
		protocol = Protocol::HTTP;
	}
	else
	{
		throw CUrlParsingError("Invalid protocol. Protocol must be equal to http or https");
	}

	return protocol;
}

unsigned short CHttpUrl::StringToUnsignedShortPort(const std::string& port, Protocol& protocol)
{
	if (port.empty())
	{
		return (protocol == Protocol::HTTPS) ? 443 : 80;
	}

	try
	{
		unsigned short resultPort = stoi(port);
		if (resultPort >= 1 && resultPort <= 65535)
		{
			return resultPort;
		}
	}
	catch (std::invalid_argument)
	{
		throw CUrlParsingError("Invalid port. Port value must be greater than 1 and less than 65535");
	}

	throw CUrlParsingError("Invalid port. Port value must be greater than 1 and less than 65535");
}

std::string CHttpUrl::GetURL() const
{
	std::string port = (m_port != 443 && m_port != 80) ? ":" + std::to_string(m_port) : "";

	return ProtocolToString(m_protocol) + "://" + m_domain + port + m_document;
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}
