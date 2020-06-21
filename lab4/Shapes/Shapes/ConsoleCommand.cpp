#include "stdafx.h"
#include "ConsoleCommand.h"
#include "Canvas.h"
#include "Circle.h"
#include "LineSegment.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "SolidShape.h"
#include "Triangle.h"

using namespace std;
using namespace boost;

unique_ptr<CShape> CreateLineSegment(vector<string> command)
{
	if (command.size() == 6)
	{
		try
		{
			return make_unique<CLineSegment>(CPoint(stod(command[1]), stod(command[2])), CPoint(stod(command[3]), stod(command[4])), command[5]);
		}
		catch (const std::logic_error&)
		{
			throw invalid_argument("Incorrect argument");
		}
	}
	else
	{
		throw invalid_argument("Incorrect number of arguments");
	}
}

unique_ptr<CShape> CreateTriangle(vector<string> command)
{
	if (command.size() == 9)
	{
		try
		{
			return make_unique<CTriangle>(CPoint(stod(command[1]), stod(command[2])), CPoint(stod(command[3]), stod(command[4])), CPoint(stod(command[5]), stod(command[6])), command[7], command[8]);
		}
		catch (const std::logic_error&)
		{
			throw invalid_argument("Incorrect argument");
		}
	}
	else
	{
		throw invalid_argument("Incorrect number of arguments");
	}
}

unique_ptr<CShape> CreateRectangle(vector<string> command)
{
	if (command.size() == 7)
	{
		try
		{
			return make_unique<CRectangle>(CPoint(stod(command[1]), stod(command[2])), stod(command[3]), stod(command[4]), command[5], command[6]);
		}
		catch (const std::logic_error&)
		{
			throw invalid_argument("Incorrect argument");
		}
	}
	else
	{
		throw invalid_argument("Incorrect number of arguments");
	}
}

unique_ptr<CShape> CreateCircle(vector<string> command)
{
	if (command.size() == 6)
	{
		try
		{
			return make_unique<CCircle>(CPoint(stod(command[1]), stod(command[2])), stod(command[3]), command[4], command[5]);
		}
		catch (const std::logic_error&)
		{
			throw invalid_argument("Incorrect argument");
		}
	}
	else
	{
		throw invalid_argument("Incorrect number of arguments");
	}
}

bool AreaCompare(unique_ptr<IShape> const& firstShape, unique_ptr<IShape> const& secondShape)
{
	return firstShape->GetArea() < secondShape->GetArea();
}

bool PerimeterCompare(unique_ptr<IShape> const& firstShape, unique_ptr<IShape> const& secondShape)
{
	return firstShape->GetPerimeter() < secondShape->GetPerimeter();
}

void CConsoleCommand::DoCommand(istream& commands)
{
	string commandLine;
	vector<string> command;
	while (getline(commands, commandLine))
	{
		try
		{
			boost::split(command, commandLine, is_any_of(" "), token_compress_on);

			if (command[0] == "LineSegment")
			{
				m_shapes.push_back(CreateLineSegment(command));
			}
			else if (command[0] == "Triangle")
			{
				m_shapes.push_back(CreateTriangle(command));
			}
			else if (command[0] == "Rectangle")
			{
				m_shapes.push_back(CreateRectangle(command));
			}
			else if (command[0] == "Circle")
			{
				m_shapes.push_back(CreateCircle(command));
			}
			else
			{
				throw invalid_argument("Incorrect shape");
			}
		}
		catch (invalid_argument const& e)
		{
			cout << e.what() << endl;
		}
	}
}

vector<unique_ptr<IShape>>::const_iterator CConsoleCommand::GetShapeWithMaxArea() const
{
	if (!m_shapes.empty())
	{
		return max_element(m_shapes.begin(), m_shapes.end(), AreaCompare);
	}
	return m_shapes.end();
}

vector<unique_ptr<IShape>>::const_iterator CConsoleCommand::GetShapeWithMinPerimeter() const
{
	if (!m_shapes.empty())
	{
		return min_element(m_shapes.begin(), m_shapes.end(), PerimeterCompare);
	}
	return m_shapes.end();
}

string CConsoleCommand::GetShapeInfo(vector<unique_ptr<IShape>>::const_iterator shape) const
{
	if (shape == m_shapes.end())
	{
		return "";
	}
	string result;
	result = (*shape)->ToString();
	return result;
}

void CConsoleCommand::DrawShapes() const
{
	if (!m_shapes.empty())
	{
		sf::RenderWindow window(sf::VideoMode(600, 600), "Draw Shapes!");
		CCanvas canvas(window);
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
				}
			}
			window.clear(sf::Color(255, 255, 255));

			for (const auto& shape : m_shapes)
			{
				shape->Draw(canvas);
			}
			window.display();
		}
	}
}
