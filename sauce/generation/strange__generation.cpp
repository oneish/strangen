#include <iostream>
#include <fstream>

inline void start(bool& generate, std::ofstream& out)
{
	if (!generate)
	{
		generate = true;
		out << R"#(
#include <iostream>
int main()
{)#";
	}
	out << R"#(
std::cout << R"~()#";
}

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		std::cerr << "usage: strangen input_filename output_filename" << std::endl;
		return 1;
	}

	std::string input_filename = argv[1]; // "../../../../strangenerate/generate.cpp";
	std::string output_filename = argv[2]; // "../../../../strangenerate/generator.cpp";

	std::ifstream in(input_filename.c_str(), std::ios::binary);
	if (!in.is_open())
	{
		std::cerr << "failed to open input file: " << input_filename << std::endl;
		return 2;
	}

	std::ofstream out(output_filename.c_str(), std::ios::binary | std::ios::trunc);
	if (!out.is_open())
	{
		std::cerr << "failed to open output file: " << output_filename << std::endl;
		return 3;
	}

	std::istreambuf_iterator<char> it(in), end;
	char c;

	bool generate = false;
	bool tilda = false;
	bool block = false;
	bool line = false;
	bool slash = false;
	bool asterisk = false;
	bool raw = false;

	while (it != end)
	{
		c = *it++;
		if (tilda)
		{
			if (asterisk)
			{
				if (c == '/')
				{
					tilda = false;
					block = false;
					asterisk = false;
					raw = true;
					start(generate, out);
				}
				else if (c == '*')
				{
					out << '*';
				}
				else
				{
					asterisk = false;
					out << '*' << c;
				}
			}
			// !asterisk
			else if (block && c == '*')
			{
				asterisk = true;
			}
			else if (line && c == '\n')
			{
				tilda = false;
				line = false;
				raw = true;
				start(generate, out);
				out << R"#(
)#";
			}
			else
			{
				out << c;
			}
		}
		// !tilda
		else if (block || line)
		{
			if (c == '~')
			{
				tilda = true;
				if (raw)
				{
					raw = false;
					out << R"#()~";
)#";
				}
			}
			else if (block)
			{
				block = false;
				out << "/*" << c;
			}
			else
			{
				line = false;
				out << "//" << c;
			}
		}
		// !block && !line
		else if (slash)
		{
			if (c == '*')
			{
				block = true;
			}
			else if (c == '/')
			{
				line = true;
			}
			else
			{
				out << '/' << c;
			}
			slash = false;
		}
		// !slash
		else
		{
			if (c == '/')
			{
				slash = true;
			}
			else
			{
				if (!generate)
				{
					raw = true;
					start(generate, out);
				}
				out << c;
			}
		}
	}

	if (tilda)
	{
		if (asterisk)
		{
			out << '*';
		}
	}
	else if (raw)
	{
		out << R"#()~";
)#";
	}
	else if (block)
	{
		out << "/*";
	}
	else if (line)
	{
		out << "//";
	}
	else if (slash)
	{
		out << '/';
	}

	if (generate)
	{
		out << R"#(
return 0;
}
)#";
	}

	return 0;
}