#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"

#include "../HTTP_URL/CHttpUrl.h"

TEST_CASE("exception invalid argument")
{
	CHECK_THROWS_AS(CHttpUrl("http://mysite.ru:0"), std::invalid_argument);
	CHECK_THROWS_AS(CHttpUrl("ttp:/mysite"), std::invalid_argument);
}
TEST_CASE("correct url")
{
	CHttpUrl url("https://www.cplusplus.com:10/reference/string.html");
	CHECK(url.GetDomain() == "www.cplusplus.com");
	CHECK(url.GetDocument() == "/reference/string.html");
	CHECK(url.GetProtocol() == Protocol::HTTPS);
	CHECK(url.GetPort() == 10);
}

TEST_CASE("correct url without document")
{
	CHttpUrl url("http://www.cplusplus.com");
	CHECK(url.GetDomain() == "www.cplusplus.com");
	CHECK(url.GetDocument() == "/");
	CHECK(url.GetProtocol() == Protocol::HTTP);
	CHECK(url.GetPort() == 80);
}

TEST_CASE("correct url with document, protocol, and without port")
{
	CHttpUrl url("www.cplusplus", "reference", Protocol::HTTPS);
	CHECK(url.GetDomain() == "www.cplusplus");
	CHECK(url.GetDocument() == "/reference");
	CHECK(url.GetProtocol() == Protocol::HTTPS);
	CHECK(url.GetPort() == 443);
}

TEST_CASE("incorrect url with empty domain, and with document")
{
	CHECK_THROWS_AS(CHttpUrl(""), std::invalid_argument);
}

TEST_CASE("correct url with document, protocol, port")
{
	CHttpUrl url("www.cplusplus", "reference", Protocol::HTTPS, 123);
	CHECK(url.GetDomain() == "www.cplusplus");
	CHECK(url.GetDocument() == "/reference");
	CHECK(url.GetProtocol() == Protocol::HTTPS);
	CHECK(url.GetPort() == 123);
}

TEST_CASE("GetUrl")
{
	CHttpUrl url("www.cplusplus", "reference", Protocol::HTTPS, 123);
	CHECK(url.GetURL() == "https://www.cplusplus:123/reference");
}