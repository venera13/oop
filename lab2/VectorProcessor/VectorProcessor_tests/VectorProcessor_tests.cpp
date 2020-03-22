#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../catch/catch.hpp"

#include "../VectorProcessor/VectorProcessor.h"

SCENARIO("Reversing of empty string gives an empty string")
{
	REQUIRE(Reverse("").empty());
}

SCENARIO("Reverse of string of one character is the string itself")
{
	REQUIRE(Reverse("a") == "a");
}