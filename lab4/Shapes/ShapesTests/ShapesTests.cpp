#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"

#include "../Shapes/ConsoleCommand.h"
#include "../Shapes/Circle.h"
#include "../Shapes/Rectangle.h"
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

SCENARIO("Rectangle")
{
	WHEN("create rectangle")
	{
		CRectangle rectangle(CPoint(1.0, 4.0), 4.0, 3.0, "ff00ff", "cecece");
		THEN("correct result")
		{
			auto leftTopPointX = rectangle.GetLeftTopPoint().x();
			auto leftTopPointY = rectangle.GetLeftTopPoint().y();
			auto rightBottomPointX = rectangle.GetRightBottomPoint().x();
			auto rightBottomPointY = rectangle.GetRightBottomPoint().y();
			auto width = rectangle.GetWidth();
			auto height = rectangle.GetHeight();
			auto area = rectangle.GetArea();
			auto perimeter = rectangle.GetPerimeter();
			auto outlineColor = rectangle.GetOutlineColor();
			auto fillColor = rectangle.GetFillColor();

			CHECK(leftTopPointX == 1.0);
			CHECK(leftTopPointY == 4.0);
			CHECK(rightBottomPointX == 5.0);
			CHECK(rightBottomPointY == 1.0);
			CHECK(width == 4.0);
			CHECK(height == 3.0);
			CHECK(area == 12);
			CHECK(perimeter == 14);
			CHECK(outlineColor == "ff00ff");
			CHECK(fillColor == "cecece");
		}
	}
}

SCENARIO("Circle")
{
	WHEN("create circle")
	{
		CCircle circle(CPoint(1.0, 4.0), 4.0, "ff00ff", "cecece");
		double testArea = M_PI * 4.0 * 4.0;
		double testPerimeter = 2 * M_PI * 4.0;
		THEN("correct result")
		{
			auto centerPointX = circle.GetCenter().x();
			auto centerPointY = circle.GetCenter().y();
			auto radius = circle.GetRadius();
			auto area = circle.GetArea();
			auto perimeter = circle.GetPerimeter();
			auto outlineColor = circle.GetOutlineColor();
			auto fillColor = circle.GetFillColor();

			CHECK(centerPointX == 1.0);
			CHECK(centerPointY == 4.0);
			CHECK(radius == 4.0);
			CHECK(area == testArea);
			CHECK(perimeter == testPerimeter);
			CHECK(outlineColor == "ff00ff");
			CHECK(fillColor == "cecece");
		}
	}
}