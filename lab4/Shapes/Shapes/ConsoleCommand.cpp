#include "ConsoleCommand.h"
#include "Circle.h"
#include "LineSegment.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "SolidShape.h"
#include "Triangle.h"

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
		throw invalid_argument("Uncorrect number of arguments");
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
		throw invalid_argument("Uncorrect number of arguments");
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
		throw invalid_argument("Uncorrect number of arguments");
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
		throw invalid_argument("Uncorrect number of arguments");
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
	try
	{
		while (!commands.eof())
		{
			string commandLine;
			getline(commands, commandLine);
			vector<string> command;
			boost::split(command, commandLine, is_any_of(" "), token_compress_on);
			cout << command[0] << endl;

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
				throw invalid_argument("Uncorrect shape");
			}
		}
		cout << "1\n";
		if (!m_shapes.empty())
		{
			cout << "2\n";
			auto shapeWithMaxArea = max_element(m_shapes.begin(), m_shapes.end(), AreaCompare);
			(*shapeWithMaxArea)->ToString();
			auto shapeWithMinPerimeter = min_element(m_shapes.begin(), m_shapes.end(), PerimeterCompare);
			(*shapeWithMinPerimeter)->ToString();
		}
	}
	catch (invalid_argument const& e)
	{
		cout << e.what() << endl;
	}
}
