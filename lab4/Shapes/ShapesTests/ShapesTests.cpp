#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"

#include "../Shapes/ConsoleCommand.h"
#include "../Shapes/Triangle.h"
#include "../Shapes/LineSegment.h"
#include "../Shapes/Point.h"

SCENARIO("Line segment")
{
	WHEN("create line segment")
	{
		CLineSegment lineSegment(CPoint(0.0, 5.0), CPoint(10.0, 5.0), "ff00ff");
		THEN("correct result")
		{
			auto startPointX = lineSegment.GetStartPoint().x();
			auto startPointY = lineSegment.GetStartPoint().y();
			auto endPointX = lineSegment.GetEndPoint().x();
			auto endPointY = lineSegment.GetEndPoint().y();
			auto area = lineSegment.GetArea();
			auto perimeter = lineSegment.GetPerimeter();
			auto outlineColor = lineSegment.GetOutlineColor();

			CHECK(startPointX == 0.0);
			CHECK(startPointY == 5.0);
			CHECK(endPointX == 10.0);
			CHECK(endPointY == 5.0);
			CHECK(area == 0.0);
			CHECK(perimeter == 10.0);
			CHECK(outlineColor == "ff00ff");
		}
	}
}

SCENARIO("Triangle")
{
	WHEN("create triangle")
	{
		CTriangle triangle(CPoint(1.0, 1.0), CPoint(1.0, 7.0), CPoint(9.0, 1.0), "ff00ff", "cecece");
		THEN("correct result")
		{
			auto vertex1X = triangle.GetVertex1().x();
			auto vertex1Y = triangle.GetVertex1().y();
			auto vertex2X = triangle.GetVertex2().x();
			auto vertex2Y = triangle.GetVertex2().y();
			auto vertex3X = triangle.GetVertex3().x();
			auto vertex3Y = triangle.GetVertex3().y();
			auto area = triangle.GetArea();
			auto perimeter = triangle.GetPerimeter();
			auto outlineColor = triangle.GetOutlineColor();
			auto fillColor = triangle.GetFillColor();

			CHECK(vertex1X == 1.0);
			CHECK(vertex1Y == 1.0);
			CHECK(vertex2X == 1.0);
			CHECK(vertex2Y == 7.0);
			CHECK(vertex3X == 9.0);
			CHECK(vertex3Y == 1.0);
			CHECK(vertex3Y == 1.0);
			CHECK(area == 24);
			CHECK(perimeter == 24);
			CHECK(outlineColor == "ff00ff");
			CHECK(fillColor == "cecece");
		}
	}
}