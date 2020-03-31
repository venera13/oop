#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"

#include "../HTMLDecode/HTMLDecode.h"

SCENARIO("HTMLDecode")
{
	WHEN("correct input string")
	{
		std::string input("Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;");
		THEN("correct output string")
		{
			auto result = HtmlDecode(input);
			CHECK(result == "Cat <says> \"Meow\". M&M'");
		}
	}

	WHEN("empty input string")
	{
		std::string input("");
		THEN("output string also empty")
		{
			auto result = HtmlDecode(input);
			CHECK(result == "");
		}
	}

	WHEN("input string with uncorrect entity name")
	{
		std::string input("Cat &lt&lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;");
		THEN("output string with uncorrect entity name")
		{
			auto result = HtmlDecode(input);
			CHECK(result == "Cat &lt<says> \"Meow\". M&M'");
		}
	}

	WHEN("input string with entity name at the beginning and at the end")
	{
		std::string input("&apos;Cat says Meow M M&apos;");
		THEN("correct output string")
		{
			auto result = HtmlDecode(input);
			CHECK(result == "'Cat says Meow M M'");
		}
	}

	WHEN("input string with irreplaceable entity name")
	{
		std::string input("Cat says Meow M&nbsp;M");
		THEN("output string with this irreplaceable entity name")
		{
			auto result = HtmlDecode(input);
			CHECK(result == "Cat says Meow M&nbsp;M");
		}
	}
}